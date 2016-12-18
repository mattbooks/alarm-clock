#include "config/config.h"
#include "seven-seg/seven-seg.h"

#include "lib/buffer/buffer.h"
#include "lib/uart/uart.h"
#include "lib/ds_rtc/rtc.h"

int main()
{
  init_seven_seg();
  while(1)
  {
    int i;
    for (i = 0; i <= 9; i++) {
      flash(i, 1000);
    }
  }
}
