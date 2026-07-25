# vrMEr Layout Visualization (Remapped Physical Usage)

This reflects the remap implemented in [vrMEr/custom_layout.inc](vrMEr/custom_layout.inc).

## Remap Rules Applied

- Columns `1,2,11,12`: unchanged.
- Columns `3..10`: rows `2..4` shifted up by one row.
- Disabled (dead) keys: row 4 columns `3,4,9,10` and outer thumbs.
- Old 4-thumb functions moved to row 4 columns `5,6,7,8` in the same order.
- Active thumb cluster now has 6 ergonomic positions:
  - row 4 columns `5,6,7,8`
  - row 5 inner thumbs

`KC_NO` = physically removed / unusable key.

## Physical Model (12 columns)

```text
Columns:   1    2    3    4    5    6    7    8    9   10   11   12
Rows 1-4: full key rows
Row 5:     only thumb area (outer thumbs disabled)
```

## L0 MAC_BASE

```text
R1: Cmd+-   Cmd+0   U        REPEAT   LEAD     Q        G        C        L        M        TRNS     TO(CONFIG)
R2: TRNS    P       MT(A,I)  MT(G,E)  MT(S,A)  O        D        MT(S,T)  MT(G,R)  MT(A,N)  F        TRNS
R3: CW      MT(C,H) DE_Y     .        DE_DQOT  X        J        V        W        B        MT(C,S)  TRNS
R4: TRNS    K       KC_NO    KC_NO    OSL(SYM) OSL(MOU) OSL(FN)  LT(NUM,SPC) KC_NO KC_NO    DE_Z     TRNS
R5: KC_NO   BSPC                                      ENTER      KC_NO
```

## L1 WIN_BASE

```text
R1: Ctrl+-  Ctrl+0  U        REPEAT   LEAD     Q        G        C        L        M        TRNS     TO(CONFIG)
R2: TRNS    P       MT(A,I)  MT(C,E)  MT(S,A)  O        D        MT(S,T)  MT(C,R)  MT(A,N)  F        TRNS
R3: CW      MT(G,H) DE_Y     .        DE_DQOT  X        J        V        W        B        MT(G,S)  TRNS
R4: TRNS    K       KC_NO    KC_NO    OSL(SYM) OSL(MOU) OSL(FN)  LT(NUM,SPC) KC_NO KC_NO    DE_Z     TRNS
R5: KC_NO   BSPC                                      ENTER      KC_NO
```

## L2 SYMBOLS

```text
R1: TRNS    TRNS    DE_AMPR  DE_LBRC  DE_RBRC  DE_CIRC  DE_EXLM  DE_LABK  DE_RABK  DE_EQL   TRNS     TRNS
R2: TRNS    DE_SECT DE_SLSH  DE_LCBR  DE_RCBR  DE_ASTR  DE_QUES  DE_LPRN  DE_RPRN  DE_MINS  DE_TILD  TRNS
R3: TRNS    DE_AT   DE_BSLS  DE_PIPE  DE_DQOT  DE_GRV   DE_PLUS  DE_PERC  DE_DLR   DE_HASH  DE_COLN  TRNS
R4: TRNS    DE_UNDS KC_NO    KC_NO    TRNS     TRNS     BSPC     DEL      KC_NO    KC_NO    DE_SCLN  TRNS
R5: KC_NO   TRNS                                      BSPC       KC_NO
```

## L3 FUNCTION

```text
R1: TRNS    F1      DE_UE    TRNS     TRNS     TRNS     OS_PREV  OS_PGUP  TRNS     OS_NEXT  F10      TRNS
R2: F12     TAB     DE_SS    DE_EURO  MT(S,AE) DE_OE    LEFT     DOWN     UP       RIGHT    TRNS     TRNS
R3: F11     ESC     TRNS     TRNS     TRNS     TRNS     TRNS     OS_PGDN  OS_HOME  OS_END   TRNS     TRNS
R4: TRNS    ENTER   KC_NO    KC_NO    TRNS     OSM(RS)  TRNS     TRNS     KC_NO    KC_NO    TRNS     TRNS
R5: KC_NO   OSM(RS)                                   TRNS       KC_NO
```

## L4 NUMBERS

```text
R1: TRNS    TRNS    7        8        9        DE_ASTR  TRNS     TRNS     TRNS     TRNS     TRNS     TRNS
R2: TRNS    DE_MINS 1        2        3        0        OS_UNDO  OS_COPY  OS_PASTE OS_CUT   TRNS     TRNS
R3: TRNS    DE_COLN 4        5        6        DE_SLSH  TRNS     TRNS     TRNS     TRNS     TRNS     APP
R4: TRNS    DE_PLUS KC_NO    KC_NO    ,        .        TRNS     TRNS     KC_NO    KC_NO    TRNS     TRNS
R5: KC_NO   .                                          TRNS       KC_NO
```

## L5 CONFIG

```text
R1: RGB_TOG LYR_CLR RGB_S-   RGB_S+   RGB_SPD- RGB_SPD+ PGUP     HOME     UP       END      BOOT     TRNS
R2: TRNS    TRNS    MEDIA>>  MEDIASTOP RGB_H-  RGB_H+   PGDN     LEFT     DOWN     RIGHT    TRNS     TRNS
R3: TRNS    MEDIA<< TRNS     HSV_0    HSV_74   HSV_169  TRNS     C-S-TAB  C-TAB    TRNS     TRNS     TRNS
R4: TRNS    TRNS    KC_NO    KC_NO    TRNS     TRNS     TRNS     TRNS     KC_NO    KC_NO    TRNS     TRNS
R5: KC_NO   TRNS                                      TRNS       KC_NO
```

## L6 MOUSE

```text
R1: TRNS    TRNS    OS_CUT   OS_PASTE OS_COPY  TRNS     TRNS     TRNS     MS_UP    WH_UP    TRNS     TRNS
R2: TRNS    TAB     BTN3     BTN2     BTN1     TRNS     TRNS     MS_LEFT  MS_DOWN  MS_RIGHT TRNS     TRNS
R3: TRNS    LSHIFT  ACL2     ACL0     ACL1     TRNS     TRNS     WH_LEFT  WH_RIGHT WH_DOWN  TRNS     TRNS
R4: TRNS    LCTRL   KC_NO    KC_NO    TRNS     TRNS     TRNS     TRNS     KC_NO    KC_NO    TRNS     TRNS
R5: KC_NO   TRNS                                      TRNS       KC_NO
```

## Notes

- The remap intentionally removes several outer/reach-heavy positions.
- Base layers now place layer switches in row 4 (`C5..C8`) as the primary thumb arc.
- Inner thumbs are repurposed as `BSPC` and `ENTER` on base layers.
