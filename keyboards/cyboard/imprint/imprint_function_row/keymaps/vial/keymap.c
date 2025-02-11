/* Copyright 2023 Cyboard LLC (@Cyboard-DigitalTailor)
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include QMK_KEYBOARD_H
#include <cyboard.h>

#include "features/achordion.h"

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_achordion(keycode, record)) { return false; }
  // Your macros ...

  return true;
}

void matrix_scan_user(void) {
  achordion_task();
}

uint16_t achordion_streak_chord_timeout(
    uint16_t tap_hold_keycode, uint16_t next_keycode) {
  if (IS_QK_LAYER_TAP(tap_hold_keycode)) {
    return 0;  // Disable streak detection on layer-tap keys.
  }

  // Otherwise, tap_hold_keycode is a mod-tap key.
  uint8_t mod = mod_config(QK_MOD_TAP_GET_MODS(tap_hold_keycode));
  if ((mod & MOD_LSFT) != 0) {
    return 100;  // A shorter streak timeout for Shift mod-tap keys.
  } else {
    return 180;  // A longer timeout otherwise.
  }
}

bool achordion_streak_continue(uint16_t keycode) {
  // If mods other than shift or AltGr are held, don't continue the streak.
  if (get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) return false;
  // This function doesn't get called for holds, so convert to tap keycodes.
  if (IS_QK_MOD_TAP(keycode)) {
    keycode = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
  }
  if (IS_QK_LAYER_TAP(keycode)) {
    keycode = QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);
  }
  // Regular letters and punctuation continue the streak.
  if (keycode >= KC_A && keycode <= KC_Z) return true;
  switch (keycode) {
    case KC_DOT:
    case KC_COMMA:
    case KC_QUOTE:
    case KC_SPACE:
      return true;
  }
  return false;  // All other keys end the streak.
}

/* Some useful mod tap keys, used for homerow mods
 * These follow the format of MT(MOD, KEY), used by achordion
 * For example, MT_A is a mod tap key that sends LCTL when held and A when tapped
 * They are implemented in the CAGS order (Ctrl, Alt, Gui, Shift) for bindings in MacOS
 * You can read more about these homerow mods here: https://precondition.github.io/home-row-mods
 */
#define MT_A MT(MOD_LCTL, KC_A)
#define MT_R MT(MOD_LALT, KC_R)
#define MT_S MT(MOD_LGUI, KC_S)
#define MT_T MT(MOD_LSFT, KC_T)
#define MT_N MT(MOD_RSFT, KC_N)
#define MT_E MT(MOD_RGUI, KC_E)
#define MT_I MT(MOD_RALT, KC_I)
#define MT_O MT(MOD_RCTL, KC_O)

#define L_SCROLL_TOG LEFT_DRAGSCROLL_MODE_TOGGLE
#define R_SCROLL_TOG RIGHT_DRAGSCROLL_MODE_TOGGLE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Base layer
    [0] = LAYOUT_fun(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                 KC_F6,   KC_F7,   KC_F8,  KC_F9,  KC_F10,  KC_F11,
        KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                  KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
        KC_LCTL, MT_A,    MT_R,    MT_S,    MT_T,    KC_G,                                  KC_M,    MT_N,    MT_E,    MT_I,    MT_O,    KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                                  KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                        KC_GRAVE, CW_TOGG, KC_SPC,  KC_TAB, KC_BTN1,              KC_BTN2, KC_ENT,  KC_BSPC,   KC_LBRC, KC_RBRC,
                                           KC_ESC,  MO(1),  _______,              KC_BTN3, MO(1),   KC_DEL
    ),
    // Nav layer
    [1] = LAYOUT_fun(
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                           KC_AGIN, KC_PSTE, KC_COPY, KC_CUT,  KC_UNDO, _______,
        _______, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, _______,                           KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, _______,
        _______, _______, _______, _______, _______, _______,                           _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
                          _______, _______, _______, _______, L_SCROLL_TOG,        R_SCROLL_TOG, _______, _______, _______, _______,
                                            _______, _______, _______,                  _______, _______, _______
    ),
    // Mouse layer
    [2] = LAYOUT_fun(
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______,
                                            _______, _______, _______,         _______, _______, _______
    ),
    // Button layer
    [3] = LAYOUT_fun(
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______,
                                            _______, _______, _______,         _______, _______, _______
    ),
    // Media layer
    [4] = LAYOUT_fun(
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______,
                                            _______, _______, _______,         _______, _______, _______
    ),
    // Num layer
    [5] = LAYOUT_fun(
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
        _______, KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC,                           _______, _______, _______, _______, _______, _______,
        _______, KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,                            _______, KC_RCTL, KC_RALT, KC_RGUI, KC_RSFT, _______,
        _______, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS,                           _______, _______, _______, _______, _______, _______,
                          _______, _______, KC_DOT,  KC_0,    KC_MINS,         _______, _______, _______, _______, _______,
                                            _______, _______, _______,         _______, _______, _______
    ),
    // Sym layer
    [6] = LAYOUT_fun(
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
        _______, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                           _______, _______, _______, _______, _______, _______,
        _______, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                           _______, KC_RCTL, KC_RALT, KC_RGUI, KC_RSFT, _______,
        _______, KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,                           _______, _______, _______, _______, _______, _______,
                          _______, _______, KC_LPRN, KC_RPRN, KC_UNDS,         _______, _______, _______, _______, _______,
                                            _______, _______, _______,         _______, _______, _______
    ),
    // Function layer
    [7] = LAYOUT_fun(
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
        _______, KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR,                           _______, _______, _______, _______, _______, _______,
        _______, KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SCRL,                           _______, KC_RCTL, KC_RALT, KC_RGUI, KC_RSFT, _______,
        _______, KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS,                           _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______,
                                            _______, _______, _______,         _______, _______, _______
    ),
    // Additional feature layer
    [8] = LAYOUT_fun(
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______,
                                            _______, _______, _______,         _______, _______, _______
    ),

    [9] = LAYOUT_fun(
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______,
                                            _______, _______, _______,         _______, _______, _______
    )
};
