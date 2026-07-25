# vrMEr Layout Visualization (Second Pass)

This document is a compact, comparison-friendly visualization of your keymap.

Sources:
- key behavior: [vrMEr/custom_layout.inc](vrMEr/custom_layout.inc)
- DE mappings: [vrMEr/i18n.h](vrMEr/i18n.h)
- physical geometry base: ZSA Voyager keyboard.json layout coordinates (`layouts.LAYOUT.layout`)

## Reading Guide

- Every layer uses the same physical slot IDs (`k00..k51`) so location is stable.
- The template below shows true Voyager arrangement: curved columns plus offset thumbs.
- Layer sections are compact overlays on top of that same template.

## Voyager Physical Template (Slot IDs)

```text
                               LEFT HALF                                          RIGHT HALF

        k00      k01      k02      k03      k04      k05          k26      k27      k28      k29      k30      k31
        k06      k07      k08      k09      k10      k11          k32      k33      k34      k35      k36      k37
        k12      k13      k14      k15      k16      k17          k38      k39      k40      k41      k42      k43
        k18      k19      k20      k21      k22      k23          k44      k45      k46      k47      k48      k49
                                     k24      k25         k50      k51
```

## Key Label Conventions

- `TRNS`: transparent
- `MT(X,Y)`: hold modifier X, tap key Y
- `LT(L,K)`: hold layer L, tap key K
- `OSL(L)`: one-shot layer
- `OS_*`: OS-aware macro
- `DE_*`: German key abstraction

## Layer Overlays

### L0 MAC_BASE

```text
[k00 Cmd+-] [k01 Cmd+0] [k02 Cmd++] [k03 LGUI]   [k04 TRNS] [k05 TRNS]  || [k26 TRNS] [k27 S-Tab] [k28 TRNS] [k29 Tab]  [k30 TRNS] [k31 TO(CFG)]
[k06 TRNS]  [k07 P]      [k08 U]      [k09 REP]    [k10 LEAD] [k11 Q]     || [k32 G]    [k33 C]     [k34 L]    [k35 M]    [k36 F]    [k37 TRNS]
[k12 CW]    [k13 MT(C,H)][k14 MT(A,I)][k15 MT(G,E)][k16 MT(S,A)][k17 O]   || [k38 D]    [k39 MT(S,T)][k40 MT(G,R)][k41 MT(A,N)][k42 MT(C,S)][k43 TRNS]
[k18 TRNS]  [k19 K]      [k20 DE_Y]   [k21 .]      [k22 DE_DQOT][k23 X]   || [k44 J]    [k45 V]     [k46 W]    [k47 B]    [k48 DE_Z] [k49 TRNS]
                                      [k24 OSL(SYM)] [k25 OSL(MOU)] || [k50 OSL(FN)] [k51 LT(NUM,SPC)]
```

### L1 WIN_BASE

```text
[k00 Ctrl+-][k01 Ctrl+0][k02 Ctrl++][k03 LALT]   [k04 TRNS] [k05 TRNS]  || [k26 TRNS] [k27 S-Tab] [k28 TRNS] [k29 Tab]  [k30 TRNS] [k31 TO(CFG)]
[k06 TRNS]  [k07 P]      [k08 U]      [k09 REP]    [k10 LEAD] [k11 Q]     || [k32 G]    [k33 C]     [k34 L]    [k35 M]    [k36 F]    [k37 TRNS]
[k12 CW]    [k13 MT(G,H)][k14 MT(A,I)][k15 MT(C,E)][k16 MT(S,A)][k17 O]   || [k38 D]    [k39 MT(S,T)][k40 MT(C,R)][k41 MT(A,N)][k42 MT(G,S)][k43 TRNS]
[k18 TRNS]  [k19 K]      [k20 DE_Y]   [k21 .]      [k22 DE_DQOT][k23 X]   || [k44 J]    [k45 V]     [k46 W]    [k47 B]    [k48 DE_Z] [k49 TRNS]
                                      [k24 OSL(SYM)] [k25 OSL(MOU)] || [k50 OSL(FN)] [k51 LT(NUM,SPC)]
```

### L2 SYMBOLS

```text
[k00 TRNS] [k01 TRNS]   [k02 TRNS]   [k03 TRNS]   [k04 TRNS]   [k05 TRNS] || [k26 TRNS]   [k27 TRNS]   [k28 TRNS]   [k29 TRNS]  [k30 TRNS]  [k31 TRNS]
[k06 TRNS] [k07 DE_SECT][k08 DE_AMPR][k09 DE_LBRC][k10 DE_RBRC][k11 DE_CIRC] || [k32 DE_EXLM][k33 DE_LABK][k34 DE_RABK][k35 DE_EQL][k36 DE_TILD][k37 TRNS]
[k12 TRNS] [k13 DE_AT]  [k14 DE_SLSH][k15 DE_LCBR][k16 DE_RCBR][k17 DE_ASTR] || [k38 DE_QUES][k39 DE_LPRN][k40 DE_RPRN][k41 DE_MINS][k42 DE_COLN][k43 TRNS]
[k18 TRNS] [k19 DE_UNDS][k20 DE_BSLS][k21 DE_PIPE][k22 DE_DQOT][k23 DE_GRV]  || [k44 DE_PLUS][k45 DE_PERC][k46 DE_DLR] [k47 DE_HASH][k48 DE_SCLN][k49 TRNS]
                                       [k24 TRNS]    [k25 TRNS] || [k50 BSPC] [k51 DEL]
```

### L3 FUNCTION

```text
[k00 TRNS] [k01 F1]   [k02 F2]     [k03 F3]     [k04 F4]      [k05 F5]   || [k26 F6]      [k27 F7]      [k28 F8]    [k29 F9]    [k30 F10]   [k31 TRNS]
[k06 F12]  [k07 Tab]  [k08 DE_UE]  [k09 TRNS]   [k10 TRNS]    [k11 TRNS] || [k32 OS_PREV] [k33 OS_PGUP] [k34 TRNS]  [k35 OS_NEXT][k36 TRNS]  [k37 TRNS]
[k12 F11]  [k13 Esc]  [k14 DE_SS]  [k15 DE_EURO][k16 MT(S,AE)][k17 DE_OE]|| [k38 Left]    [k39 Down]    [k40 Up]    [k41 Right] [k42 TRNS]  [k43 TRNS]
[k18 TRNS] [k19 Enter][k20 TRNS]   [k21 TRNS]   [k22 TRNS]    [k23 TRNS] || [k44 TRNS]    [k45 OS_PGDN] [k46 OS_HOME][k47 OS_END][k48 TRNS] [k49 TRNS]
                                      [k24 TRNS] [k25 OSM(RS)] || [k50 TRNS] [k51 TRNS]
```

### L4 NUMBERS

```text
[k00 TRNS] [k01 TRNS]    [k02 TRNS] [k03 TRNS] [k04 TRNS] [k05 TRNS] || [k26 TRNS] [k27 TRNS] [k28 PrtSc] [k29 TRNS] [k30 TRNS] [k31 TRNS]
[k06 TRNS] [k07 DE_MINS] [k08 7]    [k09 8]    [k10 9]    [k11 DE_ASTR] || [k32 TRNS] [k33 TRNS] [k34 TRNS] [k35 TRNS] [k36 TRNS] [k37 TRNS]
[k12 TRNS] [k13 DE_COLN] [k14 1]    [k15 2]    [k16 3]    [k17 0]    || [k38 OS_UNDO] [k39 OS_COPY] [k40 OS_PASTE] [k41 OS_CUT] [k42 TRNS] [k43 APP]
[k18 TRNS] [k19 DE_PLUS] [k20 4]    [k21 5]    [k22 6]    [k23 DE_SLSH] || [k44 TRNS] [k45 TRNS] [k46 TRNS] [k47 TRNS] [k48 TRNS] [k49 TRNS]
                                       [k24 ,]      [k25 .] || [k50 TRNS] [k51 TRNS]
```

### L5 CONFIG

```text
[k00 RGB_TOG] [k01 LYR_CLR] [k02 RGB_MODE+] [k03 RGB_SLD] [k04 RGB_V-] [k05 RGB_V+] || [k26 SW_WIN] [k27 TRNS] [k28 SW_MAC] [k29 TRNS] [k30 BOOT] [k31 TRNS]
[k06 TRNS]    [k07 TRNS]    [k08 RGB_S-]    [k09 RGB_S+]  [k10 RGB_SPD-] [k11 RGB_SPD+] || [k32 PgUp] [k33 Home] [k34 Up] [k35 End] [k36 TRNS] [k37 TRNS]
[k12 TRNS]    [k13 Media<<] [k14 Media>>]   [k15 MediaStop] [k16 RGB_H-] [k17 RGB_H+] || [k38 PgDn] [k39 Left] [k40 Down] [k41 Right] [k42 TRNS] [k43 TRNS]
[k18 TRNS]    [k19 TRNS]    [k20 TRNS]      [k21 HSV_0]   [k22 HSV_74] [k23 HSV_169] || [k44 TRNS] [k45 C-S-Tab] [k46 C-Tab] [k47 TRNS] [k48 TRNS] [k49 TRNS]
                                           [k24 TRNS] [k25 TRNS] || [k50 TRNS] [k51 TRNS]
```

### L6 MOUSE

```text
[k00 TRNS] [k01 TRNS]   [k02 TRNS]  [k03 TRNS] [k04 TRNS] [k05 TRNS] || [k26 TRNS] [k27 TRNS] [k28 TRNS] [k29 TRNS] [k30 TRNS] [k31 TRNS]
[k06 TRNS] [k07 Tab]    [k08 OS_CUT][k09 OS_PASTE] [k10 OS_COPY] [k11 TRNS] || [k32 TRNS] [k33 TRNS] [k34 MS_UP] [k35 WH_UP] [k36 TRNS] [k37 TRNS]
[k12 TRNS] [k13 LShift] [k14 BTN3]  [k15 BTN2] [k16 BTN1] [k17 TRNS] || [k38 TRNS] [k39 MS_LEFT] [k40 MS_DOWN] [k41 MS_RIGHT] [k42 TRNS] [k43 TRNS]
[k18 TRNS] [k19 LCtrl]  [k20 ACL2]  [k21 ACL0] [k22 ACL1] [k23 TRNS] || [k44 TRNS] [k45 WH_LEFT] [k46 WH_RIGHT] [k47 WH_DOWN] [k48 TRNS] [k49 TRNS]
                                     [k24 TRNS] [k25 TRNS] || [k50 TRNS] [k51 TRNS]
```

## Quick Differences

- L0/L1 only differ in OS modifier strategy and home-row mod modifier assignment.
- L2 is symbol-heavy and maps punctuation via DE aliases.
- L3 centralizes nav/editing and DE umlaut access.
- L4 is numpad-like plus OS edit macros.
- L5 handles RGB, media, boot, and OS base switching.
- L6 handles mouse movement, wheel, buttons, and acceleration.
