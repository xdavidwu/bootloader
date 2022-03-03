#include "init.h"

extern void boot();

void main(const struct uart_impl *uart, uint8_t *target) {
	const char *init_msg = "\r\n\x1b[2J\x1b[H";
	while (*init_msg) {
		uart->putc(*init_msg);
		init_msg++;
	}
	const char *wait_msg = "Waiting for image\r\n";
	while (*wait_msg) {
		uart->putc(*wait_msg);
		wait_msg++;
	}
	uint32_t sz = ((uint32_t)uart->getc() << 24) +
		((uint32_t)uart->getc() << 16) +
		((uint32_t)uart->getc() << 8) + uart->getc();
	const char *recv_msg = "Receiving image\r\n";
	while (*recv_msg) {
		uart->putc(*recv_msg);
		recv_msg++;
	}
	while (sz--) {
		*target = uart->getc();
		target++;
	}
	const char *boot_msg = "Booting image\r\n";
	while (*boot_msg) {
		uart->putc(*boot_msg);
		boot_msg++;
	}
	boot();
}
