#include "../alarm-clock.h"
#include "../config/config.h"
#include <time.h>
#include "seven-seg.h"

char current_digit = 0;

ISR(TIMER0_OVF_vect) {
  current_digit = (current_digit + 1) & 3;
  set_off();
  set_digit(current_digit);

  if (current_digit == 0) {
    set_num(get_time()->tm_hour / 10);
  } else if (current_digit == 1) {
    set_num(get_time()->tm_hour % 10);
  } else if (current_digit == 2) {
    set_num(get_time()->tm_min / 10);
  } else if (current_digit == 3) {
    set_num(get_time()->tm_min % 10);
  }
}

void init_seven_seg() {
  set_off();

  TCCR0B = 1<<CS01;
  TIFR0  = 1<<TOV0;
  TIMSK0 = 1<<TOIE0;
}

void flash(int digit, int val, int duration) {
  int length = 0;

  while(length < duration) {
    set_digit(digit);
    set_num(val);
    _delay_ms(200);
    set_off();
    _delay_ms(200);
    length += 400;
  }
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
