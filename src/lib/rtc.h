/*
 * DS RTC Library: DS1307 and DS3231 driver library
 * (C) 2011 Akafugu Corporation
 *
 * This program is free software; you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation; either version 2 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 */

#ifndef DS1307_H
#define DS1307_H

#include <stdbool.h>
#include <avr/io.h>
#include "twi.h"

#define DS1307_SLAVE_ADDR 0b11010000

// statically allocated 
extern struct tm _tm;

// Initialize the RTC and autodetect type (DS1307 or DS3231)
void rtc_init(void);

// Autodetection
bool rtc_is_ds1307(void);
bool rtc_is_ds3231(void);

void rtc_set_ds1307(void);
void rtc_set_ds3231(void);

// Get/set time
// Gets the time: Supports both 24-hour and 12-hour mode
struct tm* rtc_get_time(void);
// Sets the time: Supports both 24-hour and 12-hour mode
void rtc_set_time(struct tm* tm_);

// start/stop clock running (DS1307 only)
void rtc_run_clock(bool run);
bool rtc_is_clock_running(void);

// Read Temperature (DS3231 only)
void  ds3231_get_temp_int(int8_t* i, uint8_t* f);
void rtc_force_temp_conversion(uint8_t block);

void rtc_set_alarm(uint16_t);
uint16_t rtc_get_alarm(void);

// SRAM read/write DS1307 only
void rtc_get_sram(uint8_t* data);
void rtc_set_sram(uint8_t *data);
uint8_t rtc_get_sram_byte(uint8_t offset);
void rtc_set_sram_byte(uint8_t b, uint8_t offset);

#endif
