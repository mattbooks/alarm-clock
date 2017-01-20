#include "buttons.h"

struct button_state {
  uint32_t pressed_for_ticks;
};

const uint32_t REPEAT_MOD = 100;

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
      return 0;
    case RIGHT:
      return 0;
  }

  return 0;
}

void poll_button(enum button b, void(*handler)(void)) {
  if (get_button(b) && get_ticks(b) == 0) {
    handler();
  } else if (get_button(b) && get_ticks(b) % REPEAT_MOD == 0) {
    handler();
  }
}

void poll_buttons() {
  poll_button(LEFT, left_handler);
  poll_button(RIGHT, right_handler);
}
