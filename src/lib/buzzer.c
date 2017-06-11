#include "../config/config.h"

void buzz(uint8_t val) {
  if (val) {
    BUZ_GRP |= 1<<BUZ_PIN;
  } else {
    BUZ_GRP &= ~(1<<BUZ_PIN);
  }
}
