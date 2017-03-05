#define __AVR_ATmega168P__
#define F_CPU 20000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define HIGH 1
#define LOW 0

#define SEG_A_GRP PORTB
#define SEG_A_PIN PORTB2
#define SEG_B_GRP PORTC
#define SEG_B_PIN PORTC0
#define SEG_C_GRP PORTD
#define SEG_C_PIN PORTD5
#define SEG_D_GRP PORTD
#define SEG_D_PIN PORTD7
#define SEG_E_GRP PORTB
#define SEG_E_PIN PORTB0
#define SEG_F_GRP PORTB
#define SEG_F_PIN PORTB3
#define SEG_G_GRP PORTD
#define SEG_G_PIN PORTD4
#define SEG_DP_GRP PORTD
#define SEG_DP_PIN PORTD6
#define SEG_COLON_GRP PORTC
#define SEG_COLON_PIN PORTC1
#define SEG_DIG1_GRP PORTB
#define SEG_DIG1_PIN PORTB1
#define SEG_DIG2_GRP PORTB
#define SEG_DIG2_PIN PORTB4
#define SEG_DIG3_GRP PORTB
#define SEG_DIG3_PIN PORTB5
#define SEG_DIG4_GRP PORTD
#define SEG_DIG4_PIN PORTD3

#define SETUP_B_PORTS() DDRB |= (1<<DDB0) | (1<<DDB1) | (1<<DDB2) | (1<<DDB3) | (1<<DDB4) | (1<<DDB5)
#define SETUP_C_PORTS() DDRC |= (1<<DDC0) | (1<<DDC1) | (1<<DDC2) | (1<<DDC3)
#define SETUP_D_PORTS() DDRD |= (1<<DDD3) | (1<<DDD4) | (1<<DDD5) | (1<<DDD6) | (1<<DDD7)
