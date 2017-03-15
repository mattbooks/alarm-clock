#include "../config/config.h"
#include "light-control.h"

uint8_t enabled = 0;
uint8_t counter = 0;
uint8_t threshold = 0xF0;

void init_lights() {
  // do nothing because lights are not on PWM pins :(
}

void set_light_pin() {
  if (enabled) {
    LED_GRP |= 1<<LED_PIN;
  } else {
    LED_GRP &= ~(1<<LED_PIN);
  }
}

void toggle_lights() {
  enabled = 1 ^ enabled;
  set_light_pin();
}

void set_lights(uint8_t en) {
  enabled = en;
  set_light_pin();
}

void dim_lights() {
  // do nothing because lights are not on PWM pins :(
}

void raise_lights() {
  // do nothing because lights are not on PWM pins :(
}
