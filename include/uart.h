#ifndef UART_H
#define UART_H

#include <stdint.h>

struct uart_impl {
	void (*putc)(uint8_t);
	uint8_t (*getc)();
};

#endif
