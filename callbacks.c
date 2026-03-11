#include QMK_KEYBOARD_H

#include "layers.h"

#include "inactivity.h"
#include "last_key.h"
#include "launch_tetris.h"
#include "led_indicators.h"
#include "music.h"
#include "one_handed.h"
#include "smart_brackets.h"
#include "sounds.h"
#include "tap_hold.h"
#include "unicode_leader.h"

void keyboard_post_init_user(void) {
  inactivity_on_keyboard_post_init();
  sounds_on_keyboard_post_init();
}

void matrix_init_user(void) {
  sounds_on_matrix_init();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  inactivity_on_proccess_record();
  
  bool res = tap_hold_on_process_record(keycode, record)
    && smart_brackets_on_process_record(keycode, record)
    && music_on_process_record(keycode, record)
    && tetris_on_process_record(keycode, record);

  last_key_on_process_record(keycode, record);

  return res;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  sounds_on_layer_set_state(state);
  led_indicators_on_layer_set_state(state);
  
  switch (get_highest_layer(state)) {
    case L_TET:
      tetris_on_layer_set_tetris();
      led_indicators_on_layer_set_tetris();
      return state;
    default:
      rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_INVERSE_MULTISPLASH);
      break;
  }

  return state;
}

void leader_start_user(void) {
  led_indicators_on_leader_start();
  sounds_on_leader_start();
}

void leader_end_user(void) {
  led_indicators_on_leader_end();
  sounds_on_leader_end();
  unicode_leader_on_leader_end();
}

void caps_word_set_user(bool active) {
  led_indicators_on_caps_word_set(active);
  sounds_on_caps_word_set(active);
}

void housekeeping_task_user(void) {
  one_handed_on_housekeeping_task();
}

void audio_on_user(void) {
  led_indicators_on_audio_on();
}

void audio_off_user(void) {
  led_indicators_on_audio_off();
}