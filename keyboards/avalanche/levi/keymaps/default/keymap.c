// Copyright 2022 Viatly Volkov (@vlkv)
// SPDX-License-Identifier: GPL-2.0-or-later

/*
qmk compile -kb avalanche/v4 -km default
qmk flash -kb avalanche/v4 -km default
*/

#include QMK_KEYBOARD_H

// Left-hand home row mods, colemak
#define HOME_A LGUI_T(KC_A)
#define HOME_R LALT_T(KC_R)
#define HOME_S LCTL_T(KC_S)
#define HOME_T LSFT_T(KC_T)

// Right-hand home row mods, colemak
#define HOME_N RSFT_T(KC_N)
#define HOME_E RCTL_T(KC_E)
#define HOME_I LALT_T(KC_I)
#define HOME_O RGUI_T(KC_O)

enum layer {
    COLEMAK,
    QWERTY,
    NAV,
    SYMBOLS,
    NUMBERS
};

enum {
  TD_NAV = 0,
  TD_SYMBOLS,
  TD_NUMBERS,
  TD_COLEMAK,
  TD_QWERTY
};

tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_NAV]  = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_ENT, NUMBERS),
  [TD_SYMBOLS]  = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_TAB, SYMBOLS),
  [TD_NUMBERS]  = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_SPC, NUMBERS),
  [TD_COLEMAK] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_GRV, COLEMAK),
  [TD_QWERTY] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_GRV, QWERTY)
// Other declarations would go here, separated by commas, if you have them
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[COLEMAK] = LAYOUT(
TD(TD_COLEMAK), KC_Q, KC_W, KC_F, KC_P, KC_B,		                        KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_MINS,
KC_ESC, KC_LALT, HOME_A, HOME_R, HOME_S, HOME_T,    KC_G,               KC_M,    HOME_N, HOME_E, HOME_I, HOME_O, KC_QUOT, KC_EQL,
KC_LSFT, KC_Z, KC_X, KC_C, KC_D, KC_V, KC_DEL, KC_LGUI,		 KC_INS, KC_HOME, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_BSLS,
KC_LBRC, KC_LPRN, KC_LCTL, LT(SYMBOLS, KC_TAB), LT(NUMBERS, KC_SPC),		 KC_BSPC, LT(NAV, KC_ENT), KC_TILD, KC_RPRN, KC_RBRC
),
[QWERTY] = LAYOUT(
        TD(TD_COLEMAK), KC_Q, KC_W, KC_E, KC_R, KC_T,		                                  KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS,
KC_ESC, KC_LALT, KC_A, KC_S, KC_D, KC_F, KC_G,		                                  KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_EQL,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_DEL, KC_LGUI,		 KC_INS, KC_HOME, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_BSLS,
                     KC_LBRC, KC_LPRN, KC_LCTL, LT(SYMBOLS, KC_TAB), LT(NUMBERS, KC_SPC),		 KC_BSPC, LT(NAV, KC_ENT), KC_TILD, KC_RPRN, KC_RBRC
),
[NAV] = LAYOUT(
       KC_NO, KC_AGIN, KC_PSTE, KC_COPY, KC_CUT, KC_UNDO,		                      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
TO(QWERTY), KC_NO, KC_CAPS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,		                       KC_LCTL, KC_LALT, KC_DEL, KC_NO, KC_NO, KC_NO, TO(COLEMAK),
       KC_NO, KC_INS, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_NO, KC_NO,		 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                              KC_NO, KC_NO, KC_DEL, KC_BSPC, KC_ENT,		 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
),
[SYMBOLS] = LAYOUT(
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,		                    KC_LCBR, LSFT(KC_7), LSFT(KC_8), LSFT(KC_0), KC_RCBR, KC_NO,
TO(QWERTY), KC_NO, KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_DEL,		        LSFT(KC_SCLN), LSFT(KC_4), LSFT(KC_5), LSFT(KC_6), LSFT(KC_EQL), KC_NO, TO(COLEMAK),
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,		 KC_NO, KC_NO, LSFT(KC_GRV), LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_BSLS), KC_NO,
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,		 KC_UNDS, KC_LPRN, KC_RPRN, KC_NO, KC_NO
),
[NUMBERS] = LAYOUT(
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,		                            KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC, KC_NO,
TO(QWERTY), KC_NO, KC_NO, KC_LGUI, KC_LCTL, KC_LALT, KC_DEL,		        KC_SCLN, KC_4, KC_5, KC_6, KC_EQL, KC_NO, TO(COLEMAK),
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,		 KC_NO, KC_NO, KC_GRV, KC_1, KC_2, KC_3, KC_BSLS, KC_NO,
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,		 KC_MINS, KC_0, KC_DOT, KC_NO, KC_NO
),
};


