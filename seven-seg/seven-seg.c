#include "../config/config.h"
#include "seven-seg.h"

void init_seven_seg() {
  DDRC |= (1<<DDC0) | (1<<DDC1) | (1<<DDC2) | (1<<DDC3);
  DDRB |= (1<<DDB0) | (1<<DDB1) | (1<<DDB2) | (1<<DDB4);
  set_off();
}

void flash(int val, int duration) {
  int length = 0;

  while(length < duration) {
    set_num(val);
    _delay_ms(200);
    set_off();
    _delay_ms(200);
    length += 400;
  }
}

void set_off() {
  TOP_L_OFF();
  TOP_OFF();
  TOP_R_OFF();
  MID_OFF();
  BOT_L_OFF();
  BOT_OFF();
  BOT_R_OFF();
  DOT_OFF();
}

void set_num(int val) {
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
