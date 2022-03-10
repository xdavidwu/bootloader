#ifndef INIT_H
#define INIT_H

#include "uart.h"
#include <stdint.h>

void main(const struct uart_impl *uart, uint8_t *target,
	uint8_t *initrd_target);

#endif
