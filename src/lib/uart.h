<<<<<<< HEAD:src/lib/uart.h
/*! \file uart.h \brief UART driver with buffer support. */
//*****************************************************************************
//
// File Name	: 'uart.h'
// Title		: UART driver with buffer support
// Author		: Pascal Stang - Copyright (C) 2000-2002
// Created		: 11/22/2000
// Revised		: 02/01/2004
// Version		: 1.3
// Target MCU	: ATMEL AVR Series
// Editor Tabs	: 4
//
// This code is distributed under the GNU Public License
//		which can be found at http://www.gnu.org/licenses/gpl.txt
//
///	\ingroup driver_avr
/// \defgroup uart UART Driver/Function Library (uart.c)
/// \code #include "uart.h" \endcode
/// \par Overview
///		This library provides both buffered and unbuffered transmit and receive
///		functions for the AVR processor UART.  Buffered access means that the
///		UART can transmit and receive data in the "background", while your code
///		continues executing.  Also included are functions to initialize the
///		UART, set the baud rate, flush the buffers, and check buffer status.
///
/// \note	For full text output functionality, you may wish to use the rprintf
///		functions along with this driver.
///
/// \par About UART operations
///		Most Atmel AVR-series processors contain one or more hardware UARTs
///		(aka, serial ports).  UART serial ports can communicate with other 
///		serial ports of the same type, like those used on PCs.  In general,
///		UARTs are used to communicate with devices that are RS-232 compatible
///		(RS-232 is a certain kind of serial port).
///	\par
///		By far, the most common use for serial communications on AVR processors
///		is for sending information and data to a PC running a terminal program.
///		Here is an exmaple:
///	\code
/// uartInit();					// initialize UART (serial port)
/// uartSetBaudRate(9600);		// set UART speed to 9600 baud
/// rprintfInit(uartSendByte);  // configure rprintf to use UART for output
/// rprintf("Hello World\r\n");	// send "hello world" message via serial port
/// \endcode
///
/// \warning The CPU frequency (F_CPU) must be set correctly in \c global.h
///		for the UART library to calculate correct baud rates.  Furthermore,
///		certain CPU frequencies will not produce exact baud rates due to
///		integer frequency division round-off.  See your AVR processor's
///		 datasheet for full details.
//
//*****************************************************************************
//@{

#ifndef UART_H
#define UART_H

#include <avr/io.h>
#include <inttypes.h>

#include "buffer.h"

#ifndef outb
	#define	outb(addr, data)	addr = (data)
#endif
#ifndef inb
	#define	inb(addr)			(addr)
#endif
#ifndef outw
	#define	outw(addr, data)	addr = (data)
#endif
#ifndef inw
	#define	inw(addr)			(addr)
#endif
#ifndef cbi
	#define cbi(reg,bit)	reg &= ~(_BV(bit))
#endif
#ifndef sbi
	#define sbi(reg,bit)	reg |= (_BV(bit))
#endif
#ifndef cli
	#define cli()			__asm__ __volatile__ ("cli" ::)
#endif
#ifndef BV
	#define BV _BV
#endif

//! Default uart baud rate.
/// This is the default speed after a uartInit() command,
/// and can be changed by using uartSetBaudRate().
#define UART_DEFAULT_BAUD_RATE	9600

// buffer memory allocation defines
// buffer sizes
#ifndef UART_TX_BUFFER_SIZE
//! Number of bytes for uart transmit buffer.
/// Do not change this value in uart.h, but rather override
/// it with the desired value defined in your project's global.h
#define UART_TX_BUFFER_SIZE		0x0040
#endif
#ifndef UART_RX_BUFFER_SIZE
//! Number of bytes for uart receive buffer.
/// Do not change this value in uart.h, but rather override
/// it with the desired value defined in your project's global.h
#define UART_RX_BUFFER_SIZE		0x0040
#endif

// define this key if you wish to use
// external RAM for the	UART buffers
//#define UART_BUFFER_EXTERNAL_RAM
#ifdef UART_BUFFER_EXTERNAL_RAM
	// absolute address of uart buffers
	#define UART_TX_BUFFER_ADDR	0x1000
	#define UART_RX_BUFFER_ADDR	0x1100
#endif

//! Type of interrupt handler to use for uart interrupts.
/// Value may be SIGNAL or INTERRUPT.
/// \warning Do not change unless you know what you're doing.
#ifndef UART_INTERRUPT_HANDLER
#define UART_INTERRUPT_HANDLER	SIGNAL
#endif

// compatibility with most newer processors
#ifdef UCSRB
	#define UCR					UCSRB
#endif
// compatibility with old Mega processors
#if defined(UBRR) && !defined(UBRRL)
	#define	UBRRL				UBRR
#endif
#if defined(__AVR_ATmega328P__)
   #define UDR               UDR0
   #define UCR               UCSR0B
   #define RXCIE            RXCIE0
   #define TXCIE            TXCIE0
   #define RXC               RXC0
   #define TXC               TXC0
   #define RXEN            RXEN0
   #define TXEN            TXEN0
   #define UBRRL            UBRR0L
   #define UBRRH            UBRR0H
#endif
// compatibility with megaXX8 processors
#if	defined(__AVR_ATmega88__)	|| \
	defined(__AVR_ATmega168__)	|| \
	defined(__AVR_ATmega644__)
	#define UDR					UDR0
	#define UCR					UCSR0B
	#define RXCIE				RXCIE0
	#define TXCIE				TXCIE0
	#define RXC					RXC0
	#define TXC					TXC0
	#define RXEN				RXEN0
	#define TXEN				TXEN0
	#define UBRRL				UBRR0L
	#define UBRRH				UBRR0H
	#define SIG_UART_TRANS		SIG_USART_TRANS
	#define SIG_UART_RECV		SIG_USART_RECV
	#define SIG_UART_DATA		SIG_USART_DATA
#endif
// compatibility with mega169 processors
#if	defined(__AVR_ATmega169__)
	#define SIG_UART_TRANS		SIG_USART_TRANS
	#define SIG_UART_RECV		SIG_USART_RECV
	#define SIG_UART_DATA		SIG_USART_DATA
#endif

// compatibility with dual-uart processors (untested YMMV)
// (if you need to use both uarts, please use the uart2 library)
#ifndef USART_RX_vect
  #ifdef UART_USE_UART1
    #if defined(UART1_RX_vect)
      #define USART_RX_vect UART1_RX_vect
    #elif defined(USART1_RX_vect)
      #define USART_RX_vect USART1_RX_vect
    #endif
  #else
    #if defined(UART0_RX_vect)
      #define USART_RX_vect UART0_RX_vect
    #elif defined(USART0_RX_vect)
      #define USART_RX_vect USART0_RX_vect
    #endif
  #endif
#endif

#ifndef USART_TX_vect
  #ifdef UART_USE_UART1
    #if defined(UART1_TX_vect)
      #define USART_TX_vect UART1_TX_vect
    #elif defined(USART1_TX_vect)
      #define USART_TX_vect USART1_TX_vect
    #endif
  #else
    #if defined(UART0_TX_vect)
      #define USART_TX_vect UART0_TX_vect
    #elif defined(USART0_TX_vect)
      #define USART_TX_vect USART0_TX_vect
    #endif
  #endif
#endif

#ifndef UDR
  #ifdef UART_USE_UART1
    #define UDR UDR1
    #define UCR UCSR1B
    #define UBRRL UBRR1
    #define UBRRH UBRR1H
  #else
    #define UDR UDR0
    #define UCR UCSR0B
    #define UBRRL UBRR0
    #define UBRRH UBRR0H
  #endif
#endif

// functions

//! Initializes uart.
/// \note	After running this init function, the processor
/// I/O pins that used for uart communications (RXD, TXD)
/// are no long available for general purpose I/O.
void uartInit(void);

//! Initializes transmit and receive buffers.
/// Automatically called from uartInit()
void uartInitBuffers(void);

//! Redirects received data to a user function.
///
void uartSetRxHandler(void (*rx_func)(unsigned char c));

//! Sets the uart baud rate.
/// Argument should be in bits-per-second, like \c uartSetBaudRate(9600);
void uartSetBaudRate(uint32_t baudrate);

//! Returns pointer to the receive buffer structure.
///
cBuffer* uartGetRxBuffer(void);

//! Returns pointer to the transmit buffer structure.
///
cBuffer* uartGetTxBuffer(void);

//! Sends a single byte over the uart.
/// \note This function waits for the uart to be ready,
/// therefore, consecutive calls to uartSendByte() will
/// go only as fast as the data can be sent over the
/// serial port.
void uartSendByte(uint8_t data);

//! Gets a single byte from the uart receive buffer.
/// Returns the byte, or -1 if no byte is available (getchar-style).
int uartGetByte(void);

//! Gets a single byte from the uart receive buffer.
/// Function returns TRUE if data was available, FALSE if not.
/// Actual data is returned in variable pointed to by "data".
/// Example usage:
/// \code
/// char myReceivedByte;
/// uartReceiveByte( &myReceivedByte );
/// \endcode
uint8_t uartReceiveByte(uint8_t* data);

//! Returns TRUE/FALSE if receive buffer is empty/not-empty.
///
uint8_t uartReceiveBufferIsEmpty(void);

//! Flushes (deletes) all data from receive buffer.
///
void uartFlushReceiveBuffer(void);

//! Add byte to end of uart Tx buffer.
///	Returns TRUE if successful, FALSE if failed (no room left in buffer).
uint8_t uartAddToTxBuffer(uint8_t data);

//! Begins transmission of the transmit buffer under interrupt control.
///
void uartSendTxBuffer(void);

//! Sends a block of data via the uart using interrupt control.
/// \param buffer	pointer to data to be sent
///	\param nBytes	length of data (number of bytes to sent)
uint8_t  uartSendBuffer(char *buffer, uint16_t nBytes);

uint8_t  uartSendString(char *buffer);

#endif
//@}


=======
#ifndef UART_H
#define UART_H


/************************************************************************
Title:    Interrupt UART library with receive/transmit circular buffers
Author:   Andy Gock
Software: AVR-GCC 4.1, AVR Libc 1.4
Hardware: any AVR with built-in UART, tested on AT90S8515 & ATmega8 at 4 Mhz
License:  GNU General Public License 
Usage:    see Doxygen manual

Based on original library by Peter Fluery, Tim Sharpe, Nicholas Zambetti.

https://github.com/andygock/avr-uart

LICENSE:
	Copyright (C) 2012 Andy Gock

	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

LICENSE:
    Copyright (C) 2006 Peter Fleury

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    
************************************************************************/

/************************************************************************
uart_available, uart_flush, uart1_available, and uart1_flush functions
were adapted from the Arduino HardwareSerial.h library by Tim Sharpe on 
11 Jan 2009.  The license info for HardwareSerial.h is as follows:

  HardwareSerial.h - Hardware serial library for Wiring
  Copyright (c) 2006 Nicholas Zambetti.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
************************************************************************/

/************************************************************************
Changelog for modifications made by Tim Sharpe, starting with the current
  library version on his Web site as of 05/01/2009. 

Date        Description
=========================================================================
05/12/2009  Added Arduino-style available() and flush() functions for both
			supported UARTs.  Really wanted to keep them out of the library, so
			that it would be as close as possible to Peter Fleury's original
			library, but has scoping issues accessing internal variables from
			another program.  Go C!

************************************************************************/

/** 
 *  @defgroup avr-uart UART Library
 *  @code #include <uart.h> @endcode
 * 
 *  @brief Interrupt UART library using the built-in UART with transmit and receive circular buffers. 
 *
 *  This library can be used to transmit and receive data through the built in UART. 
 *
 *  An interrupt is generated when the UART has finished transmitting or
 *  receiving a byte. The interrupt handling routines use circular buffers
 *  for buffering received and transmitted data.
 *
 *  The UART_RXn_BUFFER_SIZE and UART_TXn_BUFFER_SIZE constants define
 *  the size of the circular buffers in bytes. Note that these constants must be a power of 2.
 *
 *  You need to define these buffer sizes in uart.h
 *
 *  @note Based on Atmel Application Note AVR306
 *  @author Andy Gock <andy@gock.net>
 *  @note Based on original library by Peter Fleury and Tim Sharpe.
 */
 
/**@{*/
#include <stdint.h>
#include <avr/io.h>

#if (__GNUC__ * 100 + __GNUC_MINOR__) < 304
#error "This library requires AVR-GCC 3.4 or later, update to newer AVR-GCC compiler !"
#endif

/*
 * constants and macros
 */

/* Enable USART 1, 2, 3 as required */
#define USART0_ENABLED
//#define USART1_ENABLED
//#define USART2_ENABLED 
//#define USART3_ENABLED

/* Set size of receive and transmit buffers */

#ifndef UART_RX0_BUFFER_SIZE
	#define UART_RX0_BUFFER_SIZE 128 /**< Size of the circular receive buffer, must be power of 2 */
#endif
#ifndef UART_RX1_BUFFER_SIZE
	#define UART_RX1_BUFFER_SIZE 128 /**< Size of the circular receive buffer, must be power of 2 */
#endif
#ifndef UART_RX2_BUFFER_SIZE
	#define UART_RX2_BUFFER_SIZE 128 /**< Size of the circular receive buffer, must be power of 2 */
#endif
#ifndef UART_RX3_BUFFER_SIZE
	#define UART_RX3_BUFFER_SIZE 128 /**< Size of the circular receive buffer, must be power of 2 */
#endif

#ifndef UART_TX0_BUFFER_SIZE
	#define UART_TX0_BUFFER_SIZE 128 /**< Size of the circular transmit buffer, must be power of 2 */
#endif
#ifndef UART_TX1_BUFFER_SIZE
	#define UART_TX1_BUFFER_SIZE 128 /**< Size of the circular transmit buffer, must be power of 2 */
#endif
#ifndef UART_TX2_BUFFER_SIZE
	#define UART_TX2_BUFFER_SIZE 128 /**< Size of the circular transmit buffer, must be power of 2 */
#endif
#ifndef UART_TX3_BUFFER_SIZE
	#define UART_TX3_BUFFER_SIZE 128 /**< Size of the circular transmit buffer, must be power of 2 */
#endif

/* Check buffer sizes are not too large for 8-bit positioning */

#if (UART_RX0_BUFFER_SIZE > 256 & !defined(USART0_LARGE_BUFFER))
	#error "Buffer too large, please use -DUSART0_LARGE_BUFFER switch in compiler options"
#endif

#if (UART_RX1_BUFFER_SIZE > 256 & !defined(USART1_LARGE_BUFFER))
	#error "Buffer too large, please use -DUSART1_LARGE_BUFFER switch in compiler options"
#endif

#if (UART_RX2_BUFFER_SIZE > 256 & !defined(USART2_LARGE_BUFFER))
	#error "Buffer too large, please use -DUSART2_LARGE_BUFFER switch in compiler options"
#endif

#if (UART_RX3_BUFFER_SIZE > 256 & !defined(USART3_LARGE_BUFFER))
	#error "Buffer too large, please use -DUSART3_LARGE_BUFFER switch in compiler options"
#endif

/* Check buffer sizes are not too large for *_LARGE_BUFFER operation (16-bit positioning) */

#if (UART_RX0_BUFFER_SIZE > 65536)
	#error "Buffer too large, maximum allowed is 65536 bytes"
#endif

#if (UART_RX1_BUFFER_SIZE > 65536)
	#error "Buffer too large, maximum allowed is 65536 bytes"
#endif

#if (UART_RX2_BUFFER_SIZE > 65536)
	#error "Buffer too large, maximum allowed is 65536 bytes"
#endif

#if (UART_RX3_BUFFER_SIZE > 65536)
	#error "Buffer too large, maximum allowed is 65536 bytes"
#endif

/** @brief  UART Baudrate Expression
 *  @param  xtalCpu  system clock in Mhz, e.g. 4000000L for 4Mhz          
 *  @param  baudRate baudrate in bps, e.g. 1200, 2400, 9600     
 */
#define UART_BAUD_SELECT(baudRate,xtalCpu) (((xtalCpu)+8UL*(baudRate))/(16UL*(baudRate))-1UL)

/** @brief  UART Baudrate Expression for ATmega double speed mode
 *  @param  xtalCpu  system clock in Mhz, e.g. 4000000L for 4Mhz           
 *  @param  baudRate baudrate in bps, e.g. 1200, 2400, 9600     
 */
#define UART_BAUD_SELECT_DOUBLE_SPEED(baudRate,xtalCpu) ((((xtalCpu)+4UL*(baudRate))/(8UL*(baudRate))-1)|0x8000)

/* test if the size of the circular buffers fits into SRAM */

#if defined(USART0_ENABLED) && ( (UART_RX0_BUFFER_SIZE+UART_TX0_BUFFER_SIZE) >= (RAMEND-0x60 ) )
#error "size of UART_RX0_BUFFER_SIZE + UART_TX0_BUFFER_SIZE larger than size of SRAM"
#endif

#if defined(USART1_ENABLED) && ( (UART_RX1_BUFFER_SIZE+UART_TX1_BUFFER_SIZE) >= (RAMEND-0x60 ) )
#error "size of UART_RX1_BUFFER_SIZE + UART_TX1_BUFFER_SIZE larger than size of SRAM"
#endif

#if defined(USART2_ENABLED) && ( (UART_RX2_BUFFER_SIZE+UART_RX2_BUFFER_SIZE) >= (RAMEND-0x60 ) )
#error "size of UART_RX2_BUFFER_SIZE + UART_TX2_BUFFER_SIZE larger than size of SRAM"
#endif

#if defined(USART3_ENABLED) && ( (UART_RX3_BUFFER_SIZE+UART_RX3_BUFFER_SIZE) >= (RAMEND-0x60 ) )
#error "size of UART_RX3_BUFFER_SIZE + UART_TX3_BUFFER_SIZE larger than size of SRAM"
#endif

/* 
** high byte error return code of uart_getc()
*/
#define UART_FRAME_ERROR      0x0800              /**< Framing Error by UART       */
#define UART_OVERRUN_ERROR    0x0400              /**< Overrun condition by UART   */
#define UART_BUFFER_OVERFLOW  0x0200              /**< receive ringbuffer overflow */
#define UART_NO_DATA          0x0100              /**< no receive data available   */

/* Macros, to allow use of legacy names */

#define uart_init(b)      uart0_init(b)
#define uart_getc()       uart0_getc()
#define uart_putc(d)      uart0_putc(d)
#define uart_puts(s)      uart0_puts(s)
#define uart_puts_p(s)    uart0_puts_p(s)
#define uart_available()  uart0_available()
#define uart_flush()      uart0_flush()

/*
** function prototypes
*/

/**
   @brief   Initialize UART and set baudrate 
   @param   baudrate Specify baudrate using macro UART_BAUD_SELECT()
   @return  none
*/
extern void uart0_init(uint16_t baudrate);


/**
 *  @brief   Get received byte from ringbuffer
 *
 * Returns in the lower byte the received character and in the 
 * higher byte the last receive error.
 * UART_NO_DATA is returned when no data is available.
 *
 *  @return  lower byte:  received byte from ringbuffer
 *  @return  higher byte: last receive status
 *           - \b 0 successfully received data from UART
 *           - \b UART_NO_DATA           
 *             <br>no receive data available
 *           - \b UART_BUFFER_OVERFLOW   
 *             <br>Receive ringbuffer overflow.
 *             We are not reading the receive buffer fast enough, 
 *             one or more received character have been dropped 
 *           - \b UART_OVERRUN_ERROR     
 *             <br>Overrun condition by UART.
 *             A character already present in the UART UDR register was 
 *             not read by the interrupt handler before the next character arrived,
 *             one or more received characters have been dropped.
 *           - \b UART_FRAME_ERROR       
 *             <br>Framing Error by UART
 */
extern uint16_t uart0_getc(void);

/**
 *  @brief   Peek at next byte in ringbuffer
 *
 * Returns the next byte (character) of incoming UART data without removing it from the
 * internal ring buffer. That is, successive calls to uartN_peek() will return the same
 * character, as will the next call to uartN_getc().
 *
 * UART_NO_DATA is returned when no data is available.
 *
 *  @return  lower byte:  next byte in ringbuffer
 *  @return  higher byte: last receive status
 *           - \b 0 successfully received data from UART
 *           - \b UART_NO_DATA           
 *             <br>no receive data available
 *           - \b UART_BUFFER_OVERFLOW   
 *             <br>Receive ringbuffer overflow.
 *             We are not reading the receive buffer fast enough, 
 *             one or more received character have been dropped 
 *           - \b UART_OVERRUN_ERROR     
 *             <br>Overrun condition by UART.
 *             A character already present in the UART UDR register was 
 *             not read by the interrupt handler before the next character arrived,
 *             one or more received characters have been dropped.
 *           - \b UART_FRAME_ERROR       
 *             <br>Framing Error by UART
 */
extern uint16_t uart0_peek(void);

/**
 *  @brief   Put byte to ringbuffer for transmitting via UART
 *  @param   data byte to be transmitted
 *  @return  none
 */
extern void uart0_putc(uint8_t data);


/**
 *  @brief   Put string to ringbuffer for transmitting via UART
 *
 *  The string is buffered by the uart library in a circular buffer
 *  and one character at a time is transmitted to the UART using interrupts.
 *  Blocks if it can not write the whole string into the circular buffer.
 * 
 *  @param   s string to be transmitted
 *  @return  none
 */
extern void uart0_puts(const char *s );


/**
 * @brief    Put string from program memory to ringbuffer for transmitting via UART.
 *
 * The string is buffered by the uart library in a circular buffer
 * and one character at a time is transmitted to the UART using interrupts.
 * Blocks if it can not write the whole string into the circular buffer.
 *
 * @param    s program memory string to be transmitted
 * @return   none
 * @see      uart0_puts_P
 */
extern void uart0_puts_p(const char *s );

/**
 * @brief    Macro to automatically put a string constant into program memory
 * \param    __s string in program memory
 */
#define uart_puts_P(__s)       uart0_puts_p(PSTR(__s))
#define uart0_puts_P(__s)      uart0_puts_p(PSTR(__s))

/**
 *  @brief   Return number of bytes waiting in the receive buffer
 *  @return  bytes waiting in the receive buffer
 */
extern uint16_t uart0_available(void);

/**
 *  @brief   Flush bytes waiting in receive buffer
 */
extern void uart0_flush(void);


/** @brief  Initialize USART1 (only available on selected ATmegas) @see uart_init */
extern void uart1_init(uint16_t baudrate);
/** @brief  Get received byte of USART1 from ringbuffer. (only available on selected ATmega) @see uart_getc */
extern uint16_t uart1_getc(void);
/** @brief  Peek at next byte in USART1 ringbuffer */
extern uint16_t uart1_peek(void);
/** @brief  Put byte to ringbuffer for transmitting via USART1 (only available on selected ATmega) @see uart_putc */
extern void uart1_putc(uint8_t data);
/** @brief  Put string to ringbuffer for transmitting via USART1 (only available on selected ATmega) @see uart_puts */
extern void uart1_puts(const char *s );
/** @brief  Put string from program memory to ringbuffer for transmitting via USART1 (only available on selected ATmega) @see uart_puts_p */
extern void uart1_puts_p(const char *s );
/** @brief  Macro to automatically put a string constant into program memory */
#define uart1_puts_P(__s)       uart1_puts_p(PSTR(__s))
/** @brief   Return number of bytes waiting in the receive buffer */
extern uint16_t uart1_available(void);
/** @brief   Flush bytes waiting in receive buffer */
extern void uart1_flush(void);


/** @brief  Initialize USART2 (only available on selected ATmegas) @see uart_init */
extern void uart2_init(uint16_t baudrate);
/** @brief  Get received byte of USART2 from ringbuffer. (only available on selected ATmega) @see uart_getc */
extern uint16_t uart2_getc(void);
/** @brief  Peek at next byte in USART2 ringbuffer */
extern uint16_t uart2_peek(void);
/** @brief  Put byte to ringbuffer for transmitting via USART2 (only available on selected ATmega) @see uart_putc */
extern void uart2_putc(uint8_t data);
/** @brief  Put string to ringbuffer for transmitting via USART2 (only available on selected ATmega) @see uart_puts */
extern void uart2_puts(const char *s );
/** @brief  Put string from program memory to ringbuffer for transmitting via USART2 (only available on selected ATmega) @see uart_puts_p */
extern void uart2_puts_p(const char *s );
/** @brief  Macro to automatically put a string constant into program memory */
#define uart2_puts_P(__s)       uart2_puts_p(PSTR(__s))
/** @brief   Return number of bytes waiting in the receive buffer */
extern uint16_t uart2_available(void);
/** @brief   Flush bytes waiting in receive buffer */
extern void uart2_flush(void);


/** @brief  Initialize USART3 (only available on selected ATmegas) @see uart_init */
extern void uart3_init(uint16_t baudrate);
/** @brief  Get received byte of USART3 from ringbuffer. (only available on selected ATmega) @see uart_getc */
extern uint16_t uart3_getc(void);
/** @brief  Peek at next byte in USART3 ringbuffer */
extern uint16_t uart3_peek(void);
/** @brief  Put byte to ringbuffer for transmitting via USART3 (only available on selected ATmega) @see uart_putc */
extern void uart3_putc(uint8_t data);
/** @brief  Put string to ringbuffer for transmitting via USART3 (only available on selected ATmega) @see uart_puts */
extern void uart3_puts(const char *s );
/** @brief  Put string from program memory to ringbuffer for transmitting via USART3 (only available on selected ATmega) @see uart_puts_p */
extern void uart3_puts_p(const char *s );
/** @brief  Macro to automatically put a string constant into program memory */
#define uart3_puts_P(__s)       uart3_puts_p(PSTR(__s))
/** @brief   Return number of bytes waiting in the receive buffer */
extern uint16_t uart3_available(void);
/** @brief   Flush bytes waiting in receive buffer */
extern void uart3_flush(void);

/**@}*/

#endif // UART_H 

>>>>>>> Swap uart library:src/lib/uart/uart.h
