#include "interrupt.h"
#include <kernel/irq.h>
#include <kernel/io.h>
#include <stdio.h>
#include <stdint.h>

void
general_interrupt_handler(trap_frame_t* frame)
{
    int ret = call_IRQ_handler((void*)frame);
    if (ret != 0)
        printf("Error[%d]: intno: %d %s\n", ret, frame->trapno,
                str_IRQ_error(ret) );
    if (frame->trapno & 0x08) {
        _outb(PIC_SLAVE_CTRL, IRQ_EOI);
    } else {
        _outb(PIC_MASTER_CTRL, IRQ_EOI);
    }
}

void
general_trap_handler(trap_frame_t* frame)
{
    printf("trap #%d\n", frame->trapno);
}

void
fill_idr()
{

}
