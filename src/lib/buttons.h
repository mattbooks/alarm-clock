#include <stdint.h>

enum button {
  LEFT,
  RIGHT
};

void register_button(enum button, void (*handler)(void));
void poll_buttons(void);
