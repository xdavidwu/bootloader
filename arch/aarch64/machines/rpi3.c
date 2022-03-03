#include "init.h"
#include "bcm2835_mini_uart.h"

void machine_init() {
	const struct uart_impl *uart = bcm2835_mini_uart_setup();
	main(uart, (uint8_t *)0x80000);
}
