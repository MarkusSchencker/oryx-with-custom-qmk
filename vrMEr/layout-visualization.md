# vrMEr Layout Visualization

This reflects the current mapping in [vrMEr/custom_layout.inc](vrMEr/custom_layout.inc).

## Remap Rules Applied

- Columns 1, 2, 11, 12: top-row bindings are lowered by one row across all layers.
- Row 4 columns 3, 4, 9, 10 stay disabled (`KC_NO`) on all layers.
- `KC_NO` = physically removed / unusable key.

## Physical Model (12 columns)

```text
Columns:   1    2    3    4    5    6    7    8    9   10   11   12
Rows 1-4: full key rows
Row 5:     only thumb area (outer thumbs disabled)
```

## L0 MAC_BASE

```text
R1: TRNS    TRNS    U        REPEAT   LEAD     Q        G        C        L        M        TRNS     TRNS
R2: Cmd+-   P       MT(A,I)  MT(G,E)  MT(S,A)  O        D        MT(S,T)  MT(G,R)  MT(A,N)  F        TO(CONFIG)
R3: TRNS    MT(C,H) DE_Y     .        DE_DQOT  X        J        V        W        B        MT(C,S)  TRNS
R4: CW      K       KC_NO    KC_NO    OSL(SYM) OSL(MOV) OSL(FN)  LT(NUM,SPC) KC_NO KC_NO    DE_Z     TRNS
R5: KC_NO   BSPC                                      ENTER      KC_NO
```

## L1 WIN_BASE

```text
R1: TRNS    TRNS    U        REPEAT   LEAD     Q        G        C        L        M        TRNS     TRNS
R2: Ctrl+-  P       MT(A,I)  MT(C,E)  MT(S,A)  O        D        MT(S,T)  MT(C,R)  MT(A,N)  F        TO(CONFIG)
R3: TRNS    MT(G,H) DE_Y     .        DE_DQOT  X        J        V        W        B        MT(G,S)  TRNS
R4: CW      K       KC_NO    KC_NO    OSL(SYM) OSL(MOV) OSL(FN)  LT(NUM,SPC) KC_NO KC_NO    DE_Z     TRNS
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

## L3 MOVEMENT

```text
R1: TRNS    TRNS    TAB      OSL(MAC_SHORT) OSL(WIN_SHORT) TRNS  OS_PREV  OS_PGUP  TRNS     OS_NEXT  TRNS     TRNS
R2: TRNS    ESC     OSM(SFT) OSM(ALT) OSM(GUI) TRNS    TRNS     LEFT     DOWN     UP       TRNS     TRNS
R3: TRNS    OSM(CTL) OS_COPY OS_PASTE OS_CUT   TRNS     TRNS     OS_PGDN  OS_HOME  OS_END   RIGHT    TRNS
R4: TRNS    OS_UNDO KC_NO    KC_NO    TRNS     TRNS     TRNS     TRNS     KC_NO    KC_NO    TRNS     TRNS
R5: KC_NO   TRNS                                      TRNS       KC_NO
```

## L4 NUMBERS

```text
R1: TRNS    TRNS    OSM(SFT) OSM(ALT) OSM(GUI) TRNS    TRNS     7        8        9        TRNS     TRNS
R2: TRNS    OSM(CTL) OS_COPY OS_PASTE OS_CUT   OS_SELALL 0       1        2        3        TRNS     TRNS
R3: TRNS    OS_UNDO OS_PREV  OS_NEXT  BSPC     DEL      TRNS     4        5        6        TRNS     TRNS
R4: TRNS    OS_REDO KC_NO    KC_NO    ,        .        TRNS     TRNS     KC_NO    KC_NO    TRNS     APP
R5: KC_NO   .                                          TRNS       KC_NO
```

## L5 CONFIG

```text
R1: TRNS    TRNS    RGB_S-   RGB_S+   RGB_SPD- RGB_SPD+ SW_MAC   SW_WIN   TRNS     TRNS     TRNS     TRNS
R2: RGB_TOG LYR_CLR MEDIA>>  MEDIASTOP RGB_H-  RGB_H+   TRNS     TRNS     TRNS     TRNS     BOOT     TRNS
R3: TRNS    TRNS    TRNS     HSV_0    HSV_74   HSV_169  TRNS     C-S-TAB  C-TAB    TRNS     TRNS     TRNS
R4: TRNS    MEDIA<< KC_NO    KC_NO    TRNS     TRNS     TRNS     TRNS     KC_NO    KC_NO    TRNS     TRNS
R5: KC_NO   TRNS                                      TRNS       KC_NO
```

## L6 FUNCTION

```text
R1: TRNS    TRNS    DE_UE    TRNS     TRNS     TRNS     TRNS     F7       F8       F9       TRNS     TRNS
R2: TRNS    TRNS    TRNS     DE_EURO  DE_AE    DE_OE    F10      F1       F2       F3       F11      F12
R3: TRNS    TRNS    TRNS     DE_SS    TRNS     TRNS     TRNS     F4       F5       F6       TRNS     TRNS
R4: TRNS    TRNS    KC_NO    KC_NO    TRNS     OSM(RS)  TRNS     TRNS     KC_NO    KC_NO    TRNS     TRNS
R5: KC_NO   OSM(RS)                                   TRNS       KC_NO
```

## L7 MAC_SHORTCUTS

```text
R1: TRNS    TRNS     AppSwitch MissionCtl ForceQuit TRNS FocusH  FocusJ  FocusK  FocusL  TRNS       TRNS
R2: TRNS    Spotlight FinderTab Duplicate GetInfo   Rename MoveH  MoveJ   MoveK   MoveL   Fullscreen TRNS
R3: TRNS    FinderWin ShotClip  Lock     Emoji      TRNS   WS1    WS2     WS3     WS4     Float      TRNS
R4: TRNS    Screenshot KC_NO    KC_NO    TRNS       TRNS   TRNS   TRNS    KC_NO   KC_NO   TRNS       TRNS
R5: KC_NO   TRNS                                      TRNS       KC_NO
```

## L8 WIN_SHORTCUTS

```text
R1: TRNS    TRNS     AppSwitch Settings Run      TRNS    SnapLeft UP      SnapRight DeskLeft TRNS      TRNS
R2: TRNS    TaskView Emoji     Lock     TRNS     TRNS    LEFT     DOWN    RIGHT     DeskNew  DeskRight TRNS
R3: TRNS    Explorer OS_COPY   OS_PASTE OS_CUT   OS_SELALL TRNS   TRNS    TRNS      TRNS     DeskClose TRNS
R4: TRNS    OS_UNDO  KC_NO     KC_NO    TRNS     TRNS    TRNS     TRNS    KC_NO     KC_NO    TRNS      TRNS
R5: KC_NO   TRNS                                      TRNS       KC_NO
```

## Notes

- This pass prioritizes the row-lowering rule in columns 1, 2, 11, and 12 across all layers.
- Visualization and firmware are synchronized to the same slot assignments.
