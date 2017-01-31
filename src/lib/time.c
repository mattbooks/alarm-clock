#include "time.h"

void increment_seconds(struct tm* t, int32_t sec) {
  uint8_t overflow = 0;

  t->sec += sec;
  if (t->sec < 60 && t->sec >= 0) {
    return;
  }

  overflow = t->sec / 60;
  t->sec /= 60;
  t->min += overflow;
  if (t->min < 60 && t->min >= 0) {
    return;
  }

  overflow = t->min / 60;
  t->hour += overflow;
  t->min /= 60;

  if (t->hour < 24 && t->hour >= 0) {
    return;
  }

  overflow = t->hour / 24;
  t->mday += overflow;
  t->hour /= 24;
  // things get sketchy here... TODO: FIX!
}
