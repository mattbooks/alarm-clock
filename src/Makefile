DEVICE = atmega328p
MCU = atmega328p
AVRDUDE_DEVICE = m328p

CFLAGS=-g -Wall -mcall-prologues -mmcu=$(MCU) $(DEVICE_SPECIFIC_CFLAGS) -Os -DUART_RX0_BUFFER_SIZE=256 -DUART_TX0_BUFFER_SIZE=256
CC=avr-gcc
OBJ2HEX=avr-objcopy
LDFLAGS=-Wl,-gc-sections -Wl,-relax

PORT ?= usb
AVRDUDE=avrdude
TARGET=alarm-clock
DEPS=$(wildcard *.h) $(wildcard lib/*.h)
SOURCES=$(wildcard *.c) $(wildcard lib/*.c)

all: $(TARGET).hex

clean:
	rm -f *.o *.hex *.obj

%.hex: %.obj
	$(OBJ2HEX) -R .eeprom -O ihex $< $@

%.obj: $(SOURCES) $(DEPS)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

program: $(TARGET).hex
	$(AVRDUDE) -p $(AVRDUDE_DEVICE) -c usbtiny -P $(PORT) -U flash:w:$(TARGET).hex
