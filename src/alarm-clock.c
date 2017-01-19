#include "alarm-clock.h"
#include "config/config.h"
#include "lib/seven-seg.h"
#include "lib/buffer.h"
#include "lib/uart.h"
#include "lib/rtc.h"

struct tm* time;

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

  while (1) {
    time = rtc_get_time();

    _delay_ms(2000);
  }
}

struct tm* get_time() {
  return time;
}
