#include <stdint.h>
#include <time.h>

struct tm* fill_in_time(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint16_t);
struct tm* increment_seconds(struct tm*, int32_t);
