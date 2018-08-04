#include "../alarm-clock.h"
#include "../config/config.h"
#include <time.h>
#include "seven-seg.h"

uint8_t flash_timer = 0;
uint8_t flash_threshold = 0x3F;

uint8_t current_digit = 0;

uint8_t colon_flash_state = 1;
uint8_t flash_lhs_state = 1;
uint8_t flash_rhs_state = 1;

void flash_off() {
  colon_flash_state = 1;
  flash_lhs_state = 1;
  flash_rhs_state = 1;
}

void flash_colon() {
  if (flash_timer > flash_threshold) {
    COLON_ON();
  } else {
    COLON_OFF();
  }
}

void flash_lhs() {
  flash_rhs_state = 1;
  if (flash_timer > flash_threshold) {
    flash_lhs_state = 1;
  } else {
    flash_lhs_state = 0;
  }
}

void flash_rhs() {
  flash_lhs_state = 1;
  if (flash_timer > flash_threshold) {
    flash_rhs_state = 1;
  } else {
    flash_rhs_state = 0;
  }
}

ISR(TIMER0_OVF_vect) {
  current_digit = (current_digit + 1) & 3;
  flash_timer = flash_timer + 1;

  set_off();

  switch(get_state()) {
    case DISPLAY_TIME:
      COLON_ON();
      flash_off();
      display_time_digit(get_time(), current_digit);
      break;
    case ADJUST_TIME_HOUR:
      flash_colon();
      flash_lhs();
      display_time_digit(get_time(), current_digit);
      break;
    case ADJUST_TIME_MINUTE:
      flash_colon();
      flash_rhs();
      display_time_digit(get_time(), current_digit);
      break;
    case DISPLAY_ALARM:
      COLON_ON();
      display_alarm_digit(get_alarm(), current_digit);
      break;
    case ADJUST_ALARM:
      flash_colon();
      display_alarm_digit(get_alarm(), current_digit);
      break;
    default:
      COLON_OFF();
      break;
  }
}

void display_alarm_digit(struct alarm* a, uint8_t digit) {
  if (digit == 0) {
    display_digit(digit, a->hour / 10);
  } else if (digit == 1) {
    display_digit(digit, a->hour % 10);
  } else if (digit == 2) {
    display_digit(digit, a->min / 10);
  } else if (digit == 3) {
    display_digit(digit, a->min % 10);
  }
}

void display_time_digit(struct tm* t, uint8_t digit) {
  if (digit == 0 && flash_lhs_state) {
    display_digit(digit, t->tm_hour / 10);
  } else if (digit == 1 && flash_lhs_state) {
    display_digit(digit, t->tm_hour % 10);
  } else if (digit == 2 && flash_rhs_state) {
    display_digit(digit, t->tm_min / 10);
  } else if (digit == 3 && flash_rhs_state) {
    display_digit(digit, t->tm_min % 10);
  }
}

void display_digit(uint8_t digit, uint8_t val) {
  set_digit(digit);

  if (digit == 0 && val == 0) {
    set_off();
  } else {
    set_num(val % 10);
  }
}

void init_seven_seg() {
  set_off();

  TCCR0B = 1<<CS01;
  TIFR0  = 1<<TOV0;
  TIMSK0 = 1<<TOIE0;
}

void set_off() {
  DIGIT1_DISABLE();
  DIGIT2_DISABLE();
  DIGIT3_DISABLE();
  DIGIT4_DISABLE();
  TOP_L_OFF();
  TOP_OFF();
  TOP_R_OFF();
  MID_OFF();
  BOT_L_OFF();
  BOT_OFF();
  BOT_R_OFF();
  DOT_OFF();
}

void set_num(char val) {
  if(val < 0 || val > 9) {
    return;
  }

  if (val == 0) {
    TOP_L_ON();
    TOP_ON();
    TOP_R_ON();
    MID_OFF();
    BOT_L_ON();
    BOT_ON();
    BOT_R_ON();
  } else if (val == 1) {
    TOP_L_OFF();
    TOP_OFF();
    TOP_R_ON();
    MID_OFF();
    BOT_L_OFF();
    BOT_OFF();
    BOT_R_ON();
  } else if (val == 2) {
    TOP_L_OFF();
    TOP_ON();
    TOP_R_ON();
    MID_ON();
    BOT_L_ON();
    BOT_ON();
    BOT_R_OFF();
  } else if (val == 3) {
    TOP_L_OFF();
    TOP_ON();
    TOP_R_ON();
    MID_ON();
    BOT_L_OFF();
    BOT_ON();
    BOT_R_ON();
  } else if (val == 4) {
    TOP_L_ON();
    TOP_OFF();
    TOP_R_ON();
    MID_ON();
    BOT_L_OFF();
    BOT_OFF();
    BOT_R_ON();
  } else if (val == 5) {
    TOP_L_ON();
    TOP_ON();
    TOP_R_OFF();
    MID_ON();
    BOT_L_OFF();
    BOT_ON();
    BOT_R_ON();
  } else if (val == 6) {
    TOP_L_ON();
    TOP_ON();
    TOP_R_OFF();
    MID_ON();
    BOT_L_ON();
    BOT_ON();
    BOT_R_ON();
  } else if (val == 7) {
    TOP_L_OFF();
    TOP_ON();
    TOP_R_ON();
    MID_OFF();
    BOT_L_OFF();
    BOT_OFF();
    BOT_R_ON();
  } else if (val == 8) {
    TOP_L_ON();
    TOP_ON();
    TOP_R_ON();
    MID_ON();
    BOT_L_ON();
    BOT_ON();
    BOT_R_ON();
  } else if (val == 9) {
    TOP_L_ON();
    TOP_ON();
    TOP_R_ON();
    MID_ON();
    BOT_L_OFF();
    BOT_ON();
    BOT_R_ON();
  }
}

void set_digit(char val) {
  if (val == 0) {
    DIGIT2_DISABLE();
    DIGIT3_DISABLE();
    DIGIT4_DISABLE();
    DIGIT1_ENABLE();
  } else if (val == 1) {
    DIGIT1_DISABLE();
    DIGIT3_DISABLE();
    DIGIT4_DISABLE();
    DIGIT2_ENABLE();
  } else if (val == 2) {
    DIGIT1_DISABLE();
    DIGIT2_DISABLE();
    DIGIT4_DISABLE();
    DIGIT3_ENABLE();
  } else if (val == 3) {
    DIGIT1_DISABLE();
    DIGIT2_DISABLE();
    DIGIT3_DISABLE();
    DIGIT4_ENABLE();
  }
}
