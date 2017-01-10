DEVICE = atmega328p
MCU = atmega328p
AVRDUDE_DEVICE = m328p

CFLAGS=-g -Wall -mcall-prologues -mmcu=$(MCU) $(DEVICE_SPECIFIC_CFLAGS) -Os
CC=avr-gcc
OBJ2HEX=avr-objcopy 
LDFLAGS=-Wl,-gc-sections -Wl,-relax

PORT ?= usb
AVRDUDE=avrdude
TARGET=alarm-clock
OBJECT_FILES=alarm-clock.o seven-seg/seven-seg.o lib/buffer/buffer.o lib/buttons/buttons.o lib/ds_rtc/rtc.o lib/ds_rtc/twi.o lib/ds_rtc/twi-lowlevel.o lib/uart/uart.o

all: $(TARGET).hex

clean:
	rm -f *.o *.hex *.obj *.hex

%.hex: %.obj
	$(OBJ2HEX) -R .eeprom -O ihex $< $@

test.o: test.c

%.obj: $(OBJECT_FILES)
	$(CC) $(CFLAGS) $(OBJECT_FILES) $(LDFLAGS) -o $@

program: $(TARGET).hex
	$(AVRDUDE) -p $(AVRDUDE_DEVICE) -c usbtiny -P $(PORT) -U flash:w:$(TARGET).hex
