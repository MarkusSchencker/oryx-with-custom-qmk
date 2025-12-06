#pragma once

// Layer definitions for the 7-layer architecture used by vrMEr.
enum vrmer_layer_names {
  LAYER_MAC_BASE = 0,    // macOS base layer with Cmd-optimized home row mods
  LAYER_WIN_BASE = 1,    // Windows base layer with Ctrl/Win-optimized home row mods
  LAYER_SYMBOLS = 2,     // Symbols layer (consolidates legacy layers 1 and 6)
  LAYER_FUNCTION = 3,    // Function/navigation layer
  LAYER_NUMBERS = 4,     // Numbers/numpad layer
  LAYER_CONFIG = 5,      // Configuration layer (RGB, layer switching, bootloader)
  LAYER_MOUSE = 6,       // Mouse control layer (cursor movement, buttons, scroll)
};

// Project-specific keycodes continue from the upstream HSV_169_255_255 value.
enum vrmer_custom_keycodes {
  OS_UNDO = HSV_169_255_255 + 1,
  OS_COPY,
  OS_PASTE,
  OS_CUT,
  OS_REDO,
  OS_SELECTALL,
  OS_HOME,
  OS_END,
  OS_PGUP,
  OS_PGDN,
  OS_PREVWORD,
  OS_NEXTWORD,
  SW_MAC,
  SW_WIN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_MAC_BASE] = LAYOUT_voyager(
    LGUI(DE_MINS),  LGUI(KC_0),     LGUI(DE_PLUS),  KC_LEFT_GUI,    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, LSFT(KC_TAB),   KC_TRANSPARENT, KC_TAB,         KC_TRANSPARENT, TO(LAYER_CONFIG),
    KC_TRANSPARENT, KC_P,           KC_U,           QK_REPEAT_KEY,  QK_LEAD,        KC_Q,                                           KC_G,           KC_C,           KC_L,           KC_M,           KC_F,           KC_TRANSPARENT,
    CW_TOGG,        MT(MOD_LCTL, KC_H), MT(MOD_LALT, KC_I), MT(MOD_LGUI, KC_E), MT(MOD_LSFT, KC_A), KC_O,                         KC_D,           MT(MOD_LSFT, KC_T), MT(MOD_LGUI, KC_R), MT(MOD_LALT, KC_N), MT(MOD_LCTL, KC_S), KC_TRANSPARENT,
    KC_TRANSPARENT, KC_K,          DE_Y,           KC_DOT,         DE_DQOT,        KC_X,                                           KC_J,           KC_V,           KC_W,           KC_B,           DE_Z,           KC_TRANSPARENT,
                                                    OSL(LAYER_SYMBOLS), LT(LAYER_MOUSE, KC_RSFT),                                            OSL(LAYER_FUNCTION), LT(LAYER_NUMBERS, KC_SPACE)
  ),

  [LAYER_WIN_BASE] = LAYOUT_voyager(
    LCTL(DE_MINS),  LCTL(KC_0),     LCTL(DE_PLUS),  KC_LEFT_ALT,    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, LSFT(KC_TAB),   KC_TRANSPARENT, KC_TAB,         KC_TRANSPARENT, TO(LAYER_CONFIG),
    KC_TRANSPARENT, KC_P,           KC_U,           QK_REPEAT_KEY,  QK_LEAD,        KC_Q,                                           KC_G,           KC_C,           KC_L,           KC_M,           KC_F,           KC_TRANSPARENT,
    CW_TOGG,        MT(MOD_LGUI, KC_H), MT(MOD_LALT, KC_I), MT(MOD_LCTL, KC_E), MT(MOD_LSFT, KC_A), KC_O,                         KC_D,           MT(MOD_LSFT, KC_T), MT(MOD_LCTL, KC_R), MT(MOD_LALT, KC_N), MT(MOD_LGUI, KC_S), KC_TRANSPARENT,
    KC_TRANSPARENT, KC_K,          DE_Y,           KC_DOT,         DE_DQOT,        KC_X,                                           KC_J,           KC_V,           KC_W,           KC_B,           DE_Z,           KC_TRANSPARENT,
                                                    OSL(LAYER_SYMBOLS), LT(LAYER_MOUSE, KC_RSFT),                                            OSL(LAYER_FUNCTION), LT(LAYER_NUMBERS, KC_SPACE)
  ),

  [LAYER_SYMBOLS] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, DE_SECT,        DE_AMPR,        DE_LBRC,        DE_RBRC,        DE_CIRC,                                        DE_EXLM,        DE_LABK,        DE_RABK,        DE_EQL,         DE_TILD,        KC_TRANSPARENT,
    KC_TRANSPARENT, DE_AT,          DE_SLSH,        DE_LCBR,        DE_RCBR,        DE_ASTR,                                        DE_QUES,        DE_LPRN,        DE_RPRN,        DE_MINS,        DE_COLN,        KC_TRANSPARENT,
    KC_TRANSPARENT, DE_UNDS,        DE_BSLS,        DE_PIPE,        DE_DQOT,        DE_GRV,                                         DE_PLUS,        DE_PERC,        DE_DLR,         DE_HASH,        DE_SCLN,        KC_TRANSPARENT,
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                                 KC_BSPC,        KC_DEL
  ),

  [LAYER_FUNCTION] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_TRANSPARENT,
    KC_F12,         KC_TAB,         DE_UE,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 OS_PREVWORD,    OS_PGUP,        KC_TRANSPARENT,OS_NEXTWORD,    KC_TRANSPARENT, KC_TRANSPARENT,
    KC_F11,         KC_ESCAPE,      DE_SS,          DE_EURO,        MT(MOD_LSFT, DE_AE), DE_OE,                                     KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_ENTER,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, OS_PGDN,        OS_HOME,        OS_END,         KC_TRANSPARENT, KC_TRANSPARENT,
                                                    KC_TRANSPARENT, OSM(MOD_RSFT),                                                  KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [LAYER_NUMBERS] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_PSCR,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, DE_MINS,        KC_7,           KC_8,           KC_9,           DE_ASTR,                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, DE_COLN,        KC_1,           KC_2,           KC_3,           KC_0,                                           OS_UNDO,        OS_COPY,        OS_PASTE,       OS_CUT,         KC_TRANSPARENT, KC_APPLICATION,
    KC_TRANSPARENT, DE_PLUS,        KC_4,           KC_5,           KC_6,           DE_SLSH,                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                    KC_COMMA,       KC_DOT,                                                         KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [LAYER_CONFIG] = LAYOUT_voyager(
    RGB_TOG,        TOGGLE_LAYER_COLOR, RGB_MODE_FORWARD, RGB_SLD,    RGB_VAD,        RGB_VAI,                                        SW_WIN,         KC_TRANSPARENT, SW_MAC,         KC_TRANSPARENT, QK_BOOT,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, RGB_SAD,        RGB_SAI,        RGB_SPD,        RGB_SPI,                                        KC_PAGE_UP,     KC_HOME,        KC_UP,          KC_END,         KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK, KC_MEDIA_STOP, RGB_HUD,    RGB_HUI,                                 KC_PGDN,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, HSV_0_255_255,  HSV_74_255_255, HSV_169_255_255,                                KC_TRANSPARENT, LCTL(LSFT(KC_TAB)), LCTL(KC_TAB), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [LAYER_MOUSE] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TAB,         OS_CUT,         OS_PASTE,       OS_COPY,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_U,        KC_WH_U,        KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_LEFT_SHIFT,  KC_BTN3,        KC_BTN2,        KC_BTN1,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_MS_L,        KC_MS_D,        KC_MS_R,        KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_LEFT_CTRL,   KC_ACL2,        KC_ACL0,        KC_ACL1,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_WH_L,        KC_WH_R,        KC_WH_D,        KC_TRANSPARENT, KC_TRANSPARENT,
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

const key_override_t dot_comma_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COMM);
const key_override_t quote_doublequote_override = ko_make_basic(MOD_MASK_SHIFT, DE_DQOT, DE_QUOT);

const key_override_t *key_overrides[] = {
    &dot_comma_override,
    &quote_doublequote_override,
    NULL
};

const uint16_t PROGMEM combo0[] = { LT(LAYER_MOUSE, KC_RSFT), KC_DOT, COMBO_END };
const uint16_t PROGMEM combo1[] = { LT(LAYER_MOUSE, KC_RSFT), DE_QUOT, COMBO_END };
const uint16_t PROGMEM combo2[] = { LT(LAYER_MOUSE, KC_RSFT), KC_DOT, COMBO_END };
const uint16_t PROGMEM combo3[] = { LT(LAYER_MOUSE, KC_RSFT), DE_QUOT, COMBO_END };

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, KC_COMMA),
    COMBO(combo1, DE_DQOT),
    COMBO(combo2, KC_COMMA),
    COMBO(combo3, DE_DQOT),
};

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {139,78,233}, {139,149,221}, {139,210,188}, {68,239,219}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {68,239,219}, {0,0,0}, {68,239,219}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [1] = { {0,0,0}, {0,0,0}, {0,0,0}, {139,237,161}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {139,237,161}, {0,0,0}, {139,237,161}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [5] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {139,238,159}, {0,0,0}, {68,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },
};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color(i, 0, 0, 0);
    } else {
        RGB rgb = hsv_to_rgb(hsv);
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case LAYER_MAC_BASE:
      set_layer_color(0);
      break;
    case LAYER_WIN_BASE:
      set_layer_color(1);
      break;
    case LAYER_CONFIG:
      set_layer_color(5);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
      rgb_matrix_set_color_all(0, 0, 0);
    }
    break;
  }
  return true;
}

void leader_start_user(void) {
    // Placeholder so leader_end_user has a companion function.
}

void leader_end_user(void) {
 if (leader_sequence_two_keys(LSFT(KC_2), KC_A)) {
        if (get_mods() & MOD_MASK_SHIFT) {
            tap_code16(DE_AE | S(KC_NO));
        } else {
            tap_code16(DE_AE);
        }
    } else if (leader_sequence_two_keys(LSFT(KC_2), KC_O)) {
        if (get_mods() & MOD_MASK_SHIFT) {
            tap_code16(DE_OE | S(KC_NO));
        } else {
            tap_code16(DE_OE);
        }
    } else if (leader_sequence_two_keys(LSFT(KC_2), KC_U)) {
        if (get_mods() & MOD_MASK_SHIFT) {
            tap_code16(DE_UE | S(KC_NO));
        } else {
            tap_code16(DE_UE);
        }
    } else if (leader_sequence_one_key(KC_S)) {
        tap_code16(DE_SS);
   } else if (leader_sequence_one_key(KC_A)) {
        if (get_mods() & MOD_MASK_SHIFT) {
            tap_code16(DE_AE | S(KC_NO));
        } else {
            tap_code16(DE_AE);
        }
   } else if (leader_sequence_one_key(KC_U)) {
        if (get_mods() & MOD_MASK_SHIFT) {
            tap_code16(DE_UE | S(KC_NO));
        } else {
            tap_code16(DE_UE);
        }
   } else if (leader_sequence_one_key(KC_O)) {
        if (get_mods() & MOD_MASK_SHIFT) {
            tap_code16(DE_OE | S(KC_NO));
        } else {
            tap_code16(DE_OE);
        }
   } else if (leader_sequence_two_keys(KC_S, KC_S)) {
      tap_code16(DE_SS);
    } else if (leader_sequence_two_keys(KC_C, KC_E)) {
      tap_code16(DE_EURO);
    }
}

bool is_macos_base(void) {
    return get_highest_layer(default_layer_state) == LAYER_MAC_BASE;
}

typedef struct {
    uint16_t keycode;
    uint8_t row;
    uint8_t col;
} achordion_state_t;

static achordion_state_t achordion_state = {KC_NO, 0, 0};

bool is_left_hand(uint8_t row, uint8_t col) {
    (void)col;
    return row < (MATRIX_ROWS / 2);
}

bool is_home_row_mod(uint16_t keycode) {
    switch (keycode) {
        case MT(MOD_LCTL, KC_H):
        case MT(MOD_LALT, KC_I):
        case MT(MOD_LGUI, KC_E):
        case MT(MOD_LSFT, KC_A):
        case MT(MOD_LSFT, KC_T):
        case MT(MOD_LGUI, KC_R):
        case MT(MOD_LALT, KC_N):
        case MT(MOD_LCTL, KC_S):
        case MT(MOD_LGUI, KC_H):
        case MT(MOD_LCTL, KC_R):
        case MT(MOD_LGUI, KC_S):
            return true;
        default:
            return false;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (is_home_row_mod(keycode)) {
    if (record->event.pressed) {
      achordion_state.keycode = keycode;
      achordion_state.row = record->event.key.row;
      achordion_state.col = record->event.key.col;
    } else if (achordion_state.keycode == keycode) {
      achordion_state.keycode = KC_NO;
    }
  } else if (achordion_state.keycode != KC_NO && record->event.pressed) {
    bool mod_on_left = is_left_hand(achordion_state.row, achordion_state.col);
    bool key_on_left = is_left_hand(record->event.key.row, record->event.key.col);

    if (mod_on_left == key_on_left) {
      achordion_state.keycode = KC_NO;
    }
  }

  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case HSV_0_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,255);
      }
      return false;
    case HSV_74_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(74,255,255);
      }
      return false;
    case HSV_169_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(169,255,255);
      }
      return false;

    case OS_UNDO:
      if (record->event.pressed) {
        tap_code16(is_macos_base() ? LGUI(KC_Z) : LCTL(KC_Z));
      }
      return false;
    case OS_COPY:
      if (record->event.pressed) {
        tap_code16(is_macos_base() ? LGUI(KC_C) : LCTL(KC_C));
      }
      return false;
    case OS_PASTE:
      if (record->event.pressed) {
        tap_code16(is_macos_base() ? LGUI(KC_V) : LCTL(KC_V));
      }
      return false;
    case OS_CUT:
      if (record->event.pressed) {
        tap_code16(is_macos_base() ? LGUI(KC_X) : LCTL(KC_X));
      }
      return false;
    case OS_REDO:
      if (record->event.pressed) {
        tap_code16(is_macos_base() ? LGUI(LSFT(KC_Z)) : LCTL(KC_Y));
      }
      return false;
    case OS_SELECTALL:
      if (record->event.pressed) {
        tap_code16(is_macos_base() ? LGUI(KC_A) : LCTL(KC_A));
      }
      return false;
    case OS_HOME:
      if (record->event.pressed) {
        tap_code16(is_macos_base() ? LGUI(KC_LEFT) : KC_HOME);
      }
      return false;
    case OS_END:
      if (record->event.pressed) {
        tap_code16(is_macos_base() ? LGUI(KC_RIGHT) : KC_END);
      }
      return false;
    case OS_PGUP:
      if (record->event.pressed) {
        tap_code16(KC_PGUP);
      }
      return false;
    case OS_PGDN:
      if (record->event.pressed) {
        tap_code16(KC_PGDN);
      }
      return false;
    case OS_PREVWORD:
      if (record->event.pressed) {
        tap_code16(is_macos_base() ? LALT(KC_LEFT) : LCTL(KC_LEFT));
      }
      return false;
    case OS_NEXTWORD:
      if (record->event.pressed) {
        tap_code16(is_macos_base() ? LALT(KC_RIGHT) : LCTL(KC_RIGHT));
      }
      return false;
    case SW_MAC:
      if (record->event.pressed) {
        default_layer_set(1UL << LAYER_MAC_BASE);
        layer_move(LAYER_MAC_BASE);
      }
      return false;
    case SW_WIN:
      if (record->event.pressed) {
        default_layer_set(1UL << LAYER_WIN_BASE);
        layer_move(LAYER_WIN_BASE);
      }
      return false;
  }
  return true;
}
