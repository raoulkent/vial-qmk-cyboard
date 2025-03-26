/* Copyright 2023 Cyboard LLC (@Cyboard-DigitalTailor)
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include QMK_KEYBOARD_H
#include <cyboard.h>

// #include "keymap_us_international.h"
// #include "sendstring_us_international.h"


//  █████╗  ██████╗██╗  ██╗ ██████╗ ██████╗ ██████╗ ██╗ ██████╗ ███╗   ██╗
// ██╔══██╗██╔════╝██║  ██║██╔═══██╗██╔══██╗██╔══██╗██║██╔═══██╗████╗  ██║
// ███████║██║     ███████║██║   ██║██████╔╝██║  ██║██║██║   ██║██╔██╗ ██║
// ██╔══██║██║     ██╔══██║██║   ██║██╔══██╗██║  ██║██║██║   ██║██║╚██╗██║
// ██║  ██║╚██████╗██║  ██║╚██████╔╝██║  ██║██████╔╝██║╚██████╔╝██║ ╚████║
// ╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═╝╚═════╝ ╚═╝ ╚═════╝ ╚═╝  ╚═══╝

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
    case KC_ENTER:
    case KC_BSPC:
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
//   Left hand homerow mods
#define MT_A    MT(MOD_LCTL, KC_A)
#define MT_R    MT(MOD_LALT, KC_R)
#define MT_S    MT(MOD_LGUI, KC_S)
#define MT_T    MT(MOD_LSFT, KC_T)
//  Right hand homerow mods
#define MT_N    MT(MOD_RSFT, KC_N)
#define MT_E    MT(MOD_RGUI, KC_E)
#define MT_I    MT(MOD_RALT, KC_I)
#define MT_O    MT(MOD_RCTL, KC_O)
//   Left hand thumbcluster
//  Right hand thumbcluster
#define LT_ENT  LT(5, KC_ENTER)
#define LT_BSPC LT(6, KC_BSPC)

/**
 * @file keymap.c
 * @brief Keymap definitions for Swedish Unicode characters on the Cyboard keyboard.
 *
 * This file contains the key definitions for Swedish Unicode characters, including both
 * lowercase and uppercase versions of ä, å, and ö. These definitions are used to map
 * specific keycodes to their corresponding Unicode characters.
 *
 * Key Definitions:
 * - KC_LAE: Unicode character for lowercase ä (U+00E4)
 * - KC_LAA: Unicode character for lowercase å (U+00E5)
 * - KC_LOE: Unicode character for lowercase ö (U+00F6)
 * - KC_UAE: Unicode character for uppercase Ä (U+00C4)
 * - KC_UAA: Unicode character for uppercase Å (U+00C5)
 * - KC_UOE: Unicode character for uppercase Ö (U+00D6)
 *
 * Combined Key Definitions:
 * - KC_AE: Combined key definition for ä (lowercase) and Ä (uppercase)
 * - KC_AA: Combined key definition for å (lowercase) and Å (uppercase)
 * - KC_OE: Combined key definition for ö (lowercase) and Ö (uppercase)
 */
// Swedish Unicode chars
// #define UC_LAE 0x00E4 // ä
// #define UC_LAA 0x00E5 // å
// #define UC_LOE 0x00F6 // ö
// #define UC_UAE 0x00C4 // Ä
// #define UC_UAA 0x00C5 // Å
// #define UC_UOE 0x00D6 // Ö

// #define KC_AE UP(0x00E4, 0x00C4)
// #define KC_AA UP(0x00E5, 0x00C5)
// #define KC_OE UP(0x00F6, 0x00D6)
// #define KC_AE UP(UC_LAE, UC_UAE)
// #define KC_AA UP(UC_LAA, UC_UAA)
// #define KC_OE UP(UC_LOE, UC_UOE)

// enum unicode_names {
//     UC_AE_LOWER,
//     UC_AA_LOWER,
//     UC_OE_LOWER,
//     UC_AE_UPPER,
//     UC_AA_UPPER,
//     UC_OE_UPPER,
// };

// const uint32_t unicode_map[] PROGMEM = {
//   [UC_AE_LOWER]     = 0x00e4, // ä
//   [UC_AA_LOWER]     = 0x00e5, // å
//   [UC_OE_LOWER]     = 0x00f6, // ö
//   [UC_AE_UPPER]     = 0x00c4, // Ä
//   [UC_AA_UPPER]     = 0x00c5, // Å
//   [UC_OE_UPPER]     = 0x00d6, // Ö
// };

// #define KC_AE UP(UC_AE_LOWER, UC_AE_UPPER)
// #define KC_AA UP(UC_AA_LOWER, UC_AA_UPPER)
// #define KC_OE UP(UC_OE_LOWER, UC_OE_UPPER)


// ███╗   ███╗ ██████╗ ██╗   ██╗███████╗███████╗    ███████╗ ██████╗██████╗  ██████╗ ██╗     ██╗         ████████╗ ██████╗  ██████╗  ██████╗ ██╗     ███████╗
// ████╗ ████║██╔═══██╗██║   ██║██╔════╝██╔════╝    ██╔════╝██╔════╝██╔══██╗██╔═══██╗██║     ██║         ╚══██╔══╝██╔═══██╗██╔════╝ ██╔════╝ ██║     ██╔════╝
// ██╔████╔██║██║   ██║██║   ██║███████╗█████╗      ███████╗██║     ██████╔╝██║   ██║██║     ██║            ██║   ██║   ██║██║  ███╗██║  ███╗██║     █████╗
// ██║╚██╔╝██║██║   ██║██║   ██║╚════██║██╔══╝      ╚════██║██║     ██╔══██╗██║   ██║██║     ██║            ██║   ██║   ██║██║   ██║██║   ██║██║     ██╔══╝
// ██║ ╚═╝ ██║╚██████╔╝╚██████╔╝███████║███████╗    ███████║╚██████╗██║  ██║╚██████╔╝███████╗███████╗       ██║   ╚██████╔╝╚██████╔╝╚██████╔╝███████╗███████╗
// ╚═╝     ╚═╝ ╚═════╝  ╚═════╝ ╚══════╝╚══════╝    ╚══════╝ ╚═════╝╚═╝  ╚═╝ ╚═════╝ ╚══════╝╚══════╝       ╚═╝    ╚═════╝  ╚═════╝  ╚═════╝ ╚══════╝╚══════╝

#define L_SCROLL_TOG LEFT_DRAGSCROLL_MODE_TOGGLE
#define R_SCROLL_TOG RIGHT_DRAGSCROLL_MODE_TOGGLE


//  ██████╗ █████╗ ██████╗ ███████╗██╗    ██╗ ██████╗ ██████╗ ██████╗
// ██╔════╝██╔══██╗██╔══██╗██╔════╝██║    ██║██╔═══██╗██╔══██╗██╔══██╗
// ██║     ███████║██████╔╝███████╗██║ █╗ ██║██║   ██║██████╔╝██║  ██║
// ██║     ██╔══██║██╔═══╝ ╚════██║██║███╗██║██║   ██║██╔══██╗██║  ██║
// ╚██████╗██║  ██║██║     ███████║╚███╔███╔╝╚██████╔╝██║  ██║██████╔╝
//  ╚═════╝╚═╝  ╚═╝╚═╝     ╚══════╝ ╚══╝╚══╝  ╚═════╝ ╚═╝  ╚═╝╚═════╝about:blank#blocked

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

// ██╗  ██╗███████╗██╗   ██╗    ███╗   ███╗ █████╗ ██████╗
// ██║ ██╔╝██╔════╝╚██╗ ██╔╝    ████╗ ████║██╔══██╗██╔══██╗
// █████╔╝ █████╗   ╚████╔╝     ██╔████╔██║███████║██████╔╝
// ██╔═██╗ ██╔══╝    ╚██╔╝      ██║╚██╔╝██║██╔══██║██╔═══╝
// ██║  ██╗███████╗   ██║       ██║ ╚═╝ ██║██║  ██║██║
// ╚═╝  ╚═╝╚══════╝   ╚═╝       ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Base layer
    [0] = LAYOUT_fun(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                 KC_F6,   KC_F7,   KC_F8,  KC_F9,  KC_F10,  KC_F11,
        KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                  KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
        KC_LCTL, MT_A,    MT_R,    MT_S,    MT_T,    KC_G,                                  KC_M,    MT_N,    MT_E,    MT_I,    MT_O,    KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                                  KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                        KC_GRAVE, CW_TOGG, KC_SPC,  KC_TAB, KC_BTN3,              KC_BTN1, LT_ENT,  LT_BSPC,  KC_LBRC, KC_RBRC,
                                           KC_ESC,  MO(1),  _______,              KC_BTN2, MO(1),   KC_DEL
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
        KC_GRV , KC_LBRC, KC_LPRN, KC_RPRN, KC_RBRC, KC_DOT ,                           _______, _______, _______, _______, _______, _______,
        KC_EXLM, KC_COMM, KC_LCBR, KC_RCBR, KC_SCLN, KC_QUES,                           KC_GRV , _______, _______, _______, _______, _______,
        KC_HASH, KC_CIRC, KC_EQL,  KC_UNDS, KC_DLR , KC_ASTR,                           KC_DQT , KC_RCTL, KC_RALT, KC_RGUI, KC_RSFT, _______,
        KC_TILD, KC_LABK, KC_PIPE, KC_MINS, KC_RABK, KC_SLSH,                           KC_QUOT, _______, _______, _______, _______, _______,
                          KC_AMPR, KC_PLUS, KC_BSLS, KC_DOT , KC_ASTR,         _______, _______, _______, _______, _______,
                                            KC_PERC, KC_COLN, KC_AT  ,         _______, _______, _______
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
