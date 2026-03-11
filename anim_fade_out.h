#if defined(RGB_MATRIX_FRAMEBUFFER_EFFECTS)
RGB_MATRIX_EFFECT(FADE_OUT)
#  ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#    ifndef RGB_MATRIX_FADE_OUT_DURATION_MS
#      define RGB_MATRIX_FADE_OUT_DURATION_MS 5000
#    endif

// A timer to track the last time we decremented all heatmap values.
static uint16_t value_decrease_timer;

bool FADE_OUT(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);

  if (params->init) {
    value_decrease_timer = timer_read();
    memset(g_rgb_frame_buffer, 0, sizeof g_rgb_frame_buffer);
  }

  hsv_t hsv = rgb_matrix_config.hsv;
  hsv.v     = 255 - (255 * timer_elapsed(value_decrease_timer)) / RGB_MATRIX_FADE_OUT_DURATION_MS;
  hsv.v     = scale8(hsv.v, rgb_matrix_config.hsv.v);
  rgb_t rgb = rgb_matrix_hsv_to_rgb(hsv);
  rgb_matrix_set_color_all(rgb.r, rgb.g, rgb.b);

  return rgb_matrix_check_finished_leds(led_max);
}

#  endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif   // defined(RGB_MATRIX_FRAMEBUFFER_EFFECTS)
