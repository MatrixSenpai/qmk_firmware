// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_names {
    _QL, // QWERTY Layer
    _WL, // Workman Layer
    _SL, // Symbol Layer
    _GL, // Gaming Layer
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QL] = LAYOUT(
        QK_GESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                                                KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_NO,                                             KC_MUTE, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LGUI, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_NO,   KC_NO,   DF(_WL),       DF(_GL), KC_NO,   KC_NO,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                                              MO(_SL), QK_LEAD, KC_ENT,        KC_COMM, KC_SPC,  KC_TAB
    ),
    [_WL] = LAYOUT(
        QK_GESC, KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,                                                                KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN, KC_NO,
        KC_LCTL, KC_A,    KC_S,    KC_H,    KC_T,    KC_G,    KC_MUTE,                                           KC_MUTE, KC_Y,    KC_N,    KC_E,    KC_O,    KC_I,    KC_QUOT,
        KC_LGUI, KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,    KC_NO,   KC_NO,   DF(_QL),       DF(_GL), KC_NO,   KC_NO,   KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                                              MO(_SL), QK_LEAD, KC_ENT,        KC_COMM, KC_SPC,  KC_TAB
    ),
    [_SL] = LAYOUT(
        KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                                                KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
        KC_LALT, KC_LBRC, KC_RBRC, KC_MINS, KC_EQL,  KC_TRNS, KC_TRNS,                                           KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,  KC_TRNS,
        KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_LALT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                              KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_GL] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_Q,    KC_E,    KC_R,    KC_TRNS,                                                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_A,    KC_S,    KC_W,    KC_D,    KC_F,    KC_TRNS,                                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DF(_QL),       DF(_WL), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                              KC_TAB,  KC_SPC,  KC_LALT,       KC_TRNS, KC_TRNS, KC_TRNS
    )
};

/*
    [] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                              KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS
    )
*/

void leader_end_user(void) {
    if(leader_sequence_one_key(KC_Y)) {
        SEND_STRING(SS_LCTL("c"));
    } else if(leader_sequence_one_key(KC_P)) {
        SEND_STRING(SS_LCTL("v"));
    } else if(leader_sequence_one_key(KC_S)) {
        SEND_STRING(SS_LCTL("s"));
    }
}

void keyboard_post_init_user(void) {
    rgblight_sethsv_noeeprom(234, 128, 50);
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    switch(get_highest_layer(state)) {
        case _QL:
            rgblight_sethsv_noeeprom(234, 128, 50);
            break;
        case _WL:
            rgblight_sethsv_noeeprom(0, 255, 50);
            break;
        default:
            break;
    }

    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch(get_highest_layer(state|default_layer_state)) {
        case _QL:
            rgblight_sethsv_noeeprom(234, 128, 50);
            break;
        case _WL:
            rgblight_sethsv_noeeprom(0, 255, 50);
            break;
        case _SL:
            rgblight_sethsv_noeeprom(85, 255, 50);
            break;
        default:
            break;
    }

    return state;
}