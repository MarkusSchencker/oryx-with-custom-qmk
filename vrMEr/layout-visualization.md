# vrMEr Keyboard Layout Visualization (Voyager)

Source: `vrMEr/custom_layout.inc` (rendered from the actual QMK keymap)

## Legend

- `TRNS`: transparent (falls through to lower/default layer)
- `OSL(X)`: one-shot layer
- `LT(X, K)`: tap `K`, hold for layer `X`
- `MT(MOD, K)`: tap `K`, hold `MOD`
- `OS_*`: OS-aware macro (Cmd on macOS, Ctrl on Windows where applicable)
- `DE_*`: German layout symbol mapping from `vrMEr/i18n.h`

## Physical Shape (Voyager)

Each layer uses 4 rows x 12 keys (6 left + 6 right), plus 4 thumb keys:

```text
L1 L2 L3 L4 L5 L6            R1 R2 R3 R4 R5 R6
L1 L2 L3 L4 L5 L6            R1 R2 R3 R4 R5 R6
L1 L2 L3 L4 L5 L6            R1 R2 R3 R4 R5 R6
L1 L2 L3 L4 L5 L6            R1 R2 R3 R4 R5 R6
         LT1 LT2                         RT1 RT2
```

---

## Layer 0: MAC_BASE

```text
Cmd+-   Cmd+0   Cmd++   LGUI    TRNS    TRNS      || TRNS    Shift+Tab TRNS   Tab     TRNS    TO(CONFIG)
TRNS    P       U       REPEAT  LEAD    Q         || G       C         L      M       F       TRNS
CW_TOGG HRM(H/Ctrl) HRM(I/Alt) HRM(E/Gui) HRM(A/Shift) O  || D  HRM(T/Shift) HRM(R/Gui) HRM(N/Alt) HRM(S/Ctrl) TRNS
TRNS    K       DE_Y    .       DE_DQOT X         || J       V         W      B       DE_Z    TRNS
                    OSL(SYMBOLS) OSL(MOUSE)       || OSL(FUNCTION) LT(NUMBERS, Space)
```

---

## Layer 1: WIN_BASE

```text
Ctrl+-  Ctrl+0  Ctrl++  LALT    TRNS    TRNS      || TRNS    Shift+Tab TRNS   Tab     TRNS    TO(CONFIG)
TRNS    P       U       REPEAT  LEAD    Q         || G       C         L      M       F       TRNS
CW_TOGG HRM(H/Gui) HRM(I/Alt) HRM(E/Ctrl) HRM(A/Shift) O || D HRM(T/Shift) HRM(R/Ctrl) HRM(N/Alt) HRM(S/Gui) TRNS
TRNS    K       DE_Y    .       DE_DQOT X         || J       V         W      B       DE_Z    TRNS
                    OSL(SYMBOLS) OSL(MOUSE)       || OSL(FUNCTION) LT(NUMBERS, Space)
```

---

## Layer 2: SYMBOLS

```text
TRNS    TRNS    TRNS    TRNS    TRNS    TRNS      || TRNS    TRNS      TRNS   TRNS    TRNS    TRNS
TRNS    DE_SECT DE_AMPR DE_LBRC DE_RBRC DE_CIRC   || DE_EXLM DE_LABK   DE_RABK DE_EQL DE_TILD TRNS
TRNS    DE_AT   DE_SLSH DE_LCBR DE_RCBR DE_ASTR   || DE_QUES DE_LPRN   DE_RPRN DE_MINS DE_COLN TRNS
TRNS    DE_UNDS DE_BSLS DE_PIPE DE_DQOT DE_GRV    || DE_PLUS DE_PERC   DE_DLR DE_HASH DE_SCLN TRNS
                    TRNS       TRNS                || BSPC     DEL
```

---

## Layer 3: FUNCTION

```text
TRNS    F1      F2      F3      F4      F5        || F6      F7        F8     F9      F10     TRNS
F12     Tab     DE_UE   TRNS    TRNS    TRNS      || OS_PREVWORD OS_PGUP TRNS OS_NEXTWORD TRNS TRNS
F11     Esc     DE_SS   DE_EURO MT(Shift,DE_AE) DE_OE || Left Down Up Right TRNS TRNS
TRNS    Enter   TRNS    TRNS    TRNS    TRNS      || TRNS    OS_PGDN   OS_HOME OS_END TRNS   TRNS
                    TRNS      OSM(RShift)         || TRNS    TRNS
```

---

## Layer 4: NUMBERS

```text
TRNS    TRNS    TRNS    TRNS    TRNS    TRNS      || TRNS    TRNS      PrintScr TRNS TRNS TRNS
TRNS    DE_MINS 7       8       9       DE_ASTR   || TRNS    TRNS      TRNS    TRNS TRNS TRNS
TRNS    DE_COLN 1       2       3       0         || OS_UNDO OS_COPY   OS_PASTE OS_CUT TRNS APP
TRNS    DE_PLUS 4       5       6       DE_SLSH   || TRNS    TRNS      TRNS    TRNS TRNS TRNS
                    ,         .                   || TRNS    TRNS
```

---

## Layer 5: CONFIG

```text
RGB_TOG TOGGLE_LAYER_COLOR RGB_MODE_FWD RGB_SLD RGB_VAD RGB_VAI || SW_WIN TRNS SW_MAC TRNS BOOT TRNS
TRNS    TRNS    RGB_SAD RGB_SAI RGB_SPD RGB_SPI || PgUp    Home      Up     End   TRNS TRNS
TRNS    MediaPrev MediaNext MediaStop RGB_HUD RGB_HUI || PgDn Left Down Right TRNS TRNS
TRNS    TRNS    TRNS    HSV(0) HSV(74) HSV(169) || TRNS Ctrl+Shift+Tab Ctrl+Tab TRNS TRNS TRNS
                    TRNS      TRNS               || TRNS    TRNS
```

---

## Layer 6: MOUSE

```text
TRNS    TRNS    TRNS    TRNS    TRNS    TRNS      || TRNS    TRNS      TRNS   TRNS   TRNS   TRNS
TRNS    Tab     OS_CUT  OS_PASTE OS_COPY TRNS     || TRNS    TRNS      MS_UP  WH_UP  TRNS   TRNS
TRNS    LShift  BTN3    BTN2    BTN1    TRNS      || TRNS    MS_LEFT   MS_DOWN MS_RIGHT TRNS TRNS
TRNS    LCtrl   ACL2    ACL0    ACL1    TRNS      || TRNS    WH_LEFT   WH_RIGHT WH_DOWN TRNS TRNS
                    TRNS      TRNS                || TRNS    TRNS
```

---

## Notes

- Default base behavior is dual-OS: `SW_MAC` and `SW_WIN` on `CONFIG` set default layer and move to that base.
- Home row mods have per-key tapping term and hold behavior tuning in `custom_layout.inc`.
- Combos on the mouse one-shot key produce comma/double-quote variants.
