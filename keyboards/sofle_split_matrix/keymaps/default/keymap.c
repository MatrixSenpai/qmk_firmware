/* Copyright 2023 Brian Low
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "leader.c"
#include "ux.c"

#include "animations/music-bars.c"

#define ANIM_INVERT false
#define ANIM_RENDER_WPM true
#define FAST_TYPE_WPM 45

// General aliases
#define MTLGA MT(MOD_LGUI, KC_A)
#define MTLSS MT(MOD_LSFT, KC_S)

// Some aliases for qwerty layout
#define MTRSL MT(MOD_RSFT, KC_L)
#define MTRGC MT(MOD_RGUI, KC_SCLN)

enum KB_LAYERS {
    _QL, // Qwerty Layer
    _AL, // Action Layer
    _GL, // Gaming Layer

    _SM, // Star Citizen Main Layer
    _SA, // Star Citizen Action Layer
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
    [] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,					     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,					     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,					     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        			  	  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    */

    [_QL] = LAYOUT(
        QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,     KC_5,	   				     	 KC_6,	  KC_7,	   KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,   					     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT,
        KC_LCTL, MTLGA,   MTLSS,   KC_D,    KC_F,     KC_G,   					     KC_H,    KC_J,    KC_K,    MTRSL,   MTRGC,   KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,    KC_MUTE,		DF(_SM), KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_EQL,
        			  	  KC_LGUI, KC_LALT, TT(_AL),  QK_LEAD, KC_SPC,		DF(_GL), KC_SPC,  KC_MINS, KC_LBRC, KC_RBRC
    ),
    [_AL] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,	     				     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
        KC_TRNS, KC_F11,  KC_F12,  KC_F13,  KC_F14,   KC_F15,					     KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,					     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_BSLS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        			  	  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,		KC_TRNS, KC_PSCR, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_GL] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,     KC_5,	   				     	 KC_6,	  KC_7,	   KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,   					     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT,
        KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,     KC_G,   					     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,    KC_MUTE,		KC_F12,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_EQL,
        			  	  KC_LGUI, KC_LALT, KC_SPC,   KC_M,    KC_I,  		DF(_QL), KC_SPC,  KC_DOWN, KC_UP,   KC_RGHT
    ),

    [_SM] = LAYOUT(
        QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,     KC_5,	   				     	 KC_6,	  KC_7,	   KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,   					     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT,
        KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,     KC_G,   					     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,   KC_ENT,
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,    KC_MUTE,		KC_PSCR, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_EQL,
        			  	  KC_LGUI, KC_LALT, OSL(_SA), QK_LEAD, KC_SPC,		DF(_QL), KC_SPC,  KC_MINS, KC_RALT, KC_RGUI
    ),
    [_SA] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,	     				     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
        KC_TRNS, KC_F11,  KC_F12,  KC_F13,  KC_F14,   KC_F15,					     KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,					     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_BSLS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        			  	  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,		KC_TRNS, KC_PSCR, KC_TRNS, KC_TRNS, KC_TRNS
    ),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
};
#endif

bool oled_task_user(void) {
    if(is_keyboard_master()) {
        oled_render_anim();
    } else {
        oled_write_P(PSTR("Layer: "), false);

        switch(get_highest_layer(layer_state|default_layer_state)) {
            case _SM:
                oled_write_ln_P(PSTR("SC MAIN"), false);
                break;
            case _SA:
                oled_write_ln_P(PSTR("SC ACTION"), false);
                break;
            case _GL:
                oled_write_ln_P(PSTR("GAMING"), false);
                break;
            case _AL:
                oled_write_ln_P(PSTR("ACTION"), false);
                break;
            default:
                oled_write_ln_P(PSTR("QWERTY"), false);
        }
    }

    return false;
}

layer_state_t g_last_default_layer;

void housekeeping_task_user(void) {
    layer_state_t current_default_layer = layer_state | default_layer_state;

    if(current_default_layer != g_last_default_layer) {
        g_last_default_layer = current_default_layer;

        switch(get_highest_layer(g_last_default_layer)) {
            case _SM:
                rgb_matrix_mode(RGB_MATRIX_PIXEL_FLOW);
                break;
            case _GL:
                rgb_matrix_mode(RGB_MATRIX_PIXEL_RAIN);
                break;
            case _SA:
            case _AL:
                rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
                break;
            default:
                rgb_matrix_mode(RGB_MATRIX_RAINBOW_MOVING_CHEVRON);
        }
    }
}