#include QMK_KEYBOARD_H

#include "layers.h"

#include "inactivity.h"
#include "launch_tetris.h"
#include "led_indicators.h"
#include "music.h"
#include "one_handed.h"
#include "tap_hold.h"
#include "unicode_leader.h"

void keyboard_post_init_user(void) {
  inactivity_on_keyboard_post_init();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  inactivity_on_proccess_record();
  return tap_hold_on_process_record(keycode, record)
    && music_on_process_record(keycode, record)
    && tetris_on_process_record(keycode, record);
}

layer_state_t layer_state_set_user(layer_state_t state) {
  switch (get_highest_layer(state)) {
    case L_GAM:
      music_on_layer_set_gaming();
    case L_DEF:
    case L_NUM:
    case L_FUN:
      rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_INVERSE_MULTISPLASH);
      break;
    case L_TET:
      tetris_on_layer_set_tetris();
      led_indicators_on_layer_set_tetris();
      return state;
  }

  led_indicators_on_layer_set_state(state);

  return state;
}

void leader_start_user(void) {
  led_indicators_on_leader_start();
}

void leader_end_user(void) {
  led_indicators_on_leader_end();
  unicode_leader_on_leader_end();
}

void caps_word_set_user(bool active) {
  led_indicators_on_caps_word_set(active);
}

void housekeeping_task_user(void) {
  one_handed_on_housekeeping_task();
}