# Repository Overview

## What this repository is for

This repository combines:
- Oryx layout editing convenience
- Custom QMK code features
- Automated firmware builds via GitHub Actions

In practical terms, the workflow pulls your latest Oryx layout, merges it with your custom keymap code, and builds firmware artifacts you can flash.

## Environment and context provided

- Operating system used in this workspace: macOS
- Workspace root:
  - /Users/mschenc/data/repos/MarkusSchencker/oryx-with-custom-qmk
- User context provided during setup:
  - Generic QMK code is expected in qmk_firmware
  - Active custom layout work is in vrMEr

Current local state note:
- The qmk_firmware folder exists but is currently empty in this checkout.

## Repository structure

Top-level items currently present:
- .github (workflow automation)
- Dockerfile
- README.md
- JRaem (one generated/customized layout folder)
- vrMEr (active generated/customized layout folder)
- qmk_firmware (intended generic QMK location)
- build.log

Layout folders:

JRaem contains:
- config.h
- i18n.h
- keymap.c
- keymap.json
- rules.mk

vrMEr contains:
- config.h
- i18n.h
- keymap.c
- keymap.json
- custom_layout.inc
- rules.mk
- layout-visualization.md
- layout-visualization.html
- visualization-method.md
- session-summary-2026-07-25.md

## How the repository workflow works

Based on the repository README:
1. Run the GitHub Action called Fetch and build layout.
2. The action fetches the latest Oryx layout updates.
3. It merges those updates with your custom QMK source changes.
4. It builds firmware and publishes artifacts.
5. You download artifacts and flash them with Keymapp.

## How to use this repository

1. Fork the repository and include full branch history.
2. Open GitHub Actions and run the layout fetch/build workflow.
3. Provide layout ID and keyboard type if needed.
4. After layout folder generation, edit your layout source files:
   - config.h
   - keymap.c
   - rules.mk
   - plus any project-specific files such as custom_layout.inc
5. Commit and push your changes.
6. Re-run the workflow whenever you want a fresh merged build.
7. Download artifact firmware and flash it.

## vrMEr-specific documentation added in this workspace

- layout-visualization.md
  - Text visualization of the current keymap.
- layout-visualization.html
  - Interactive visualization with real Voyager slot geometry and layer switching.
- visualization-method.md
  - Reusable method for keeping visualizations in sync with keymap changes.
- session-summary-2026-07-25.md
  - Summary of decisions and changes from the major layout redesign session.

## Recommended ongoing practice

For every keymap change:
1. Update the keymap source first.
2. Sync both visualization files.
3. Validate layer mappings visually.
4. Commit code and visualization updates together.
