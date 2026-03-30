#include QMK_KEYBOARD_H

#include "custom_keycodes.h"

#include "music.h"
#include "tetris.h"

void begin_tetris(void) {
  init_tetris_state();
  tetris_start();
}

bool tetris_on_process_record(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Tetris Keycodes
    case TE_RES:
      if (record->event.pressed) begin_tetris();
      return false;
    case TE_LEFT:
      if (record->event.pressed) tetris_register_move(MOVE_LEFT);
      return false;
    case TE_ROT:
      if (record->event.pressed) tetris_register_move(MOVE_ROTATE);
      return false;
    case TE_RGHT:
      if (record->event.pressed) tetris_register_move(MOVE_RIGHT);
      return false;
    case TE_PAUS:
      if (record->event.pressed) tetris_pause();
      return false;
  }
  return true;
}

void tetris_on_layer_set_tetris(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_TETRIS);
    PLAY_LOOP(song_tetris_theme);
    begin_tetris();
}
