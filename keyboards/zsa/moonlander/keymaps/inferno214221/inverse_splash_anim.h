#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
#    if defined(ENABLE_RGB_MATRIX_INVERSE_MULTISPLASH)

#        ifdef ENABLE_RGB_MATRIX_INVERSE_MULTISPLASH
RGB_MATRIX_EFFECT(INVERSE_MULTISPLASH)
#        endif

#        ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

hsv_t INVERSE_SPLASH_math(hsv_t hsv, int16_t dx, int16_t dy, uint8_t dist, uint16_t tick) {
    uint16_t effect = tick - dist;
    if (effect > 255) effect = 255;
    hsv.h = qadd8(hsv.h, scale8(255 - effect, 8));
    hsv.v = qsub8(hsv.v, scale8(255 - effect, 40));
    return hsv;
}

bool effect_runner_inverse_reactive_splash(uint8_t start, effect_params_t* params, reactive_splash_f effect_func) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    uint8_t count = g_last_hit_tracker.count;
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        hsv_t hsv = rgb_matrix_config.hsv;
        hsv.v     = 255;
        for (uint8_t j = start; j < count; j++) {
            int16_t  dx   = g_led_config.point[i].x - g_last_hit_tracker.x[j];
            int16_t  dy   = g_led_config.point[i].y - g_last_hit_tracker.y[j];
            uint8_t  dist = sqrt16(dx * dx + dy * dy);
            uint16_t tick = scale16by8(g_last_hit_tracker.tick[j], qadd8(rgb_matrix_config.speed, 1));
            hsv           = effect_func(hsv, dx, dy, dist, tick);
        }
        hsv.v     = scale8(hsv.v, rgb_matrix_config.hsv.v);
        rgb_t rgb = rgb_matrix_hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return rgb_matrix_check_finished_leds(led_max);
}

#            ifdef ENABLE_RGB_MATRIX_INVERSE_MULTISPLASH
bool INVERSE_MULTISPLASH(effect_params_t* params) {
    return effect_runner_inverse_reactive_splash(0, params, &INVERSE_SPLASH_math);
}
#            endif

#        endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#    endif     // !defined(ENABLE_RGB_MATRIX_SPLASH) && !defined(ENABLE_RGB_MATRIX_MULTISPLASH)
#endif         // RGB_MATRIX_KEYREACTIVE_ENABLED
