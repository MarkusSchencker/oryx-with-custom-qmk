# Mouse Layer Contract

**Feature**: 003-mouse-layer  
**Layer**: LAYER_MOUSE (layer 6)  
**Purpose**: Enable mouse cursor control and clicking via keyboard keys

## Layer Activation Contract

### Preconditions
- User is on any base layer (LAYER_MAC_BASE or LAYER_WIN_BASE)
- Keyboard firmware has MOUSEKEY_ENABLE = yes in rules.mk
- LAYER_MOUSE is defined in keymap

### Activation Trigger
**Input**: Press and hold `MO(LAYER_MOUSE)` toggle key (left keyboard half)

**Expected Behavior**:
1. LAYER_MOUSE becomes active in layer_state bitfield
2. Base layer (macOS or Windows) remains active in default_layer_state
3. Mouse layer key mappings become accessible
4. KC_TRANSPARENT keys fall through to base layer
5. Layer activation completes within 1ms (QMK processing time)

### Deactivation Trigger
**Input**: Release `MO(LAYER_MOUSE)` toggle key

**Expected Behavior**:
1. LAYER_MOUSE cleared from layer_state bitfield
2. All mouse button states cleared (no stuck buttons)
3. Cursor movement stops immediately
4. Return to base layer key mappings
5. Layer deactivation completes within 1ms

### Postconditions
- User can repeat activation/deactivation cycle without issues
- Default layer (OS mode) preserved across mouse layer activations
- No memory leaks or state corruption

## Cursor Movement Contract

### Preconditions
- LAYER_MOUSE is active
- MOUSEKEY configuration defined in config.h

### Single Direction Movement

**Input**: Press and hold directional key (KC_MS_UP/DOWN/LEFT/RIGHT)

**Expected Behavior**:
1. Cursor begins moving in specified direction
2. Initial movement after MOUSEKEY_DELAY (0ms default)
3. Movement repeats every MOUSEKEY_INTERVAL (16ms default)
4. Movement distance per interval: MOUSEKEY_MOVE_DELTA (8 pixels default)
5. Acceleration applied based on MOUSEKEY_TIME_TO_MAX (30 intervals)
6. Maximum speed: MOUSEKEY_MAX_SPEED multiplier (10x default)
7. Movement continues until key released

**Release Behavior**:
1. Cursor stops moving in that direction
2. Movement in other held directions continues (for diagonal)
3. Acceleration state resets for that direction

### Diagonal Movement

**Input**: Press and hold two orthogonal directional keys simultaneously (e.g., KC_MS_UP + KC_MS_RIGHT)

**Expected Behavior**:
1. Cursor moves in diagonal direction (combination of both vectors)
2. Velocity in both axes applied simultaneously
3. Diagonal angle: ~45 degrees (equal velocity in each direction)
4. Movement is smooth without stuttering
5. Speed matches single-direction movement (combined vector magnitude may be higher)

**Validation**:
```c
// Example: Up + Right
velocity_x = (KC_MS_R held ? +speed : 0) + (KC_MS_L held ? -speed : 0)
velocity_y = (KC_MS_U held ? -speed : 0) + (KC_MS_D held ? +speed : 0)

// Up + Right pressed: velocity_x = +speed, velocity_y = -speed
// Result: Diagonal movement up-right
```

### Boundary Conditions
- **Screen Edge**: Cursor stops at screen boundary (OS behavior, not keyboard)
- **All Directions Pressed**: Velocities cancel, cursor stationary
- **Rapid Direction Change**: New direction applies immediately, no lag

## Mouse Button Contract

### Preconditions
- LAYER_MOUSE is active
- Operating system has active window/cursor context

### Button Click (Single Click)

**Input**: Press and release button key (KC_BTN1/BTN2/BTN3)

**Expected Behavior**:
1. Button press: HID report sent with button bit set (e.g., bit 0 for BTN1)
2. OS registers mouse button down event
3. Button release: HID report sent with button bit cleared
4. OS registers mouse button up event
5. Total click duration: User's press duration (typically 50-150ms)
6. OS performs click action (select, activate, etc.)

**Validation**:
- Left click (KC_BTN1): Selects items, activates buttons
- Right click (KC_BTN2): Opens context menus
- Middle click (KC_BTN3): Opens links in new tab (browser), paste (Linux)

### Button Hold (Drag Operation)

**Input**: Press and hold button key (KC_BTN1/BTN2/BTN3)

**Expected Behavior**:
1. Button press: HID report sent with button bit set
2. OS registers mouse button down event
3. **While button held**: Cursor movement keys still functional
4. User can move cursor with movement keys while button held
5. OS interprets as drag operation
6. Button release: HID report sent with button bit cleared
7. OS registers mouse button up event (completes drag)

**Example Drag Workflow**:
```
1. Position cursor over draggable item (use KC_MS_* keys)
2. Press and hold KC_BTN1 (left click)
3. Move cursor to destination (use KC_MS_* keys while holding BTN1)
4. Release KC_BTN1 (completes drag-and-drop)
```

**Validation**:
- File drag-and-drop in file explorer
- Text selection (click start, drag to end, release)
- Window resizing/moving

### Multiple Buttons

**Input**: Press multiple button keys simultaneously (e.g., KC_BTN1 + KC_BTN2)

**Expected Behavior**:
1. HID report sent with multiple button bits set
2. OS registers both buttons pressed
3. Application-specific behavior (varies by software)
4. Buttons release independently

**Note**: Most applications don't use multi-button combinations, but keyboard supports it.

## Scroll Wheel Contract

### Preconditions
- LAYER_MOUSE is active
- Scrollable content is focused (document, webpage, list)

### Vertical Scroll

**Input**: Press and hold scroll key (KC_WH_U for up, KC_WH_D for down)

**Expected Behavior**:
1. Scroll begins after MOUSEKEY_WHEEL_DELAY (0ms default)
2. Scroll repeats every MOUSEKEY_WHEEL_INTERVAL (80ms default)
3. Scroll distance per event: MOUSEKEY_WHEEL_DELTA (1 unit default)
4. Acceleration applied based on MOUSEKEY_WHEEL_TIME_TO_MAX (40 intervals)
5. Maximum scroll speed: MOUSEKEY_WHEEL_MAX_SPEED (8x default)
6. Content scrolls in specified direction
7. Scrolling continues until key released

**Validation**:
- KC_WH_U: Page scrolls upward (earlier content visible)
- KC_WH_D: Page scrolls downward (later content visible)

### Horizontal Scroll

**Input**: Press and hold scroll key (KC_WH_L for left, KC_WH_R for right)

**Expected Behavior**: Same as vertical scroll, but in horizontal direction

**Validation**:
- KC_WH_L: Content scrolls left (earlier columns visible in spreadsheet)
- KC_WH_R: Content scrolls right (later columns visible)

**Note**: Horizontal scroll support varies by application.

### Boundary Conditions
- **Content Start**: Scroll up at document start has no effect
- **Content End**: Scroll down at document end has no effect
- **Non-scrollable Content**: Scroll keys have no effect (expected)

## Speed Control Contract

### Preconditions
- LAYER_MOUSE is active
- Speed control keys mapped (KC_ACL0/ACL1/ACL2)

### Speed Change

**Input**: Press speed control key (KC_ACL0/ACL1/ACL2)

**Expected Behavior**:
1. Internal mousekey_accel variable updated:
   - KC_ACL0: mousekey_accel = 0 (precision mode, 1/4 speed)
   - KC_ACL1: mousekey_accel = 1 (normal mode, 1/2 speed)
   - KC_ACL2: mousekey_accel = 2 (fast mode, full speed - default)
2. Speed change applies immediately (next cursor movement)
3. Speed setting persists until another speed key pressed
4. Speed setting survives layer deactivation/reactivation

**Validation**:
```
Test procedure:
1. Press KC_ACL2 (fast mode)
2. Press and hold KC_MS_R for 1 second
3. Measure cursor distance traveled: ~150-200 pixels (with acceleration)
4. Press KC_ACL0 (precision mode)
5. Press and hold KC_MS_R for 1 second  
6. Measure cursor distance traveled: ~40-50 pixels (slower)
```

### Speed Persistence

**Input**: 
1. Set speed to KC_ACL0 (precision)
2. Deactivate mouse layer
3. Reactivate mouse layer
4. Move cursor

**Expected Behavior**: Cursor moves at precision speed (setting persisted)

## OS Compatibility Contract

### macOS

**Preconditions**: Keyboard is connected to macOS computer, default_layer_state = LAYER_MAC_BASE

**Expected Behavior**:
- Mouse cursor movement: ✅ Works identically to Windows
- Left/Right/Middle click: ✅ Works identically to Windows
- Scroll wheel: ✅ Works identically to Windows
- OS-aware functions (copy/paste): ✅ Still use Cmd (is_macos_base() checks default_layer_state)
- No special macOS configuration required

### Windows

**Preconditions**: Keyboard is connected to Windows computer, default_layer_state = LAYER_WIN_BASE

**Expected Behavior**:
- Mouse cursor movement: ✅ Works identically to macOS
- Left/Right/Middle click: ✅ Works identically to macOS
- Scroll wheel: ✅ Works identically to macOS
- OS-aware functions (copy/paste): ✅ Still use Ctrl (is_macos_base() returns false)
- No special Windows configuration required

### Linux

**Expected Behavior**: Same as macOS/Windows (HID mouse protocol is universal)

## Performance Contract

### Timing Constraints

| Operation | Target Latency | Maximum Latency | Measurement Method |
|-----------|----------------|-----------------|-------------------|
| Layer activation | <1ms | <5ms | QMK processing time |
| Layer deactivation | <1ms | <5ms | QMK processing time |
| Cursor movement start | <16ms | <50ms | Time from key press to first movement |
| Button click response | <10ms | <30ms | Time from key press to HID report |
| Speed change application | <16ms | <50ms | Time until next movement uses new speed |

### Resource Constraints

| Resource | Maximum Usage | Constitutional Limit | Validation Method |
|----------|---------------|---------------------|-------------------|
| Flash (firmware size) | ~7KB (mouse layer) | <230KB total | GitHub Actions build log |
| RAM (runtime) | ~6 bytes | N/A (plenty available) | QMK memory profiler |
| CPU (processing) | <5% per movement | N/A (QMK handles efficiently) | No perceptible lag |
| USB bandwidth | ~8 bytes per report | N/A (HID reports are tiny) | Standard HID protocol |

## Error Handling Contract

### Invalid States

| Error Condition | Expected Behavior | Recovery Method |
|-----------------|-------------------|-----------------|
| Mouse layer defined but MOUSEKEY disabled | Compile error | Enable MOUSEKEY_ENABLE in rules.mk |
| Invalid MOUSEKEY config (e.g., INTERVAL=0) | Undefined behavior or compile warning | Fix config.h values |
| Firmware size exceeds 230KB | Build failure | Disable RGB effects or reduce features |
| Toggle key not mapped | Mouse layer inaccessible | Add MO(LAYER_MOUSE) to keymap |
| Stuck button state (rare QMK bug) | Button remains pressed after release | Reset keyboard (unplug/replug) |

### Graceful Degradation

If mouse functionality fails:
1. Keyboard remains functional for typing (base layers unaffected)
2. User can still access config layer to switch OS modes
3. User can exit mouse layer via toggle key
4. Physical mouse/trackpad still works (keyboard doesn't interfere)

## Testing Contract

### Unit Tests (Manual Hardware Tests)

**Test 1: Basic Activation**
```
Input:  Press MO(LAYER_MOUSE)
Expect: Mouse layer active, mouse keys functional
Pass:   [ ] Yes [ ] No
```

**Test 2: Cursor Movement - All Directions**
```
Input:  Hold KC_MS_U for 2 seconds
Expect: Cursor moves upward ~100-150 pixels
Pass:   [ ] Yes [ ] No

Repeat for KC_MS_D, KC_MS_L, KC_MS_R
```

**Test 3: Diagonal Movement**
```
Input:  Hold KC_MS_U + KC_MS_R simultaneously
Expect: Cursor moves diagonally up-right at ~45°
Pass:   [ ] Yes [ ] No
```

**Test 4: Mouse Buttons**
```
Input:  Click KC_BTN1 on desktop icon
Expect: Icon selected (single click)
Pass:   [ ] Yes [ ] No

Input:  Click KC_BTN2 on desktop
Expect: Context menu appears
Pass:   [ ] Yes [ ] No
```

**Test 5: Drag-and-Drop**
```
Input:  Hold KC_BTN1, move cursor with KC_MS_*, release BTN1
Expect: File/window drags to new location
Pass:   [ ] Yes [ ] No
```

**Test 6: Scroll Wheel**
```
Input:  Hold KC_WH_D in long document
Expect: Document scrolls downward smoothly
Pass:   [ ] Yes [ ] No
```

**Test 7: Speed Control**
```
Input:  Press KC_ACL0, move cursor
Expect: Cursor moves slowly (precision mode)
Pass:   [ ] Yes [ ] No

Input:  Press KC_ACL2, move cursor
Expect: Cursor moves quickly (fast mode)
Pass:   [ ] Yes [ ] No
```

**Test 8: Layer Deactivation**
```
Input:  Release MO(LAYER_MOUSE)
Expect: Mouse layer deactivates, typing keys work
Pass:   [ ] Yes [ ] No
```

**Test 9: OS Preservation**
```
Input:  Activate mouse layer from Windows base, press OS_COPY
Expect: Ctrl+C sent (not Cmd+C)
Pass:   [ ] Yes [ ] No
```

**Test 10: Firmware Size**
```
Input:  Build firmware via GitHub Actions
Expect: Binary size <230KB
Pass:   [ ] Yes [ ] No
```

### Integration Tests

**Test I1: Cross-Layer Interaction**
```
Scenario: User activates mouse layer from macOS base, uses mouse, returns to macOS base
Expected: OS detection still works, Cmd-based shortcuts functional
```

**Test I2: Rapid Layer Switching**
```
Scenario: User rapidly toggles mouse layer on/off 10 times
Expected: No stuck keys, no state corruption, keyboard remains responsive
```

**Test I3: Multi-Application Usage**
```
Scenario: Use mouse layer in text editor, web browser, file explorer
Expected: Mouse functions work consistently across all applications
```

## Success Criteria (from Spec)

**SC-001**: ✅ User can activate mouse layer and move cursor to any screen position using only keyboard keys  
**SC-002**: ✅ User can perform all three mouse clicks (left, middle, right) using only left-hand keys without repositioning right hand  
**SC-003**: ✅ User can complete a typical drag-and-drop operation (activate mouse layer, position cursor, hold click, move cursor, release) using only keyboard  
**SC-004**: ✅ Mouse cursor movement responds to directional input within 50ms of key press  
**SC-005**: ✅ Diagonal movement (pressing two directional keys) produces smooth 45-degree cursor travel  
**SC-006**: ✅ Mouse layer activation and deactivation completes in a single key press  
**SC-007**: ✅ User can scroll through a 1000-line document using keyboard scroll keys  
**SC-008**: ✅ Firmware size remains under 230KB constitutional target (90% of 256KB flash) after adding mouse layer

## Version & Changelog

**Version**: 1.0  
**Created**: November 11, 2025  
**Status**: Draft (pre-implementation)

**Future Revisions**: Update after implementation with actual key positions, performance measurements, and test results.
