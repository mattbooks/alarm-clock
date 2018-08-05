#include <time.h>
#include "lib/time.h"
#include "alarm-clock.h"
#include "config/config.h"
#include "lib/seven-seg.h"
#include "lib/buffer.h"
#include "lib/uart.h"
#include "lib/rtc.h"
#include "lib/buttons.h"
#include "lib/light-control.h"
#include "lib/buzzer.h"

struct tm t;
struct alarm a = {12,0};

enum clock_state state = DISPLAY_OFF;
enum alarm_state alarm_state = OFF;

const uint32_t INTERVAL_MS = 1;
const uint32_t RESET_VAL = 1000000;
const uint32_t TIME_POLL = 200; // 2000 * 1ms = 2s
const uint32_t BUTTON_POLL = 1;
const uint32_t EDIT_TIMEOUT = 200; // 2000 * 1ms = 2s

void init() {
  sei();
  SETUP_B_PORTS();
  SETUP_C_PORTS();
  SETUP_D_PORTS();
  PIND |= (1<<PD0) | (1<<PD1) | (1<<PD2);
}

uint32_t edit_timer = 0;

void reset_edit_timer() {
  edit_timer = 0;
}

uint8_t is_on() {
  return (PIND & (1<<PD2)) == 0 ? 1 : 0;
}

void handle_left() {
  if (alarm_state == ON) {
    alarm_state = OFF;
    buzz(0);
    return;
  }

  if (is_on()) {
    switch (state) {
      case DISPLAY_OFF:
        t = *rtc_get_time();
        state = DISPLAY_TIME;
        break;
      case ALARM_DISABLED:
        dim_lights();
        break;
      case DISPLAY_TIME:
        reset_edit_timer();
        state = ADJUST_TIME_HOUR;
        break;
      case DISPLAY_ALARM:
        state = DISPLAY_OFF;
        break;
      case ADJUST_ALARM:
        reset_edit_timer();
        increment_alarm(&a, -5);
        break;
      case ADJUST_TIME_HOUR:
        reset_edit_timer();
        t = *increment_seconds(&t, -3600);
        break;
      case ADJUST_TIME_MINUTE:
        reset_edit_timer();
        t = *increment_seconds(&t, -60);
        break;
    }
  } else {
    toggle_lights();
  }
}

void handle_right() {
  if (alarm_state == ON) {
    alarm_state = OFF;
    buzz(0);
    return;
  }

  if (is_on()) {
    switch (state) {
      case DISPLAY_OFF:
        state = DISPLAY_ALARM;
        break;
      case ALARM_DISABLED:
        raise_lights();
        break;
      case DISPLAY_TIME:
        state = DISPLAY_OFF;
        break;
      case DISPLAY_ALARM:
        reset_edit_timer();
        state = ADJUST_ALARM;
        break;
      case ADJUST_ALARM:
        reset_edit_timer();
        increment_alarm(&a, 5);
        break;
      case ADJUST_TIME_HOUR:
        reset_edit_timer();
        t = *increment_seconds(&t, 3600);
        break;
      case ADJUST_TIME_MINUTE:
        reset_edit_timer();
        t = *increment_seconds(&t, 60);
        break;
    }
  } else {
    toggle_lights();
  }
}

uint8_t edit_active() {
  switch (state) {
    case ADJUST_TIME_HOUR:
    case ADJUST_TIME_MINUTE:
    case ADJUST_ALARM:
      return 1;
    default:
      return 0;
  }
}

int main()
{
  init();

  twi_init_master();
  rtc_init();
  rtc_run_clock(1);

  init_seven_seg();
  init_lights();

  set_lights(1);

  min_to_alarm(rtc_get_alarm(), &a);

  /* t = *fill_in_time(0, 9, 15, 11, 6, 17); */
  /* rtc_set_time(&t); */

  register_button(LEFT, *handle_left);
  register_button(RIGHT, *handle_right);

  uint32_t counter = 0;

  struct tm prev_time = *rtc_get_time();
  t = *rtc_get_time();

  while (1) {
    _delay_ms(INTERVAL_MS);

    if (counter % BUTTON_POLL == 0) {
      poll_buttons();
    }

    if (edit_active()) {
      edit_timer += 1;

      if (edit_timer > EDIT_TIMEOUT) {
        if (state == ADJUST_TIME_HOUR) {
          state = ADJUST_TIME_MINUTE;
          reset_edit_timer();
        } else {
          if (state == ADJUST_ALARM) {
            state = DISPLAY_OFF;
            rtc_set_alarm(alarm_to_min(&a));
          } else if (state == ADJUST_TIME_MINUTE) {
            state = DISPLAY_TIME;
            rtc_set_time(&t);
          }
        }
      }
    } else {
      if (counter % TIME_POLL == 0) {
        prev_time = t;
        t = *rtc_get_time();

        if (is_on()) {
          if (cmp_pre_alarm(&prev_time, &a) < 0 && cmp_pre_alarm(&t, &a) >= 0) {
            alarm_state = WARM;
            set_lights(1);
          }
          if (cmp_alarm(&prev_time, &a) < 0 && cmp_alarm(&t, &a) >= 0) {
            alarm_state = ON;
            buzz(1);
          }
        }
      }
    }

    counter += 1;
    if (counter >= RESET_VAL) {
      counter = 0;
    }

  }
}

struct tm* get_time() {
  return &t;
}

struct alarm* get_alarm() {
  return &a;
}

enum clock_state get_state() {
  return state;
}
