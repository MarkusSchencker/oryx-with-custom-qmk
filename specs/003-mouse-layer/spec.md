# Feature Specification: Mouse Layer

**Feature Branch**: `003-mouse-layer`  
**Created**: November 11, 2025  
**Status**: Draft  
**Input**: User description: "implement a mouse layer with the mouse movement keys on the right and the mouse button keys on the left hand. Choose a suitable key to switch to the mouse layer. If possible on the left keyboard half to allow mouse button usage without right hand at the keyboard."

## User Scenarios & Testing *(mandatory)*

### User Story 1 - Navigate Computer Using Keyboard Mouse (Priority: P1)

As a keyboard user, I want to control the mouse cursor using keys on my keyboard's right hand while triggering mouse clicks with my left hand, so that I can navigate my computer without reaching for a physical mouse or trackpad.

**Why this priority**: This is the core value proposition - enabling basic mouse functionality directly from the keyboard. Essential for users who want to minimize hand movement between keyboard and mouse.

**Independent Test**: Can be fully tested by activating the mouse layer, moving the cursor in all directions using right-hand keys, clicking with left-hand buttons, and verifying cursor responds correctly to all inputs.

**Acceptance Scenarios**:

1. **Given** I am on any base layer, **When** I activate the mouse layer toggle on the left keyboard half, **Then** the mouse layer becomes active
2. **Given** the mouse layer is active, **When** I press directional keys on the right hand, **Then** the mouse cursor moves in the corresponding direction (up/down/left/right)
3. **Given** the mouse layer is active, **When** I press a left-hand mouse button key, **Then** the corresponding mouse click (left/middle/right) is triggered
4. **Given** the mouse layer is active, **When** I press the layer toggle key again, **Then** I return to my previous base layer (macOS or Windows)

---

### User Story 2 - One-Handed Mouse Click Operation (Priority: P2)

As a keyboard user who occasionally needs to click without repositioning my right hand from the mouse movement area, I want all mouse buttons (left, middle, right click) accessible on my left hand, so that I can perform complete mouse operations with my right hand off the keyboard.

**Why this priority**: Enables truly one-handed operation for scenarios where the user has positioned the cursor and wants to perform multiple clicks without returning their hand to the keyboard. Critical for the "without right hand at the keyboard" requirement.

**Independent Test**: Can be independently tested by activating the mouse layer, removing the right hand entirely, and verifying that all mouse click operations can be completed using only left-hand keys.

**Acceptance Scenarios**:

1. **Given** the mouse layer is active and my right hand is off the keyboard, **When** I press the left click key on my left hand, **Then** a left mouse click is triggered
2. **Given** the mouse layer is active and my right hand is off the keyboard, **When** I press the middle click key on my left hand, **Then** a middle mouse click is triggered
3. **Given** the mouse layer is active and my right hand is off the keyboard, **When** I press the right click key on my left hand, **Then** a right mouse click is triggered
4. **Given** the mouse layer is active, **When** I hold a mouse button key, **Then** the button remains pressed until I release the key (for drag operations)

---

### User Story 3 - Adjust Mouse Speed for Precision (Priority: P3)

As a keyboard user controlling the mouse via keyboard, I want to adjust mouse movement speed between fast (for crossing the screen) and slow (for precision work), so that I can efficiently handle both coarse and fine cursor positioning tasks.

**Why this priority**: Enhances usability but not essential for basic functionality. Users can work with a single fixed speed initially.

**Independent Test**: Can be independently tested by activating the mouse layer, triggering speed adjustment keys, and measuring cursor movement distance per key press at different speed settings.

**Acceptance Scenarios**:

1. **Given** the mouse layer is active, **When** I press the speed decrease key, **Then** subsequent cursor movements are slower and more precise
2. **Given** the mouse layer is active, **When** I press the speed increase key, **Then** subsequent cursor movements are faster for traversing larger distances
3. **Given** I have adjusted the mouse speed, **When** I deactivate and reactivate the mouse layer, **Then** the speed setting is preserved

---

### User Story 4 - Scroll Content Without Mouse Wheel (Priority: P3)

As a keyboard user, I want to scroll vertically and horizontally using dedicated scroll keys on the mouse layer, so that I can navigate documents and web pages without a physical mouse wheel.

**Why this priority**: Nice-to-have enhancement that completes the mouse emulation experience. Not essential for basic cursor control and clicking.

**Independent Test**: Can be independently tested by activating the mouse layer, opening a scrollable document, pressing scroll keys, and verifying the content scrolls in the expected direction.

**Acceptance Scenarios**:

1. **Given** the mouse layer is active and a scrollable window is focused, **When** I press the scroll up key, **Then** the content scrolls upward
2. **Given** the mouse layer is active and a scrollable window is focused, **When** I press the scroll down key, **Then** the content scrolls downward
3. **Given** the mouse layer is active and horizontally scrollable content is focused, **When** I press the scroll left/right keys, **Then** the content scrolls horizontally in the corresponding direction

---

### Edge Cases

- What happens when the user activates the mouse layer while holding a home row modifier from the base layer?
- How does the keyboard handle rapid cursor movement key presses (should movement accelerate or remain constant)?
- What occurs if the user presses multiple directional keys simultaneously (e.g., up + right for diagonal movement)?
- How does the mouse layer interact with OS-specific features (macOS Mission Control gestures, Windows window snapping)?
- What happens if the user triggers a mouse click while no cursor movement keys are being held?
- How does the layer toggle key behave if the user was on a temporary layer (OSL/LT) when activating mouse mode?
- What happens when the user presses a mouse button and then switches layers without releasing?

## Requirements *(mandatory)*

### Functional Requirements

- **FR-001**: System MUST add a new LAYER_MOUSE (layer 6) to the existing 6-layer architecture
- **FR-002**: System MUST provide a mouse layer toggle key positioned on the left keyboard half for easy one-handed access
- **FR-003**: System MUST map mouse cursor movement keys (up, down, left, right) to the right keyboard half in an ergonomic arrangement
- **FR-004**: System MUST map mouse button keys (left click, middle click, right click) to the left keyboard half
- **FR-005**: System MUST support holding mouse button keys to enable drag-and-drop operations
- **FR-006**: Mouse layer MUST be accessible from both macOS and Windows base layers
- **FR-007**: System MUST support diagonal cursor movement when multiple directional keys are pressed simultaneously
- **FR-008**: System MUST provide mouse wheel scroll emulation (up, down, left, right)
- **FR-009**: System MUST provide at least two mouse speed settings (default and precision/slow mode)
- **FR-010**: Mouse layer toggle key MUST return user to their previous base layer (macOS or Windows) when deactivated
- **FR-011**: System MUST preserve existing 6-layer functionality when mouse layer is inactive
- **FR-012**: System MUST use QMK mouse key features (QK_MOUSE_CURSOR_*, QK_MOUSE_BUTTON_*, QK_MOUSE_WHEEL_*) rather than custom implementations

### Key Entities *(include if feature involves data)*

- **Mouse Layer State**: Tracks whether mouse layer is active or inactive
- **Mouse Speed Setting**: Stores current mouse movement speed (default, precision)
- **Previous Base Layer**: Records which base layer (macOS/Windows) was active before entering mouse layer for proper return behavior

## Success Criteria *(mandatory)*

### Measurable Outcomes

- **SC-001**: User can activate mouse layer and move cursor to any screen position using only keyboard keys
- **SC-002**: User can perform all three mouse clicks (left, middle, right) using only left-hand keys without repositioning right hand
- **SC-003**: User can complete a typical drag-and-drop operation (activate mouse layer, position cursor, hold click, move cursor, release) using only keyboard
- **SC-004**: Mouse cursor movement responds to directional input within 50ms of key press
- **SC-005**: Diagonal movement (pressing two directional keys) produces smooth 45-degree cursor travel
- **SC-006**: Mouse layer activation and deactivation completes in a single key press
- **SC-007**: User can scroll through a 1000-line document using keyboard scroll keys
- **SC-008**: Firmware size remains under 230KB constitutional target (90% of 256KB flash) after adding mouse layer

## Non-Functional Requirements *(optional)*

### Performance

- Mouse cursor movement must feel responsive with minimal latency
- Key repeat rate for cursor movement should balance speed and control
- Layer switching should be instantaneous without perceptible delay

### Usability

- Mouse movement key layout should follow intuitive directional patterns (arrow-key-like or WASD-like)
- Mouse button keys should be positioned on easily accessible home row or adjacent positions
- Speed adjustment keys should be clearly distinguishable from movement and click keys

## Dependencies *(optional)*

- Requires QMK firmware mouse key support (MOUSEKEY_ENABLE = yes in rules.mk)
- Must integrate with existing 6-layer architecture without disrupting base/symbol/function/number/config layers
- Layer toggle mechanism must respect default_layer_state for proper OS detection on return

## Assumptions *(optional)*

- Users are familiar with the existing 6-layer architecture and layer switching mechanisms
- Mouse movement speed defaults will be based on QMK's standard MOUSEKEY configuration values
- Cursor acceleration features are not required (constant speed movement is acceptable)
- The mouse layer will use a toggle mechanism (MO or TG) rather than one-shot (OSL) since users may need sustained mouse control
- Left keyboard half has an available key position suitable for the mouse layer toggle
- Users accept that keyboard-based mouse control will be slower than physical mouse/trackpad for most tasks but valuable for occasional use or ergonomic breaks

## Out of Scope *(optional)*

- Advanced mouse gestures (three-finger swipe, pinch-to-zoom)
- OS-specific mouse configuration integration (macOS cursor acceleration curves, Windows pointer precision)
- Macros that combine mouse movement with clicks (e.g., "move to coordinates X,Y and click")
- Mouse sensitivity that adapts based on screen resolution or multi-monitor setups
- Visual feedback on screen showing which mouse layer speed is active
- Integration with external mouse/trackpad (e.g., disabling keyboard mouse when physical mouse is detected)

## Open Questions *(optional)*

None - all critical design decisions have reasonable defaults based on QMK mouse key conventions and the existing keyboard layout structure.
