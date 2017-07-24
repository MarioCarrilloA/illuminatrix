#ifndef _KERNEL_PORT_H
#define _KERNEL_PORT_H

#include <stddef.h>
#include <stdint.h>

static inline uint8_t
_inb(uint16_t port)
{
    uint8_t ret;
    asm volatile ("inb %1, %0" : "=a" (ret) : "dN" (port));
    return ret;
}

static inline void
_outb(uint16_t port, uint8_t val)
{
    asm volatile ("outb %0, %1" : : "a"(val), "dN"(port));
}

static inline int are_interrupts_enabled()
{
        unsigned long flags;
        asm volatile ( "pushf\n\t"
                       "pop %0"
                       : "=g"(flags) );
        return flags & (1 << 9);
}

static inline void
wait_out()
{
    uint32_t i;
    for (i = 0; i < 1000; i++);
}
#endif
