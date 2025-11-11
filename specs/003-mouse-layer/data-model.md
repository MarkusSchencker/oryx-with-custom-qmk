# Data Model: Mouse Layer

**Feature**: 003-mouse-layer  
**Created**: November 11, 2025  
**Purpose**: Define the state model, configuration parameters, and layer structure for mouse layer functionality

## Overview

The mouse layer introduces a new layer state (LAYER_MOUSE = 6) to the existing 6-layer vrMEr keyboard architecture. Unlike traditional data models, keyboard firmware manages layer state, mouse movement/button state, and configuration parameters rather than persistent data entities.

## Layer State Model

### Enum: layer_names

```c
enum layer_names {
  LAYER_MAC_BASE = 0,    // macOS base layer (existing)
  LAYER_WIN_BASE = 1,    // Windows base layer (existing)
  LAYER_SYMBOLS = 2,     // Symbols layer (existing)
  LAYER_FUNCTION = 3,    // Function/navigation layer (existing)
  LAYER_NUMBERS = 4,     // Numbers/numpad layer (existing)
  LAYER_CONFIG = 5,      // Configuration layer (existing)
  LAYER_MOUSE = 6,       // Mouse control layer (NEW)
};
```

**State Transitions**:
- From any layer → LAYER_MOUSE: Press and hold `MO(LAYER_MOUSE)` toggle key
- LAYER_MOUSE → previous layer: Release `MO(LAYER_MOUSE)` toggle key
- Auto-return: Layer automatically deactivates when toggle key released

### Layer State Tracking

**QMK Internal State** (managed by QMK firmware):
- `layer_state`: Current active layers (bitfield)
- `default_layer_state`: Base layer (macOS or Windows)
- Mouse layer is a **temporary layer** activated via MO(), not a default layer

**State Rules**:
1. Mouse layer can be activated from any base layer (MAC or WIN)
2. Mouse layer does not change `default_layer_state` (OS mode preserved)
3. Multiple layers can be active simultaneously (e.g., LAYER_MOUSE + LAYER_MAC_BASE)
4. Releasing toggle key clears LAYER_MOUSE from `layer_state`

## Mouse State Model

### Mouse Cursor State

**Managed by QMK MOUSEKEY Module**:

```c
typedef struct {
  int8_t x;          // Cursor X velocity (-127 to +127)
  int8_t y;          // Cursor Y velocity (-127 to +127)
  int8_t h;          // Horizontal scroll (-127 to +127)
  int8_t v;          // Vertical scroll (-127 to +127)
  uint8_t buttons;   // Button state bitfield
} mouse_report_t;
```

**Button Bitfield**:
- Bit 0: Left button (KC_BTN1)
- Bit 1: Right button (KC_BTN2)
- Bit 2: Middle button (KC_BTN3)
- Bit 3: Button 4 (KC_BTN4)
- Bit 4: Button 5 (KC_BTN5)

**Cursor Movement Logic**:
1. When movement key pressed (KC_MS_UP/DOWN/LEFT/RIGHT):
   - Set velocity in corresponding direction
   - Apply acceleration based on time held
   - Send HID report to OS
2. When movement key released:
   - Clear velocity for that direction
   - Continue movement in other held directions (diagonal)
3. OS receives HID mouse reports and moves cursor accordingly

### Mouse Speed State

**Speed Acceleration Levels** (managed by MOUSEKEY module):

```c
// Speed mode selected by KC_ACL0/ACL1/ACL2
uint8_t mousekey_accel = 2;  // Default: ACL2 (full speed)

// Acceleration levels:
// ACL0 = 0: Precision mode (1/4 speed)
// ACL1 = 1: Normal mode (1/2 speed)  
// ACL2 = 2: Fast mode (full speed) - DEFAULT
```

**Speed State Transitions**:
- Press `KC_ACL0` → Set mousekey_accel = 0 (precision mode)
- Press `KC_ACL1` → Set mousekey_accel = 1 (normal mode)
- Press `KC_ACL2` → Set mousekey_accel = 2 (fast mode - default)
- Speed setting persists across layer activations

## Configuration Parameters

### MOUSEKEY Configuration (config.h)

**Static Configuration** (compile-time constants):

| Parameter | Type | Default Value | Purpose | Range |
|-----------|------|---------------|---------|-------|
| `MOUSEKEY_DELAY` | uint16_t | 0 ms | Delay before cursor starts moving | 0-255 ms |
| `MOUSEKEY_INTERVAL` | uint16_t | 16 ms | Time between cursor movements | 1-255 ms |
| `MOUSEKEY_MOVE_DELTA` | uint8_t | 8 pixels | Base cursor movement distance | 1-127 pixels |
| `MOUSEKEY_MAX_SPEED` | uint8_t | 10 | Maximum speed multiplier | 1-127 |
| `MOUSEKEY_TIME_TO_MAX` | uint8_t | 30 intervals | Time to reach max speed | 1-255 |
| `MOUSEKEY_WHEEL_DELAY` | uint16_t | 0 ms | Delay before wheel scrolling | 0-255 ms |
| `MOUSEKEY_WHEEL_INTERVAL` | uint16_t | 80 ms | Time between scroll events | 1-255 ms |
| `MOUSEKEY_WHEEL_DELTA` | uint8_t | 1 | Scroll wheel movement per event | 1-127 |
| `MOUSEKEY_WHEEL_MAX_SPEED` | uint8_t | 8 | Maximum scroll speed | 1-127 |
| `MOUSEKEY_WHEEL_TIME_TO_MAX` | uint8_t | 40 intervals | Time to reach max scroll speed | 1-255 |

**Validation Rules**:
- All timing values must be > 0 (except DELAY which can be 0)
- MOVE_DELTA must balance speed and precision (recommended: 5-15 pixels)
- INTERVAL affects update rate: lower = smoother but more CPU (recommended: 10-20ms)
- MAX_SPEED multiplier affects acceleration curve (recommended: 8-12)

## Key Layout Model

### Mouse Layer Key Mapping

**Left Hand (Mouse Buttons & Speed Control)**:

```c
// Row 1 (top): Speed controls
[0][0] = KC_ACL0,        // Precision mode (1/4 speed)
[0][1] = KC_ACL1,        // Normal mode (1/2 speed)
[0][2] = KC_ACL2,        // Fast mode (full speed)

// Row 2: (TBD - may include button 4/5 or additional functions)

// Row 3 (home row): Mouse buttons
[2][0] = KC_BTN3,        // Middle click (index finger)
[2][1] = KC_BTN1,        // Left click (middle finger) - most frequent
[2][2] = KC_BTN2,        // Right click (ring finger)

// Row 4: (TBD - may include scroll or modifier combos)

// Thumb: Layer access preserved (symbols/shift)
```

**Right Hand (Cursor Movement & Scroll)**:

```c
// Row 1: (TBD - may include special functions)

// Row 2-3: Cursor movement (arrow-key layout)
[1][1] = KC_MS_U,        // Cursor up
[2][0] = KC_MS_L,        // Cursor left
[2][1] = KC_MS_D,        // Cursor down
[2][2] = KC_MS_R,        // Cursor right

// Row 2-3 (adjacent): Scroll wheel
[1][2] = KC_WH_U,        // Scroll up
[2][3] = KC_WH_D,        // Scroll down
[1][3] = KC_WH_L,        // Scroll left (optional)
[2][4] = KC_WH_R,        // Scroll right (optional)

// Row 4: (TBD - may include modifiers or special controls)

// Thumb: Space/function access preserved
```

**Toggle Key** (activates LAYER_MOUSE):
- Position: Left hand, easily accessible (home row or adjacent)
- Keycode: `MO(LAYER_MOUSE)`
- Suggested: Replace a `KC_TRANSPARENT` on left base layer with toggle

### Diagonal Movement Support

**Implementation**:
QMK automatically handles simultaneous key presses. No special configuration required.

**Examples**:
- Press `KC_MS_U` + `KC_MS_R` → Cursor moves diagonally up-right
- Press `KC_MS_D` + `KC_MS_L` → Cursor moves diagonally down-left
- Movement vectors combine: velocity_x = (left ? -1 : 0) + (right ? 1 : 0)

## Relationships

### Layer Hierarchy

```
┌─────────────────────────────────────────────┐
│ LAYER_MOUSE (temporary, MO-activated)      │
│ ┌─────────────────────────────────────────┐ │
│ │ LAYER_MAC_BASE or LAYER_WIN_BASE        │ │
│ │ (default layer, persists)               │ │
│ └─────────────────────────────────────────┘ │
└─────────────────────────────────────────────┘

Interaction:
- Mouse layer overlays base layer (both active simultaneously)
- KC_TRANSPARENT keys on mouse layer fall through to base layer
- OS detection (is_macos_base) uses default_layer_state, works correctly even when mouse layer active
```

### State Persistence

| State | Persistence | Storage | Lifetime |
|-------|-------------|---------|----------|
| Layer state | Volatile | RAM | Until key released or layer switched |
| Default layer | Volatile | RAM | Until SW_MAC/SW_WIN pressed or keyboard reset |
| Mouse speed | Volatile | RAM | Until speed key pressed or keyboard reset |
| Mouse position | External | OS | Managed by operating system |
| Mouse buttons | Volatile | HID report | Until button key released |
| Configuration | Static | Flash | Compile-time constants in config.h |

**Key Insight**: 
- Mouse layer state is **temporary** (cleared when toggle released)
- Mouse speed setting **persists** across layer activations (until changed)
- Default layer (OS mode) **persists** even when mouse layer active (critical for OS-aware functions)

## Firmware Size Impact

### Memory Allocation

**Flash (Code)**:
- MOUSEKEY module: ~3-5KB
- LAYER_MOUSE definition: ~0.5KB (52 keys × 2 bytes)
- Configuration constants: ~50 bytes
- **Total**: ~5.5KB added to firmware

**RAM (Runtime)**:
- Mouse report buffer: 5 bytes
- Layer state: No additional (uses existing bitfield)
- Speed state: 1 byte
- **Total**: ~6 bytes additional RAM

**Validation**: 
- Constitutional target: <230KB flash
- Current firmware: ~180-200KB (estimated)
- After mouse layer: ~186-206KB
- ✅ **PASS**: Remains well under 230KB limit

## Edge Cases & Boundary Conditions

### Edge Case 1: Rapid Layer Switching
**Scenario**: User rapidly presses/releases mouse layer toggle  
**Behavior**: QMK handles debouncing, layer state updates on each valid press/release  
**Validation**: Mouse buttons released when layer deactivates (no stuck buttons)

### Edge Case 2: Button Held During Layer Switch
**Scenario**: User holds KC_BTN1, releases MO(LAYER_MOUSE)  
**Behavior**: Button release event sent when layer deactivates  
**Implementation**: QMK clears button state on layer change

### Edge Case 3: Simultaneous Movement Keys
**Scenario**: User presses all 4 directional keys (up+down+left+right)  
**Behavior**: Velocities cancel out, cursor stationary  
**Math**: velocity_x = -1 + 1 = 0, velocity_y = -1 + 1 = 0

### Edge Case 4: OS Detection While Mouse Layer Active
**Scenario**: User activates mouse layer from Windows base, uses OS-aware function  
**Behavior**: `is_macos_base()` correctly returns false (checks default_layer_state)  
**Validation**: OS-aware clipboard/navigation keys work correctly even when mouse layer active

### Edge Case 5: Firmware Size Exceeds Limit
**Scenario**: Compiled firmware >230KB after adding mouse layer  
**Mitigation**: Disable unused RGB effects in config.h, review feature flags in rules.mk  
**Fallback**: Reduce MOUSEKEY features (disable buttons 4/5, horizontal scroll)

## Testing Validation Matrix

| State Transition | Input | Expected Output | Validation Method |
|------------------|-------|-----------------|-------------------|
| Activate mouse layer | Press MO(LAYER_MOUSE) | layer_state includes LAYER_MOUSE | LED indication or key test |
| Deactivate mouse layer | Release MO(LAYER_MOUSE) | layer_state clears LAYER_MOUSE | Return to base layer keys |
| Move cursor up | Press KC_MS_U | Cursor moves upward | Visual cursor movement |
| Move cursor diagonal | Press KC_MS_U + KC_MS_R | Cursor moves up-right at 45° | Visual cursor movement |
| Left click | Press KC_BTN1 | Left mouse click event | Click on UI element |
| Right click | Press KC_BTN2 | Right mouse click event | Context menu appears |
| Middle click | Press KC_BTN3 | Middle mouse click event | Browser tab behavior |
| Drag operation | Hold KC_BTN1, press KC_MS_R | Click and drag right | Drag file/window |
| Scroll down | Press KC_WH_D | Page scrolls downward | Document scrolls |
| Precision mode | Press KC_ACL0 | Cursor moves slower | Compare movement distance |
| Fast mode | Press KC_ACL2 | Cursor moves faster | Compare movement distance |
| OS preservation | Activate mouse from WIN base | is_macos_base() = false | OS-aware key test |

## Dependencies

**QMK Modules**:
- `quantum/mousekey/mousekey.c` - Core mouse key implementation
- `quantum/action.c` - Key action processing
- `quantum/action_layer.c` - Layer state management

**External Dependencies**:
- Operating system HID mouse driver (standard on all platforms)
- USB HID protocol support (built into ZSA Voyager hardware)

## Summary

The mouse layer data model is primarily **state-based** rather than entity-based. Key concepts:

1. **Layer State**: LAYER_MOUSE as temporary overlay via MO() mechanism
2. **Mouse State**: Velocity vectors and button bitfield managed by MOUSEKEY module  
3. **Configuration**: Static parameters in config.h defining speed/acceleration curves
4. **Relationships**: Mouse layer overlays base layer, preserves OS detection via default_layer_state

The model is designed for minimal memory footprint (~5.5KB flash, ~6 bytes RAM) while providing full mouse control functionality within constitutional constraints.
