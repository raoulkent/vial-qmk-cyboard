/* Copyright 2023 Cyboard LLC (@Cyboard-DigitalTailor)
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_dactyl_function_row(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,                                         KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,     KC_5,                                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,                                          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,     KC_G,                                          KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,   KC_LALT, KC_LGUI,    KC_RALT,  KC_ESC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                 KC_CAPS, KC_LALT, KC_LEFT, KC_RIGHT,                  KC_HOME,    KC_PGUP,                   KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC,
                                                      KC_SPC, KC_BSPC, KC_END,     KC_PGDN,  KC_TAB, KC_ENTER
    ),

    [1] = LAYOUT_dactyl_function_row(
        _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______,                   _______,     _______,                   _______, _______, _______, _______,
                                                     _______, _______, _______,     _______, _______, _______
    ),

    [2] = LAYOUT_dactyl_function_row(
        _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______,                   _______,     _______,                   _______, _______, _______, _______,
                                                     _______, _______, _______,     _______, _______, _______
    ),
    
    [3] = LAYOUT_dactyl_function_row(
        _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______,                   _______,     _______,                   _______, _______, _______, _______,
                                                     _______, _______, _______,     _______, _______, _______
    ),
    
    [4] = LAYOUT_dactyl_function_row(
        _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______,                   _______,     _______,                   _______, _______, _______, _______,
                                                     _______, _______, _______,     _______, _______, _______
    ),
    
    [5] = LAYOUT_dactyl_function_row(
        _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______,                   _______,     _______,                   _______, _______, _______, _______,
                                                     _______, _______, _______,     _______, _______, _______
    ),
    
    [6] = LAYOUT_dactyl_function_row(
        _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______,                   _______,     _______,                   _______, _______, _______, _______,
                                                     _______, _______, _______,     _______, _______, _______
    ),
    
    [7] = LAYOUT_dactyl_function_row(
        _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______,                   _______,     _______,                   _______, _______, _______, _______,
                                                     _______, _______, _______,     _______, _______, _______
    ),
    
    [8] = LAYOUT_dactyl_function_row(
        _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______,                   _______,     _______,                   _______, _______, _______, _______,
                                                     _______, _______, _______,     _______, _______, _______
    ),
    
    [9] = LAYOUT_dactyl_function_row(
        _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______,                   _______,     _______,                   _______, _______, _______, _______,
                                                     _______, _______, _______,     _______, _______, _______
    )
};
