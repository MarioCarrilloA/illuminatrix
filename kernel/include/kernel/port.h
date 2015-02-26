#include <stddef.h>
#include <stdint.h>
#define KEYBOARD_PORT_R 0x60

static inline uint8_t _port_readb(uint16_t port)
{
	uint8_t ret;
	asm volatile ("inb %1, %0" : "=a" (ret) : "dN" (port));
	return ret;
}

static inline void _port_writeb(uint16_t port, uint8_t val)
{
	asm volatile ("outb %0, %1" : : "a"(val), "dN"(port));
}
