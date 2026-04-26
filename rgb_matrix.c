#include QMK_KEYBOARD_H

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    rgb_t rgb;

    if (is_caps_word_on()) {
        rgb = hsv_to_rgb((hsv_t) { .h = 160, .s = 255, .v = rgb_matrix_config.hsv.v });
    } else if (leader_sequence_active()) {
        rgb = hsv_to_rgb((hsv_t) { .h =  85, .s = 255, .v = rgb_matrix_config.hsv.v });
    } else if (!audio_is_on()) {
        rgb = hsv_to_rgb((hsv_t) { .h =   0, .s = 255, .v = rgb_matrix_config.hsv.v });
    } else {
        rgb = (rgb_t) { .r = 0, .g = 0, .b = 0 };
    }

    for (uint8_t i = led_min; i < led_max; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_INDICATOR)) {
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
    }
    return false;
}
