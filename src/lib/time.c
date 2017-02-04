#include <stdint.h>
#include "time.h"

struct tm* fill_in_time(uint8_t sec, uint8_t min, uint8_t hour, uint8_t mday, uint8_t mon, uint16_t year) {
  struct tm* sparse_t = &(struct tm) {
    .tm_sec = sec,
    .tm_min = min,
    .tm_hour = hour,
    .tm_mday = mday,
    .tm_mon = mon - 1,
    .tm_year = year + 100
  };

  time_t _t = mktime(sparse_t);

  return localtime(&_t);
}

struct tm* increment_seconds(struct tm* t, int32_t sec) {
  time_t _t;

  _t = mktime(t);

  _t += sec;

  return localtime(&_t);
}
