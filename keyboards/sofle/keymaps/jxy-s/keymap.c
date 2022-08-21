#include QMK_KEYBOARD_H

/*
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */ 

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{

[0] = LAYOUT(
   KC_EQL,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                      KC_6,   KC_7,   KC_8,   KC_9,   KC_0,KC_MINS,
   KC_ESC,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                      KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,KC_BSLS,
   KC_TAB,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                      KC_H,   KC_J,   KC_K,   KC_L,KC_SCLN,KC_QUOT,
  KC_LCTL,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,KC_MUTE,   KC_HOME,   KC_N,   KC_M,KC_COMM, KC_DOT,KC_SLSH,KC_RCTL,

    LALT_T(KC_GRV),KC_LGUI, MO(1),LSFT_T(KC_DEL),KC_BSPC,     KC_SPC,RSFT_T(KC_ENT), MO(1), KC_LBRC,RALT_T(KC_RBRC)
),

[1] = LAYOUT(
    KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,                     KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11, KC_F12,
   KC_EQL,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                      KC_6,   KC_7,   KC_8,   KC_9,   KC_0,KC_MINS,
  _______,  MO(2),KC_HOME,KC_PGUP,KC_PGDN, KC_END,                   KC_LEFT, KC_DOWN, KC_UP,KC_RGHT,  MO(2),_______,
  _______,KC_EXLM,  KC_AT,KC_HASH, KC_DLR,KC_PERC,_______,   _______,KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,_______,

                  _______,_______,_______,_______,_______,   _______,_______,_______,RCTL(KC_C),RCTL(KC_V)
),

[2] = LAYOUT(
  _______,_______,_______,_______,_______,_______,                   _______,_______,_______,_______,_______,_______,
    KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,                     KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11, KC_F12,
  _______,_______,KC_MS_L,KC_MS_U,KC_MS_D,KC_MS_R,                   _______,_______,_______,_______,_______,_______,
  _______,KC_NLCK,KC_SLCK,KC_BTN1,KC_BTN2,KC_CAPS,_______,   _______,KC_PSCR,KC_PAUS, KC_INS,_______,_______,_______,

                  _______,_______,_______,_______,_______,   _______,_______,_______,RCTL(KC_X),RCTL(KC_Z)
),
};

#ifdef OLED_ENABLE

static void render_logo(void)
{
    static const char PROGMEM qmk_logo[] =
    {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void)
{
    oled_write_P(PSTR("\n\n"), false);

    oled_write_P(PSTR("LYR:"), false);
    switch (get_highest_layer(layer_state))
    {
        case 0:
        {
            oled_write_P(PSTR("0"), false);
            break;
        }
        case 1:
        {
            oled_write_P(PSTR("1"), false);
            break;
        }
        case 2:
        {
            oled_write_P(PSTR("2"), false);
            break;
        }
        default:
        {
            oled_write_P(PSTR("?"), false);
            break;
        }
    }

    oled_write_P(PSTR("\n\n"), false);

    led_t led_usb_state = host_keyboard_led_state();
    oled_write_P(PSTR("NUMLK\n"), led_usb_state.num_lock);
    oled_write_P(PSTR("CPSLK\n"), led_usb_state.caps_lock);
    oled_write_P(PSTR("SCRLK\n"), led_usb_state.scroll_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation)
{
    return (is_keyboard_master() ? OLED_ROTATION_270 : rotation);
}

bool oled_task_user(void)
{
    if (is_keyboard_master())
    {
        print_status_narrow();
    }
    else
    {
        render_logo();
    }

    return false;
}

#endif

#ifdef ENCODER_ENABLE

uint16_t encoder_tabbing_timeout_ms = 0;
uint16_t encoder_tabbing_timer = 0;

uint16_t activate_encoder_tabbing(void)
{
    uint16_t previous;

    encoder_tabbing_timer = timer_read();

    previous = encoder_tabbing_timeout_ms;

    if (!previous)
    {
        encoder_tabbing_timeout_ms = 100;
    }
    else
    {
        encoder_tabbing_timeout_ms = 600;
    }

    return previous;
}

void matrix_scan_user(void)
{
    if (encoder_tabbing_timeout_ms)
    {
        if (timer_elapsed(encoder_tabbing_timer) > encoder_tabbing_timeout_ms)
        {
            unregister_code(KC_LALT);
            unregister_code(KC_LSFT);
            unregister_code(KC_LCTL);
            encoder_tabbing_timeout_ms = 0;
        }
    }
}

bool encoder_update_user(uint8_t index, bool clockwise)
{
    if (index == 0)
    {
        uint16_t previous;

        previous = activate_encoder_tabbing();

        if (get_highest_layer(layer_state) == 0)
        {
            if (clockwise)
            {
                register_code(KC_LALT);
                register_code(KC_LSFT);
                unregister_code(KC_LCTL);
            }
            else
            {
                register_code(KC_LALT);
                unregister_code(KC_LSFT);
                unregister_code(KC_LCTL);
            }
        }
        else
        {
            if (clockwise)
            {
                unregister_code(KC_LALT);
                register_code(KC_LSFT);
                register_code(KC_LCTL);
            }
            else
            {
                unregister_code(KC_LALT);
                unregister_code(KC_LSFT);
                register_code(KC_LCTL);
            }
        }

        if (previous)
        {
            tap_code(KC_TAB);
        }
        else
        {
            register_code(KC_TAB);
            unregister_code(KC_LALT);
            unregister_code(KC_LSFT);
            unregister_code(KC_LCTL);
            unregister_code(KC_TAB);
        }
    }
    else if (index == 1)
    {
        if (get_highest_layer(layer_state) == 0)
        {
            if (clockwise)
            {
                tap_code(KC_WH_D);
            }
            else
            {
                tap_code(KC_WH_U);
            }
        }
        else
        {
            if (clockwise)
            {
                tap_code(KC_PGDN);
            }
            else
            {
                tap_code(KC_PGUP);
            }
        }
    }

    return true;
}

#endif
