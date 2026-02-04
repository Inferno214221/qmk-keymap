#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

#include "tetris.h"
#include "music.h"
#include "layers.h"

#include "audio.h"

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  // Keyboard-level Music Controls
  KM_PLAY,
  KM_STOP,
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_DEF] = LAYOUT_moonlander(
    KC_ESC,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_CALC,                            KC_PSCR,    KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       OSL(L_FUN),
    KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_HOME,                            KC_END,     KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       TG(L_GAM),
    KC_LGUI,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_LALT,                            TG(L_NUM),  KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,
    KC_GRV,     KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,                                                       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_AMPR,
    QK_LEAD,    KC_MINS,    KC_EQL,     KC_UP,      KC_DOWN,                LCTL(KC_X),                         LCTL(KC_V),             KC_LEFT,    KC_RGHT,    KC_QUES,    KC_ASTR,    KC_DEL,
                                                                KC_LSFT,    KC_BSPC,    KC_LCTL,    LCTL(KC_C), KC_SPC,     KC_ENT
  ),
  [L_FUN] = LAYOUT_moonlander(
    EE_CLR,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,                              KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     XXXXXXX,
    XXXXXXX,    KC_VOLD,    KC_MPLY,    KC_VOLU,    XXXXXXX,    XXXXXXX,    XXXXXXX,                            XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KM_PLAY,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    KC_MPRV,    KC_MSTP,    KC_MNXT,    XXXXXXX,    XXXXXXX,    XXXXXXX,                            XXXXXXX,    XXXXXXX,    XXXXXXX,    KM_PREV,    KM_STOP,    KM_NEXT,    XXXXXXX,
    XXXXXXX,    KC_SLEP,    KC_PWR,     XXXXXXX,    XXXXXXX,    XXXXXXX,                                                    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                XXXXXXX,                            XXXXXXX,                XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    TO(L_TET),
                                                                XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX
  ),
  [L_NUM] = LAYOUT_moonlander(
    _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,                            XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_LPRN,    KC_RPRN,    KC_CIRC,
    _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,                            _______,    XXXXXXX,    XXXXXXX,    KC_P7,      KC_P8,      KC_P9,      KC_PSLS,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                            _______,    XXXXXXX,    XXXXXXX,    KC_P4,      KC_P5,      KC_P6,      KC_PAST,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                                                    XXXXXXX,    XXXXXXX,    KC_P1,      KC_P2,      KC_P3,      KC_PMNS,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,    _______,                XXXXXXX,                            XXXXXXX,                _______,    _______,    KC_P0,      KC_PDOT,    KC_PPLS,
                                                                XXXXXXX,    _______,    XXXXXXX,    XXXXXXX,    _______,    _______
  ),
  [L_GAM] = LAYOUT_moonlander(
    KC_ESC,     _______,    _______,    _______,    _______,    _______,    XXXXXXX,                            XXXXXXX,    _______,    _______,    _______,    _______,    _______,    TG(L_GAM),
    KC_TAB,     _______,    _______,    _______,    _______,    _______,    XXXXXXX,                            XXXXXXX,    _______,    _______,    _______,    _______,    _______,    _______,
    KC_GRV,     _______,    _______,    _______,    _______,    _______,    XXXXXXX,                            XXXXXXX,    _______,    _______,    _______,    _______,    KC_SCLN,    KC_QUOT,
    KC_LSFT,    _______,    _______,    _______,    _______,    _______,                                                    _______,    _______,    KC_COMM,    KC_DOT,     KC_UP,      KC_BSLS,
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
};

#define KEY_OVERRIDE_SHIFT_OR_COMBO(NAME_NONE, NAME_SHIFT, FROM, TO) \
const key_override_t NAME_NONE = ko_make_with_layers_and_negmods(0, FROM, TO, 1 << L_DEF, ~0); \
const key_override_t NAME_SHIFT = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, FROM, FROM, 1 << L_DEF, ~MOD_MASK_SHIFT);

KEY_OVERRIDE_SHIFT_OR_COMBO(o_lcbr_1_none, o_lcbr_1_shift, KC_1, KC_LCBR);
KEY_OVERRIDE_SHIFT_OR_COMBO(o_rcbr_2_none, o_rcbr_2_shift, KC_2, KC_RCBR);
KEY_OVERRIDE_SHIFT_OR_COMBO(o_labk_3_none, o_labk_3_shift, KC_3, KC_LABK);
KEY_OVERRIDE_SHIFT_OR_COMBO(o_rabk_4_none, o_rabk_4_shift, KC_4, KC_RABK);
KEY_OVERRIDE_SHIFT_OR_COMBO(o_hash_5_none, o_hash_5_shift, KC_5, KC_HASH);
KEY_OVERRIDE_SHIFT_OR_COMBO(o_dlr_6_none,  o_dlr_6_shift,  KC_6, KC_DLR );
KEY_OVERRIDE_SHIFT_OR_COMBO(o_lbrc_7_none, o_lbrc_7_shift, KC_7, KC_LBRC);
KEY_OVERRIDE_SHIFT_OR_COMBO(o_rbrc_8_none, o_rbrc_8_shift, KC_8, KC_RBRC);
KEY_OVERRIDE_SHIFT_OR_COMBO(o_lprn_9_none, o_lprn_9_shift, KC_9, KC_LPRN);
KEY_OVERRIDE_SHIFT_OR_COMBO(o_rprn_0_none, o_rprn_0_shift, KC_0, KC_RPRN);


#define KEY_OVERRIDE_SHIFT(NAME, FROM, TO) \
const key_override_t NAME = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, FROM, TO, 1 << L_DEF, ~MOD_MASK_SHIFT);

KEY_OVERRIDE_SHIFT(o_comm_at,   KC_COMM, KC_AT);
KEY_OVERRIDE_SHIFT(o_dot_circ,  KC_DOT,  KC_CIRC);
KEY_OVERRIDE_SHIFT(o_slsh_bsls, KC_SLSH, KC_BSLS);
KEY_OVERRIDE_SHIFT(o_ques_exlm, KC_QUES, KC_EXLM);
KEY_OVERRIDE_SHIFT(o_ampr_pipe, KC_AMPR, KC_PIPE);
KEY_OVERRIDE_SHIFT(o_astr_perc, KC_ASTR, KC_PERC);

const key_override_t *key_overrides[] = {
  &o_lcbr_1_none,
  &o_lcbr_1_shift,
  &o_rcbr_2_none,
  &o_rcbr_2_shift,
  &o_labk_3_none,
  &o_labk_3_shift,
  &o_rabk_4_none,
  &o_rabk_4_shift,
  &o_hash_5_none,
  &o_hash_5_shift,
  &o_dlr_6_none,
  &o_dlr_6_shift,
  &o_lbrc_7_none,
  &o_lbrc_7_shift,
  &o_rbrc_8_none,
  &o_rbrc_8_shift,
  &o_lprn_9_none,
  &o_lprn_9_shift,
  &o_rprn_0_none,
  &o_rprn_0_shift,

  &o_comm_at,
  &o_dot_circ,
  &o_slsh_bsls,
  &o_ques_exlm,
  &o_ampr_pipe,
  &o_astr_perc,
};


static deferred_token inactivity_token;

static deferred_token fade_out_timer;

typedef enum {
  STATE_ACTIVE,
  STATE_FADING_OUT,
  STATE_SLEEP
} inactivity_state_t;

static inactivity_state_t inactivity_state = STATE_ACTIVE;

static bool one_handed = false;

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
      layer_move(L_DEF);
    default:
      break;
  }
  inactivity_state = STATE_ACTIVE;
  extend_deferred_exec(inactivity_token, INACTIVITY_TIMEOUT);
}



void keyboard_post_init_user(void) {
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
      case KM_STOP:
        song_stop();
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
    case L_GAM:
      PLAY_SONG(sfx_mario_mushroom);
    case L_DEF:
    case L_NUM:
    case L_FUN:
      rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_INVERSE_MULTISPLASH);
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

  if (one_handed) {
    // Lose half of the LEDs, make them act differently
    STATUS_LED_1(IS_LAYER_ON_STATE(state, L_GAM));
    STATUS_LED_2(IS_LAYER_ON_STATE(state, L_GAM));
    STATUS_LED_3(IS_LAYER_ON_STATE(state, L_GAM));
  } else {
    STATUS_LED_1(is_caps_word_on());
    STATUS_LED_2(leader_sequence_active());
    STATUS_LED_3(false);
    STATUS_LED_4(IS_LAYER_ON_STATE(state, L_GAM));
    STATUS_LED_5(IS_LAYER_ON_STATE(state, L_NUM) || IS_LAYER_ON_STATE(state, L_GAM));
    STATUS_LED_6(IS_LAYER_ON_STATE(state, L_FUN) || IS_LAYER_ON_STATE(state, L_GAM));
  }

  return state;
}

void leader_start_user(void) {
  STATUS_LED_2(true);
}

void leader_end_user(void) {
  STATUS_LED_2(false);

  if (leader_sequence_two_keys(KC_P, KC_M)) {
    register_unicode(0x00B1);
  } else if (leader_sequence_two_keys(KC_M, KC_U)) {
    register_unicode(0x00B5);
  } else if (leader_sequence_two_keys(KC_T, KC_M)) {
    register_unicode(0x2122);
  } else if (leader_sequence_three_keys(KC_D, KC_E, KC_G)) {
    register_unicode(0x00B0);
  } else if (leader_sequence_three_keys(KC_D, KC_I, KC_V)) {
    register_unicode(0x00F7);
  } else if (leader_sequence_three_keys(KC_G, KC_T, KC_E)) {
    register_unicode(0x2265);
  } else if (leader_sequence_three_keys(KC_L, KC_T, KC_E)) {
    register_unicode(0x2264);
  } else if (leader_sequence_three_keys(KC_A, KC_P, KC_R)) {
    register_unicode(0x2248);
  } else if (leader_sequence_five_keys(KC_T, KC_I, KC_M, KC_E, KC_S)) {
    register_unicode(0x00D7);
  }
}

void caps_word_set_user(bool active) {
  STATUS_LED_1(active);
}

void enable_one_handed(void) {
  layer_move(L_DEF);
  layer_on(L_GAM);
}

void disable_one_handed(void) {
  layer_move(L_DEF);
}

void housekeeping_task_user(void) {
  if (one_handed == is_transport_connected()) {
    one_handed = !is_transport_connected();
    if (one_handed) {
      enable_one_handed();
    } else {
      disable_one_handed();
    }
  }
}