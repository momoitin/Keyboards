/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "alpine65.h"

enum nk65_layers{
    _BL, // Base Layer
    _ML, // Media Layer
    _FL, // Function Layer
    _CL, // Control Layer
    _RL  // Reset Layer
};

#define KC_CSE LCTL(LSA(KC_ESC))        // ctrl + shift + escape
#define KC_CAD LCTL(LSFT(KC_DEL))       // ctrl + alt + delete
#define KC_WSS LWIN(LSFT(KC_S))         // windows + shift + s
#define KC_DIS LSFT(KC_GRV)             // shift + ~ to open discord
#define KC_TER LCTL(KC_GRV)             // ctrl + ` to open terminal in VS code
#define KC_VID LWIN(LCTL(LSFT(KC_B)))   // win + ctrl + shift + B to reset graphics drivers

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [_BL] = LAYOUT(
	KC_ESC ,  KC_1  , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSPC,
    KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
    MO(_FL), KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, KC_ENT          , KC_PGDN,
    KC_LSFT,          KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT, KC_UP  , MO(_CL),
    KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC ,                   KC_RALT, MO(_ML), MO(_RL), KC_LEFT, KC_DOWN, KC_RGHT ),

    [_ML] = LAYOUT(
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
	_______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLU, _______,
	_______, _______, _______,                            _______,                   _______, _______, _______, _______, KC_VOLD, _______ ),

   [_FL] = LAYOUT(
	KC_GRV ,  KC_F1 , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_DEL ,
	_______, _______, _______, _______, _______, KC_TER , _______, _______, _______, _______, _______, _______, _______, _______, _______,
	_______, _______, KC_WSS , KC_DIS , _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
	_______,          _______, _______, _______, _______, KC_VID , _______, _______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______,                            _______,                   _______, _______, _______, KC_HOME, _______, KC_END  ),

   [_CL] = LAYOUT(
	_______, _______, _______, _______, _______, _______, _______, KC_7   , KC_8   , KC_9   , _______, _______, _______, _______,
	_______, RGB_TOG, _______, _______, _______, _______, _______, KC_4   , KC_5   , KC_6   , _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, KC_1   , KC_2   , KC_3   , _______, _______, _______,          _______,
	_______,          _______, _______, _______, _______, _______, KC_0   , _______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______,                            _______,                   _______, _______, _______, _______, _______, _______ ),

   [_RL] = LAYOUT(
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, RESET  , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
	_______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______,                            _______,                   _______, _______, _______, _______, _______, _______ ),
};

void matrix_init_user(void) {
  //user initialization
}

void matrix_scan_user(void) {
  //user matrix
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

#ifdef RGBLIGHT_ENABLE
//Initalize the keyboard with RGB on with all leds turned off
void keyboard_post_init_user(void)
{
    rgblight_setrgb(0, 0, 0);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _BL:
            rgblight_setrgb(0, 0, 0);
            break;

        case _ML:
            rgblight_setrgb_at(0, 255, 255, 62);
            break;

        case _FL:
            rgblight_setrgb_at(0, 0, 255, 29);
            // rgblight_setrgb_at(0, 0, 255, 62);
            break;

        case _CL:
            rgblight_setrgb_at(0, 255, 0, 43);
            break;

        case _RL:
            rgblight_setrgb_at(255, 0, 0, 63);
            break;
    }
    return state;
}
#endif
