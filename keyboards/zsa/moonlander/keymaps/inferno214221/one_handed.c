#include QMK_KEYBOARD_H

#include "layers.h"

static bool one_handed = false;

void enable_one_handed(void) {
  layer_move(L_DEF);
  layer_on(L_GAM);
}

void disable_one_handed(void) {
  layer_move(L_DEF);
}

void one_handed_on_housekeeping_task(void) {
    if (one_handed == is_transport_connected()) {
    one_handed = !is_transport_connected();
    if (one_handed) {
      enable_one_handed();
    } else {
      disable_one_handed();
    }
  }
}

bool is_one_handed(void) {
    return one_handed;
}