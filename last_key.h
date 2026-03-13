#include QMK_KEYBOARD_H

uint16_t get_last_key(void);

bool is_shifted(void);

void restore_shift(void);

void last_key_on_process_record(uint16_t keycode, keyrecord_t *record);