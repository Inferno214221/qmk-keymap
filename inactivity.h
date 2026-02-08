typedef enum {
  STATE_ACTIVE,
  STATE_FADING_OUT,
  STATE_SLEEP
} inactivity_state_t;

void inactivity_on_keyboard_post_init(void);

void inactivity_on_proccess_record(void);