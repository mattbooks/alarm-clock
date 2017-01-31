#include <avr/io.h>
#include "buttons.h"

struct button_state {
  uint32_t pressed_for_ticks;
};

const uint32_t UNHOLD_THRESH = 2;
const uint32_t REPEAT_MOD = 30;
const uint32_t REPEAT_THRESH = 200;

struct button_state left_state = {0};
struct button_state right_state = {0};

void (*left_handler)(void);
void (*right_handler)(void);

void register_button(enum button b, void (*handler)(void)) {
  switch(b) {
    case LEFT:
      left_handler = handler;
      break;
    case RIGHT:
      right_handler = handler;
      break;
  }
}

uint32_t get_ticks(enum button b) {
  switch (b) {
    case LEFT:
      return left_state.pressed_for_ticks;
    case RIGHT:
      return right_state.pressed_for_ticks;
  }

  return 0;
}

uint8_t get_button(enum button b) {
  switch (b) {
    case LEFT:
      return (PIND & (1<<PD0)) == 0 ? 1 : 0;
    case RIGHT:
      return (PIND & (1<<PD1)) == 0 ? 1 : 0;
  }

  return 0;
}

void tick(enum button b) {
  switch (b) {
    case LEFT:
      left_state.pressed_for_ticks += 1;
      break;
    case RIGHT:
      right_state.pressed_for_ticks += 1;
      break;
  }
}

void untick(enum button b) {
  switch (b) {
    case LEFT:
      left_state.pressed_for_ticks = 0;
      break;
    case RIGHT:
      right_state.pressed_for_ticks = 0;
      break;
  }
}

void poll_button(enum button b, void(*handler)(void)) {
  if (get_button(b)) {
    if (get_ticks(b) == 0 || (get_ticks(b) > REPEAT_THRESH && get_ticks(b) % REPEAT_MOD == 0)) {
      handler();
    }
    tick(b);
  } else {
    untick(b);
  }
}

void poll_buttons() {
  poll_button(LEFT, left_handler);
  poll_button(RIGHT, right_handler);
}
