#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED

RGB_MATRIX_EFFECT(INVERSE_MULTISPLASH)

#    ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#include "layers.h"
#include "keymap_common.h"

#define LED_LAYOUT_moonlander( \
    k0A, k0B, k0C, k0D, k0E, k0F, k0G,            k6A, k6B, k6C, k6D, k6E, k6F, k6G, \
    k1A, k1B, k1C, k1D, k1E, k1F, k1G,            k7A, k7B, k7C, k7D, k7E, k7F, k7G, \
    k2A, k2B, k2C, k2D, k2E, k2F, k2G,            k8A, k8B, k8C, k8D, k8E, k8F, k8G, \
    k3A, k3B, k3C, k3D, k3E, k3F,                      k9B, k9C, k9D, k9E, k9F, k9G, \
    k4A, k4B, k4C, k4D, k4E,      k5D,            kBD,      kAC, kAD, kAE, kAF, kAG, \
                             k5A, k5B, k5C,  kBE, kBF, kBG \
) { \
    k0A, k1A, k2A, k3A, k4A, \
    k0B, k1B, k2B, k3B, k4B, \
    k0C, k1C, k2C, k3C, k4C, \
    k0D, k1D, k2D, k3D, k4D, \
    k0E, k1E, k2E, k3E, k4E, \
    k0F, k1F, k2F, k3F, \
    k0G, k1G, k2G, \
    k5A, k5B, k5C, k5D, \
\
    k6G, k7G, k8G, k9G, kAG, \
    k6F, k7F, k8F, k9F, kAF, \
    k6E, k7E, k8E, k9E, kAE, \
    k6D, k7D, k8D, k9D, kAD, \
    k6C, k7C, k8C, k9C, kAC, \
    k6B, k7B, k8B, k9B, \
    k6A, k7A, k8A, \
    kBG, kBF, kBE, kBD, \
}

//                h   s   v   dh  ds  dv
#define C_BLUE  {135,255,255,  8,  0,-40}
#define C_RED   {  0,255,255,  0,  0,-60}
#define C_OFF_R {  0,255,  0,  0,  0, 40}
#define C_GREEN { 85,255,255,  0,  0,-40}
#define C_OFF_G { 85,255,  0,  0,  0, 40}

typedef struct PACKED hsv_delta_t {
    int8_t h;
    int8_t s;
    int8_t v;
} hsv_delta_t;

int16_t PROGMEM led_layers[][2][6] = {
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
    hsv.s = apply_hsv_delta(hsv.s, effect, delta.s);
    hsv.v = apply_hsv_delta(hsv.v, effect, delta.v);
    return hsv;
}

bool INVERSE_MULTISPLASH(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    uint8_t highest = get_highest_layer(layer_state);

    uint8_t count = g_last_hit_tracker.count;
    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            uint8_t i = g_led_config.matrix_co[row][col];

            bool use_secondary = keymap_key_to_keycode(highest, (keypos_t){col,row}) == KC_NO;

            hsv_t hsv = {
                .h = pgm_read_byte(&led_layers[highest][use_secondary][0]),
                .s = pgm_read_byte(&led_layers[highest][use_secondary][1]),
                .v = pgm_read_byte(&led_layers[highest][use_secondary][2]),
            };
            hsv_delta_t delta = {
                .h = pgm_read_byte(&led_layers[highest][use_secondary][3]),
                .s = pgm_read_byte(&led_layers[highest][use_secondary][4]),
                .v = pgm_read_byte(&led_layers[highest][use_secondary][5]),
            };

            for (uint8_t j = 0; j < count; j++) {
                int16_t  dx   = g_led_config.point[i].x - g_last_hit_tracker.x[j];
                int16_t  dy   = g_led_config.point[i].y - g_last_hit_tracker.y[j];
                uint8_t  dist = sqrt16(dx * dx + dy * dy);
                uint16_t tick = scale16by8(g_last_hit_tracker.tick[j], qadd8(rgb_matrix_config.speed, 1));
                hsv           = inverse_splash_math(hsv, delta, dx, dy, dist, tick);
            }
            hsv.v     = scale8(hsv.v, rgb_matrix_config.hsv.v);
            rgb_t rgb = rgb_matrix_hsv_to_rgb(hsv);
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
    }
    return rgb_matrix_check_finished_leds(led_max);
}

#    endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif     // RGB_MATRIX_KEYREACTIVE_ENABLED
