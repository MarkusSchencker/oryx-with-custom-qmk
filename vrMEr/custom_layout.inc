#pragma once

// Layer definitions for the 9-layer architecture used by vrMEr.
enum vrmer_layer_names {
  LAYER_MAC_BASE = 0,    // macOS base layer with Cmd-optimized home row mods
  LAYER_WIN_BASE = 1,    // Windows base layer with Ctrl/Win-optimized home row mods
  LAYER_SYMBOLS = 2,     // Symbols layer with shortcut-friendly modifiers
  LAYER_MOVEMENT = 3,    // Movement and navigation layer
  LAYER_NUMBERS = 4,     // Numbers/numpad layer
  LAYER_CONFIG = 5,      // Configuration layer (RGB, layer switching, bootloader)
  LAYER_FUNCTION = 6,    // Function keys and utility keys
  LAYER_MAC_SHORTCUTS = 7, // macOS shortcuts (system, Finder, AeroSpace-style window actions)
  LAYER_WIN_SHORTCUTS = 8, // Windows shortcuts (system, Explorer, window management)
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
  MC_SPOTLIGHT,
  MC_APP_SWITCH,
  MC_MISSION_CTL,
  MC_FORCE_QUIT,
  MC_SCREENSHOT,
  MC_SCREENSHOT_CLIP,
  MC_LOCK_SCREEN,
  MC_EMOJI,
  MC_HIDE_APP,
  FNDR_NEW_WINDOW,
  FNDR_NEW_TAB,
  FNDR_DUPLICATE,
  FNDR_GET_INFO,
  FNDR_RENAME,
  AS_FOCUS_LEFT,
  AS_FOCUS_DOWN,
  AS_FOCUS_UP,
  AS_FOCUS_RIGHT,
  AS_MOVE_LEFT,
  AS_MOVE_DOWN,
  AS_MOVE_UP,
  AS_MOVE_RIGHT,
  AS_WORKSPACE_1,
  AS_WORKSPACE_2,
  AS_WORKSPACE_3,
  AS_WORKSPACE_4,
  AS_FULL_SCREEN,
  AS_FLOAT_TOGGLE,
  WN_TASK_VIEW,
  WN_APP_SWITCH,
  WN_LOCK,
  WN_EMOJI,
  WN_SETTINGS,
  WN_EXPLORER,
  WN_RUN,
  WN_SNAP_LEFT,
  WN_SNAP_RIGHT,
  WN_VDESK_LEFT,
  WN_VDESK_RIGHT,
  WN_VDESK_NEW,
  WN_VDESK_CLOSE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_MAC_BASE] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_U,           QK_REPEAT_KEY,  OSL(LAYER_MAC_SHORTCUTS), KC_Q,                                  KC_G,           KC_C,           KC_L,           KC_M,           KC_TRANSPARENT, KC_TRANSPARENT,
    LGUI(DE_MINS),  KC_P,          MT(MOD_LALT, KC_I), MT(MOD_LGUI, KC_E), MT(MOD_LSFT, KC_A), KC_O,                               KC_D,           MT(MOD_LSFT, KC_T), MT(MOD_LGUI, KC_R), MT(MOD_LALT, KC_N), KC_F,           TO(LAYER_CONFIG),
    KC_TRANSPARENT, MT(MOD_LCTL, KC_H), DE_Y,      KC_DOT,         DE_DQOT,         KC_X,                                           KC_J,           KC_V,           KC_W,           KC_B,           MT(MOD_LCTL, KC_S), KC_TRANSPARENT,
    CW_TOGG,        KC_K,          KC_NO,          KC_NO,          OSL(LAYER_SYMBOLS), OSL(LAYER_MOVEMENT),                          OSL(LAYER_FUNCTION), LT(LAYER_NUMBERS, KC_SPACE), KC_NO, KC_NO, DE_Z,           KC_TRANSPARENT,
                                                    KC_NO,          KC_BSPC,                                                      KC_ENTER,       KC_NO
  ),

  [LAYER_WIN_BASE] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_U,           QK_REPEAT_KEY,  OSL(LAYER_WIN_SHORTCUTS), KC_Q,                                  KC_G,           KC_C,           KC_L,           KC_M,           KC_TRANSPARENT, KC_TRANSPARENT,
    LCTL(DE_MINS),  KC_P,          MT(MOD_LALT, KC_I), MT(MOD_LCTL, KC_E), MT(MOD_LSFT, KC_A), KC_O,                               KC_D,           MT(MOD_LSFT, KC_T), MT(MOD_LCTL, KC_R), MT(MOD_LALT, KC_N), KC_F,           TO(LAYER_CONFIG),
    KC_TRANSPARENT, MT(MOD_LGUI, KC_H), DE_Y,      KC_DOT,         DE_DQOT,         KC_X,                                           KC_J,           KC_V,           KC_W,           KC_B,           MT(MOD_LGUI, KC_S), KC_TRANSPARENT,
    CW_TOGG,        KC_K,          KC_NO,          KC_NO,          OSL(LAYER_SYMBOLS), OSL(LAYER_MOVEMENT),                          OSL(LAYER_FUNCTION), LT(LAYER_NUMBERS, KC_SPACE), KC_NO, KC_NO, DE_Z,           KC_TRANSPARENT,
                                                    KC_NO,          KC_BSPC,                                                      KC_ENTER,       KC_NO
  ),

  [LAYER_SYMBOLS] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, DE_AMPR,        DE_LBRC,        DE_RBRC,        DE_CIRC,                                        DE_EXLM,        DE_LABK,        DE_RABK,        DE_EQL,         KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, DE_SECT,        DE_SLSH,        DE_LCBR,        DE_RCBR,        DE_ASTR,                                        DE_QUES,        DE_LPRN,        DE_RPRN,        DE_MINS,        DE_TILD,        KC_TRANSPARENT,
    KC_TRANSPARENT, DE_AT,          DE_BSLS,        DE_PIPE,        DE_DQOT,        DE_GRV,                                         DE_PLUS,        DE_PERC,        DE_DLR,         DE_HASH,        DE_COLN,        KC_TRANSPARENT,
    KC_TRANSPARENT, DE_UNDS,        KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_BSPC,        KC_DEL,         KC_NO,          KC_NO,          DE_SCLN,        KC_TRANSPARENT,
                                                    KC_NO,          KC_TRANSPARENT,                                                 KC_BSPC,        KC_NO
  ),

  [LAYER_MOVEMENT] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TAB,         OSL(LAYER_MAC_SHORTCUTS), OSL(LAYER_WIN_SHORTCUTS), KC_TRANSPARENT,            OS_PREVWORD,    OS_PGUP,        KC_TRANSPARENT, OS_NEXTWORD,    KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_ESCAPE,      OSM(MOD_LALT),  OSM(MOD_LGUI),  OSM(MOD_LSFT),  KC_TRANSPARENT,                                  KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_UP,          KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, OSM(MOD_LCTL),  OS_COPY,        OS_PASTE,       OS_CUT,         KC_TRANSPARENT,                                  KC_TRANSPARENT, OS_PGDN,        OS_HOME,        OS_END,         KC_RIGHT,       KC_TRANSPARENT,
    KC_TRANSPARENT, OS_UNDO,        KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT,                                  KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT,
                                                    KC_NO,          KC_TRANSPARENT,                                                 KC_TRANSPARENT, KC_NO
  ),

  [LAYER_MAC_SHORTCUTS] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, MC_APP_SWITCH,  MC_MISSION_CTL, MC_FORCE_QUIT, KC_TRANSPARENT,                                 KC_TAB,         KC_SLSH,        KC_COMM,       KC_MINS,       KC_EQL,         KC_TRANSPARENT,
    KC_TRANSPARENT, MC_SPOTLIGHT,   KC_LALT,        KC_LGUI,        KC_LSFT,        FNDR_RENAME,                                    KC_F,           KC_H,           KC_J,          KC_K,          KC_L,           KC_TRANSPARENT,
    KC_TRANSPARENT, KC_LCTL,        MC_SCREENSHOT_CLIP, MC_LOCK_SCREEN, MC_EMOJI, KC_TRANSPARENT,                                  KC_1,           KC_2,           KC_3,          KC_4,          KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, MC_SCREENSHOT,  KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT,
                                                    KC_NO,          KC_TRANSPARENT,                                                 KC_TRANSPARENT, KC_NO
  ),

  [LAYER_NUMBERS] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, OSM(MOD_LSFT),  OSM(MOD_LALT),  OSM(MOD_LGUI),  KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_7,           KC_8,           KC_9,           KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, OSM(MOD_LCTL),  OS_COPY,        OS_PASTE,       OS_CUT,         OS_SELECTALL,                                   KC_0,           KC_1,           KC_2,           KC_3,           KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, OS_UNDO,        OS_PREVWORD,    OS_NEXTWORD,    KC_BSPC,        KC_DEL,                                         KC_TRANSPARENT, KC_4,           KC_5,           KC_6,           KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, OS_REDO,        KC_NO,          KC_NO,          KC_COMMA,       KC_DOT,                                         KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_TRANSPARENT, KC_APPLICATION,
                                                    KC_NO,          KC_DOT,                                                        KC_TRANSPARENT, KC_NO
  ),

  [LAYER_CONFIG] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, RGB_SAD,        RGB_SAI,        RGB_SPD,        RGB_SPI,                                      SW_MAC,         SW_WIN,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    RGB_TOG,        TOGGLE_LAYER_COLOR, KC_MEDIA_NEXT_TRACK, KC_MEDIA_STOP, RGB_HUD, RGB_HUI,                                       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, QK_BOOT,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, HSV_0_255_255, HSV_74_255_255, HSV_169_255_255,                               KC_TRANSPARENT, LCTL(LSFT(KC_TAB)), LCTL(KC_TAB), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_MEDIA_PREV_TRACK, KC_NO,     KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT,
                                                    KC_NO,          KC_TRANSPARENT,                                                 KC_TRANSPARENT, KC_NO
  ),

  [LAYER_FUNCTION] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, DE_UE,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F7,          KC_F8,          KC_F9,          KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, DE_EURO,        DE_AE,          DE_OE,                                           KC_F10,         KC_F1,          KC_F2,          KC_F3,          KC_F11,         KC_F12,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, DE_SS,          KC_TRANSPARENT, KC_TRANSPARENT,                                  KC_TRANSPARENT, KC_F4,          KC_F5,          KC_F6,          KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_TRANSPARENT, OSM(MOD_RSFT),                                  KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT,
                                                    KC_NO,          OSM(MOD_RSFT),                                                  KC_TRANSPARENT, KC_NO
  ),

  [LAYER_WIN_SHORTCUTS] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, WN_APP_SWITCH,  WN_SETTINGS,    WN_RUN,         KC_TRANSPARENT,                                 WN_SNAP_LEFT,   KC_UP,          WN_SNAP_RIGHT,  WN_VDESK_LEFT,  KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, WN_TASK_VIEW,   WN_EMOJI,       WN_LOCK,        KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_LEFT,        KC_DOWN,        KC_RIGHT,       WN_VDESK_NEW,   WN_VDESK_RIGHT, KC_TRANSPARENT,
    KC_TRANSPARENT, WN_EXPLORER,    OS_COPY,        OS_PASTE,       OS_CUT,         OS_SELECTALL,                                   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, WN_VDESK_CLOSE, KC_TRANSPARENT,
    KC_TRANSPARENT, OS_UNDO,        KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT,
                                                    KC_NO,          KC_TRANSPARENT,                                                 KC_TRANSPARENT, KC_NO
  ),
};

const key_override_t dot_comma_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COMM);
const key_override_t quote_doublequote_override = ko_make_basic(MOD_MASK_SHIFT, DE_DQOT, DE_QUOT);

const key_override_t *key_overrides[] = {
    &dot_comma_override,
    &quote_doublequote_override,
    NULL
};

const uint16_t PROGMEM combo0[] = { OSL(LAYER_MOVEMENT), KC_DOT, COMBO_END };
const uint16_t PROGMEM combo1[] = { OSL(LAYER_MOVEMENT), DE_QUOT, COMBO_END };
const uint16_t PROGMEM combo2[] = { OSL(LAYER_MOVEMENT), KC_DOT, COMBO_END };
const uint16_t PROGMEM combo3[] = { OSL(LAYER_MOVEMENT), DE_QUOT, COMBO_END };

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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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

    case MC_SPOTLIGHT:
      if (record->event.pressed) {
        tap_code16(LGUI(KC_SPACE));
      }
      return false;
    case MC_APP_SWITCH:
      if (record->event.pressed) {
        tap_code16(LGUI(KC_TAB));
      }
      return false;
    case MC_MISSION_CTL:
      if (record->event.pressed) {
        tap_code16(LCTL(KC_UP));
      }
      return false;
    case MC_FORCE_QUIT:
      if (record->event.pressed) {
        tap_code16(LGUI(LALT(KC_ESCAPE)));
      }
      return false;
    case MC_SCREENSHOT:
      if (record->event.pressed) {
        tap_code16(LGUI(LSFT(KC_4)));
      }
      return false;
    case MC_SCREENSHOT_CLIP:
      if (record->event.pressed) {
        tap_code16(LCTL(LGUI(LSFT(KC_4))));
      }
      return false;
    case MC_LOCK_SCREEN:
      if (record->event.pressed) {
        tap_code16(LCTL(LGUI(KC_Q)));
      }
      return false;
    case MC_EMOJI:
      if (record->event.pressed) {
        tap_code16(LCTL(LGUI(KC_SPACE)));
      }
      return false;
    case MC_HIDE_APP:
      if (record->event.pressed) {
        tap_code16(LGUI(KC_H));
      }
      return false;

    case FNDR_NEW_WINDOW:
      if (record->event.pressed) {
        tap_code16(LGUI(KC_N));
      }
      return false;
    case FNDR_NEW_TAB:
      if (record->event.pressed) {
        tap_code16(LGUI(KC_T));
      }
      return false;
    case FNDR_DUPLICATE:
      if (record->event.pressed) {
        tap_code16(LGUI(KC_D));
      }
      return false;
    case FNDR_GET_INFO:
      if (record->event.pressed) {
        tap_code16(LGUI(KC_I));
      }
      return false;
    case FNDR_RENAME:
      if (record->event.pressed) {
        tap_code(KC_ENTER);
      }
      return false;

    case AS_FOCUS_LEFT:
      if (record->event.pressed) {
        tap_code16(LALT(KC_H));
      }
      return false;
    case AS_FOCUS_DOWN:
      if (record->event.pressed) {
        tap_code16(LALT(KC_J));
      }
      return false;
    case AS_FOCUS_UP:
      if (record->event.pressed) {
        tap_code16(LALT(KC_K));
      }
      return false;
    case AS_FOCUS_RIGHT:
      if (record->event.pressed) {
        tap_code16(LALT(KC_L));
      }
      return false;
    case AS_MOVE_LEFT:
      if (record->event.pressed) {
        tap_code16(LALT(LSFT(KC_H)));
      }
      return false;
    case AS_MOVE_DOWN:
      if (record->event.pressed) {
        tap_code16(LALT(LSFT(KC_J)));
      }
      return false;
    case AS_MOVE_UP:
      if (record->event.pressed) {
        tap_code16(LALT(LSFT(KC_K)));
      }
      return false;
    case AS_MOVE_RIGHT:
      if (record->event.pressed) {
        tap_code16(LALT(LSFT(KC_L)));
      }
      return false;
    case AS_WORKSPACE_1:
      if (record->event.pressed) {
        tap_code16(LALT(KC_1));
      }
      return false;
    case AS_WORKSPACE_2:
      if (record->event.pressed) {
        tap_code16(LALT(KC_2));
      }
      return false;
    case AS_WORKSPACE_3:
      if (record->event.pressed) {
        tap_code16(LALT(KC_3));
      }
      return false;
    case AS_WORKSPACE_4:
      if (record->event.pressed) {
        tap_code16(LALT(KC_4));
      }
      return false;
    case AS_FULL_SCREEN:
      if (record->event.pressed) {
        tap_code16(LALT(KC_F));
      }
      return false;
    case AS_FLOAT_TOGGLE:
      if (record->event.pressed) {
        tap_code16(LALT(LSFT(KC_F)));
      }
      return false;

    case WN_TASK_VIEW:
      if (record->event.pressed) {
        tap_code16(LGUI(KC_TAB));
      }
      return false;
    case WN_APP_SWITCH:
      if (record->event.pressed) {
        tap_code16(LALT(KC_TAB));
      }
      return false;
    case WN_LOCK:
      if (record->event.pressed) {
        tap_code16(LGUI(KC_L));
      }
      return false;
    case WN_EMOJI:
      if (record->event.pressed) {
        tap_code16(LGUI(KC_DOT));
      }
      return false;
    case WN_SETTINGS:
      if (record->event.pressed) {
        tap_code16(LGUI(KC_I));
      }
      return false;
    case WN_EXPLORER:
      if (record->event.pressed) {
        tap_code16(LGUI(KC_E));
      }
      return false;
    case WN_RUN:
      if (record->event.pressed) {
        tap_code16(LGUI(KC_R));
      }
      return false;
    case WN_SNAP_LEFT:
      if (record->event.pressed) {
        tap_code16(LGUI(KC_LEFT));
      }
      return false;
    case WN_SNAP_RIGHT:
      if (record->event.pressed) {
        tap_code16(LGUI(KC_RIGHT));
      }
      return false;
    case WN_VDESK_LEFT:
      if (record->event.pressed) {
        tap_code16(LGUI(LCTL(KC_LEFT)));
      }
      return false;
    case WN_VDESK_RIGHT:
      if (record->event.pressed) {
        tap_code16(LGUI(LCTL(KC_RIGHT)));
      }
      return false;
    case WN_VDESK_NEW:
      if (record->event.pressed) {
        tap_code16(LGUI(LCTL(KC_D)));
      }
      return false;
    case WN_VDESK_CLOSE:
      if (record->event.pressed) {
        tap_code16(LGUI(LCTL(KC_F4)));
      }
      return false;
  }
  return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Slower tapping term for home row mods to reduce false positives
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
      return 200;  // Longer term for home row mods = fewer false positives
    case LT(LAYER_NUMBERS, KC_SPACE):
      // Make the space/thumb layer-tap more forgiving to reduce missed spaces.
      return 230;
    default:
      return TAPPING_TERM;  // 150ms for everything else
  }
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

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
  // Chordal hold with bilateral filtering:
  // Only activate home row mods when opposite-hand key is pressed
  if (is_home_row_mod(keycode)) {
    // Check if the mod key is on the left hand (rows 0-2)
    bool mod_on_left = record->event.key.row < (MATRIX_ROWS / 2);
    // Check if the interrupting key is on the left hand
    bool interrupting_on_left = record->event.key.row < (MATRIX_ROWS / 2);
    
    // Only activate hold if keys are on opposite hands
    return mod_on_left != interrupting_on_left;
  }
  return false;
}
