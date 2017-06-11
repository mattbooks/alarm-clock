#include <stdint.h>
#include "sput.h"
#include "../lib/time.h"

struct tm t;

static void set_time(uint8_t wday, uint32_t yday, uint32_t year, uint8_t mon, uint8_t mday, uint8_t hour, uint8_t min, uint8_t sec) {
  t = (struct tm) {
    .tm_sec = sec,
    .tm_min = min,
    .tm_hour = hour,
    .tm_mday = mday,
    .tm_mon = mon,
    .tm_year = year - 1900,
    .tm_wday = wday,
    .tm_yday = yday,
    .tm_isdst = -1
  };
}

static void check_time(uint8_t wday, uint32_t yday, uint32_t year, uint8_t mon, uint8_t mday, uint8_t hour, uint8_t min, uint8_t sec) {
  sput_fail_unless(t.tm_wday == wday, "wday");
  sput_fail_unless(t.tm_year == year - 1900, "year");
  sput_fail_unless(t.tm_mon == mon, "month");
  sput_fail_unless(t.tm_mday == mday, "mday");
  sput_fail_unless(t.tm_hour == hour, "hour");
  sput_fail_unless(t.tm_min == min, "min");
  sput_fail_unless(t.tm_sec == sec, "sec");
}

static void test_simple_changes()
{
  char buffer[80];
  set_time(0, 0, 2017, 0, 1, 14, 0, 0);
  strftime(buffer,80,"%c", &t);
  printf("%s\n", buffer);

  t = *increment_seconds(&t, 40);
  strftime(buffer,80,"%c", &t);
  printf("%s\n", buffer);

  check_time(0, 0, 2017, 0, 1, 14, 0, 40);

  t = *increment_seconds(&t, 3623);

  check_time(0, 0, 2017, 0, 1, 15, 1, 3);

  t = *increment_seconds(&t, 60 * 60 * 24 * 365);

  check_time(1, 0, 2018, 0, 1, 15, 1, 3);
}

static void test_fill_in_time() {
  t = *fill_in_time(0, 0, 0, 1, 1, 17);

  char buffer[80];
  strftime(buffer,80,"%c", &t);
  printf("%s\n", buffer);
  check_time(0, 0, 2017, 0, 1, 0, 0, 0);
}

static void test_cmp_alarm() {
  struct alarm a = {2, 0};
  struct tm t1 = *fill_in_time(59, 59, 1, 1, 1, 17);
  struct tm t2 = *fill_in_time(0, 0, 2, 1, 1, 17);
  struct tm t3 = *fill_in_time(0, 1, 2, 1, 1, 17);
  struct tm t4 = *fill_in_time(1, 0, 2, 1, 1, 17);
  struct tm t5 = *fill_in_time(0, 0, 3, 1, 1, 17);

  sput_fail_unless(cmp_alarm(&t1, &a) < 0, "before");
  sput_fail_unless(cmp_alarm(&t2, &a) == 0, "equal" );
  sput_fail_unless(cmp_alarm(&t3, &a) == 1, "past" );
  sput_fail_unless(cmp_alarm(&t4, &a) == 1, "past" );
  sput_fail_unless(cmp_alarm(&t5, &a) == 1, "past" );
}

int main(int argc, char *argv[]) {
  sput_start_testing();

  sput_enter_suite("increment_seconds()");
  sput_run_test(test_simple_changes);

  sput_enter_suite("test_fill_in_time()");
  sput_run_test(test_fill_in_time);

  sput_enter_suite("test_cmp_alarm()");
  sput_run_test(test_cmp_alarm);

  sput_finish_testing();

  return sput_get_return_value();
}
