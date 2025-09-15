#include "keycodes.h"
#include QMK_KEYBOARD_H

#define LAYOUT LAYOUT_planck_1x2uC

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

#define K_MAGIC KC_A

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_MAIN] = LAYOUT(
        KC_V   , KC_M   , KC_L   , KC_C   , KC_P   , XXXXXXX, XXXXXXX, KC_B   , QK_AREP, KC_U   , KC_O   , KC_P   ,
        KC_S   , KC_T   , KC_R   , KC_D   , KC_Y   , XXXXXXX, XXXXXXX, KC_F   , KC_N   , KC_E   , KC_A   , KC_I   ,
        KC_X   , KC_K   , KC_J   , KC_G   , KC_W   , XXXXXXX, XXXXXXX, KC_Z   , KC_H   , KC_COMM, KC_DOT , KC_SCLN,
        XXXXXXX, XXXXXXX, XXXXXXX, ML_NUM , KC_SPC ,     XXXXXXX,      QK_REP , ML_SYM , XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [L_SYM] = LAYOUT(
        KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, XXXXXXX, XXXXXXX, KC_CIRC, KC_AMPR, KC_ASTR, KC_QUES, KC_QUOT,
        KC_PLUS, KC_EQL , KC_LPRN, KC_RPRN, KC_DQT , XXXXXXX, XXXXXXX, KC_COLN, KC_RBRC, KC_LBRC, KC_RCBR, KC_LCBR,
        KC_LT  , KC_PIPE, KC_MINS, KC_GT  , KC_BSLS, XXXXXXX, XXXXXXX, KC_GRV , KC_UNDS, KC_SLSH, KC_TILD, KC_SCLN,
        XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,     XXXXXXX,      _______, _______, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [L_NUM] = LAYOUT(
        XXXXXXX, KC_7   , KC_8   , KC_9   , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, S(A(KC_LEFT)), XXXXXXX, S(A(KC_RIGHT)), XXXXXXX,
        KC_0   , KC_4   , KC_5   , KC_6   , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TAB , KC_ESC , KC_RETN, XXXXXXX,
        XXXXXXX, KC_1   , KC_2   , KC_3   , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,     XXXXXXX,      _______, _______, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [L_SYS] = LAYOUT(
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    )
};
// clang-format on

#define DEF_COMBO(name, ...) const uint16_t PROGMEM combo_##name[] = {__VA_ARGS__, COMBO_END}
DEF_COMBO(escape, KC_R, KC_D);
DEF_COMBO(backspace, KC_N, KC_E);
DEF_COMBO(tab, KC_T, KC_R, KC_D);
DEF_COMBO(enter, KC_N, KC_E, KC_A);

// clang-format off
combo_t key_combos[] = {
    COMBO(combo_escape, KC_ESCAPE),
    COMBO(combo_backspace, KC_BACKSPACE),
    COMBO(combo_tab, KC_TAB),
    COMBO(combo_enter, KC_ENTER)
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

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
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
