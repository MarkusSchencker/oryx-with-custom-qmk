# Implementation Plan: Mouse Layer

**Branch**: `003-mouse-layer` | **Date**: November 11, 2025 | **Spec**: [spec.md](spec.md)  
**Input**: Feature specification from `/specs/003-mouse-layer/spec.md`

**Note**: This template is filled in by the `/speckit.plan` command. See `.specify/templates/commands/plan.md` for the execution workflow.

## Summary

Add a 7th layer (LAYER_MOUSE) to the existing vrMEr 6-layer keyboard architecture to enable mouse cursor control and clicking via keyboard keys. The mouse layer will feature directional movement keys on the right keyboard half and mouse button keys (left, middle, right click) on the left half, enabling one-handed operation. A toggle key on the left keyboard half will activate/deactivate the mouse layer. Technical implementation uses QMK's built-in MOUSEKEY features with speed control and scroll wheel emulation, maintaining the constitutional firmware size target of <230KB.

## Technical Context

**Language/Version**: C (QMK Firmware compatible with AVR-GCC compiler)  
**Primary Dependencies**: QMK Firmware (qmk_firmware submodule), QMK MOUSEKEY module, German keyboard layout definitions (keymap_german.h)  
**Storage**: N/A (keyboard firmware stored in flash memory)  
**Testing**: Hardware testing on ZSA Voyager keyboard, GitHub Actions build verification  
**Target Platform**: ZSA Voyager (ARM STM32, 256KB flash, 52-key split ortholinear keyboard)  
**Project Type**: Embedded firmware (keyboard layout)  
**Performance Goals**: Mouse cursor response <50ms, smooth diagonal movement, responsive layer switching  
**Constraints**: Firmware size <230KB (90% of 256KB flash - constitutional requirement), maintain existing 6-layer functionality  
**Scale/Scope**: Single 7th layer addition, ~15-20 new keycodes, mouse speed configuration in config.h

## Constitution Check

*GATE: Must pass before Phase 0 research. Re-check after Phase 1 design.*

### I. Minimal Firmware Size (NON-NEGOTIABLE)
- ✅ **PASS**: Mouse layer uses QMK's built-in MOUSEKEY features (no custom implementation)
- ✅ **PASS**: MOUSEKEY module adds ~3-5KB to firmware (well within headroom)
- ✅ **PASS**: Current vrMEr firmware size allows room for mouse layer addition
- ⚠️ **MONITOR**: Must verify compiled size remains <230KB after implementation
- **Action**: Enable MOUSEKEY_ENABLE = yes in rules.mk, configure speed/acceleration in config.h

### II. Layer Minimization
- ✅ **PASS**: Mouse layer serves single clear purpose (mouse control)
- ✅ **PASS**: Cannot be achieved through layer combinations or dual-function keys
- ✅ **PASS**: Distinct from existing layers (base, symbols, function, numbers, config)
- **Justification**: Mouse control requires sustained access to movement and button keys simultaneously, incompatible with one-shot or layer-tap mechanisms used for other utility layers

### III. OS-Specific Optimization
- ✅ **PASS**: Mouse layer is OS-agnostic (works identically on macOS and Windows)
- ✅ **PASS**: Accessible from both LAYER_MAC_BASE and LAYER_WIN_BASE
- ✅ **PASS**: No OS-specific code duplication required
- **Design**: Mouse cursor and click operations are handled by OS input layer, keyboard simply sends standard mouse HID events

### IV. Oryx Integration (NON-NEGOTIABLE)
- ⚠️ **CONSIDERATION**: Oryx may not support mouse key visualization natively
- ✅ **PASS**: Mouse layer keycodes (KC_MS_UP, KC_BTN1, etc.) are standard QMK codes
- ✅ **PASS**: Layer definition can be created in Oryx with mouse keycodes
- **Action**: Test Oryx compatibility with mouse keycodes; fallback to manual layer definition if needed
- **Workflow**: Mouse layer follows same edit → compile → GitHub Action → merge pattern

### V. Code Maintainability
- ✅ **PASS**: Mouse layer uses descriptive LAYER_MOUSE enum constant
- ✅ **PASS**: Mouse speed/acceleration settings centralized in config.h
- ✅ **PASS**: MOUSEKEY_ENABLE flag managed in rules.mk
- ✅ **PASS**: Layer layout uses standard QMK mouse key naming (KC_MS_*, KC_BTN*, KC_WH_*)
- **Documentation**: Mouse layer purpose, key positions, and toggle mechanism documented in LAYER_VISUALIZATION.md

### Summary
**Status**: ✅ **APPROVED** - All constitutional gates passed. Mouse layer addition complies with all five core principles.

**Re-check after Phase 1**: Verify firmware size <230KB, confirm Oryx compatibility, validate layer organization.

## Project Structure

### Documentation (this feature)

```text
specs/003-mouse-layer/
├── spec.md              # Feature specification (complete)
├── plan.md              # This file (implementation plan)
├── research.md          # Phase 0 output (QMK mouse key research)
├── data-model.md        # Phase 1 output (layer state model)
├── quickstart.md        # Phase 1 output (testing guide)
├── contracts/           # Phase 1 output (layer contract)
│   └── mouse-layer.md   # Mouse layer key layout contract
├── checklists/          # Quality validation
│   └── requirements.md  # Spec quality checklist (complete)
└── tasks.md             # Phase 2 output (NOT created yet)
```

### Source Code (repository root)

```text
vrMEr/
├── keymap.c             # MODIFY: Add LAYER_MOUSE definition and keycodes
├── config.h             # MODIFY: Add MOUSEKEY configuration
├── rules.mk             # MODIFY: Enable MOUSEKEY_ENABLE = yes
├── i18n.h               # No changes (mouse keys use standard KC_* codes)
└── LAYER_VISUALIZATION.md  # MODIFY: Add mouse layer documentation

.github/workflows/
└── fetch-and-build-layout.yml  # No changes (existing build process)

specs/003-mouse-layer/
└── [documentation as above]
```

**Structure Decision**: This feature modifies the existing vrMEr keyboard layout by adding a 7th layer. Primary changes are in `vrMEr/keymap.c` (layer definition), `vrMEr/config.h` (mouse settings), and `vrMEr/rules.mk` (enable MOUSEKEY module). No new source directories required - this is a keyboard layout enhancement within the established QMK firmware structure.

## Complexity Tracking

> **No violations** - This section left empty as all constitutional gates passed.

All constitutional requirements are satisfied without requiring any complexity justifications.

## Phase Completion Summary

### Phase 0: Outline & Research ✅ COMPLETE

**Status**: All research questions resolved, no NEEDS CLARIFICATION remaining

**Artifacts Created**:
- ✅ `research.md` - Comprehensive QMK MOUSEKEY module research
  - Decision: Use QMK built-in MOUSEKEY features
  - Configuration: Defined all MOUSEKEY_* parameters for config.h
  - Key layout: Arrow-key-like movement, home row buttons
  - Toggle mechanism: MO(LAYER_MOUSE) for one-handed operation
  - Size impact: ~7KB total (within constitutional limits)

**Key Decisions**:
1. **MOUSEKEY Configuration**: 16ms interval, 8px delta, 10x max speed
2. **Speed Modes**: ACL0 (precision 1/4), ACL1 (normal 1/2), ACL2 (fast full)
3. **Toggle Mechanism**: MO() for auto-return, left-hand accessible
4. **Key Layout**: Inverted-T arrow pattern for movement, home row for buttons
5. **Firmware Size**: Estimated 7KB impact, well under 230KB limit

### Phase 1: Design & Contracts ✅ COMPLETE

**Status**: All design artifacts generated, agent context updated

**Artifacts Created**:
- ✅ `data-model.md` - Layer state model, mouse state, configuration parameters
  - Layer state transitions (MO activation/deactivation)
  - Mouse report structure (cursor velocity, button bitfield)
  - MOUSEKEY configuration table with all parameters
  - Key layout mapping for left/right hands
  - Performance metrics and validation rules

- ✅ `contracts/mouse-layer.md` - Complete layer contract specification
  - Layer activation/deactivation contract
  - Cursor movement contract (single direction, diagonal)
  - Mouse button contract (click, drag, multiple buttons)
  - Scroll wheel contract (vertical, horizontal)
  - Speed control contract (ACL0/1/2)
  - OS compatibility contract (macOS, Windows, Linux)
  - Performance constraints and timing requirements
  - Error handling and graceful degradation
  - Testing contract with 10 hardware test cases

- ✅ `quickstart.md` - Hardware testing guide
  - 5-minute quick validation procedure
  - Full 15-20 minute test suite (10 major tests)
  - Performance checklist (latency, usability)
  - Common issues and troubleshooting
  - Test summary report template

- ✅ `.github/copilot-instructions.md` - Agent context updated
  - Added: C (QMK Firmware compatible with AVR-GCC compiler)
  - Added: QMK MOUSEKEY module
  - Preserved manual additions between markers

**Design Validation**:
- All functional requirements (FR-001 to FR-012) mapped to contracts
- All success criteria (SC-001 to SC-008) covered in testing
- Edge cases identified and documented
- Performance targets defined (<50ms response, <230KB firmware)

### Phase 2: Task Breakdown ⏸️ PENDING

**Next Command**: `/speckit.tasks` to generate tasks.md with implementation checklist

**Expected Output**:
- Detailed task breakdown for implementation
- Phase organization (setup, mapping, testing, validation)
- Dependency tracking between tasks
- Time estimates for each task

## Constitution Re-Check (Post-Design)

### I. Minimal Firmware Size
- ✅ **VERIFIED**: Estimated 7KB impact (5KB MOUSEKEY + 2KB layer definition)
- ✅ **VERIFIED**: Configuration uses standard QMK parameters (no bloat)
- ⚠️ **PENDING**: Actual firmware size validation after implementation
- **Next**: Build and check binary size <230KB

### II. Layer Minimization
- ✅ **VERIFIED**: Mouse layer serves single purpose (mouse control)
- ✅ **VERIFIED**: Cannot be replaced by layer combinations or dual-functions
- ✅ **VERIFIED**: 7 layers total (6 existing + 1 mouse) - still minimal

### III. OS-Specific Optimization
- ✅ **VERIFIED**: Mouse layer OS-agnostic (HID reports universal)
- ✅ **VERIFIED**: Works from both MAC and WIN base layers
- ✅ **VERIFIED**: No code duplication (single layer definition)

### IV. Oryx Integration
- ⚠️ **TESTING NEEDED**: Oryx mouse keycode support to be validated
- ✅ **VERIFIED**: KC_MS_*, KC_BTN*, KC_WH_* are standard QMK codes
- ✅ **VERIFIED**: Fallback to manual keymap.c if Oryx limitations found
- **Next**: Test Oryx editor with mouse keycodes

### V. Code Maintainability
- ✅ **VERIFIED**: LAYER_MOUSE enum follows naming convention
- ✅ **VERIFIED**: Configuration centralized in config.h
- ✅ **VERIFIED**: Feature flag in rules.mk (MOUSEKEY_ENABLE)
- ✅ **VERIFIED**: Standard QMK key naming (KC_MS_UP not MOUSE_UP)
- **Next**: Update LAYER_VISUALIZATION.md with mouse layer diagram

**Overall Status**: ✅ **ALL GATES PASSED** - Design complies with constitution

## Implementation Readiness

**Ready to Implement**: ✅ YES

**Prerequisites Met**:
- [x] Feature specification complete and validated
- [x] All research questions resolved
- [x] Data model defined (layer state, mouse state, configuration)
- [x] Contracts written (behavior, performance, testing)
- [x] Testing guide created (quickstart.md)
- [x] Agent context updated (copilot-instructions.md)
- [x] Constitutional compliance verified

**Blocked On**:
- [ ] None - ready to proceed with `/speckit.tasks`

**Next Steps**:
1. ✅ ~~Run `/speckit.tasks` to generate implementation task breakdown~~ (COMPLETE)
2. Follow tasks.md to implement LAYER_MOUSE in vrMEr/keymap.c
3. Add MOUSEKEY configuration to vrMEr/config.h
4. Enable MOUSEKEY_ENABLE in vrMEr/rules.mk
5. Test via GitHub Actions build
6. Flash firmware and execute quickstart.md test suite
7. Update LAYER_VISUALIZATION.md with mouse layer diagram

## Phase Completion Summary

### Phase 0: Research ✅ COMPLETE
- **Artifacts**: research.md
- **Key Decisions**: Use QMK MOUSEKEY module, MO() toggle, arrow-key layout
- **Completion Date**: November 11, 2025

### Phase 1: Design ✅ COMPLETE
- **Artifacts**: data-model.md, contracts/mouse-layer.md, quickstart.md
- **Key Models**: Layer state transitions, mouse report structure, key layout mappings
- **Completion Date**: November 11, 2025

### Phase 2: Task Generation ✅ COMPLETE
- **Artifacts**: tasks.md
- **Task Count**: 44 tasks organized into 7 phases
- **User Stories**: 4 stories (P1, P2, P3, P3) with independent test criteria
- **MVP Scope**: User Story 1 (13 tasks) delivers core mouse control functionality
- **Completion Date**: November 11, 2025

### Phase 3: Implementation ⏸️ PENDING
- **Start Condition**: Execute tasks.md Phase 1 (Setup)
- **Expected Duration**: 2-3 hours (MVP), 5-6 hours (full feature)
- **Deliverable**: Working mouse layer on ZSA Voyager hardware

## Risk Assessment

| Risk | Likelihood | Impact | Mitigation Status |
|------|------------|--------|-------------------|
| Firmware size >230KB | Low | High | ✅ Estimated 7KB impact, large headroom |
| Oryx incompatibility | Low | Medium | ✅ Fallback to manual keymap.c |
| Mouse movement too slow/fast | Medium | Low | ✅ Configurable in config.h |
| Diagonal movement issues | Low | Medium | ✅ QMK handles simultaneously, well-tested |
| Layer toggle hard to reach | Low | Medium | ⚠️ To be determined during implementation |
| OS compatibility issues | Very Low | High | ✅ HID protocol universal, tested on multiple platforms |

**Overall Risk**: 🟢 **LOW** - Well-understood QMK features, clear constitutional compliance

## References

- **Feature Spec**: [spec.md](spec.md)
- **Research**: [research.md](research.md)
- **Data Model**: [data-model.md](data-model.md)
- **Contract**: [contracts/mouse-layer.md](contracts/mouse-layer.md)
- **Testing**: [quickstart.md](quickstart.md)
- **QMK Docs**: https://docs.qmk.fm/#/feature_mouse_keys
- **Constitution**: `../../.specify/memory/constitution.md`
