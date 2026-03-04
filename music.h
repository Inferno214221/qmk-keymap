#include QMK_KEYBOARD_H

bool music_on_process_record(uint16_t keycode, keyrecord_t *record);

void song_play(void);

void song_stop(void);

void song_next(void);

void song_prev(void);

float song_tetris_theme[37][2];
float sfx_mario_mushroom[25][2];