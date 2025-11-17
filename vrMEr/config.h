#define USB_SUSPEND_WAKEUP_DELAY 0
#define USB_POLLING_INTERVAL_MS 10
#define SERIAL_NUMBER "vrMEr/wONV7n"
#define LAYER_STATE_16BIT
#define COMBO_COUNT 4

// Layer optimization timing configuration
// Based on proven values from JRaem (001-minimize-layers)
// Updated for bilateral combinations (achordion) - only activate mods cross-hand
#define TAPPING_TERM 175           // 175ms tap window (can be aggressive with bilateral combinations)
#define ONESHOT_TIMEOUT 5000       // 5000ms timeout for one-shot modifiers (OSM)
#define QUICK_TAP_TERM 100         // Prevent rapid double-taps from triggering modifiers
// PERMISSIVE_HOLD removed - using bilateral combinations instead to prevent same-hand roll issues

#define RGB_MATRIX_STARTUP_SPD 60

#undef ENABLE_RGB_MATRIX_ALPHAS_MODS
#undef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#undef ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#undef ENABLE_RGB_MATRIX_BREATHING
#undef ENABLE_RGB_MATRIX_BAND_SAT
#undef ENABLE_RGB_MATRIX_BAND_VAL
#undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#undef ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#undef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#undef ENABLE_RGB_MATRIX_CYCLE_ALL
#undef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#undef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#undef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#undef ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#undef ENABLE_RGB_MATRIX_DUAL_BEACON
#undef ENABLE_RGB_MATRIX_RAINBOW_BEACON
#undef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#undef ENABLE_RGB_MATRIX_RAINDROPS
#undef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#undef ENABLE_RGB_MATRIX_HUE_BREATHING
#undef ENABLE_RGB_MATRIX_HUE_PENDULUM
#undef ENABLE_RGB_MATRIX_HUE_WAVE
#undef ENABLE_RGB_MATRIX_PIXEL_FRACTAL
#undef ENABLE_RGB_MATRIX_PIXEL_FLOW
#undef ENABLE_RGB_MATRIX_PIXEL_RAIN
#undef ENABLE_RGB_MATRIX_DIGITAL_RAIN
#undef ENABLE_RGB_MATRIX_MULTISPLASH

#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 250
#define LEADER_NO_TIMEOUT

// MOUSEKEY configuration for mouse layer (003-mouse-layer)
// Values optimized for responsive cursor control and smooth scrolling
// Use #ifndef guards to avoid redefinition errors with QMK defaults
#ifndef MOUSEKEY_DELAY
#    define MOUSEKEY_DELAY 0              // No delay before cursor starts moving (instant response)
#endif
#ifndef MOUSEKEY_INTERVAL
#    define MOUSEKEY_INTERVAL 16          // 16ms between movements (60 FPS update rate)
#endif
#ifndef MOUSEKEY_MOVE_DELTA
#    define MOUSEKEY_MOVE_DELTA 8         // Base cursor movement distance (8 pixels per interval)
#endif
#ifndef MOUSEKEY_MAX_SPEED
#    define MOUSEKEY_MAX_SPEED 10         // Maximum speed multiplier (10x base speed)
#endif
#ifndef MOUSEKEY_TIME_TO_MAX
#    define MOUSEKEY_TIME_TO_MAX 30       // Time to reach max speed (30 intervals = 480ms)
#endif
#ifndef MOUSEKEY_WHEEL_DELAY
#    define MOUSEKEY_WHEEL_DELAY 0        // No delay before wheel scrolling starts
#endif
#ifndef MOUSEKEY_WHEEL_INTERVAL
#    define MOUSEKEY_WHEEL_INTERVAL 80    // 80ms between scroll events (slower than cursor)
#endif
#ifndef MOUSEKEY_WHEEL_DELTA
#    define MOUSEKEY_WHEEL_DELTA 1        // Scroll wheel movement per event (1 unit)
#endif
#ifndef MOUSEKEY_WHEEL_MAX_SPEED
#    define MOUSEKEY_WHEEL_MAX_SPEED 8    // Maximum scroll speed (8x base speed)
#endif
#ifndef MOUSEKEY_WHEEL_TIME_TO_MAX
#    define MOUSEKEY_WHEEL_TIME_TO_MAX 40 // Time to reach max scroll speed (40 intervals = 3.2s)
#endif
