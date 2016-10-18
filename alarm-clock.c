#include <pololu/orangutan.h>

/*
 * Based on example code from and depends on libpololu-avr
 *
 * http://www.pololu.com/docs/0J20
 * http://www.pololu.com
 * http://forum.pololu.com
 */

#define TOP_L IO_C1
#define TOP IO_C2
#define TOP_R IO_C3
#define MID IO_C0
#define BOT_L IO_B4
#define BOT IO_B2
#define BOT_R IO_B1
#define DOT IO_B0

void flash(int val, int duration) {
  int length = 0;

  while(length < duration) {
    set_num(val);
    delay_ms(200);
    set_off();
    delay_ms(200);
    length += 400;
  }
}

void set_off() {
  set_digital_output(TOP_L, HIGH);
  set_digital_output(TOP, HIGH);
  set_digital_output(TOP_R, HIGH);
  set_digital_output(MID, HIGH);
  set_digital_output(BOT_L, HIGH);
  set_digital_output(BOT, HIGH);
  set_digital_output(BOT_R, HIGH);
}

void set_num(int val) {
  if(val < 0 || val > 9) {
    return;
  }

  if (val == 0) {
    set_digital_output(TOP_L, LOW);
    set_digital_output(TOP, LOW);
    set_digital_output(TOP_R, LOW);
    set_digital_output(MID, HIGH);
    set_digital_output(BOT_L, LOW);
    set_digital_output(BOT, LOW);
    set_digital_output(BOT_R, LOW);
  } else if (val == 1) {
    set_digital_output(TOP_L, HIGH);
    set_digital_output(TOP, HIGH);
    set_digital_output(TOP_R, LOW);
    set_digital_output(MID, HIGH);
    set_digital_output(BOT_L, HIGH);
    set_digital_output(BOT, HIGH);
    set_digital_output(BOT_R, LOW);
  } else if (val == 2) {
    set_digital_output(TOP_L, HIGH);
    set_digital_output(TOP, LOW);
    set_digital_output(TOP_R, LOW);
    set_digital_output(MID, LOW);
    set_digital_output(BOT_L, LOW);
    set_digital_output(BOT, LOW);
    set_digital_output(BOT_R, HIGH);
  } else if (val == 3) {
    set_digital_output(TOP_L, HIGH);
    set_digital_output(TOP, LOW);
    set_digital_output(TOP_R, LOW);
    set_digital_output(MID, LOW);
    set_digital_output(BOT_L, HIGH);
    set_digital_output(BOT, LOW);
    set_digital_output(BOT_R, LOW);
  } else if (val == 4) {
    set_digital_output(TOP_L, LOW);
    set_digital_output(TOP, HIGH);
    set_digital_output(TOP_R, LOW);
    set_digital_output(MID, LOW);
    set_digital_output(BOT_L, HIGH);
    set_digital_output(BOT, HIGH);
    set_digital_output(BOT_R, LOW);
  } else if (val == 5) {
    set_digital_output(TOP_L, LOW);
    set_digital_output(TOP, LOW);
    set_digital_output(TOP_R, HIGH);
    set_digital_output(MID, LOW);
    set_digital_output(BOT_L, HIGH);
    set_digital_output(BOT, LOW);
    set_digital_output(BOT_R, LOW);
  } else if (val == 6) {
    set_digital_output(TOP_L, LOW);
    set_digital_output(TOP, LOW);
    set_digital_output(TOP_R, HIGH);
    set_digital_output(MID, LOW);
    set_digital_output(BOT_L, LOW);
    set_digital_output(BOT, LOW);
    set_digital_output(BOT_R, LOW);
  } else if (val == 7) {
    set_digital_output(TOP_L, HIGH);
    set_digital_output(TOP, LOW);
    set_digital_output(TOP_R, LOW);
    set_digital_output(MID, HIGH);
    set_digital_output(BOT_L, HIGH);
    set_digital_output(BOT, HIGH);
    set_digital_output(BOT_R, LOW);
  } else if (val == 8) {
    set_digital_output(TOP_L, LOW);
    set_digital_output(TOP, LOW);
    set_digital_output(TOP_R, LOW);
    set_digital_output(MID, LOW);
    set_digital_output(BOT_L, LOW);
    set_digital_output(BOT, LOW);
    set_digital_output(BOT_R, LOW);
  } else if (val == 9) {
    set_digital_output(TOP_L, LOW);
    set_digital_output(TOP, LOW);
    set_digital_output(TOP_R, LOW);
    set_digital_output(MID, LOW);
    set_digital_output(BOT_L, HIGH);
    set_digital_output(BOT, LOW);
    set_digital_output(BOT_R, LOW);
  }
}


int main()
{
  while(1)
  {
    int i;
    for (i = 0; i <= 9; i++) {
      flash(i, 1000);
    }
  }
}

