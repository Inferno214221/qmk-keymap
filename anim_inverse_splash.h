#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED

RGB_MATRIX_EFFECT(INVERSE_MULTISPLASH)

#  ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#include <string.h>

#include "custom_keycodes.h"
#include "layers.h"

#include "keymap_common.h"
#include "audio.h"

//                h   v   dh  dv
#define C_BLUE  {135,255,  8,-40}
#define C_RED   {  0,255,  0,-60}
#define C_OFF_R {  0,  0,  0, 40}
#define C_GREEN { 85,255,  0,-40}
#define C_OFF_G { 85,  0,  0, 40}

typedef struct PACKED hsv_delta_t {
  int8_t h;
  int8_t v;
} hsv_delta_t;

int16_t PROGMEM led_layers[][2][4] = {
  //         primary  secondary
  [L_DEF] = {C_BLUE,  C_BLUE},
  [L_FUN] = {C_RED,   C_OFF_R},
  [L_NUM] = {C_GREEN, C_OFF_G},
  [L_GAM] = {C_BLUE,  C_BLUE},
  [L_TET] = {C_BLUE,  C_BLUE},
};

uint8_t apply_hsv_delta(uint8_t value, uint8_t effect, int8_t delta) {
  if (delta < 0) {
    return qsub8(value, scale8(255 - effect, abs8(delta)));
  } else {
    return qadd8(value, scale8(255 - effect, delta));
  }
}

hsv_t inverse_splash_math(hsv_t hsv, hsv_delta_t delta, int16_t dx, int16_t dy, uint8_t dist, uint16_t tick) {
  uint16_t effect = tick - dist;
  if (effect > 255) effect = 255;
  hsv.h = apply_hsv_delta(hsv.h, effect, delta.h);
  hsv.v = apply_hsv_delta(hsv.v, effect, delta.v);
  return hsv;
}

void apply_inverse_splash(uint8_t i, uint8_t count, hsv_t hsv, hsv_delta_t delta) {
  for (uint8_t j = 0; j < count; j++) {
    int16_t dx    = g_led_config.point[i].x - g_last_hit_tracker.x[j];
    int16_t dy    = g_led_config.point[i].y - g_last_hit_tracker.y[j];
    uint8_t dist  = sqrt16(dx * dx + dy * dy);
    uint16_t tick = scale16by8(g_last_hit_tracker.tick[j], qadd8(rgb_matrix_config.speed, 1));
    hsv      = inverse_splash_math(hsv, delta, dx, dy, dist, tick);
  }
  hsv.v     = scale8(hsv.v, rgb_matrix_config.hsv.v);
  rgb_t rgb = rgb_matrix_hsv_to_rgb(hsv);
  rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
}

bool INVERSE_MULTISPLASH(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);

  uint8_t count = g_last_hit_tracker.count;

  uint8_t highest = get_highest_layer(layer_state);

  hsv_t hsvs[] = {
    {
      .h = pgm_read_byte(&led_layers[highest][0][0]),
      .s = 255,
      .v = pgm_read_byte(&led_layers[highest][0][1]),
    },
    {
      .h = pgm_read_byte(&led_layers[highest][1][0]),
      .s = 255,
      .v = pgm_read_byte(&led_layers[highest][1][1]),
    }
  };

  hsv_delta_t deltas[] = {
    {
      .h = pgm_read_byte(&led_layers[highest][0][2]),
      .v = pgm_read_byte(&led_layers[highest][0][3]),
    },
    {
      .h = pgm_read_byte(&led_layers[highest][1][2]),
      .v = pgm_read_byte(&led_layers[highest][1][3]),
    }
  };

    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            uint8_t i = g_led_config.matrix_co[row][col];

            switch (keymap_key_to_keycode(highest, (keypos_t){col,row})) {
                case INF_IND:
                    rgb_t rgb;

                    if (is_caps_word_on()) {
                        rgb = rgb_matrix_hsv_to_rgb((hsv_t) { .h = 160, .s = 255, .v = rgb_matrix_config.hsv.v });
                    } else if (leader_sequence_active()) {
                        rgb = rgb_matrix_hsv_to_rgb((hsv_t) { .h =  85, .s = 255, .v = rgb_matrix_config.hsv.v });
                    } else if (!audio_is_on()) {
                        rgb = rgb_matrix_hsv_to_rgb((hsv_t) { .h =   0, .s = 255, .v = rgb_matrix_config.hsv.v });
                    } else {
                        rgb = (rgb_t) { .r = 0, .g = 0, .b = 0 };
                    }

                    rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
                    // Don't write anything at all, leave these keys for indicators.
                    break;
                case KC_NO:
                    apply_inverse_splash(i, count, hsvs[true], deltas[true]);
                    break;
                default:
                    apply_inverse_splash(i, count, hsvs[false], deltas[false]);
            }
        }
    }
  return rgb_matrix_check_finished_leds(led_max);
}

#  endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif   // RGB_MATRIX_KEYREACTIVE_ENABLED
