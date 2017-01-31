#include "alarm-clock.h"
#include "config/config.h"
#include "lib/seven-seg.h"
#include "lib/buffer.h"
#include "lib/uart.h"
#include "lib/rtc.h"
#include "lib/buttons.h"
#include "lib/state.h"
#include "lib/light-control.h"
#include "lib/time.h"

struct tm* time;
enum clock_state state;

const uint32_t INTERVAL_MS = 10;
const uint32_t RESET_VAL = 1000000;
const uint32_t TIME_POLL = 200; // 200 * 10ms = 2s
const uint32_t BUTTON_POLL = 1;

void init() {
  sei();
  SETUP_B_PORTS();
  SETUP_C_PORTS();
  SETUP_D_PORTS();
}

void handle_left() {
  switch (state) {
    case DISPLAY_OFF:
      state = DISPLAY_ALARM;
      break;
    case ALARM_DISABLED:
      dim_lights();
      break;
    case DISPLAY_ALARM:
      state = ADJUST_ALARM;
      break;
    case DISPLAY_TIME:
      state = DISPLAY_OFF;
      break;
    case ADJUST_ALARM:
      decrement_alarm();
      break;
    case ADJUST_TIME:
      decrement_time();
      break;
  }
}

void handle_right() {
  switch (state) {
    case DISPLAY_OFF:
      state = DISPLAY_TIME;
      break;
    case ALARM_DISABLED:
      raise_lights();
      break;
    case DISPLAY_ALARM:
      state = DISPLAY_OFF;
      break;
    case DISPLAY_TIME:
      state = ADJUST_TIME;
      break;
    case ADJUST_ALARM:
      increment_alarm();
      break;
    case ADJUST_TIME:
      increment_time();
      break;
  }
}

int main()
{
  init();

  twi_init_master();
  rtc_init();
  rtc_run_clock(1);

  init_seven_seg();

  register_button(LEFT, *handle_left);
  register_button(RIGHT, *handle_right);

  uint32_t counter = 0;

  while (1) {
    _delay_ms(INTERVAL_MS);

    if (counter % TIME_POLL == 0) {
      time = rtc_get_time();
    }

    if (counter % BUTTON_POLL == 0) {
      poll_buttons();
    }

    counter += 1;
    if (counter >= RESET_VAL) {
      counter = 0;
    }
  }
}

struct tm* get_time() {
  return time;
}

