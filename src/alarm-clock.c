#include "config/config.h"
#include "lib/seven-seg.h"
#include "lib/buffer.h"
#include "lib/uart.h"
#include "lib/rtc.h"

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
