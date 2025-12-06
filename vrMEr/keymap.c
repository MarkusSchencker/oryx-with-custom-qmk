#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

// Keep the upstream custom keycode block untouched so merges stay trivial.
enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  HSV_0_255_255,
  HSV_74_255_255,
  HSV_169_255_255,
};

// Project-specific layers, keymaps, combos, and hooks live in this include so
// the upstream skeleton can evolve without merge conflicts.
#include "custom_layout.inc"
