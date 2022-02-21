#include "../drivers/screen.h"

void draw()
{
    int i = 0;
    for (i = 0; i < MAX_COLS; i++)
    {
        kprint_at(" ", i, 0, 0xff);
        kprint_at(" ", i, MAX_ROWS / 3, 0xff);
        kprint_at(" ", i, 2 * MAX_ROWS / 3, 0xff);
        kprint_at(" ", i, MAX_ROWS - 2, 0xff);
    }
    for (i = 0; i < MAX_ROWS - 1; i++)
    {
        kprint_at("  ", 0, i, 0xff);
        kprint_at("  ", MAX_COLS / 3, i, 0xff);
        kprint_at("  ", 2 * MAX_COLS / 3, i, 0xff);
        kprint_at("  ", MAX_COLS - 1, i, 0xff);
    }
}