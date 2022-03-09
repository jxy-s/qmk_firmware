#include QMK_KEYBOARD_H

#define _COPY RCTL(KC_C)
#define _PSTE RCTL(KC_V)
#define __CUT RCTL(KC_X)
#define _UNDO RCTL(KC_Z)

#define _LS(x) LSFT_T(x)
#define _RS(x) RSFT_T(x)
#define _LC(x) LCTL_T(x)
#define _RC(x) RCTL_T(x)
#define _LA(x) LALT_T(x)
#define _RA(x) RALT_T(x)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base (qwerty)
     * +-----------------------------------------------+                 +-----------------------------------------------+
     * |       |       |       |       |       |       |                 |       |       |       |       |       |       |
     * |-------+-------+-------+-------+-------+-------|                 |-------+-------+-------+-------+-------+-------|
     * |       |       |       |       |       |       |                 |       |       |       |       |       |       |
     * |-------+-------+-------+-------+-------+-------|                 |-------+-------+-------+-------+-------+-------|
     * |       |       |       |       |       |       |                 |       |       |       |       |       |       |
     * |-------+-------+-------+-------+-------+-------|                 |-------+-------+-------+-------+-------+-------|
     * |       |       |       |       |       |       |                 |       |       |       |       |       |       |
     * +-------+-------+-------+-------+-------+-------+                 +-------+-------+-------+-------+-------+-------+
     *                 |       |       |                                                 |       |       |
     *                 +---------------+---------------+                 +---------------+---------------+
     *                                 |       |       |                 |       |       |
     *                                 +-------+-------+                 +---------------+
     *                                                 +-------+ +-------+
     *                                                 |       | |       |
     *                                                 +-------+ +-------+
     */
    [0] = LAYOUT(
        KC_GRV,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                     KC_Y,   KC_U,   KC_I,   KC_O,   KC_P, KC_BSLS,
        KC_TAB,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                     KC_H,   KC_J,   KC_K,   KC_L,KC_SCLN, KC_QUOT,
       KC_LCTL,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,                     KC_N,   KC_M,KC_COMM, KC_DOT,KC_SLSH, KC_RCTL,
                   _LA(KC_ESC),KC_LGUI,                                                  KC_LBRC,_RA(KC_RBRC),
                                         TT(1),KC_BSPC,                   KC_SPC,  TT(1),
                                                    _LS(KC_DEL),_RS(KC_ENT)
    ),

    [1] = LAYOUT(
        KC_EQL,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,KC_MINS,
         TO(0),  TT(2),KC_HOME,KC_PGUP,KC_PGDN, KC_END,                  KC_LEFT, KC_DOWN, KC_UP,KC_RGHT,  TT(2),   TO(0),
       _______,KC_EXLM,  KC_AT,KC_HASH, KC_DLR,KC_PERC,                  KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,_______,
                       _______,_______,                                                    _COPY,  _PSTE,
                                       _______,_______,                  _______,_______,
                                                        _______,_______
    ),

    [2] = LAYOUT(
         KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,                    KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11, KC_F12,
       _______,_______,KC_MS_L,KC_MS_U,KC_MS_D,KC_MS_R,                  _______,_______,_______,_______,_______,_______,
       _______,KC_NLCK,KC_SLCK,KC_BTN1,KC_BTN2,KC_CAPS,                  KC_PSCR,KC_PAUS, KC_INS,_______,_______,_______,
                       _______,_______,                                                    __CUT,  _UNDO,
                                       _______,_______,                  _______,_______,
                                                        _______,_______
    )
};

void persistent_default_layer_set(uint16_t default_layer)
{
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

void keyboard_post_init_user(void)
{
    //debug_enable = true;
    //debug_matrix = true;
    //debug_keyboard = true;
    //debug_mouse = true;
}