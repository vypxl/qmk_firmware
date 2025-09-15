#include QMK_KEYBOARD_H

enum custom_keycodes {
    LAYER0 = SAFE_RANGE,
    LAYER1,
    LAYER2,
    LAYER3,
    MG_ON,
    MG_ENT,
    MG_ION,
    MG_UE,
    MG_MENT,
    MG_THE,
    MG_SPACE_BUT,
    MG_INCLUDE,
};

#include "layout.h"
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    #define l keymap[L_MAIN]
    [L_MAIN] = LAYOUT(
        // M <    M v      M ^      M >       Ms<      Ms>
        MS_LEFT, MS_DOWN, MS_UP  , MS_RGHT, MS_WHLL, MS_WHLR,                   KC_PSCR, KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT, KC_PGUP,
        XXXXXXX, l[0],  l[1],  l[2],  l[3],  l[4],                              l[5],  l[6],  l[7],  l[8],  l[9],           MS_WHLU,
        XXXXXXX, l[10], l[11], l[12], l[13], l[14],                             l[15], l[16], l[17], l[18], l[19],          MS_WHLD,
        XXXXXXX, l[20], l[21], l[22], l[23], l[24],                             l[25], l[26], l[27], l[28], l[29],          KC_PGDN,
                                      l[30], l[31],                             l[32], l[33]
    ),

    #undef l
    #define l keymap[L_SYM]
    [L_SYM] = LAYOUT(
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
        XXXXXXX, l[0],  l[1],  l[2],  l[3],  l[4],                              l[5],  l[6],  l[7],  l[8],  l[9],            XXXXXXX,
        XXXXXXX, l[10], l[11], l[12], l[13], l[14],                             l[15], l[16], l[17], l[18], l[19],           XXXXXXX,
        XXXXXXX, l[20], l[21], l[22], l[23], l[24],                             l[25], l[26], l[27], l[28], l[29],           XXXXXXX,
                                      l[30], l[31],                             l[32], l[33]
    ),

    #undef l
    #define l keymap[L_NUM]
    [L_NUM] = LAYOUT(
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
        XXXXXXX, l[0],  l[1],  l[2],  l[3],  l[4],                              l[5],  l[6],  l[7],  l[8],  l[9],            XXXXXXX,
        XXXXXXX, l[10], l[11], l[12], l[13], l[14],                             l[15], l[16], l[17], l[18], l[19],           XXXXXXX,
        XXXXXXX, l[20], l[21], l[22], l[23], l[24],                             l[25], l[26], l[27], l[28], l[29],           XXXXXXX,
                                      l[30], l[31],                             l[32], l[33]
    ),

    #undef l
    [L_SYS] = LAYOUT(
        QK_BOOT, XXXXXXX, KC_F10 , KC_F11 , KC_F12 , XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
        XXXXXXX, XXXXXXX, KC_F7  , KC_F8  , KC_F9  , XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_F4  , KC_F5  , KC_F6  , XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_F1  , KC_F2  , KC_F3  , XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                            XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX
    ),

    [L_GAME] = LAYOUT(
        KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                            KC_SPC , QK_BOOT,                   XXXXXXX, XXXXXXX
    )
};

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        case KC_A: return KC_O;
        case KC_B: return XXXXXXX;
        case KC_C: return KC_Y;
        case KC_D: return KC_Y;
        case KC_E: return KC_U;
        case KC_F: return XXXXXXX;
        case KC_G: return KC_O;
        case KC_H: return XXXXXXX;
        case KC_I: return MG_ON;
        case KC_J: return XXXXXXX;
        case KC_K: return XXXXXXX;
        case KC_L: return KC_K;
        case KC_M: return MG_ENT;
        case KC_N: return MG_ION;
        case KC_O: return KC_A;
        case KC_P: return KC_Y;
        case KC_Q: return MG_UE;
        case KC_R: return KC_L;
        case KC_S: return KC_K;
        case KC_T: return MG_MENT;
        case KC_U: return KC_E;
        case KC_V: return XXXXXXX;
        case KC_W: return XXXXXXX;
        case KC_X: return XXXXXXX;
        case KC_Y: return KC_P;
        case KC_Z: return XXXXXXX;
        case KC_DOT:
            if (mods & MOD_MASK_SHIFT) return KC_EQUAL;
            else return KC_SLASH;;
        case KC_COMMA:
            if (mods & MOD_MASK_SHIFT) return KC_EQUAL;
            else return MG_SPACE_BUT;
        case KC_COLON: return KC_O;
        case KC_SPACE: return MG_THE;
        case KC_HASH: return MG_INCLUDE;
    }

    return KC_TRANSPARENT;
}

// clang-format on

#define MAGIC_CASE(id, str) \
    case MG_##id:           \
        SEND_STRING(#str);  \
        return false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) return true;

    switch (keycode) {
        MAGIC_CASE(ON, on)
        MAGIC_CASE(ENT, ent)
        MAGIC_CASE(UE, ue)
        MAGIC_CASE(MENT, ment)
        MAGIC_CASE(ION, ion)
        MAGIC_CASE(THE, the)
        MAGIC_CASE(SPACE_BUT, " but")
        MAGIC_CASE(INCLUDE, include)
        default:
            break;
    }
    return true;
}

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT_T(KC_Z):
        case ALT_T(KC_X):
        case GUI_T(KC_C):
        case CTL_T(KC_D):
        case RCTL_T(KC_H):
        case RGUI_T(KC_COMMA):
        case RALT_T(KC_DOT):
        case RSFT_T(KC_SLASH):
        // case AUTO_SHIFT_ALPHA:
        case KC_ENTER:
            return true;
        default:
            return false;
    }
}

// gaming mode when single
void handle_auto_switch_gaming(void) {
    static bool did_first  = false;
    static bool last_state = false;

    bool connected = is_transport_connected();
    if (!did_first) {
        did_first  = true;
        last_state = !connected;
    }

    if (last_state == connected) return;
    last_state = connected;
    if (!connected) {
        // Only left half -> gaming mode
        layer_on(L_GAME);
        // autoshift_disable();
        combo_disable();
    } else {
        // Both halves -> normal mode
        layer_off(L_GAME);
        // autoshift_enable();
        combo_enable();
    }
}

void housekeeping_task_user(void) {
    handle_auto_switch_gaming();
}
