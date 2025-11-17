# vrMEr Keyboard Layout Visualization

**7-Layer Architecture for ZSA Voyager**  
**Firmware Version:** 003-mouse-layer  
**Layout:** HIEA O / DTRNS (Custom)

---

## Layer Overview

| Layer | Name | Purpose | Access Method |
|-------|------|---------|---------------|
| 0 | `LAYER_MAC_BASE` | macOS base layer with Cmd-optimized home row mods | Default layer (TO key from config) |
| 1 | `LAYER_WIN_BASE` | Windows base layer with Ctrl/Win-optimized home row mods | TO key from config layer |
| 2 | `LAYER_SYMBOLS` | Unified programming symbols | OSL from both base layers |
| 3 | `LAYER_FUNCTION` | Function keys, navigation, German umlauts | OSL from both base layers |
| 4 | `LAYER_NUMBERS` | Numpad with OS-aware clipboard | LT (hold space) from both base layers |
| 5 | `LAYER_CONFIG` | RGB controls, layer switching, bootloader | TO key from both base layers |
| 6 | `LAYER_MOUSE` | Mouse control (cursor, buttons, scroll, speed) | MO (bottom-left key) from both base layers |

---

## Layer 0: LAYER_MAC_BASE
**macOS Base Layer with Cmd-optimized Home Row Mods**

```
┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐                 ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
│ Cmd+-   │ Cmd+0   │ Cmd+=   │ LGui    │    ·    │    ·    │                 │    ·    │ Shft+Tab│    ·    │  Tab    │    ·    │TO(CFG)  │
├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                 ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
│    ·    │    P    │    U    │ Repeat  │ Leader  │    Q    │                 │    G    │    C    │    L    │    M    │    F    │    ·    │
├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                 ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
│CapsWord │ H/Ctrl  │ I/Alt   │ E/Cmd   │    A    │    O    │                 │    D    │ T/Cmd   │ R/Alt   │ N/Ctrl  │    S    │    ·    │
├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                 ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
│MO(MOUSE)│    K    │    Y    │    .    │    "    │    X    │                 │    J    │    V    │    W    │    B    │    Z    │    ·    │
└─────────┴─────────┴─────────┼─────────┼─────────┤         │                 │         ├─────────┼─────────┼─────────┴─────────┴─────────┘
                              │OSL(SYM) │OSM(Shft)│         │                 │         │OSL(FNC) │LT(NUM,  │
                              │         │         │         │                 │         │         │ Space)  │
                              └─────────┴─────────┘         │                 │         └─────────┴─────────┘
```

**Key Features:**
- **Home Row Mods (Left):** H=Ctrl, I=Alt, E=Cmd, A=Shift
- **Home Row Mods (Right):** T=Shift, R=Cmd, N=Alt, S=Ctrl
- **Alpha Layout:** HIEA O / DTRNS (optimized for German/English)
- **Special Keys:** Caps Word, Repeat Key, Leader Key
- **Layer Access:** MO(Mouse) on left thumb, OSL for Symbols/Function, LT for Numbers

---

## Layer 1: LAYER_WIN_BASE
**Windows Base Layer with Ctrl/Win-optimized Home Row Mods**

```
┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐                 ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
│ Ctrl+-  │ Ctrl+0  │ Ctrl+=  │  LAlt   │    ·    │    ·    │                 │    ·    │ Shft+Tab│    ·    │  Tab    │    ·    │TO(CFG)  │
├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                 ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
│    ·    │    P    │    U    │ Repeat  │ Leader  │    Q    │                 │    G    │    C    │    L    │    M    │    F    │    ·    │
├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                 ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
│CapsWord │ H/Win   │ I/Alt   │ E/Ctrl  │ A/Shft  │    O    │                 │    D    │ T/Shft  │ R/Alt   │ N/Win   │    S    │    ·    │
├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                 ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
│    ·    │    K    │    Y    │    .    │    "    │    X    │                 │    J    │    V    │    W    │    B    │    Z    │    ·    │
└─────────┴─────────┴─────────┼─────────┼─────────┤         │                 │         ├─────────┼─────────┼─────────┴─────────┴─────────┘
                              │OSL(SYM) │MO(MOUSE)│         │                 │         │OSL(FNC) │LT(NUM,  │
                              │         │         │         │                 │         │         │ Space)  │
                              └─────────┴─────────┘         │                 │         └─────────┴─────────┘
```

**Key Features:**
- **Home Row Mods (Left):** H=Win, I=Alt, E=Ctrl, A=Shift
- **Home Row Mods (Right):** T=Shift, R=Alt, N=Win
- **Alpha Layout:** Identical to macOS layer (HIEA O / DTRNS)
- **Differences:** Only modifier keys changed for Windows optimization
- **Layer Access:** MO(Mouse) on left thumb, OSL for Symbols/Function, LT for Numbers

---

## Layer 2: LAYER_SYMBOLS
**Unified Programming Symbols Layer**

```
┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐                 ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
│    ·    │    ·    │    ·    │    ·    │    ·    │    ·    │                 │    ·    │    ·    │    ·    │    ·    │    ·    │    ·    │
├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                 ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
│    ·    │    §    │    &    │    [    │    ]    │    ^    │                 │    !    │    <    │    >    │    =    │    ~    │    ·    │
├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                 ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
│    ·    │    @    │    /    │    {    │    }    │    *    │                 │    ?    │    (    │    )    │    -    │    :    │    ·    │
├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                 ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
│    ·    │    _    │    \    │    |    │    "    │    `    │                 │    +    │    %    │    $    │    #    │    ;    │    ·    │
└─────────┴─────────┴─────────┼─────────┼─────────┤         │                 │         ├─────────┼─────────┼─────────┴─────────┴─────────┘
                              │    ·    │    ·    │         │                 │         │  Bksp   │   Del   │
                              │         │         │         │                 │         │         │         │
                              └─────────┴─────────┘         │                 │         └─────────┴─────────┘
```

**Key Features:**
- **Left Side:** Brackets, braces, special symbols (@, §, &, ^, *, /, \, |, `, _)
- **Right Side:** Operators and punctuation (!, ?, +, -, =, <, >, %, $, #, :, ;, ~)
- **Thumb Keys:** Backspace, Delete
- **Use Case:** Programming, text editing, symbol-heavy workflows

---

## Layer 3: LAYER_FUNCTION
**Function Keys, Navigation, and German Umlauts**

```
┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐                 ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
│    ·    │   F1    │   F2    │   F3    │   F4    │   F5    │                 │   F6    │   F7    │   F8    │   F9    │  F10    │    ·    │
├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                 ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
│  F12    │  Tab    │    Ü    │    ·    │    ·    │    ·    │                 │  PgUp   │   Up    │    ·    │    ·    │    ·    │    ·    │
├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                 ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
│  F11    │   Esc   │    ß    │    €    │    Ä    │    Ö    │                 │  Left   │  Down   │   Up    │  Right  │    ·    │    ·    │
├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                 ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
│    ·    │  Enter  │    ·    │    ·    │    ·    │    ·    │                 │  PgDn   │  Home   │   End   │    ·    │    ·    │    ·    │
└─────────┴─────────┴─────────┼─────────┼─────────┤         │                 │         ├─────────┼─────────┼─────────┴─────────┴─────────┘
                              │    ·    │    ·    │         │                 │         │    ·    │    ·    │
                              │         │         │         │                 │         │         │         │
                              └─────────┴─────────┘         │                 │         └─────────┴─────────┘
```

**Key Features:**
- **Function Keys:** F1-F12 across top row
- **German Characters:** Ä, Ö, Ü, ß, € (optimized for German typing)
- **Navigation:** Arrow keys (vim-style on right), PgUp/PgDn, Home/End
- **Common Keys:** Esc, Tab, Enter
- **Use Case:** Application shortcuts, German text, document navigation

---

## Layer 4: LAYER_NUMBERS
**Numpad with OS-aware Clipboard Operations**

```
┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐                 ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
│    ·    │    ·    │    ·    │    ·    │    ·    │    ·    │                 │    ·    │    ·    │  PrtSc  │    ·    │    ·    │    ·    │
├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                 ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
│    ·    │    -    │    7    │    8    │    9    │    *    │                 │    ·    │    ·    │    ·    │    ·    │    ·    │    ·    │
├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                 ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
│    ·    │    :    │    1    │    2    │    3    │    0    │                 │OS Undo  │OS Copy  │OS Paste │ OS Cut  │    ·    │  Menu   │
├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                 ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
│    ·    │    +    │    4    │    5    │    6    │    /    │                 │    ·    │    ·    │    ·    │    ·    │    ·    │    ·    │
└─────────┴─────────┴─────────┼─────────┼─────────┤         │                 │         ├─────────┼─────────┼─────────┴─────────┴─────────┘
                              │    ,    │    .    │         │                 │         │    ·    │    ·    │
                              │         │         │         │                 │         │         │         │
                              └─────────┴─────────┘         │                 │         └─────────┴─────────┘
```

**Key Features:**
- **Numpad Layout:** 0-9 arranged in standard calculator layout
- **Operators:** +, -, *, /, :
- **OS-Aware Clipboard:**
  - **OS_UNDO:** Cmd+Z (macOS) / Ctrl+Z (Windows)
  - **OS_COPY:** Cmd+C (macOS) / Ctrl+C (Windows)
  - **OS_PASTE:** Cmd+V (macOS) / Ctrl+V (Windows)
  - **OS_CUT:** Cmd+X (macOS) / Ctrl+X (Windows)
- **Special:** Print Screen, Menu key
- **Thumb Keys:** Comma, period for decimal input

---

## Layer 5: LAYER_CONFIG
**RGB Controls, Layer Switching, and System Functions**

```
┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐                 ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
│RGB Tog  │RGB Layer│RGB Mode │RGB Slide│RGB Val- │RGB Val+ │                 │TO(WIN)  │    ·    │TO(MAC)  │    ·    │Bootload │    ·    │
├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                 ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
│    ·    │    ·    │RGB Sat- │RGB Sat+ │RGB Spd- │RGB Spd+ │                 │  PgUp   │  Home   │   Up    │   End   │    ·    │    ·    │
├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                 ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
│    ·    │MediaPrev│MediaNext│MediaStop│RGB Hue- │RGB Hue+ │                 │  PgDn   │  Left   │  Down   │  Right  │    ·    │    ·    │
├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                 ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
│    ·    │    ·    │    ·    │RGB Red  │RGB Grn  │RGB Blue │                 │    ·    │Ctrl+Shft│Ctrl+Tab │    ·    │    ·    │    ·    │
│         │         │         │         │         │         │                 │         │  +Tab   │         │         │         │         │
└─────────┴─────────┴─────────┼─────────┼─────────┤         │                 │         ├─────────┼─────────┼─────────┴─────────┴─────────┘
                              │    ·    │    ·    │         │                 │         │    ·    │    ·    │
                              │         │         │         │                 │         │         │         │
                              └─────────┴─────────┘         │                 │         └─────────┴─────────┘
```

**Key Features:**
- **RGB Controls:**
  - Toggle, Mode, Slide, Layer Color Toggle
  - Hue, Saturation, Value, Speed adjustments
  - Preset colors: Red, Green, Blue
- **Layer Switching:** TO(LAYER_MAC_BASE), TO(LAYER_WIN_BASE)
- **System:** Bootloader access for flashing firmware
- **Media Controls:** Previous, Next, Stop
- **Navigation:** Full arrow keys, PgUp/PgDn, Home/End
- **Browser:** Ctrl+Tab, Ctrl+Shift+Tab for tab switching

---

## Layer 6: LAYER_MOUSE
**Mouse Control Layer (Cursor Movement, Buttons, Scroll, Speed, Keyboard Shortcuts)**

```
┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐                 ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
│    ·    │    ·    │    ·    │    ·    │    ·    │    ·    │                 │    ·    │    ·    │    ·    │    ·    │    ·    │    ·    │
│         │         │         │         │         │         │                 │         │         │         │         │         │         │
├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                 ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
│    ·    │   TAB   │   Cut   │  Paste  │  Copy   │    ·    │                 │    ·    │    ·    │MS Up    │Scroll   │    ·    │    ·    │
│         │         │ OS Agn. │ OS Agn. │ OS Agn. │         │                 │         │         │    ↑    │  Up ↑   │         │         │
├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                 ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
│    ·    │  SHIFT  │  BTN3   │  BTN2   │  BTN1   │    ·    │                 │    ·    │MS Left  │MS Down  │MS Right │    ·    │    ·    │
│         │         │ Middle  │  Right  │  Left   │         │                 │         │    ←    │    ↓    │    →    │         │         │
├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                 ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
│    ·    │  CTRL   │  ACL2   │  ACL0   │  ACL1   │    ·    │                 │    ·    │Scroll   │Scroll   │Scroll   │    ·    │    ·    │
│         │         │  Fast   │  Slow   │ Normal  │         │                 │         │ Left ←  │Right →  │ Down ↓  │         │         │
└─────────┴─────────┴─────────┼─────────┼─────────┤         │                 │         ├─────────┼─────────┼─────────┴─────────┴─────────┘
                              │    ·    │    ·    │         │                 │         │    ·    │    ·    │
                              │         │         │         │                 │         │         │         │
                              └─────────┴─────────┘         │                 │         └─────────┴─────────┘
```

**Key Features:**
- **Cursor Movement (Right Hand - Row 2-3):**
  - **Arrow-key layout:** MS_UP, MS_LEFT, MS_DOWN, MS_RIGHT
  - **Diagonal movement:** Press two keys simultaneously (e.g., UP+RIGHT)
  - **Acceleration:** Movement speeds up the longer keys are held
  - **Configuration:** 16ms interval (60 FPS), 8px delta, 10x max speed
- **Mouse Buttons (Left Hand - Row 3 Home Row):**
  - **BTN1 (Left Click):** I position - most frequent action
  - **BTN2 (Right Click):** E position
  - **BTN3 (Middle Click):** H position (after Shift)
  - **One-handed operation:** All buttons accessible with left hand while right hand controls cursor
  - **Drag-and-drop:** Hold button key, move cursor with MS keys, release
- **Speed Control (Left Hand - Row 4):**
  - **ACL2 (Fast - Default):** Full speed for quick navigation (Y position)
  - **ACL0 (Slow/Precision):** 1/4 speed for accurate positioning (. position)
  - **ACL1 (Normal):** 1/2 speed for general use (" position)
  - **Persistence:** Speed setting survives layer deactivation
- **Keyboard Shortcuts (Left Hand - Row 2):**
  - **TAB:** Navigate between UI elements (P position)
  - **Clipboard (OS-agnostic):** 
    - OS_CUT (Cmd+X/Ctrl+X) at U position
    - OS_PASTE (Cmd+V/Ctrl+V) at Repeat position
    - OS_COPY (Cmd+C/Ctrl+C) at Leader position
  - **Modifiers:** SHIFT (H position - row 3), CTRL (K position - row 4)
  - **Common workflows:** Select text with SHIFT+cursor, copy/paste, tab navigation
- **Scroll Wheel (Right Hand - Row 4):**
  - **Horizontal:** WH_LEFT (under MS_LEFT), WH_RIGHT (under MS_DOWN)
  - **Vertical:** WH_DOWN (under MS_RIGHT), WH_UP (row 2)
  - **Configuration:** 80ms interval, slower than cursor movement
- **Layer Access:** Hold left thumb MO(LAYER_MOUSE) key (former Shift position)
- **Auto-return:** Releasing thumb key returns to base layer immediately
- **OS-agnostic:** Clipboard shortcuts work on both macOS and Windows

**Use Cases:**
- **Laptop mode:** Use keyboard as mouse when trackpad unavailable
- **Precision work:** Switch to ACL0 for pixel-perfect cursor positioning
- **One-handed operation:** Control mouse with left hand while eating/writing
- **Text selection:** Hold SHIFT, navigate with cursor keys, copy with OS_COPY (works on both macOS/Windows)
- **Form navigation:** TAB through fields, ENTER to submit, ESC to cancel
- **File management:** Navigate with mouse, select with SHIFT+click, copy/paste files with OS-agnostic shortcuts
- **Accessibility:** Alternative input method for users with limited mouse access
- **Ergonomic:** Reduce hand movement between keyboard and mouse
- **Cross-platform:** All clipboard/edit shortcuts automatically adapt to macOS (Cmd) or Windows (Ctrl)

**Performance:**
- **Response time:** <50ms from key press to cursor movement
- **Firmware size:** ~7KB (within 230KB constitutional limit)
- **Update rate:** 60 FPS for smooth cursor movement

---

## Special Features

### Home Row Mods (Mod-Tap)
- **MT(modifier, key):** Hold for modifier, tap for key
- **macOS:** H=Ctrl, I=Alt, E=Cmd (left) | T=Cmd, R=Alt, N=Ctrl (right)
- **Windows:** H=Win, I=Alt, E=Ctrl (left) | T=Ctrl, R=Alt, N=Win (right)

### One-Shot Keys
- **OSL(layer):** Tap to activate layer for next keypress only
- **OSM(modifier):** Tap to activate modifier for next keypress only

### Layer-Tap (LT)
- **LT(LAYER_NUMBERS, KC_SPACE):** Hold for numbers layer, tap for space

### Key Overrides
1. **Shift + . → ,** (dot becomes comma when shifted)
2. **Shift + " → '** (double quote becomes single quote when shifted)

### Combos
1. **OSM(Shift) + . → ,** (shift + dot produces comma)
2. **OSM(Shift) + ' → "** (shift + single quote produces double quote)

### Leader Key Sequences
Access via Leader key, then:
- **@A, A → ä/Ä** (lowercase/uppercase based on shift state)
- **@O, O → ö/Ö**
- **@U, U → ü/Ü**
- **S, SS → ß** (sharp S)
- **CE → €** (Euro symbol)

### OS-Aware Functions
Custom keycodes that automatically adapt to current base layer:
- **OS_UNDO:** Cmd+Z (macOS) / Ctrl+Z (Windows)
- **OS_COPY:** Cmd+C (macOS) / Ctrl+C (Windows)
- **OS_PASTE:** Cmd+V (macOS) / Ctrl+V (Windows)
- **OS_CUT:** Cmd+X (macOS) / Ctrl+X (Windows)

### LED Indicators
- **Layer 0 (MAC_BASE):** Blue theme (HSV: 139,78,233)
- **Layer 1 (WIN_BASE):** Cyan theme (HSV: 139,237,161)
- **Layer 5 (CONFIG):** Red/Green theme
- **Other layers:** LEDs off (transparent)

---

## Architecture Principles

### Layer Consolidation (from 10 → 6 → 7 layers)
1. **Separated base layers by OS** (macOS vs Windows)
2. **Unified utility layers** (Symbols, Function, Numbers, Config)
3. **Shared access patterns** (OSL/LT work from both bases)
4. **OS-aware operations** (clipboard functions auto-detect base layer)
5. **Purpose-driven additions** (Mouse layer added for hardware mouse control)

### Code Efficiency
- **Home row mods:** Using QMK's MT() instead of custom dual-functions
- **Removed tap dances:** All 17 tap dances eliminated (538 lines deleted)
- **Built-in features:** Mouse layer uses QMK MOUSEKEY module (no custom implementation)
- **Code reduction:** 67.4% reduction from original 10-layer design
- **Firmware target:** <230KB (90% of 256KB flash capacity)

### Mouse Layer Design (003-mouse-layer)
- **QMK MOUSEKEY module:** Built-in feature, ~7KB firmware impact
- **Arrow-key layout:** Intuitive cursor movement on right hand
- **One-handed operation:** All buttons on left hand for accessibility
- **Speed control:** 3 modes (precision/normal/fast) for different tasks
- **Scroll wheel:** Vertical and horizontal scrolling support
- **OS-agnostic:** Works identically on macOS, Windows, and Linux

### German Language Support
- **Native umlauts:** Ä, Ö, Ü, ß accessible via Function layer
- **Leader key shortcuts:** Quick access to German characters
- **Layout:** Uses `keymap_german.h` (DE_* keycodes)
- **Euro symbol:** Accessible via Leader or Function layer

---

## Layer Access Summary

| From Layer | Symbol (L2) | Function (L3) | Numbers (L4) | Config (L5) | Mouse (L6) | Mac Base (L0) | Win Base (L1) |
|------------|-------------|---------------|--------------|-------------|------------|---------------|---------------|
| **MAC_BASE (L0)** | OSL (thumb) | OSL (thumb) | LT Space (thumb) | TO (top-right) | MO (bottom-left) | - | TO (from config) |
| **WIN_BASE (L1)** | OSL (thumb) | OSL (thumb) | LT Space (thumb) | TO (top-right) | MO (bottom-left) | TO (from config) | - |
| **All Others** | - | - | - | - | - | TO (from config) | TO (from config) |

**Legend:**
- **OSL:** One-Shot Layer (tap to activate for next keypress)
- **LT:** Layer-Tap (hold for layer, tap for key)
- **TO:** Permanent layer switch until another TO is pressed
- **MO:** Momentary layer (active while key held, returns on release)

---

## Metrics

| Metric | Value |
|--------|-------|
| **Total Layers** | 7 (6-layer base + mouse layer) |
| **Total Keys** | 52 (26 per side) |
| **Home Row Mods** | 6 per side (12 total) |
| **Code Lines** | ~380 (includes mouse layer) |
| **Tap Dances** | 0 (removed all 17) |
| **Custom Keycodes** | 12 (4 RGB + 8 OS-aware operations) |
| **Key Overrides** | 2 |
| **Combos** | 4 |
| **Leader Sequences** | 9 |
| **Firmware Target** | <230KB (90% of 256KB flash) |
| **MOUSEKEY Features** | Cursor control, 3 buttons, scroll wheel, 3 speed modes |

---

*Generated for 003-mouse-layer feature implementation*  
*ZSA Voyager • QMK Firmware • HIEA O / DTRNS Layout*
