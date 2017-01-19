#include <stdint.h>

enum button {
  LEFT,
  RIGHT
};

void register_button(enum button, void (*handler)(void));
uint8_t poll_buttons(void);
