#include "keyboard.h"
#include "../cpu/ports.h"
#include "../cpu/isr.h"
#include "screen.h"
#include "../libc/string.h"
#include "../libc/function.h"
#include "../kernel/kernel.h"
#include <stdint.h>

static void keyboard_callback(registers_t *regs)
{
    /* The PIC leaves us the scancode in port 0x60 */
    uint8_t scancode = port_byte_in(0x60);
    if (scancode > 0x53)
        return;
    else
    {
        user_input(scancode);
    }
    UNUSED(regs);
}

void init_keyboard()
{
    register_interrupt_handler(IRQ1, keyboard_callback);
}
