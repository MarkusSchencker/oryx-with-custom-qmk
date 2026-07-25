# Reusable Visualization Method for vrMEr Layout Changes

This document describes a repeatable method to regenerate and verify the layout visualizations after any keymap change.

Scope:
- primary keymap source: [vrMEr/custom_layout.inc](vrMEr/custom_layout.inc)
- textual view: [vrMEr/layout-visualization.md](vrMEr/layout-visualization.md)
- interactive view: [vrMEr/layout-visualization.html](vrMEr/layout-visualization.html)

## 1. Source of Truth

Use this order of precedence:
1. Key positions and keycodes from [vrMEr/custom_layout.inc](vrMEr/custom_layout.inc).
2. Physical geometry from Voyager keyboard metadata (the same geometry currently embedded in HTML as `SLOT_COORDS`).
3. Key aliases/macros from [vrMEr/i18n.h](vrMEr/i18n.h).

Rule: visualizations must follow code, not the other way around.

## 2. Physical Slot Model

All layers use the same 52 slots:
- left hand: `k00..k25`
- right hand: `k26..k51`

The slot coordinates are already captured in [vrMEr/layout-visualization.html](vrMEr/layout-visualization.html) under `SLOT_COORDS`.
Do not change slot coordinates unless the physical keyboard model changes.

## 3. Extract Layer Data from custom_layout.inc

For each layer block
- `LAYER_MAC_BASE`
- `LAYER_WIN_BASE`
- `LAYER_SYMBOLS`
- `LAYER_FUNCTION`
- `LAYER_NUMBERS`
- `LAYER_CONFIG`
- `LAYER_MOUSE`

read the `LAYOUT_voyager(` argument list in order and map each argument to the slot sequence below.

Slot sequence for `LAYOUT_voyager` used here:
1. Row group 1 (12 keys): `k00..k05`, `k26..k31`
2. Row group 2 (12 keys): `k06..k11`, `k32..k37`
3. Row group 3 (12 keys): `k12..k17`, `k38..k43`
4. Row group 4 (12 keys): `k18..k23`, `k44..k49`
5. Thumbs (4 keys): `k24`, `k25`, `k50`, `k51`

## 4. Update Markdown Visualization

Update [vrMEr/layout-visualization.md](vrMEr/layout-visualization.md):
1. Keep the remap assumptions section in sync with current code.
2. For each layer, rewrite all row lines from the extracted mapping.
3. Keep removed keys shown as `KC_NO`.
4. Keep transparent keys shown as `TRNS`.

Recommended check:
- Count each layer to ensure 52 mapped positions.

## 5. Update HTML Visualization

Update [vrMEr/layout-visualization.html](vrMEr/layout-visualization.html):
1. Keep `SLOT_COORDS` unchanged unless geometry changes.
2. Update `KEYMAP` entries for layers `L0..L6` from extracted mapping.
3. Keep labels concise and readable (`OSL(SYM)`, `LT(NUM,SPC)`, etc.).
4. Preserve classification behavior (`KC_NO`, `TRNS`, layer/mod/nav tinting).

Recommended check:
- Each layer object should contain values for all visible slots used by renderer.

## 6. Verification Checklist

After editing:
1. Confirm no syntax errors in edited files.
2. Open [vrMEr/layout-visualization.html](vrMEr/layout-visualization.html) in a browser.
3. Click through all layers and verify:
   - key placement is physically correct,
   - `KC_NO` and `TRNS` toggles behave correctly,
   - thumb cluster matches intended design.
4. Cross-check at least one full layer against [vrMEr/custom_layout.inc](vrMEr/custom_layout.inc) manually.

## 7. Commit Workflow

Use one commit for synchronized visualization updates:
1. Stage changed files.
2. Commit with a message describing both keymap and visualization impact.

Example pattern:
- "Update vrMEr keymap and synchronize markdown/html visualizations"

## 8. Optional Future Improvement

To reduce manual sync work, add a small generator script that:
1. Parses `LAYOUT_voyager(...)` blocks from [vrMEr/custom_layout.inc](vrMEr/custom_layout.inc).
2. Produces JSON for layer-slot mappings.
3. Regenerates both [vrMEr/layout-visualization.md](vrMEr/layout-visualization.md) and [vrMEr/layout-visualization.html](vrMEr/layout-visualization.html) from templates.

Until that exists, this method is the canonical process.
