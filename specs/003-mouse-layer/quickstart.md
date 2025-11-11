# Quickstart: Testing Mouse Layer

**Feature**: 003-mouse-layer  
**Purpose**: Quick testing guide for validating mouse layer functionality on actual hardware  
**Audience**: Developers and testers validating the mouse layer implementation

## Prerequisites

- [ ] Firmware compiled with MOUSEKEY_ENABLE = yes
- [ ] LAYER_MOUSE defined in vrMEr/keymap.c
- [ ] Firmware flashed to ZSA Voyager keyboard
- [ ] Computer with desktop environment (macOS, Windows, or Linux)
- [ ] Test applications: Text editor, web browser, file explorer

## Quick Validation (5 minutes)

### Step 1: Activate Mouse Layer
1. **Action**: Press the mouse layer toggle key (left keyboard half)
2. **Expected**: Layer activates (may have LED indication if configured)
3. **Test**: Press a typing key (e.g., 'A')
   - If nothing happens → Mouse layer active ✅
   - If 'A' types → Mouse layer not active ❌

### Step 2: Move Cursor
1. **Action**: Press KC_MS_UP (cursor up key on right hand)
2. **Expected**: Cursor moves upward on screen
3. **Repeat**: Test KC_MS_DOWN, KC_MS_LEFT, KC_MS_RIGHT
4. **Pass Criteria**: Cursor responds to all four directions

### Step 3: Click
1. **Action**: Position cursor over desktop icon
2. **Action**: Press KC_BTN1 (left click on left hand)
3. **Expected**: Icon gets selected (highlighted)
4. **Pass Criteria**: Single click registers

### Step 4: Deactivate Layer
1. **Action**: Release mouse layer toggle key
2. **Expected**: Return to base layer (typing works)
3. **Test**: Type some text
4. **Pass Criteria**: Normal typing functionality restored

**Result**: ✅ Basic mouse layer functionality working

## Full Test Suite (15-20 minutes)

### Test 1: Cursor Movement - All Directions

**Purpose**: Verify all directional movements work

| Direction | Key | Test | Expected Result | Pass/Fail |
|-----------|-----|------|-----------------|-----------|
| Up | KC_MS_UP | Hold for 2 seconds | Cursor moves upward ~100-150px | [ ] |
| Down | KC_MS_DOWN | Hold for 2 seconds | Cursor moves downward ~100-150px | [ ] |
| Left | KC_MS_LEFT | Hold for 2 seconds | Cursor moves left ~100-150px | [ ] |
| Right | KC_MS_RIGHT | Hold for 2 seconds | Cursor moves right ~100-150px | [ ] |

**Notes**: _____________________

### Test 2: Diagonal Movement

**Purpose**: Verify simultaneous directional keys work

| Combination | Test | Expected Result | Pass/Fail |
|-------------|------|-----------------|-----------|
| Up + Right | Hold both keys | Cursor moves diagonally up-right (~45°) | [ ] |
| Up + Left | Hold both keys | Cursor moves diagonally up-left (~45°) | [ ] |
| Down + Right | Hold both keys | Cursor moves diagonally down-right (~45°) | [ ] |
| Down + Left | Hold both keys | Cursor moves diagonally down-left (~45°) | [ ] |

**Notes**: _____________________

### Test 3: Mouse Buttons

**Purpose**: Verify all three mouse buttons work

**3a. Left Click**
1. **Setup**: Open file explorer, find a file icon
2. **Action**: Position cursor, press KC_BTN1 (left click key)
3. **Expected**: File gets selected (single click)
4. **Result**: [ ] Pass [ ] Fail

**3b. Right Click**
1. **Setup**: Position cursor over desktop or file
2. **Action**: Press KC_BTN2 (right click key)
3. **Expected**: Context menu appears
4. **Result**: [ ] Pass [ ] Fail

**3c. Middle Click**
1. **Setup**: Open web browser, position cursor over a link
2. **Action**: Press KC_BTN3 (middle click key)
3. **Expected**: Link opens in new tab
4. **Result**: [ ] Pass [ ] Fail

**Notes**: _____________________

### Test 4: Drag-and-Drop

**Purpose**: Verify holding button while moving cursor works

**Setup**: Open file explorer with draggable files

**Procedure**:
1. Position cursor over a file using KC_MS_* keys
2. Press and **hold** KC_BTN1 (left click)
3. While holding BTN1, move cursor with KC_MS_* keys to new location
4. Release KC_BTN1

**Expected**: File moves/copies to new location (drag-and-drop)

**Result**: [ ] Pass [ ] Fail

**Alternative Test**: Text selection in editor
1. Position cursor at start of text
2. Hold KC_BTN1
3. Move cursor to end of text
4. Release KC_BTN1
5. **Expected**: Text highlighted/selected

**Notes**: _____________________

### Test 5: Scroll Wheel

**Purpose**: Verify vertical and horizontal scrolling

**5a. Vertical Scroll**

**Setup**: Open long document (>1000 lines) or long webpage

| Direction | Key | Test | Expected Result | Pass/Fail |
|-----------|-----|------|-----------------|-----------|
| Scroll Up | KC_WH_UP | Hold for 3 seconds | Document scrolls upward (earlier content) | [ ] |
| Scroll Down | KC_WH_DOWN | Hold for 3 seconds | Document scrolls downward (later content) | [ ] |

**5b. Horizontal Scroll** (if mapped)

**Setup**: Open wide spreadsheet or webpage

| Direction | Key | Test | Expected Result | Pass/Fail |
|-----------|-----|------|-----------------|-----------|
| Scroll Left | KC_WH_LEFT | Hold for 2 seconds | Content scrolls left | [ ] |
| Scroll Right | KC_WH_RIGHT | Hold for 2 seconds | Content scrolls right | [ ] |

**Notes**: _____________________

### Test 6: Speed Control

**Purpose**: Verify speed adjustment keys work

**Procedure**:
1. Press KC_ACL2 (fast mode)
2. Hold KC_MS_RIGHT for 1 second
3. **Observe**: Cursor distance traveled (should be ~150-200px)
4. Press KC_ACL0 (precision mode)
5. Hold KC_MS_RIGHT for 1 second
6. **Observe**: Cursor distance traveled (should be ~40-50px, much slower)

**Expected**: Clear difference in cursor speed between ACL0 and ACL2

**Result**: [ ] Pass [ ] Fail

**Notes**: _____________________

### Test 7: Layer Switching

**Purpose**: Verify layer activation/deactivation works correctly

**7a. Activation**
1. Start on base layer (typing works)
2. Press mouse toggle key
3. **Expected**: Mouse layer active, typing keys don't work
4. **Result**: [ ] Pass [ ] Fail

**7b. Deactivation**
1. While mouse layer active, release toggle key
2. **Expected**: Return to base layer, typing works
3. Try typing "hello"
4. **Result**: [ ] Pass [ ] Fail

**7c. Rapid Switching**
1. Rapidly press/release toggle key 10 times
2. **Expected**: No keyboard freezing, no stuck keys
3. **Result**: [ ] Pass [ ] Fail

**Notes**: _____________________

### Test 8: OS Compatibility

**Purpose**: Verify mouse layer works on both operating systems

**8a. macOS** (if available)

**Setup**: Connect keyboard to macOS computer, ensure LAYER_MAC_BASE active

| Test | Expected Result | Pass/Fail |
|------|-----------------|-----------|
| Cursor movement | Works identically to Windows | [ ] |
| Mouse clicks | All three buttons work | [ ] |
| Scroll wheel | Scrolling works in all apps | [ ] |
| OS-aware shortcuts | Cmd+C still works (not affected by mouse layer) | [ ] |

**8b. Windows** (if available)

**Setup**: Connect keyboard to Windows computer, ensure LAYER_WIN_BASE active

| Test | Expected Result | Pass/Fail |
|------|-----------------|-----------|
| Cursor movement | Works identically to macOS | [ ] |
| Mouse clicks | All three buttons work | [ ] |
| Scroll wheel | Scrolling works in all apps | [ ] |
| OS-aware shortcuts | Ctrl+C still works (not affected by mouse layer) | [ ] |

**Notes**: _____________________

### Test 9: Edge Cases

**Purpose**: Verify unusual scenarios don't break functionality

**9a. Simultaneous Opposite Directions**
1. Press KC_MS_UP + KC_MS_DOWN together
2. **Expected**: Cursor stationary (velocities cancel)
3. **Result**: [ ] Pass [ ] Fail

**9b. Button Held During Layer Exit**
1. Press and hold KC_BTN1
2. While holding, release mouse layer toggle
3. **Expected**: Button releases, no stuck click state
4. **Result**: [ ] Pass [ ] Fail

**9c. Multiple Buttons**
1. Press KC_BTN1 + KC_BTN2 simultaneously
2. **Expected**: Both buttons register (rare use case, but shouldn't crash)
3. **Result**: [ ] Pass [ ] Fail

**Notes**: _____________________

### Test 10: Firmware Size

**Purpose**: Verify constitutional constraint (<230KB)

**Procedure**:
1. Build firmware via GitHub Actions
2. Check build log for firmware size
3. **Expected**: Total size <230KB (90% of 256KB flash)

**Actual Size**: __________ KB

**Result**: [ ] Pass [ ] Fail

**Notes**: _____________________

## Performance Checklist

**Latency Tests**:
- [ ] Cursor movement starts within 50ms of key press (perceptually instant)
- [ ] Button clicks register immediately (<30ms perceived delay)
- [ ] Layer switching feels instantaneous (<5ms)
- [ ] Diagonal movement is smooth (no stuttering or skipped frames)

**Usability Tests**:
- [ ] One-handed operation works (left hand can click while right hand off keyboard)
- [ ] Mouse layer toggle is easily accessible with left hand
- [ ] Cursor speed feels controllable (not too fast or too slow)
- [ ] Precision mode (ACL0) enables accurate small movements

## Common Issues & Troubleshooting

### Issue: Cursor doesn't move

**Possible Causes**:
- [ ] MOUSEKEY_ENABLE not set in rules.mk
- [ ] LAYER_MOUSE not properly defined
- [ ] Movement keys not mapped to KC_MS_* codes
- [ ] Firmware not flashed

**Fix**: Re-check keymap.c, rules.mk, rebuild and flash firmware

### Issue: Cursor moves too slowly/quickly

**Possible Causes**:
- [ ] MOUSEKEY_MOVE_DELTA too low/high
- [ ] MOUSEKEY_INTERVAL too high/low
- [ ] Speed mode set to ACL0 instead of ACL2

**Fix**: Adjust config.h values or press ACL2 for fast mode

### Issue: Clicks don't register

**Possible Causes**:
- [ ] Button keys not mapped to KC_BTN1/2/3
- [ ] Mouse layer not active
- [ ] OS accessibility settings interfering

**Fix**: Verify key mapping, ensure layer active, check OS settings

### Issue: Layer won't activate

**Possible Causes**:
- [ ] Toggle key not mapped to MO(LAYER_MOUSE)
- [ ] Wrong layer number in MO() macro
- [ ] Key position mapped as KC_TRANSPARENT

**Fix**: Check keymap.c layer definitions and toggle key mapping

### Issue: Firmware size exceeds 230KB

**Possible Causes**:
- [ ] Too many RGB effects enabled
- [ ] Multiple large features enabled
- [ ] Debug/console enabled

**Fix**: Disable unused RGB effects in config.h, review features in rules.mk

## Test Summary Report

**Date Tested**: ______________  
**Tester**: ______________  
**Firmware Version**: ______________  
**OS Tested**: [ ] macOS [ ] Windows [ ] Linux

**Overall Results**:
- Tests Passed: ______ / 10
- Tests Failed: ______
- Performance: [ ] Excellent [ ] Good [ ] Needs Improvement
- Ready for Production: [ ] Yes [ ] No

**Critical Issues Found**:
_______________________________________
_______________________________________
_______________________________________

**Recommendations**:
_______________________________________
_______________________________________
_______________________________________

## Next Steps

**If All Tests Pass**:
1. ✅ Update LAYER_VISUALIZATION.md with mouse layer diagram
2. ✅ Document final key positions in contracts/mouse-layer.md
3. ✅ Commit and push implementation to GitHub
4. ✅ Create pull request or merge to main branch

**If Tests Fail**:
1. ❌ Document failures in test notes
2. ❌ Reference contracts/mouse-layer.md for expected behavior
3. ❌ Debug keymap.c, config.h, or rules.mk
4. ❌ Rebuild and re-test
5. ❌ Repeat until all tests pass

## Reference Documents

- **Feature Spec**: `specs/003-mouse-layer/spec.md`
- **Implementation Plan**: `specs/003-mouse-layer/plan.md`
- **Layer Contract**: `specs/003-mouse-layer/contracts/mouse-layer.md`
- **Data Model**: `specs/003-mouse-layer/data-model.md`
- **QMK Mouse Keys Docs**: https://docs.qmk.fm/#/feature_mouse_keys
