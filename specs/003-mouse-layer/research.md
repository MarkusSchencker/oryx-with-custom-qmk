# Research: Mouse Layer Implementation

**Feature**: 003-mouse-layer  
**Created**: November 11, 2025  
**Purpose**: Research QMK mouse key features, configuration options, and best practices for implementing a mouse control layer

## Research Questions

1. How does QMK's MOUSEKEY module work and what keycodes are available?
2. What configuration options control mouse speed, acceleration, and behavior?
3. What is the firmware size impact of enabling MOUSEKEY?
4. How should the mouse layer toggle key be implemented (MO vs TG vs TT)?
5. What is the optimal key layout for mouse movement and buttons?

## Findings

### 1. QMK MOUSEKEY Module

**Decision**: Use QMK's built-in MOUSEKEY module with standard keycodes

**Rationale**: 
- QMK provides comprehensive mouse control via HID mouse reports
- Standard keycodes work across all platforms (macOS, Windows, Linux)
- No custom code required - reduces firmware size and complexity
- Well-tested and maintained by QMK community

**Available Keycodes**:

**Cursor Movement**:
- `KC_MS_UP` / `KC_MS_U` - Move cursor up
- `KC_MS_DOWN` / `KC_MS_D` - Move cursor down
- `KC_MS_LEFT` / `KC_MS_L` - Move cursor left
- `KC_MS_RIGHT` / `KC_MS_R` - Move cursor right

**Mouse Buttons**:
- `KC_MS_BTN1` / `KC_BTN1` - Left click
- `KC_MS_BTN2` / `KC_BTN2` - Right click
- `KC_MS_BTN3` / `KC_BTN3` - Middle click
- `KC_MS_BTN4` / `KC_BTN4` - Mouse button 4
- `KC_MS_BTN5` / `KC_BTN5` - Mouse button 5

**Scroll Wheel**:
- `KC_MS_WH_UP` / `KC_WH_U` - Scroll up
- `KC_MS_WH_DOWN` / `KC_WH_D` - Scroll down
- `KC_MS_WH_LEFT` / `KC_WH_L` - Scroll left
- `KC_MS_WH_RIGHT` / `KC_WH_R` - Scroll right

**Speed Control**:
- `KC_MS_ACCEL0` / `KC_ACL0` - Set acceleration to 0 (slowest)
- `KC_MS_ACCEL1` / `KC_ACL1` - Set acceleration to 1 (slow)
- `KC_MS_ACCEL2` / `KC_ACL2` - Set acceleration to 2 (default/medium)

**Alternatives Considered**:
- Custom mouse control implementation via pointing device API - Rejected: More complex, larger code size, reinvents wheel
- Macro-based mouse emulation - Rejected: Platform-specific, unreliable, poor performance

### 2. MOUSEKEY Configuration

**Decision**: Configure mouse behavior in `config.h` with balanced speed/precision settings

**Configuration Options** (add to `vrMEr/config.h`):

```c
// Mouse key configuration
#define MOUSEKEY_DELAY 0              // Delay before cursor starts moving (ms)
#define MOUSEKEY_INTERVAL 16          // Time between cursor movements (ms) - ~60 updates/sec
#define MOUSEKEY_MOVE_DELTA 8         // Cursor movement distance per update (pixels)
#define MOUSEKEY_MAX_SPEED 10         // Maximum cursor speed multiplier
#define MOUSEKEY_TIME_TO_MAX 30       // Time to reach max speed (intervals)
#define MOUSEKEY_WHEEL_DELAY 0        // Delay before wheel starts scrolling (ms)
#define MOUSEKEY_WHEEL_INTERVAL 80    // Time between scroll events (ms)
#define MOUSEKEY_WHEEL_DELTA 1        // Scroll wheel movement per event
#define MOUSEKEY_WHEEL_MAX_SPEED 8    // Maximum scroll speed
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40 // Time to reach max scroll speed
```

**Rationale**:
- 16ms interval provides smooth 60fps cursor movement
- 8 pixel delta balances speed and control for 1080p/1440p displays
- Acceleration curve (TIME_TO_MAX=30) allows both precision and speed
- Scroll settings optimized for document navigation

**Speed Modes**:
- `KC_ACL0`: Precision mode (1/4 speed) - for fine positioning
- `KC_ACL1`: Normal mode (1/2 speed) - balanced
- `KC_ACL2`: Fast mode (full speed) - default, for traversing screen

**Alternatives Considered**:
- Constant speed without acceleration - Rejected: Poor UX, either too slow or too imprecise
- Higher base speed (>8 pixels) - Rejected: Difficult to control for small movements
- Platform-specific acceleration curves - Rejected: Added complexity, OS handles acceleration

### 3. Firmware Size Impact

**Decision**: MOUSEKEY module is acceptable within constitutional size limits

**Size Analysis**:
- MOUSEKEY module size: ~3-5KB (varies by enabled features)
- Current vrMEr firmware: ~70-80% of 256KB flash (estimated from 002-minimize-layers)
- Constitutional target: <230KB (90% of 256KB)
- Headroom: ~25-30KB available
- Mouse layer addition: ~5KB (module) + ~2KB (layer definition) = ~7KB total

**Verification Plan**:
- Compile firmware after adding MOUSEKEY_ENABLE = yes
- Check binary size in GitHub Actions build log
- If approaching limit: Review enabled RGB effects, audit feature flags

**Rationale**: 
- 7KB impact is well within available headroom
- Mouse layer provides significant UX value for size cost
- Constitutional principle "Every feature inclusion MUST be justified against the firmware size constraint" - satisfied by one-handed mouse control use case

**Alternatives Considered**:
- Minimize MOUSEKEY features (disable wheel, buttons 4/5) - Rejected: Minimal size savings (~500 bytes), reduces feature completeness
- Use pointing device API instead - Rejected: More complex, similar or larger size

### 4. Layer Toggle Mechanism

**Decision**: Use `MO(LAYER_MOUSE)` on left keyboard half for mouse layer access

**Toggle Options Compared**:

| Mechanism | Behavior | Pros | Cons | Use Case |
|-----------|----------|------|------|----------|
| `MO(layer)` | Active while held | One-handed operation, auto-return | Must hold key | ✅ **CHOSEN** - Sustained mouse control |
| `TG(layer)` | Toggle on/off | Hands-free toggle | Easy to forget state | Persistent mouse mode |
| `TT(layer)` | Tap-toggle hybrid | Best of both worlds | More complex behavior | Advanced users |
| `OSL(layer)` | One-shot layer | Single action use | Not suitable for mouse | Quick symbols |

**Rationale**:
- `MO()` allows one-handed operation: hold toggle with left hand, use mouse buttons with left hand, cursor stays accessible
- Auto-return when released prevents getting "stuck" in mouse layer
- Consistent with existing layer access patterns (OSL for symbols, LT for numbers)
- Spec requirement: "toggle key on left keyboard half to allow mouse button usage without right hand at the keyboard"

**Recommended Toggle Key Position**:
- Left keyboard half, easily accessible (home row or adjacent)
- Suggested: Replace `KC_TRANSPARENT` on left side with `MO(LAYER_MOUSE)`
- Alternative: Add to config layer for explicit activation

**Alternatives Considered**:
- `TG()` for persistent mode - Rejected: Users might forget mouse layer is active, leading to confusion
- `TT()` tap-toggle - Rejected: Added complexity, doesn't clearly solve "hold for sustained use" pattern
- Right-hand toggle - Rejected: Violates spec requirement for left-hand access

### 5. Optimal Key Layout

**Decision**: Arrow-key-like cursor layout on right hand, mouse buttons on left home row

**Cursor Movement Layout** (Right Hand):
```
Suggested mapping:
     [Up]
[Left][Down][Right]

Positions on Voyager right half:
- Up: Middle finger column, row 2
- Down: Middle finger column, row 3  
- Left: Index finger column, row 3
- Right: Ring finger column, row 3

Similar to inverted-T arrow key layout
```

**Mouse Button Layout** (Left Hand):
```
Left click:  Index or middle finger (most frequent action)
Right click: Ring or middle finger  
Middle click: Less accessible position (less frequent)

Suggested home row positions:
- Left click:  I position (left middle finger)
- Right click: E position (left ring finger)
- Middle click: H position (left index finger)
```

**Scroll Wheel Layout**:
```
Scroll up/down: Near cursor movement (right hand)
Scroll left/right: Less frequent, can use secondary positions
```

**Speed Control**:
```
Speed adjustment: Left hand, top row
ACL0 (precision), ACL1 (normal), ACL2 (fast)
```

**Rationale**:
- Arrow-key layout leverages existing muscle memory
- Cursor on right allows simultaneous button press with left
- Most frequent action (left click) on strongest/most accessible finger
- Diagonal movement naturally supported by pressing adjacent keys
- Speed controls on left hand keep right hand focused on movement

**Alternatives Considered**:
- WASD-style movement (W=up, A=left, S=down, D=right) - Rejected: Less intuitive for non-gamers, conflicts with HIEA alpha layout
- Vim-style HJKL movement - Rejected: Steeper learning curve, less universal
- Trackpoint-style acceleration - Rejected: Requires custom implementation, complexity increase

## Implementation Checklist

Based on research findings, the implementation requires:

### Phase 1 - Core Setup
- [ ] Add `MOUSEKEY_ENABLE = yes` to `vrMEr/rules.mk`
- [ ] Add MOUSEKEY configuration to `vrMEr/config.h`
- [ ] Add `LAYER_MOUSE = 6` to `enum layer_names` in `vrMEr/keymap.c`
- [ ] Define LAYER_MOUSE layout in `keymaps[][]` array

### Phase 2 - Key Mapping
- [ ] Map cursor movement keys (KC_MS_U/D/L/R) to right hand
- [ ] Map mouse buttons (KC_BTN1/2/3) to left hand
- [ ] Map scroll wheel (KC_WH_U/D/L/R) to appropriate positions
- [ ] Map speed controls (KC_ACL0/1/2) to left hand top row
- [ ] Add `MO(LAYER_MOUSE)` toggle key to left hand accessible position

### Phase 3 - Documentation & Testing
- [ ] Update `vrMEr/LAYER_VISUALIZATION.md` with mouse layer diagram
- [ ] Create testing checklist in `specs/003-mouse-layer/quickstart.md`
- [ ] Build firmware via GitHub Actions
- [ ] Test on actual hardware (all movement directions, all buttons, speed modes)

### Phase 4 - Validation
- [ ] Verify firmware size <230KB (constitutional requirement)
- [ ] Test diagonal cursor movement (simultaneous key presses)
- [ ] Test drag-and-drop operations (hold button, move cursor, release)
- [ ] Test OS compatibility (macOS and Windows)
- [ ] Verify auto-return to base layer when toggle released

## Dependencies & Prerequisites

1. **QMK Firmware Version**: Current qmk_firmware submodule supports MOUSEKEY (standard feature)
2. **Build System**: Existing GitHub Actions workflow supports MOUSEKEY compilation
3. **No External Dependencies**: MOUSEKEY is built into QMK, no additional libraries required

## Risks & Mitigations

| Risk | Impact | Probability | Mitigation |
|------|--------|-------------|------------|
| Firmware size exceeds 230KB | High (violates constitution) | Low | Monitor size during build, disable unused RGB effects if needed |
| Mouse movement feels sluggish | Medium (UX issue) | Medium | Tune MOUSEKEY_INTERVAL and MOVE_DELTA in config.h |
| Oryx doesn't support mouse keycodes | Medium (workflow disruption) | Low | Fallback to manual keymap.c editing for mouse layer |
| Diagonal movement doesn't work | Low (feature limitation) | Low | QMK supports simultaneous keys, test configuration |
| Users forget mouse layer is active | Low (UX confusion) | Very Low | Use MO() instead of TG() for auto-return behavior |

## Best Practices Applied

1. **Use Standard QMK Features**: Leverage built-in MOUSEKEY rather than custom implementation
2. **Configuration Centralization**: All mouse settings in config.h per constitution principle V
3. **Size Consciousness**: Monitor firmware size per constitution principle I
4. **Clear Documentation**: Layer purpose and key layout per constitution principle V
5. **OS-Agnostic Design**: Mouse HID events work universally per constitution principle III

## References

- [QMK Mouse Keys Documentation](https://docs.qmk.fm/#/feature_mouse_keys)
- QMK Source: `quantum/mousekey/mousekey.c`
- vrMEr Constitution: `.specify/memory/constitution.md`
- Feature Spec: `specs/003-mouse-layer/spec.md`
