// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
  COLEMAK,
  QWERTY,
  NAV,
  SYMBOLS,
  NUMBERS
};

enum {
  TD_QWERTY = 0,
  TD_COLEMAK,
  TD_Z,
  TD_CTRL
};

tap_dance_action_t tap_dance_actions[]  = {
  [TD_QWERTY] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_Q, COLEMAK),
  [TD_COLEMAK] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_Q, QWERTY),
  [TD_Z] = ACTION_TAP_DANCE_DOUBLE(KC_Z, KC_LSFT),
  [TD_CTRL] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_ESC)
};

enum custom_keycodes {
    DRAG_SCROLL = SAFE_RANGE,
};

bool set_scrolling = false;

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (set_scrolling) {
        mouse_report.h = mouse_report.x;
        mouse_report.v = mouse_report.y;
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == DRAG_SCROLL && record->event.pressed) {
        set_scrolling = !set_scrolling;
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [COLEMAK] = LAYOUT_split(
        TD(TD_QWERTY),    KC_W,    KC_F,    KC_P,    KC_B,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,
        KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                               KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
        TD(TD_Z),    KC_X,    KC_C,    KC_D,    KC_V,                               KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
                                     TD(TD_CTRL), LT(SYMBOLS, KC_TAB), LT(NUMBERS, KC_SPC),          KC_BSPC, LT(NAV, KC_ENT), KC_SCLN, KC_EQL,                 
                                     KC_LSFT, KC_BTN2, KC_BTN1
    ),
    [QWERTY] = LAYOUT_split(
        TD(TD_COLEMAK),    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                                            KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [NAV] = LAYOUT_split(
        KC_AGIN, KC_PSTE, KC_COPY, KC_CUT, KC_UNDO,                              KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_CAPS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,                               KC_LCTL, KC_LALT, KC_DEL, KC_NO, KC_NO,
        KC_INS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,                               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                            KC_TRNS, KC_TRNS, KC_TRNS,           KC_NO,  KC_NO,  KC_NO, KC_NO,
                                            KC_DEL, KC_BSPC, KC_ENT
    ),
    [SYMBOLS] = LAYOUT_split(
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                               KC_LCBR, LSFT(KC_7), LSFT(KC_8), LSFT(KC_0), KC_RCBR,
        KC_NO,    KC_LGUI, KC_LALT, KC_LCTL, KC_DEL,                                 LSFT(KC_SCLN), LSFT(KC_4), LSFT(KC_5), LSFT(KC_6), LSFT(KC_EQL),
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                               LSFT(KC_GRV), LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_BSLS),
                                            KC_TRNS, KC_TRNS, KC_TRNS,               KC_UNDS, KC_LPRN, KC_RPRN, KC_TRNS,
                                            KC_NO, KC_NO, KC_NO
    ),
    [NUMBERS] = LAYOUT_split(
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                               KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC,
        KC_NO,    KC_LGUI,    KC_LCTL,    KC_LALT,    KC_DEL,                        KC_SCLN, KC_4, KC_5, KC_6, KC_EQL,
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                               KC_GRV, KC_1, KC_2, KC_3, KC_BSLS,
                                            KC_TRNS, KC_TRNS, KC_TRNS,           KC_MINS, KC_0, KC_DOT, KC_NO,
                                            KC_NO, KC_NO, KC_NO
    )        
};
