#include QMK_KEYBOARD_H
#include "layout_def.h"

#define COLEMAK

#define HRML(k1, k2, k3, k4) LSFT_T(k1), LALT_T(k2), LGUI_T(k3), LCTL_T(k4)
#define HRMR(k1, k2, k3, k4) RCTL_T(k1), RGUI_T(k2), RALT_T(k3), RSFT_T(k4)

// clang-format off
const uint16_t keymap[3][34] = {
    #ifdef COLEMAK
    [L_MAIN] = {
        // q  w  f  p  b      j  l  u  y  ;
        // a  r  s  t  g      m  n  e  i  o
        // z  x  c  d  v      k  h  ,  .  /
        //         num spc   rep sym
        q, w, f, p, b, j, l, u, y, semi,
        a, r, s, t, g, m, n, e, i, o,
        HRML(z, x, c, d), v, k, HRMR(h, comma, dot, slash),
        SFT_T(space), ML_NUM, ML_SYM, QK_REP
    },
    #endif
    #ifdef MAGIC_STURDY
    [L_MAIN] = {
        // v  m  l  c  p      j  @  u  o  p
        // s  t  r  d  y      f  n  e  a  i
        // x  k  j  g  w      z  h  ,  .  ;
        //         num spc   rep sym
        v, m, l, c, p, j, QK_AREP, u, o, p,
        s, t, r, d, y, f, n, e, a, i,
        HRML(x, k, j, g), w, z, HRMR(h, comma, dot, semi),
        ML_NUM, SFT_T(space), QK_REP, ML_SYM
    },
    #endif
    [L_SYM] = {
        //  !      @        #        $        %             ^        &        *       ?         '
        //  +      =        (        )        "             :        [        ]        {        }
        //  <      |        -        >        \             `        _        /        ~        ;
        KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR, KC_QUES, KC_QUOT,
        KC_PLUS, KC_EQL , KC_LPRN, KC_RPRN, KC_DQT ,     KC_COLN, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR,
        KC_LT  , KC_PIPE, KC_MINS, KC_GT  , KC_BSLS,     KC_GRV , KC_UNDS, KC_SLSH, KC_TILD, KC_SCLN,
        CW_TOGG, _______, _______, _______
    },
    [L_NUM] = {
        _,  _7, _8, _9, _, /* */ _, S(A(left)), _, S(A(right)), _,
        _0, _4, _5, _6, _, /* */ _, left, down, up, right,
        _,  _1, _2, _3, _, /* */ _, ctrl, super, alt, shift,
        _______, _______, _______, _______,
    },
};

#define km keymap[L_MAIN]
const uint16_t PROGMEM combo_1_12[]  = {km[11], km[12], COMBO_END};
const uint16_t PROGMEM combo_1_23[]  = {km[12], km[13], COMBO_END};
const uint16_t PROGMEM combo_1_123[] = {km[11], km[12], km[3], COMBO_END};

const uint16_t PROGMEM combo_1_67[]  = {km[16], km[17], COMBO_END};
const uint16_t PROGMEM combo_1_78[]  = {km[17], km[18], COMBO_END};
const uint16_t PROGMEM combo_1_678[] = {km[16], km[17], km[8], COMBO_END};
#undef mm1

combo_t key_combos[] = {
    COMBO(combo_1_23, KC_ESCAPE),
    COMBO(combo_1_67, KC_BACKSPACE),
    COMBO(combo_1_12, KC_TAB),
    COMBO(combo_1_78, KC_ENTER)
};
// clang-format on

#include "layout_undef.h"
