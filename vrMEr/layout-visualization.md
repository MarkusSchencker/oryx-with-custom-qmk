# vrMEr Layout Visualization (ZSA Voyager Physical Base)

This visualization is generated from:
- key definitions in [vrMEr/custom_layout.inc](vrMEr/custom_layout.inc)
- physical Voyager geometry from `zsa/qmk_firmware` `keyboards/zsa/voyager/keyboard.json` (`layouts.LAYOUT.layout`)

The drawing below follows the Voyager's real key arrangement (column stagger + thumb placement), not a generic ortho grid.

## Legend

- `TRNS`: transparent
- `OSL(X)`: one-shot layer X
- `LT(X,K)`: tap K, hold for layer X
- `MT(MOD,K)`: tap K, hold MOD
- `OS_*`: OS-aware macro (Cmd on macOS base, Ctrl on Windows base where relevant)
- `DE_*`: German mapping from [vrMEr/i18n.h](vrMEr/i18n.h)

## Physical Slot Map (Voyager)

Slots are shown in physical order for all layers:

```text
                LEFT HALF                                      RIGHT HALF

      [k00] [k01] [k02] [k03] [k04] [k05]      [k26] [k27] [k28] [k29] [k30] [k31]
      [k06] [k07] [k08] [k09] [k10] [k11]      [k32] [k33] [k34] [k35] [k36] [k37]
      [k12] [k13] [k14] [k15] [k16] [k17]      [k38] [k39] [k40] [k41] [k42] [k43]
      [k18] [k19] [k20] [k21] [k22] [k23]      [k44] [k45] [k46] [k47] [k48] [k49]
                              [k24] [k25]  [k50] [k51]
```

Coordinate profile from Voyager JSON (for reference):
- top row arc: y `0.5 0.5 0.25 0 0.25 0.5` (mirrored on right)
- home row arc: y `1.5 1.5 1.25 1 1.25 1.5`
- lower row arc: y `2.5 2.5 2.25 2 2.25 2.5`
- bottom row arc: y `3.5 3.5 3.25 3 3.25 3.5`
- thumbs: left `[k24]=y4.5 [k25]=y4.75`, right `[k50]=y4.75 [k51]=y4.5`

---

## Layer 0: MAC_BASE

```text
            LEFT HALF                                       RIGHT HALF

[Cmd+-] [Cmd+0] [Cmd++] [LGUI] [TRNS] [TRNS]     [TRNS] [S-Tab] [TRNS] [Tab] [TRNS] [TO(CONFIG)]
[TRNS]  [P]     [U]     [REP]  [LEAD] [Q]        [G]    [C]     [L]    [M]   [F]    [TRNS]
[CW]    [MT(C,H)] [MT(A,I)] [MT(G,E)] [MT(S,A)] [O]     [D] [MT(S,T)] [MT(G,R)] [MT(A,N)] [MT(C,S)] [TRNS]
[TRNS]  [K]     [DE_Y]  [.]    [DE_DQOT] [X]     [J]    [V]     [W]    [B]   [DE_Z] [TRNS]
                             [OSL(SYM)] [OSL(MOU)] [OSL(FN)] [LT(NUM,SPC)]
```

## Layer 1: WIN_BASE

```text
            LEFT HALF                                       RIGHT HALF

[Ctrl+-] [Ctrl+0] [Ctrl++] [LALT] [TRNS] [TRNS]  [TRNS] [S-Tab] [TRNS] [Tab] [TRNS] [TO(CONFIG)]
[TRNS]   [P]      [U]      [REP]  [LEAD] [Q]     [G]    [C]     [L]    [M]   [F]    [TRNS]
[CW]     [MT(G,H)] [MT(A,I)] [MT(C,E)] [MT(S,A)] [O]    [D] [MT(S,T)] [MT(C,R)] [MT(A,N)] [MT(G,S)] [TRNS]
[TRNS]   [K]      [DE_Y]   [.]    [DE_DQOT] [X]  [J]    [V]     [W]    [B]   [DE_Z] [TRNS]
                              [OSL(SYM)] [OSL(MOU)] [OSL(FN)] [LT(NUM,SPC)]
```

## Layer 2: SYMBOLS

```text
            LEFT HALF                                       RIGHT HALF

[TRNS] [TRNS]   [TRNS]   [TRNS]   [TRNS]   [TRNS]     [TRNS]    [TRNS]    [TRNS]    [TRNS]   [TRNS]   [TRNS]
[TRNS] [DE_SECT][DE_AMPR][DE_LBRC][DE_RBRC][DE_CIRC]  [DE_EXLM] [DE_LABK] [DE_RABK] [DE_EQL] [DE_TILD] [TRNS]
[TRNS] [DE_AT]  [DE_SLSH][DE_LCBR][DE_RCBR][DE_ASTR]  [DE_QUES] [DE_LPRN] [DE_RPRN] [DE_MINS][DE_COLN] [TRNS]
[TRNS] [DE_UNDS][DE_BSLS][DE_PIPE][DE_DQOT][DE_GRV]   [DE_PLUS] [DE_PERC] [DE_DLR]  [DE_HASH][DE_SCLN] [TRNS]
                              [TRNS] [TRNS] [BSPC] [DEL]
```

## Layer 3: FUNCTION

```text
            LEFT HALF                                       RIGHT HALF

[TRNS] [F1]   [F2]    [F3]    [F4]      [F5]      [F6]       [F7]    [F8]   [F9]   [F10]  [TRNS]
[F12]  [Tab]  [DE_UE] [TRNS]  [TRNS]    [TRNS]    [OS_PREV]  [OS_PGUP] [TRNS] [OS_NEXT] [TRNS] [TRNS]
[F11]  [Esc]  [DE_SS] [DE_EURO][MT(S,AE)][DE_OE]  [Left]     [Down]  [Up]   [Right] [TRNS] [TRNS]
[TRNS] [Enter][TRNS]  [TRNS]  [TRNS]    [TRNS]    [TRNS]     [OS_PGDN] [OS_HOME] [OS_END] [TRNS] [TRNS]
                               [TRNS] [OSM(RS)] [TRNS] [TRNS]
```

## Layer 4: NUMBERS

```text
            LEFT HALF                                       RIGHT HALF

[TRNS] [TRNS]    [TRNS] [TRNS] [TRNS] [TRNS]      [TRNS] [TRNS] [PrtSc] [TRNS] [TRNS] [TRNS]
[TRNS] [DE_MINS] [7]    [8]    [9]    [DE_ASTR]   [TRNS] [TRNS] [TRNS]  [TRNS] [TRNS] [TRNS]
[TRNS] [DE_COLN] [1]    [2]    [3]    [0]         [UNDO] [COPY] [PASTE] [CUT]  [TRNS] [APP]
[TRNS] [DE_PLUS] [4]    [5]    [6]    [DE_SLSH]   [TRNS] [TRNS] [TRNS]  [TRNS] [TRNS] [TRNS]
                                [,]   [.]         [TRNS] [TRNS]
```

## Layer 5: CONFIG

```text
            LEFT HALF                                       RIGHT HALF

[RGB_TOG] [LYR_CLR] [RGB_MODE+] [RGB_SLD] [RGB_V-] [RGB_V+]  [SW_WIN] [TRNS] [SW_MAC] [TRNS] [BOOT] [TRNS]
[TRNS]    [TRNS]    [RGB_S-]    [RGB_S+]  [RGB_SPD-] [RGB_SPD+] [PgUp] [Home] [Up] [End] [TRNS] [TRNS]
[TRNS]    [Media<<] [Media>>]   [MediaStop] [RGB_H-] [RGB_H+] [PgDn] [Left] [Down] [Right] [TRNS] [TRNS]
[TRNS]    [TRNS]    [TRNS]      [HSV_0]   [HSV_74] [HSV_169] [TRNS] [C-S-Tab] [C-Tab] [TRNS] [TRNS] [TRNS]
                                   [TRNS] [TRNS] [TRNS] [TRNS]
```

## Layer 6: MOUSE

```text
            LEFT HALF                                       RIGHT HALF

[TRNS] [TRNS]   [TRNS] [TRNS] [TRNS] [TRNS]      [TRNS] [TRNS]   [TRNS]   [TRNS]  [TRNS] [TRNS]
[TRNS] [Tab]    [CUT]  [PASTE] [COPY] [TRNS]     [TRNS] [TRNS]   [MS_UP]  [WH_UP] [TRNS] [TRNS]
[TRNS] [LShift] [BTN3] [BTN2]  [BTN1] [TRNS]     [TRNS] [MS_LEFT][MS_DOWN][MS_RIGHT] [TRNS] [TRNS]
[TRNS] [LCtrl]  [ACL2] [ACL0]  [ACL1] [TRNS]     [TRNS] [WH_LEFT][WH_RIGHT][WH_DOWN] [TRNS] [TRNS]
                                [TRNS] [TRNS]    [TRNS] [TRNS]
```

---

## Behavior Notes

- Base switching is on `CONFIG`: `SW_MAC` and `SW_WIN` set default layer and move there.
- Home-row mod timing/hold tuning is implemented in [vrMEr/custom_layout.inc](vrMEr/custom_layout.inc).
- Combos include mouse one-shot plus punctuation combos for comma/double quote behavior.
