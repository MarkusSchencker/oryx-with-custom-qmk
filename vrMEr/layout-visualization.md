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
R4: TRNS    K       KC_NO    KC_NO    OSL(SYM) OSL(MOV) OSL(FN)  LT(NUM,SPC) KC_NO KC_NO    DE_Z     TRNS
R5: KC_NO   BSPC                                      ENTER      KC_NO
```

## L1 WIN_BASE

```text
R1: Ctrl+-  Ctrl+0  U        REPEAT   LEAD     Q        G        C        L        M        TRNS     TO(CONFIG)
R2: TRNS    P       MT(A,I)  MT(C,E)  MT(S,A)  O        D        MT(S,T)  MT(C,R)  MT(A,N)  F        TRNS
R3: CW      MT(G,H) DE_Y     .        DE_DQOT  X        J        V        W        B        MT(G,S)  TRNS
R4: TRNS    K       KC_NO    KC_NO    OSL(SYM) OSL(MOV) OSL(FN)  LT(NUM,SPC) KC_NO KC_NO    DE_Z     TRNS
R5: KC_NO   BSPC                                      ENTER      KC_NO
```

## L2 SYMBOLS

```text
R1: TRNS    TRNS    DE_AMPR  DE_LBRC  DE_RBRC  DE_CIRC  DE_EXLM  DE_LABK  DE_RABK  DE_EQL   TRNS     TRNS
R2: TRNS    DE_SECT OSM(CTL) OSM(SFT) OSM(ALT) OSM(GUI) DE_QUES  DE_LPRN  DE_RPRN  DE_MINS  DE_TILD  TRNS
R3: TRNS    DE_AT   OSM(CS)  OSM(AS)  OSM(GS)  DE_GRV   DE_PLUS  DE_PERC  DE_DLR   DE_HASH  DE_COLN  TRNS
R4: TRNS    DE_UNDS KC_NO    KC_NO    DE_SLSH  DE_ASTR  DE_BSLS  DE_PIPE  KC_NO    KC_NO    DE_SCLN  TRNS
R5: KC_NO   TRNS                                      BSPC       KC_NO
```

## L3 MOVEMENT

```text
R1: TRNS    ESC     TAB      OSL(MAC_SHORT) OSL(WIN_SHORT) TRNS  OS_PREV  OS_PGUP  TRNS     OS_NEXT  TRNS     TRNS
R2: TRNS    OSM(CTL) OSM(SFT) OSM(ALT) OSM(GUI) TRNS    TRNS     LEFT     DOWN     UP       RIGHT    TRNS
R3: TRNS    OS_UNDO OS_COPY  OS_PASTE  OS_CUT   TRNS     TRNS     OS_PGDN  OS_HOME  OS_END   TRNS     TRNS
R4: TRNS    ENTER   KC_NO    KC_NO    TRNS     TRNS     TRNS     TRNS     KC_NO    KC_NO    TRNS     TRNS
R5: KC_NO   TRNS                                      TRNS       KC_NO
```

## L4 NUMBERS

```text
R1: TRNS    OSM(CTL) OSM(SFT) OSM(ALT) OSM(GUI) TRNS    TRNS     7        8        9        TRNS     TRNS
R2: TRNS    OS_UNDO OS_COPY  OS_PASTE OS_CUT   OS_SELALL 0       1        2        3        TRNS     TRNS
R3: TRNS    OS_REDO OS_PREV  OS_NEXT  BSPC     DEL      TRNS     4        5        6        TRNS     APP
R4: TRNS    ESC     TAB      KC_NO    ,        .        TRNS     TRNS     KC_NO    KC_NO    TRNS     TRNS
R5: KC_NO   .                                          TRNS       KC_NO
```

## L5 CONFIG

```text
R1: RGB_TOG LYR_CLR RGB_S-   RGB_S+   RGB_SPD- RGB_SPD+ SW_MAC   SW_WIN   TRNS     TRNS     BOOT     TRNS
R2: TRNS    TRNS    MEDIA>>  MEDIASTOP RGB_H-  RGB_H+   TRNS     TRNS     TRNS     TRNS     TRNS     TRNS
R3: TRNS    MEDIA<< TRNS     HSV_0    HSV_74   HSV_169  TRNS     C-S-TAB  C-TAB    TRNS     TRNS     TRNS
R4: TRNS    TRNS    KC_NO    KC_NO    TRNS     TRNS     TRNS     TRNS     KC_NO    KC_NO    TRNS     TRNS
R5: KC_NO   TRNS                                      TRNS       KC_NO
```

## L6 FUNCTION

```text
R1: TRNS    TRNS    DE_UE    TRNS     TRNS     TRNS     TRNS     F7       F8       F9       F11      F12
R2: TRNS    TRNS    DE_AE    DE_EURO  TRNS     DE_OE    F10      F1       F2       F3       TRNS     TRNS
R3: TRNS    TRNS    TRNS     DE_SS    TRNS     TRNS     TRNS     F4       F5       F6       TRNS     TRNS
R4: TRNS    TRNS    KC_NO    KC_NO    TRNS     OSM(RS)  TRNS     TRNS     KC_NO    KC_NO    TRNS     TRNS
R5: KC_NO   OSM(RS)                                   TRNS       KC_NO
```

## L7 MAC_SHORTCUTS

```text
R1: TRNS    Spotlight AppSwitch MissionCtl ForceQuit TRNS FocusH  FocusJ  FocusK  FocusL  Fullscreen TRNS
R2: TRNS    FinderWin FinderTab Duplicate GetInfo   Rename MoveH   MoveJ   MoveK   MoveL   Float      TRNS
R3: TRNS    Screenshot ShotClip  Lock     Emoji     TRNS   WS1     WS2     WS3     WS4     TRNS       TRNS
R4: TRNS    SPACE    KC_NO    KC_NO    TRNS     TRNS     TRNS     TRNS     KC_NO    KC_NO    HideApp   TRNS
R5: KC_NO   TRNS                                      TRNS       KC_NO
```

## L8 WIN_SHORTCUTS

```text
R1: TRNS    TaskView AppSwitch Settings Run      TRNS    SnapLeft UP      SnapRight DeskLeft DeskRight TRNS
R2: TRNS    Explorer Emoji     Lock     TRNS     TRNS    LEFT     DOWN    RIGHT     DeskNew  DeskClose TRNS
R3: TRNS    OS_UNDO OS_COPY    OS_PASTE OS_CUT   OS_SELALL TRNS   TRNS    TRNS      TRNS     TRNS      TRNS
R4: TRNS    SPACE    KC_NO     KC_NO    TRNS     TRNS    TRNS     TRNS    KC_NO     KC_NO    TRNS      TRNS
R5: KC_NO   TRNS                                      TRNS       KC_NO
```

## Notes

- The remap intentionally removes several outer/reach-heavy positions.
- Base layers now place layer switches in row 4 (`C5..C8`) as the primary thumb arc (`SYM`, `MOV`, `FN`, `NUM`).
- Inner thumbs are repurposed as `BSPC` and `ENTER` on base layers.
