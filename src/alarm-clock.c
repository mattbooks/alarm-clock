#include "alarm-clock.h"
#include "config/config.h"
#include "lib/seven-seg.h"
#include "lib/buffer.h"
#include "lib/uart.h"
#include "lib/rtc.h"
#include "lib/buttons.h"

struct tm* time;

const uint32_t INTERVAL_MS = 10;
const uint32_t RESET_VAL = 1000000;
const uint32_t TIME_POLL = 200; // 200 * 10ms = 2s

void init() {
  sei();
  SETUP_B_PORTS();
  SETUP_C_PORTS();
  SETUP_D_PORTS();
}

int main()
{
  init();

  twi_init_master();
  rtc_init();
  rtc_run_clock(1);

  init_seven_seg();

  uint32_t counter = 0;

  while (1) {
    _delay_ms(INTERVAL_MS);

    if (counter % TIME_POLL == 0) {
      time = rtc_get_time();
    }

    /* if (counter % BUTTON_POLL == 0) { */
    /*   // TODO: Poll Buttons */
    /* } */

    counter += 1;
    if (counter >= RESET_VAL) {
      counter = 0;
    }
  }
}

struct tm* get_time() {
  return time;
}
