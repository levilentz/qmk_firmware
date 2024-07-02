// Copyright 2022 Will Winder (@winder)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

//#  define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_STATIC_GRADIENT+4
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U
// #        define ENABLE_RGB_MATRIX_ALPHAS_MODS
// #        define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
// #        define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
// #        define ENABLE_RGB_MATRIX_BREATHING
// #        define ENABLE_RGB_MATRIX_BAND_SAT
// #        define ENABLE_RGB_MATRIX_BAND_VAL
// #        define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
// #        define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
// #        define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
// #        define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
// #        define ENABLE_RGB_MATRIX_CYCLE_ALL
// #        define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
// #        define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
// #        define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
// #        define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
// #        define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
// #        define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
// #        define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
// #        define ENABLE_RGB_MATRIX_DUAL_BEACON
// #        define ENABLE_RGB_MATRIX_RAINBOW_BEACON
// #        define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
// #        define ENABLE_RGB_MATRIX_RAINDROPS
// #        define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
// #        define ENABLE_RGB_MATRIX_HUE_BREATHING
// #        define ENABLE_RGB_MATRIX_HUE_PENDULUM
// #        define ENABLE_RGB_MATRIX_HUE_WAVE
// #   define ENABLE_RGB_MATRIX_TYPING_HEATMAP
// #        define ENABLE_RGB_MATRIX_DIGITAL_RAIN
// #        define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
// #        define ENABLE_RGB_MATRIX_SOLID_REACTIVE
// #        define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
// #        define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
// #        define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
// #        define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
// #        define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
// #        define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
// #        define ENABLE_RGB_MATRIX_SPLASH
// #        define ENABLE_RGB_MATRIX_MULTISPLASH
// #        define ENABLE_RGB_MATRIX_SOLID_SPLASH
// #        define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
//#define WS2812_LED_COUNT 52
//#define WS2812_DI_PIN GP0

//#define ENABLE_RGB_MATRIX_DIGITAL_RAIN//#define RGB_MATRIX_TYPING_HEATMAP
// #define RGB_MATRIX_DEFAULT_ON true // Sets the default enabled state, if none has been set
// #define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_CYCLE_LEFT_RIGHT
#ifdef OLED_ENABLE
#    define OLED_DISPLAY_128X64
#    define OLED_TIMEOUT 30000
#endif
