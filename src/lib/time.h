#ifndef ALARM_TIME_H
#define ALARM_TIME_H

#include <stdint.h>
#include <time.h>

struct alarm {
  uint8_t hour;
  uint8_t min;
};

void min_to_alarm(uint16_t, struct alarm*);
uint16_t alarm_to_min(struct alarm*);

struct alarm* increment_alarm(struct alarm*, int16_t);

int8_t cmp_alarm(struct tm*, struct alarm*);
int8_t cmp_pre_alarm(struct tm*, struct alarm*);

struct tm* fill_in_time(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint16_t);
struct tm* increment_seconds(struct tm*, int32_t);
#endif
