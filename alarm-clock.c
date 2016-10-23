#include "config/config.h"
#include "seven-seg/seven-seg.h"

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
