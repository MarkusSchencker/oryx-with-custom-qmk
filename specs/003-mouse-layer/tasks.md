---
description: "Implementation tasks for mouse layer feature"
---

# Tasks: Mouse Layer for ZSA Voyager

**Feature**: 003-mouse-layer  
**Input**: Design documents from `specs/003-mouse-layer/`  
**Prerequisites**: plan.md, spec.md, research.md, data-model.md, contracts/, quickstart.md

**Organization**: Tasks are grouped by user story to enable independent implementation and testing of each story.

## Format: `[ID] [P?] [Story] Description`

- **[P]**: Can run in parallel (different files, no dependencies)
- **[Story]**: Which user story this task belongs to (e.g., US1, US2, US3, US4)
- Include exact file paths in descriptions

---

## Phase 1: Setup (Shared Infrastructure)

**Purpose**: Enable MOUSEKEY module and configure parameters

- [x] T001 Add `MOUSEKEY_ENABLE = yes` to `vrMEr/rules.mk`
- [x] T002 [P] Add MOUSEKEY configuration to `vrMEr/config.h` (MOUSEKEY_DELAY=0, MOUSEKEY_INTERVAL=16, MOUSEKEY_MOVE_DELTA=8, MOUSEKEY_MAX_SPEED=10, MOUSEKEY_TIME_TO_MAX=30, MOUSEKEY_WHEEL_DELAY=0, MOUSEKEY_WHEEL_INTERVAL=80, MOUSEKEY_WHEEL_DELTA=1, MOUSEKEY_WHEEL_MAX_SPEED=8, MOUSEKEY_WHEEL_TIME_TO_MAX=40)
- [x] T003 [P] Add `LAYER_MOUSE = 6` to `enum layer_names` in `vrMEr/keymap.c`

---

## Phase 2: Foundational (Blocking Prerequisites)

**Purpose**: Core infrastructure that MUST be complete before ANY user story can be implemented

**⚠️ CRITICAL**: No user story work can begin until this phase is complete

- [x] T004 Define LAYER_MOUSE layout structure in `keymaps[][]` array in `vrMEr/keymap.c` (52 key positions, initially all KC_TRANSPARENT)
- [x] T005 Add `MO(LAYER_MOUSE)` toggle key to left hand accessible position in base layers (LAYER_MAC_BASE and LAYER_WIN_BASE) in `vrMEr/keymap.c`

**Checkpoint**: Foundation ready - user story implementation can now begin in parallel

---

## Phase 3: User Story 1 - Navigate Computer Using Keyboard Mouse (Priority: P1) 🎯 MVP

**Goal**: Enable basic cursor movement and mouse clicking via keyboard keys

**Independent Test**: Activate mouse layer, move cursor in all 4 directions, perform left/right/middle clicks, deactivate layer

### Implementation for User Story 1

- [x] T006 [P] [US1] Map cursor up key (KC_MS_U) to right hand middle finger, row 2 in `vrMEr/keymap.c` LAYER_MOUSE definition
- [x] T007 [P] [US1] Map cursor down key (KC_MS_D) to right hand middle finger, row 3 in `vrMEr/keymap.c` LAYER_MOUSE definition
- [x] T008 [P] [US1] Map cursor left key (KC_MS_L) to right hand index finger, row 3 in `vrMEr/keymap.c` LAYER_MOUSE definition
- [x] T009 [P] [US1] Map cursor right key (KC_MS_R) to right hand ring finger, row 3 in `vrMEr/keymap.c` LAYER_MOUSE definition
- [x] T010 [P] [US1] Map left click (KC_BTN1) to left hand middle finger home row (I position) in `vrMEr/keymap.c` LAYER_MOUSE definition
- [x] T011 [P] [US1] Map right click (KC_BTN2) to left hand ring finger home row (E position) in `vrMEr/keymap.c` LAYER_MOUSE definition
- [x] T012 [P] [US1] Map middle click (KC_BTN3) to left hand index finger home row (H position) in `vrMEr/keymap.c` LAYER_MOUSE definition
- [ ] T013 [US1] Build firmware via GitHub Actions workflow (`.github/workflows/fetch-and-build-layout.yml`)
- [ ] T014 [US1] Flash firmware to ZSA Voyager using Keymapp application
- [ ] T015 [US1] Execute quickstart.md tests: Step 1 (activate layer), Step 2 (move cursor all directions), Step 3 (left click), Step 4 (deactivate layer)
- [ ] T016 [US1] Execute quickstart.md Test 1 (cursor movement all directions with timing validation)
- [ ] T017 [US1] Execute quickstart.md Test 3 (mouse buttons: left, right, middle clicks)
- [ ] T018 [US1] Execute quickstart.md Test 7 (layer activation/deactivation/rapid switching)

**Checkpoint**: At this point, User Story 1 should be fully functional and testable independently

---

## Phase 4: User Story 2 - One-Handed Mouse Click Operation (Priority: P2)

**Goal**: Enable all mouse buttons accessible from left hand only for one-handed operation

**Independent Test**: Remove right hand from keyboard, activate layer with left hand, verify all three mouse buttons work, perform drag-and-drop with left hand only

### Implementation for User Story 2

- [ ] T019 [US2] Verify left-hand button positions (KC_BTN1/2/3) allow one-handed reach per data-model.md layout
- [ ] T020 [US2] Execute quickstart.md Test 4 (drag-and-drop: hold KC_BTN1, move cursor with KC_MS_*, release BTN1)
- [ ] T021 [US2] Execute quickstart.md Test 4 Alternative (text selection: hold BTN1, move cursor, release)
- [ ] T022 [US2] Validate one-handed operation: Remove right hand, verify all clicks work using only left hand

**Checkpoint**: At this point, User Stories 1 AND 2 should both work independently

---

## Phase 5: User Story 3 - Adjust Mouse Speed for Precision (Priority: P3)

**Goal**: Enable speed adjustment for precision work vs fast navigation

**Independent Test**: Activate layer, press ACL0 (precision), move cursor (slow), press ACL2 (fast), move cursor (fast), verify speed difference

### Implementation for User Story 3

- [x] T023 [P] [US3] Map precision mode (KC_ACL0) to left hand top row position 1 in `vrMEr/keymap.c` LAYER_MOUSE definition
- [x] T024 [P] [US3] Map normal mode (KC_ACL1) to left hand top row position 2 in `vrMEr/keymap.c` LAYER_MOUSE definition
- [x] T025 [P] [US3] Map fast mode (KC_ACL2) to left hand top row position 3 in `vrMEr/keymap.c` LAYER_MOUSE definition
- [ ] T026 [US3] Build and flash firmware with speed controls
- [ ] T027 [US3] Execute quickstart.md Test 6 (speed control: measure cursor distance in ACL0 vs ACL2 mode)
- [ ] T028 [US3] Validate speed persistence: Set ACL0, deactivate layer, reactivate, verify speed still precision

**Checkpoint**: User Stories 1, 2, AND 3 should all work independently

---

## Phase 6: User Story 4 - Scroll Content Without Mouse Wheel (Priority: P3)

**Goal**: Enable vertical and horizontal scrolling via keyboard keys

**Independent Test**: Open long document, activate layer, scroll up/down/left/right, verify content scrolls

### Implementation for User Story 4

- [x] T029 [P] [US4] Map scroll up (KC_WH_U) to right hand position near cursor movement in `vrMEr/keymap.c` LAYER_MOUSE definition
- [x] T030 [P] [US4] Map scroll down (KC_WH_D) to right hand position near cursor movement in `vrMEr/keymap.c` LAYER_MOUSE definition
- [x] T031 [P] [US4] Map scroll left (KC_WH_L) to right hand secondary position in `vrMEr/keymap.c` LAYER_MOUSE definition
- [x] T032 [P] [US4] Map scroll right (KC_WH_R) to right hand secondary position in `vrMEr/keymap.c` LAYER_MOUSE definition
- [ ] T033 [US4] Build and flash firmware with scroll wheel controls
- [ ] T034 [US4] Execute quickstart.md Test 5a (vertical scroll: up/down in long document)
- [ ] T035 [US4] Execute quickstart.md Test 5b (horizontal scroll: left/right in wide spreadsheet)

**Checkpoint**: All user stories should now be independently functional

---

## Phase 7: Polish & Cross-Cutting Concerns

**Purpose**: Improvements that affect multiple user stories

- [x] T036 [P] Update `vrMEr/LAYER_VISUALIZATION.md` with LAYER_MOUSE diagram showing all key positions
- [ ] T037 [P] Execute quickstart.md Test 2 (diagonal movement: all 4 combinations with 45° angle validation)
- [ ] T038 [P] Execute quickstart.md Test 8 (OS compatibility: macOS and Windows testing)
- [ ] T039 [P] Execute quickstart.md Test 9 (edge cases: opposite directions, button held during exit, multiple buttons)
- [ ] T040 Execute quickstart.md Test 10 (firmware size: verify <230KB constitutional requirement)
- [ ] T041 Execute quickstart.md Performance Checklist (latency, usability, all items)
- [ ] T042 Execute all quickstart.md Quick Validation steps (full 5-minute validation)
- [ ] T043 Update `specs/003-mouse-layer/contracts/mouse-layer.md` with actual key positions and performance measurements
- [ ] T044 Final validation: All 8 success criteria from spec.md (SC-001 through SC-008)

---

## Dependencies & Execution Order

### Phase Dependencies

- **Setup (Phase 1)**: No dependencies - can start immediately
- **Foundational (Phase 2)**: Depends on Setup completion - BLOCKS all user stories
- **User Stories (Phase 3-6)**: All depend on Foundational phase completion
  - User stories can then proceed in parallel (if staffed)
  - Or sequentially in priority order (P1 → P2 → P3 → P3)
- **Polish (Phase 7)**: Depends on all desired user stories being complete

### User Story Dependencies

- **User Story 1 (P1)**: Can start after Foundational (Phase 2) - No dependencies on other stories
- **User Story 2 (P2)**: Can start after User Story 1 (needs basic mouse control working) - Tests one-handed operation of US1 features
- **User Story 3 (P3)**: Can start after User Story 1 (needs cursor movement working to test speed) - Independent feature, can run parallel to US2
- **User Story 4 (P3)**: Can start after Foundational (Phase 2) - Independent feature, can run parallel to US2/US3

### Within Each User Story

- **User Story 1**: All key mapping tasks (T006-T012) can run in parallel, then build/flash/test sequentially
- **User Story 2**: All validation tasks build on US1 completion
- **User Story 3**: All speed key mapping tasks (T023-T025) can run in parallel, then build/flash/test sequentially
- **User Story 4**: All scroll key mapping tasks (T029-T032) can run in parallel, then build/flash/test sequentially

### Parallel Opportunities

- All Setup tasks marked [P] can run in parallel (T002, T003)
- All US1 key mapping tasks (T006-T012) can run in parallel
- All US3 speed keys (T023-T025) can run in parallel
- All US4 scroll keys (T029-T032) can run in parallel
- All Polish documentation tasks (T036-T039) can run in parallel

---

## Parallel Example: User Story 1

```bash
# After Foundational phase complete (T001-T005)
# The following tasks can run simultaneously:

# Developer 1: Cursor movement keys
git checkout -b feature/us1-cursor-movement
# Edit vrMEr/keymap.c: Add KC_MS_U/D/L/R (T006-T009)

# Developer 2: Mouse button keys (in parallel)
git checkout -b feature/us1-mouse-buttons
# Edit vrMEr/keymap.c: Add KC_BTN1/2/3 (T010-T012)

# After both branches merged:
# Single developer continues:
# Build firmware (T013)
# Flash firmware (T014)
# Run tests (T015-T018)
```

---

## Parallel Example: User Story 3 and 4

```bash
# After User Story 1 complete
# US3 and US4 can proceed in parallel:

# Developer 1: Speed controls
git checkout -b feature/us3-speed-control
# Edit vrMEr/keymap.c: Add KC_ACL0/1/2 (T023-T025)
# Build, flash, test (T026-T028)

# Developer 2: Scroll controls (in parallel)
git checkout -b feature/us4-scroll-wheel
# Edit vrMEr/keymap.c: Add KC_WH_U/D/L/R (T029-T032)
# Build, flash, test (T033-T035)
```

---

## MVP Scope

**Minimum Viable Product**: User Story 1 only (P1)

If time/resources are limited, implement only Phase 1 (Setup), Phase 2 (Foundational), and Phase 3 (User Story 1). This delivers:
- ✅ Basic cursor movement (all 4 directions + diagonal)
- ✅ All three mouse button clicks (left, right, middle)
- ✅ Layer activation/deactivation
- ✅ One-handed operation (buttons on left, movement on right)
- ❌ No speed adjustment (uses default ACL2 fast mode)
- ❌ No scroll wheel emulation

This MVP satisfies the core value proposition: "I can navigate my computer and perform mouse operations using only my keyboard."

**Enhanced MVP**: User Story 1 + User Story 2 (P1 + P2)

Adds explicit one-handed operation validation and drag-and-drop testing.

**Full Feature**: All User Stories (P1 + P2 + P3 + P3)

Includes speed controls and scroll wheel for complete mouse replacement.

---

## Task Summary

- **Total Tasks**: 44
- **Setup Tasks**: 3 (T001-T003)
- **Foundational Tasks**: 2 (T004-T005)
- **User Story 1 Tasks**: 13 (T006-T018) - P1 Priority
- **User Story 2 Tasks**: 4 (T019-T022) - P2 Priority
- **User Story 3 Tasks**: 6 (T023-T028) - P3 Priority
- **User Story 4 Tasks**: 7 (T029-T035) - P3 Priority
- **Polish Tasks**: 9 (T036-T044)
- **Parallelizable Tasks**: 16 (marked with [P])

---

## Success Metrics (from spec.md)

Upon completion of all tasks:

- **SC-001**: ✅ User can activate mouse layer and move cursor to any screen position using only keyboard keys
- **SC-002**: ✅ User can perform all three mouse clicks (left, middle, right) using only left-hand keys without repositioning right hand
- **SC-003**: ✅ User can complete a typical drag-and-drop operation using only keyboard
- **SC-004**: ✅ Mouse cursor movement responds to directional input within 50ms of key press
- **SC-005**: ✅ Diagonal movement produces smooth 45-degree cursor travel
- **SC-006**: ✅ Mouse layer activation and deactivation completes in a single key press
- **SC-007**: ✅ User can scroll through a 1000-line document using keyboard scroll keys
- **SC-008**: ✅ Firmware size remains under 230KB constitutional target

---

## Next Steps

1. **Immediate**: Execute Phase 1 (Setup) - T001-T003
2. **Next**: Execute Phase 2 (Foundational) - T004-T005
3. **Then**: Begin Phase 3 (User Story 1) - T006-T018
4. **Optional**: Continue with Phase 4-6 for additional features
5. **Final**: Execute Phase 7 (Polish) for validation and documentation

**Estimated Effort**:
- MVP (US1 only): 2-3 hours (setup, foundational, user story 1, basic testing)
- Enhanced MVP (US1+US2): 3-4 hours (adds one-handed validation)
- Full Feature (all stories): 5-6 hours (adds speed controls, scroll wheel, comprehensive testing)
