#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL

#include "custom_keycodes.h"
#include "layers.h"

#include "callbacks.c"
#include "key_overrides.c"
#include "rgb_matrix.c"
#include "tapdance.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_DEF] = LAYOUT_moonlander(
    // These numbers aren't actually numbers unless shifted. See key_overrides for more info.
    //          KC_LCBR,    KC_RCBR,    KC_LABK,    KC_RABK,    KC_MINS,                                                    KC_PERC,    KC_LBRC,    KC_RBRC,    KC_LPRN,    KC_RPRN,
    KC_ESC,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_CALC,                            KC_PSCR,    KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       OSL(L_FUN),
    KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_HOME,                            KC_END,     KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_HASH,
    KC_LGUI,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       XXXXXXX,                            TG(L_NUM),  KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,
    KC_GRV,     KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,                                                       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_AMPR,
    XXXXXXX,    KC_MINS,    KC_EQL,     KC_UP,      KC_DOWN,                TH_ALTU,                            LCTL(KC_V),             KC_LEFT,    KC_RGHT,    KC_EXLM,    KC_QUES,    KC_DEL,
                                                                KC_LSFT,    KC_BSPC,    KC_LCTL,    TD(T_COPY), KC_SPC,     KC_ENT
  ),
  [L_FUN] = LAYOUT_moonlander(
    QK_BOOT,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,                              KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     INF_NUL,
    XXXXXXX,    KC_VOLD,    KC_MPLY,    KC_VOLU,    XXXXXXX,    XXXXXXX,    XXXXXXX,                            XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KM_PLAY,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    KC_MPRV,    KC_MSTP,    KC_MNXT,    XXXXXXX,    XXXXXXX,    XXXXXXX,                            TO(L_GAM),  XXXXXXX,    XXXXXXX,    KM_PREV,    KM_STOP,    KM_NEXT,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                                                    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    AU_TOGG,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                _______,                            XXXXXXX,                XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    TO(L_TET),
                                                                _______,    XXXXXXX,    _______,    XXXXXXX,    KC_SLEP,    KC_PWR
  ),
  [L_NUM] = LAYOUT_moonlander(
    _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,                            XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,    _______,    XXXXXXX,
    _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,                            _______,    XXXXXXX,    XXXXXXX,    KC_P7,      KC_P8,      KC_P9,      KC_PAST,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                            _______,    XXXXXXX,    XXXXXXX,    KC_P4,      KC_P5,      KC_P6,      KC_PSLS,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                                                    XXXXXXX,    XXXXXXX,    KC_P1,      KC_P2,      KC_P3,      KC_CIRC,
    XXXXXXX,    KC_PMNS,    KC_PPLS,     _______,    _______,               XXXXXXX,                            _______,                _______,    _______,    KC_P0,      KC_PDOT,    KC_PENT,
                                                                XXXXXXX,    _______,    XXXXXXX,    _______,    _______,    _______
  ),
  [L_GAM] = LAYOUT_moonlander(
    KC_ESC,     _______,    _______,    _______,    _______,    _______,    XXXXXXX,                            G(KC_PSCR), _______,    _______,    _______,    _______,    _______,    TO(L_DEF),
    KC_TAB,     _______,    _______,    _______,    _______,    _______,    XXXXXXX,                            XXXXXXX,    _______,    _______,    _______,    _______,    _______,    XXXXXXX,
    KC_GRV,     _______,    _______,    _______,    _______,    _______,    XXXXXXX,                            TO(L_DEF),  _______,    _______,    _______,    _______,    KC_SCLN,    KC_QUOT,
    KC_LSFT,    _______,    _______,    _______,    _______,    _______,                                                    _______,    _______,    KC_COMM,    KC_DOT,     KC_UP,      KC_BSLS,
    KC_LCTL,    KC_F1,      KC_F2,      KC_F3,      KC_F4,                  KC_LALT,                            XXXXXXX,                KC_DEL,     KC_SLSH,    KC_LEFT,    KC_DOWN,    KC_RGHT,
                                                                KC_SPC,     KC_SPC,     KC_LGUI,    XXXXXXX,    XXXXXXX,    XXXXXXX
  ),
  [L_TET] = LAYOUT_moonlander(
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                            XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    TO(L_DEF),
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                            XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                            XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                                                    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                XXXXXXX,                            TE_ROT,                 TO(L_DEF),  XXXXXXX,    AU_TOGG,    TE_PAUS,    TE_RES,
                                                                XXXXXXX,    XXXXXXX,    XXXXXXX,    TE_LEFT,    TE_DOWN,    TE_RGHT
  ),
};
