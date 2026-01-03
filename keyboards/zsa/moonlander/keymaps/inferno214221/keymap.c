#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

#include "tetris.h"
#include "music.h"

#include "audio.h"

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  // Keyboard-level Music Controls
  KM_PLAY,
  KM_NEXT,
  KM_PREV,

  // Tetris Keycodes
  TET_LEFT,
  TET_RGHT,
  TET_DOWN,
  TET_ROT,
  TET_RES,
  TET_PAUS
};

#define L_DEF 0
#define L_FUN 1
#define L_GAM 2
#define L_TET 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_DEF] = LAYOUT_moonlander(
    KC_ESC,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_CALC,                            KC_PSCR,    KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       OSL(L_FUN),
    KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_HOME,                            KC_END,     KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       TG(L_GAM),
    KC_LGUI,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_LALT,                            _______,    KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,
    KC_GRV,     KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,                                                       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_BSLS,
    _______,    KC_MINS,    KC_EQL,     KC_UP,      KC_DOWN,                LCTL(KC_X),                         LCTL(KC_V),             KC_LEFT,    KC_RGHT,    KC_LBRC,    KC_RBRC,    KC_DEL,
                                                                KC_LSFT,    KC_BSPC,    KC_LCTL,    LCTL(KC_C), KC_SPC,     KC_ENT
  ),
  [L_FUN] = LAYOUT_moonlander(
    EE_CLR,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,                              KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     XXXXXXX,
    MU_TOGG,    KC_VOLD,    KC_MPLY,    KC_VOLU,    XXXXXXX,    XXXXXXX,    XXXXXXX,                            XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KM_PLAY,    XXXXXXX,    XXXXXXX,
    MU_NEXT,    KC_MPRV,    KC_MSTP,    KC_MNXT,    XXXXXXX,    XXXXXXX,    XXXXXXX,                            XXXXXXX,    XXXXXXX,    XXXXXXX,    KM_PREV,    XXXXXXX,    KM_NEXT,    XXXXXXX,
    XXXXXXX,    KC_SLEP,    KC_PWR,     XXXXXXX,    XXXXXXX,    XXXXXXX,                                                    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                XXXXXXX,                            XXXXXXX,                XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    TO(L_TET),
                                                                XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX
  ),
  [L_GAM] = LAYOUT_moonlander(
    KC_ESC,     _______,    _______,    _______,    _______,    _______,    XXXXXXX,                            XXXXXXX,    _______,    _______,    _______,    _______,    _______,    _______,
    KC_TAB,     _______,    _______,    _______,    _______,    _______,    XXXXXXX,                            XXXXXXX,    _______,    _______,    _______,    _______,    _______,    _______,
    KC_GRV,     _______,    _______,    _______,    _______,    _______,    XXXXXXX,                            XXXXXXX,    _______,    _______,    _______,    _______,    _______,    _______,
    KC_LSFT,    _______,    _______,    _______,    _______,    _______,                                                    _______,    _______,    _______,    _______,    KC_UP,      _______,
    KC_LCTL,    KC_F1,      KC_F2,      KC_F3,      KC_F4,                  XXXXXXX,                            XXXXXXX,                KC_DEL,     KC_SLSH,    KC_LEFT,    KC_DOWN,    KC_RGHT,
                                                                KC_SPC,     KC_SPC,     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX
  ),
  [L_TET] = LAYOUT_moonlander(
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                            XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    TO(L_DEF),
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                            XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                            XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                                                    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                XXXXXXX,                            TET_ROT,                TO(L_DEF),  XXXXXXX,    AU_TOGG,    TET_PAUS,   TET_RES,
                                                                XXXXXXX,    XXXXXXX,    XXXXXXX,    TET_LEFT,   TET_DOWN,    TET_RGHT
  ),
  // Numpad doesn't make sense on a one shot layer.
  // [L_FUN] = LAYOUT_moonlander(
  //   QK_BOOT,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,                              KC_F7,      KC_F8,      KC_F9,      KC_F10,       KC_F11,     KC_F12,     _______,
  //   MU_TOGG,    KC_VOLD,    KC_MPLY,    KC_VOLU,    TG(L_FUN),  TG(L_FUN),  TG(L_FUN),                          TG(L_FUN),  TG(L_FUN),  TG(L_FUN),  KC_P7,        KC_P8,      KC_P9,      KC_PAST,
  //   MU_NEXT,    KC_MPRV,    KC_MSTP,    KC_MNXT,    TG(L_FUN),  TG(L_FUN),  TG(L_FUN),                          TG(L_FUN),  TG(L_FUN),  TG(L_FUN),  KC_P4,        KC_P5,      KC_P6,      KC_PMNS,
  //   TG(L_FUN),  KC_SLEP,    KC_PWR,     TG(L_FUN),  TG(L_FUN),  TG(L_FUN),                                                  TG(L_FUN),  TG(L_FUN),  KC_P1,        KC_P2,      KC_P3,      KC_PPLS,
  //   TG(L_FUN),  TG(L_FUN),  TG(L_FUN),  TG(L_FUN),  TG(L_FUN),              TG(L_FUN),                          TG(L_FUN),              TG(L_FUN),  KC_PSLS,      KC_P0,      KC_PDOT,    KC_PENT,
  //                                                               RM_HUEU,    RM_HUED,    TG(L_FUN),  TG(L_FUN),  RM_SATU,    RM_SATD
  // ),
};



static deferred_token inactivity_token;

static deferred_token fade_out_timer;

#define STATE_ACTIVE 0
#define STATE_FADING_OUT 1
#define STATE_SLEEP 2

static uint8_t inactivity_state = STATE_ACTIVE;

uint32_t on_fade_out_finished(uint32_t trigger_time, void *cb_arg) {
  inactivity_state = STATE_SLEEP;
  rgb_matrix_mode_noeeprom(RGB_MATRIX_DIGITAL_RAIN);
  return 0;
}

uint32_t on_keyboard_inactivity(uint32_t trigger_time, void *cb_arg) {
  inactivity_state = STATE_FADING_OUT;
  rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_FADE_OUT);
  fade_out_timer = defer_exec(RGB_MATRIX_FADE_OUT_DURATION_MS, on_fade_out_finished, NULL);
  return 0;
}

void update_inactivity(void) {
  switch (inactivity_state) {
    case STATE_FADING_OUT:
      cancel_deferred_exec(fade_out_timer);
    case STATE_SLEEP:
      inactivity_token = defer_exec(INACTIVITY_TIMEOUT, on_keyboard_inactivity, NULL);
      // FIXME: assumes layer 0
      rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_INVERSE_MULTISPLASH);
  }
  inactivity_state = STATE_ACTIVE;
  extend_deferred_exec(inactivity_token, INACTIVITY_TIMEOUT);
}



void keyboard_post_init_user(void) {
  rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_INVERSE_MULTISPLASH);
  rgb_matrix_sethsv_noeeprom(135, 255, 255);
  rgb_matrix_set_speed_noeeprom(63);
  inactivity_token = defer_exec(INACTIVITY_TIMEOUT, on_keyboard_inactivity, NULL);
}



void begin_tetris(void) {
  init_tetris_state();
  tetris_start();
}



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  update_inactivity();

  switch (keycode) {
    case RGB_SLD:
      if (rawhid_state.rgb_control) {
        return false;
      }
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }

  if (record->event.pressed) {
    switch (keycode) {
      // Keyboard-level Music Controls
      case KM_PLAY:
        song_play();
        return false;
      case KM_NEXT:
        song_next();
        return false;
      case KM_PREV:
        song_prev();
        return false;

      // Tetris Keycodes
      case TET_RES:
        begin_tetris();
        return false;
      case TET_LEFT:
        tetris_register_move(MOVE_LEFT);
        return false;
      case TET_ROT:
        tetris_register_move(MOVE_ROTATE);
        return false;
      case TET_RGHT:
        tetris_register_move(MOVE_RIGHT);
        return false;
      case TET_PAUS:
        tetris_pause();
        return false;
    }
  }
  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  switch (get_highest_layer(state)) {
    case L_FUN:
      rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_STATIC_FUN_KEYS);
      break;
    case L_DEF:
      rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_INVERSE_MULTISPLASH);
      // audio_stop_all();
      break;
    case L_GAM:
      // rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_INVERSE_MULTISPLASH);
      PLAY_SONG(sfx_mario_mushroom);
      break;    
    case L_TET:
      rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_TETRIS);
      PLAY_LOOP(song_tetris_theme);
      begin_tetris();

      STATUS_LED_1(false);
      STATUS_LED_2(false);
      STATUS_LED_3(false);
      STATUS_LED_4(true);
      STATUS_LED_5(true);
      STATUS_LED_6(true);
      return state;
  }

  STATUS_LED_1(is_caps_word_on());
  STATUS_LED_2(false);
  STATUS_LED_3(false);
  STATUS_LED_4(false);
  STATUS_LED_5(IS_LAYER_ON_STATE(state, L_GAM));
  STATUS_LED_6(IS_LAYER_ON_STATE(state, L_FUN));

  return state;
}

void caps_word_set_user(bool active) {
  STATUS_LED_1(active);
}