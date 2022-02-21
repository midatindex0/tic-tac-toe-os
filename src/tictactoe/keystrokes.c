#include "draw_grid.h"
#include "draw_components.h"
#include "logic.h"
#include "../drivers/screen.h"
#include <stdint.h>
#include "../kernel/kernel.h"

int cur_pos = 1;
int cross;

int cross_s = 0;
int round_s = 0;

int filled[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

void take_bind(int bindCode)
{
    switch (bindCode)
    {
        int i;
    case 0:
        if (cur_pos != 1 && cur_pos != 2 && cur_pos != 3)
        {
            cur_pos -= 3;
        }
        draw_cur(cur_pos);
        break;
    case 1:
        if (cur_pos != 1 && cur_pos != 4 && cur_pos != 7)
        {
            cur_pos--;
        }
        draw_cur(cur_pos);
        break;
    case 2:
        if (cur_pos != 3 && cur_pos != 6 && cur_pos != 9)
        {
            cur_pos++;
        }
        draw_cur(cur_pos);
        break;
    case 3:
        if (cur_pos != 7 && cur_pos != 8 && cur_pos != 9)
        {
            cur_pos += 3;
        }
        draw_cur(cur_pos);
        break;
    case 4:
        if (filled[cur_pos - 1] == 0)
        {
            if (cross == 1)
            {
                draw_cross(cur_pos);
                cross = 0;
                filled[cur_pos - 1] = 1;
            }
            else
            {
                draw_circle(cur_pos);
                cross = 1;
                filled[cur_pos - 1] = 2;
            }
        }
        int status = verify(filled);
        if (status == 0)
        {
        }
        else if (status == -1)
        {
            draw_cur(0);
            draw();
            kprint_at(" ", 78, 24, 0x00);
            clear_line();
            set_stats("DRAW: ", 0x0c);
            kprint("Press ENTER to start new match", 0x0a);

            lock_controls();
        }
        else
        {
            draw_cur(0);
            draw_line(status);
            draw();
            kprint_at(" ", 78, 24, 0x00);
            clear_line();
            if (cross == 1)
            {
                round_s++;
                set_stats("WIN for round: ", 0x0c);
                kprint_int(round_s, 0x0f);
            }
            else
            {
                cross_s++;
                set_stats("WIN for cross: ", 0x0c);
                kprint_int(cross_s, 0x0f);
            }
            kprint(". Press ENTER to start new match", 0x0a);
            lock_controls();
        }
        break;
    case 5:
        for (i = 0; i < 9; i++)
        {
            filled[i] = 0;
        }
        cur_pos = 1;
        draw_cur(cur_pos);
        cross = 1;
        set_stats("Started new game. ", 0x0a);
        kprint("Use arrow keys to move around and SPACE to insert into boxes", 0x0c);
        break;
    case 6:
        for (i = 0; i < 9; i++)
        {
            filled[i] = 0;
        }
        cur_pos = 1;
        draw_cur(cur_pos);
        cross = 1;
        cross_s = 0;
        round_s = 0;
        set_stats("Score reset 0-0. ", 0x0a);
        kprint("Use arrow keys to move around and SPACE to insert into boxes", 0x0c);
        break;
    case 7:
        draw_score_board(cross_s, round_s);
        set_stats("Game over. Halting cpu. Bye!", 0x0a);
        break;
    default:
        break;
    }
}