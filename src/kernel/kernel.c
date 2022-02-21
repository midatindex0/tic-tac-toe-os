#include "../cpu/isr.h"
#include "../drivers/screen.h"
#include "kernel.h"
#include "../libc/string.h"
#include "../libc/mem.h"
#include <stdint.h>

#include "../tictactoe/draw_grid.h"
#include "../tictactoe/keystrokes.h"

int finished = 0;

void kernel_main()
{
    clear_screen();
    isr_install();
    irq_install();

    kprint("  _______ _____ _____    _______ ____   _____ \n"
           " |__   __|_   _/ ____|  |__   __/ __ \\ / ____|\n"
           "    | |    | || |          | | | |  | | (___  \n"
           "    | |    | || |          | | | |  | |\\___ \\ \n"
           "    | |   _| || |____      | | | |__| |____) |\n"
           "    |_|  |_____\\_____|     |_|  \\____/|_____/ \n"
           "                                              \n"
           "                                              \n",
           0x0e);

    kprint("Dual player Tic Tac Toe on bare metal from scratch.\nBy lonely-code-cube.\nGithub profile: ", 0x0f);
    kprint("https://github.com/lonely-code-cube\n", 0x0c);
    kprint("Project repo: ", 0x0f);
    kprint("https://github.com/lonely-code-cube/tic-tac-toe-os\n", 0x0c);
    kprint("Refer README in project repo for more info\n", 0x0f);
    kprint("This is my second ever program written in C after hello world.\n\n", 0x0f);
    kprint("Controls: Use ARROWS to move around, SPACE to enter cross or round,\nENTER to restart game, DEL to reset score, ESC to view score board and halt CPU.\n", 0x0a);

    kprint("Press ENTER to start a new game\n", 0x0c);
}

int controls = 1;
void init_game()
{
    clear_screen();
    draw();
    controls = 1;
}

void lock_controls()
{
    controls = 0;
}

void user_input(uint8_t scancode)
{
    switch (scancode)
    {
        {
        case 0x48: // up
            if (controls == 1)
                take_bind(0);
            break;
        case 0x4b: // left
            if (controls == 1)
                take_bind(1);
            break;
        case 0x4d: // right
            if (controls == 1)
                take_bind(2);
            break;
        case 0x50: // down
            if (controls == 1)
                take_bind(3);
            break;
        case 0x39: // space
            if (controls == 1)
                take_bind(4);
            kprint_at(" ", 78, 24, 0x00);
            break;
        case 0x1c: // enter
            init_game();
            take_bind(5);
            break;
        case 0x53: // del
            init_game();
            take_bind(6);
            break;
        case 0x01: //esc
            take_bind(7);
            asm volatile("hlt");
            break;
        default:
            break;
        }
    }
}