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

    LALT_T(KC_GRV),KC_LGUI, MO(1),KC_BSPC,LSFT_T(KC_DEL),     RSFT_T(KC_ENT),KC_SPC, MO(1), KC_LBRC,RALT_T(KC_RBRC)
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
    static const char PROGMEM raw_logo[] = {
        0,128,192,224,240,248,248,248,248,248,248,248,248,248,248,248,248,152,192,248,248,248,248,248,248,248,248,240,224,192,128,  0,  3,  7, 15, 31, 63,127,255,239,223,191,127,255,255,255,255,255,255,255,255,255,255,127,255,255,255,255,127, 63, 31, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  1,  3,  7,  6,  0,  3, 15, 63,255,127, 63, 55,  1,  0,  3,  3,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,120,248,248,248,248,248,248,248,248,248,248,248,248,248,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,255,255,255,255,255,255,255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,255,255,255,255,255,255,255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,126,254,252,248,248,240,240,240,240,240,240,248,255,255,255,255,255, 63,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 32,224,224,225,225,225,227,195,  3,  3,  3,  3,  3,  1,  1,129,224,224,224,224,224,224, 96,  0,  0,  0,  0,  0, 
        0,  0,  0,  0,  0,  0,  1,  7, 31,127,255,255,255,252,240,192,224,248,254,255,255,255, 63, 15,  3,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,129,227,255,255,255,255,255,255,255,247,193,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192,240,248,254,255,255,255, 63, 15,  3,  7, 31,127,255,255,255,252,248,224,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,132,135,135,135,135,135,135,  3,  0,  0,  0,  0,  0,  0,  0,  0,  3,135,135,135,135,135,134,132,  0,  0,  0,  0, 
        0,  0,  0,  0,  1,  7, 31,127,255,255,255,254,248,192,  0,  0,  0,192,240,252,255,255,255,255, 63, 15,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  7, 31,127,255,255,255,252,254,255,255,255, 63, 15,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,255,255,255,255,255,255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 31, 31, 31, 31, 31, 31,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    };
    oled_write_raw_P(raw_logo, sizeof(raw_logo));
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

    static const char PROGMEM raw_logo[] = {
        0,  0,  0,128,192,224,224,224,224,224,224,224,224,224,224,224,224, 96,  0,224,224,224,224,224,224,224,224,192,128,  0,  0,  0, 12, 30, 63,127,255,255,255,191,127,255,255,255,255,255,255,255,255,254,255,255,255,255,255,255,255,255,255,255,127, 63, 30, 12,  0,  0,  0,  0,  0,  1,  3,  7, 15, 30, 25,  3, 15, 63,255,255,255,255,223,  7,  3, 13, 15,  7,  3,  3,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    };
    oled_write_raw_P(raw_logo, sizeof(raw_logo));
}

oled_rotation_t oled_init_user(oled_rotation_t rotation)
{
    return OLED_ROTATION_270;
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

typedef enum _enc_tab_t
{
    ENC_TAB_ALT,
    ENC_TAB_CTL

} enc_tab_t;

void do_encoder_tabbing(bool clockwise, enc_tab_t type)
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

    if (type == ENC_TAB_ALT)
    {
        if (clockwise)
        {
            register_code(KC_LALT);
            unregister_code(KC_LSFT);
            unregister_code(KC_LCTL);
        }
        else
        {
            register_code(KC_LALT);
            register_code(KC_LSFT);
            unregister_code(KC_LCTL);
        }
    }
    else
    {
        if (clockwise)
        {
            unregister_code(KC_LALT);
            unregister_code(KC_LSFT);
            register_code(KC_LCTL);
        }
        else
        {
            unregister_code(KC_LALT);
            register_code(KC_LSFT);
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
        switch (get_highest_layer(layer_state))
        {
            case 0:
            {
                do_encoder_tabbing(clockwise, ENC_TAB_ALT);
                break;
            }
            case 1:
            {
                do_encoder_tabbing(clockwise, ENC_TAB_CTL);
                break;
            }
            case 2:
            {
                if (clockwise)
                {
                    tap_code(KC_VOLU);
                }
                else
                {
                    tap_code(KC_VOLD);
                }
                break;
            }
        }
    }
    else if (index == 1)
    {
        switch (get_highest_layer(layer_state))
        {
            case 0:
            {
                if (clockwise)
                {
                    tap_code(KC_WH_U);
                }
                else
                {
                    tap_code(KC_WH_D);
                }
                break;
            }
            case 1:
            {
                if (clockwise)
                {
                    tap_code(KC_PGUP);
                }
                else
                {
                    tap_code(KC_PGDN);
                }
                break;
            }
            case 2:
            {
                if (clockwise)
                {
                    tap_code(KC_VOLD);
                }
                else
                {
                    tap_code(KC_VOLU);
                }
                break;
            }
        }
    }

    return true;
}

#endif
