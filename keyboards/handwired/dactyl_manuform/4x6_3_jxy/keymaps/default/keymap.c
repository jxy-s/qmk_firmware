#include QMK_KEYBOARD_H

#define LS(KC) LSFT_T(KC)
#define RS(KC) RSFT_T(KC)
#define LC(KC) LCTL_T(KC)
#define RC(KC) RCTL_T(KC)
#define LA(KC) LALT_T(KC)
#define RA(KC) RALT_T(KC)

#define L0 0
#define L1 1
#define L2 2

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
    [L0] = LAYOUT(
        KC_GRV,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                     KC_Y,   KC_U,   KC_I,   KC_O,   KC_P, KC_BSLS,
        KC_TAB,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                     KC_H,   KC_J,   KC_K,   KC_L,KC_SCLN, KC_QUOT,
   LC(KC_LPRN),   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,                     KC_N,   KC_M,KC_COMM, KC_DOT,KC_SLSH,RC(KC_RPRN),
                    LA(KC_ESC),KC_RGUI,                                                  KC_LBRC, RA(KC_RBRC),
                                        TT(L1),  KC_SPC,                  KC_SPC, TT(L1),
                                                      LS(KC_DEL),RS(KC_ENT)
    ),

    [L1] = LAYOUT(
        KC_EQL,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,KC_MINS,
        TO(L0), TT(L2),KC_HOME,KC_PGDN,KC_PGUP, KC_END,                  KC_LEFT,  KC_UP,KC_DOWN,KC_RGHT, TT(L2),  TO(L0),
   LC(KC_PLUS),KC_EXLM,  KC_AT,KC_HASH, KC_DLR,KC_PERC,                  KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,RC(KC_UNDS),
                       _______,_______,                                                  KC_COPY,RA(KC_PSTE),
                                       _______,_______,                  _______,_______,
                                                        _______,_______
    ),

    [L0] = LAYOUT(
         KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,                    KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11, KC_F12,
       _______,_______,_______,_______,_______,_______,                  _______,_______,_______,_______,_______,_______,
       KC_LCTL,KC_NLCK,KC_SLCK,KC_CAPS,KC_PAUS, KC_INS,                  KC_PSCR,_______,_______,_______,_______,KC_RCTL,
                       _______,_______,                                                   KC_CUT,_______,
                                       _______,_______,                  _______,_______,
                                                        _______,_______
    )
};

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}
