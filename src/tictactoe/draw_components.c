#include "../drivers/screen.h"

void draw_borders(int r1, int c1, int r2, int c2)
{
    int i;
    for (i = c1; i <= c2; i++)
    {
        kprint_at(" ", i, r1, 0xc0);
    }
    for (i = c1; i <= c2; i++)
    {
        kprint_at(" ", i, r2 - 1, 0xc0);
    }
    for (i = r1; i <= r2 - 1; i++)
    {
        kprint_at("  ", c1, i, 0xc0);
    }
    for (i = r1; i <= r2 - 1; i++)
    {
        kprint_at("  ", c2 - 1, i, 0xc0);
    }
}

void clear_borders(int r1, int c1, int r2, int c2)
{
    int i;
    for (i = c1; i <= c2; i++)
    {
        kprint_at(" ", i, r1, 0x00);
    }
    for (i = c1; i <= c2; i++)
    {
        kprint_at(" ", i, r2 - 1, 0x00);
    }
    for (i = r1; i <= r2 - 1; i++)
    {
        kprint_at("  ", c1, i, 0x00);
    }
    for (i = r1; i <= r2 - 1; i++)
    {
        kprint_at("  ", c2 - 1, i, 0x00);
    }
}

void draw_cur(int box)
{
    char *cur = "+";
    char *clear_char = "   ";

    // kprint_at(clear_char, MAX_COLS / 6, MAX_ROWS / 6, 0x0f);
    // kprint_at(clear_char, MAX_COLS / 2, MAX_ROWS / 6, 0x0f);
    // kprint_at(clear_char, 5 * MAX_COLS / 6, MAX_ROWS / 6, 0x0f);
    // kprint_at(clear_char, MAX_COLS / 6, MAX_ROWS / 2, 0x0f);
    // kprint_at(clear_char, MAX_COLS / 2, MAX_ROWS / 2, 0x0f);
    // kprint_at(clear_char, 5 * MAX_COLS / 6, MAX_ROWS / 2, 0x0f);
    // kprint_at(clear_char, MAX_COLS / 6, 5 * MAX_ROWS / 6, 0x0f);
    // kprint_at(clear_char, MAX_COLS / 2, 5 * MAX_ROWS / 6, 0x0f);
    // kprint_at(clear_char, 5 * MAX_COLS / 6, 5 * MAX_ROWS / 6, 0x0f);

    clear_borders(1, 2, MAX_ROWS / 3, MAX_COLS / 3 - 1);
    clear_borders(1, MAX_COLS / 3 + 2, MAX_ROWS / 3, 2 * MAX_COLS / 3 - 1);
    clear_borders(1, 2 * MAX_COLS / 3 + 2, MAX_ROWS / 3, MAX_COLS - 2);
    clear_borders(MAX_ROWS / 3 + 1, 2, 2 * MAX_ROWS / 3, MAX_COLS / 3 - 1);
    clear_borders(MAX_ROWS / 3 + 1, MAX_COLS / 3 + 2, 2 * MAX_ROWS / 3, 2 * MAX_COLS / 3 - 1);
    clear_borders(MAX_ROWS / 3 + 1, 2 * MAX_COLS / 3 + 2, 2 * MAX_ROWS / 3, MAX_COLS - 2);
    clear_borders(2 * MAX_ROWS / 3 + 1, 2, MAX_ROWS - 2, MAX_COLS / 3 - 1);
    clear_borders(2 * MAX_ROWS / 3 + 1, MAX_COLS / 3 + 2, MAX_ROWS - 2, 2 * MAX_COLS / 3 - 1);
    clear_borders(2 * MAX_ROWS / 3 + 1, 2 * MAX_COLS / 3 + 2, MAX_ROWS - 2, MAX_COLS - 2);

    switch (box)
    {
    case 0:
        break;
    case 1:
        // kprint_at(cur, MAX_COLS / 6, MAX_ROWS / 6, 0x0f);
        draw_borders(1, 2, MAX_ROWS / 3, MAX_COLS / 3 - 1);
        break;
    case 2:
        // kprint_at(cur, MAX_COLS / 2, MAX_ROWS / 6, 0x0f);
        draw_borders(1, MAX_COLS / 3 + 2, MAX_ROWS / 3, 2 * MAX_COLS / 3 - 1);
        break;
    case 3:
        // kprint_at(cur, 5 * MAX_COLS / 6, MAX_ROWS / 6, 0x0f);
        draw_borders(1, 2 * MAX_COLS / 3 + 2, MAX_ROWS / 3, MAX_COLS - 2);
        break;
    case 4:
        // kprint_at(cur, MAX_COLS / 6, MAX_ROWS / 2, 0x0f);
        draw_borders(MAX_ROWS / 3 + 1, 2, 2 * MAX_ROWS / 3, MAX_COLS / 3 - 1);
        break;
    case 5:
        // kprint_at(cur, MAX_COLS / 2, MAX_ROWS / 2, 0x0f);
        draw_borders(MAX_ROWS / 3 + 1, MAX_COLS / 3 + 2, 2 * MAX_ROWS / 3, 2 * MAX_COLS / 3 - 1);
        break;
    case 6:
        // kprint_at(cur, 5 * MAX_COLS / 6, MAX_ROWS / 2, 0x0f);
        draw_borders(MAX_ROWS / 3 + 1, 2 * MAX_COLS / 3 + 2, 2 * MAX_ROWS / 3, MAX_COLS - 2);
        break;
    case 7:
        // kprint_at(cur, MAX_COLS / 6, 5 * MAX_ROWS / 6, 0x0f);
        draw_borders(2 * MAX_ROWS / 3 + 1, 2, MAX_ROWS - 2, MAX_COLS / 3 - 1);
        break;
    case 8:
        // kprint_at(cur, MAX_COLS / 2, 5 * MAX_ROWS / 6, 0x0f);
        draw_borders(2 * MAX_ROWS / 3 + 1, MAX_COLS / 3 + 2, MAX_ROWS - 2, 2 * MAX_COLS / 3 - 1);
        break;
    case 9:
        // kprint_at(cur, 5 * MAX_COLS / 6, 5 * MAX_ROWS / 6, 0x0f);
        draw_borders(2 * MAX_ROWS / 3 + 1, 2 * MAX_COLS / 3 + 2, MAX_ROWS - 2, MAX_COLS - 2);
        break;
    default:
        break;
    }
}

void draw_cross_by_cords(int x, int y)
{
    kprint_at("x", y, x, 0x0d);

    kprint_at("x", y - 4, x - 2, 0x0d);
    kprint_at("x", y - 2, x - 1, 0x0d);
    kprint_at("x", y + 2, x + 1, 0x0d);
    kprint_at("x", y + 4, x + 2, 0x0d);
    kprint_at("x", y - 4, x + 2, 0x0d);
    kprint_at("x", y - 2, x + 1, 0x0d);
    kprint_at("x", y + 2, x - 1, 0x0d);
    kprint_at("x", y + 4, x - 2, 0x0d);
}

void draw_circle_by_cords(int x, int y)
{
    kprint_at("o", y - 4, x, 0x0e);
    kprint_at("o", y - 2, x, 0x0e);
    kprint_at("o", y, x, 0x0e);
    kprint_at("o", y + 2, x, 0x0e);
    kprint_at("o", y + 4, x, 0x0e);

    kprint_at("o", y - 2, x + 1, 0x0e);
    kprint_at("o", y, x + 1, 0x0e);
    kprint_at("o", y + 2, x + 1, 0x0e);

    kprint_at("o", y - 2, x - 1, 0x0e);
    kprint_at("o", y, x - 1, 0x0e);
    kprint_at("o", y + 2, x - 1, 0x0e);

    kprint_at("o", y, x + 2, 0x0e);

    kprint_at("o", y, x - 2, 0x0e);
}

void draw_cross(int box)
{
    switch (box)
    {
    case 1:
        draw_cross_by_cords(MAX_ROWS / 6, MAX_COLS / 6);
        break;
    case 2:
        draw_cross_by_cords(MAX_ROWS / 6, MAX_COLS / 2);
        break;
    case 3:
        draw_cross_by_cords(MAX_ROWS / 6, 5 * MAX_COLS / 6);
        break;
    case 4:
        draw_cross_by_cords(MAX_ROWS / 2, MAX_COLS / 6);
        break;
    case 5:
        draw_cross_by_cords(MAX_ROWS / 2, MAX_COLS / 2);
        break;
    case 6:
        draw_cross_by_cords(MAX_ROWS / 2, 5 * MAX_COLS / 6);
        break;
    case 7:
        draw_cross_by_cords(5 * MAX_ROWS / 6 - 1, MAX_COLS / 6);
        break;
    case 8:
        draw_cross_by_cords(5 * MAX_ROWS / 6 - 1, MAX_COLS / 2);
        break;
    case 9:
        draw_cross_by_cords(5 * MAX_ROWS / 6 - 1, 5 * MAX_COLS / 6);
        break;
    default:
        break;
    }
}

void draw_circle(int box)
{
    switch (box)
    {
    case 1:
        draw_circle_by_cords(MAX_ROWS / 6, MAX_COLS / 6);
        break;
    case 2:
        draw_circle_by_cords(MAX_ROWS / 6, MAX_COLS / 2);
        break;
    case 3:
        draw_circle_by_cords(MAX_ROWS / 6, 5 * MAX_COLS / 6);
        break;
    case 4:
        draw_circle_by_cords(MAX_ROWS / 2, MAX_COLS / 6);
        break;
    case 5:
        draw_circle_by_cords(MAX_ROWS / 2, MAX_COLS / 2);
        break;
    case 6:
        draw_circle_by_cords(MAX_ROWS / 2, 5 * MAX_COLS / 6);
        break;
    case 7:
        draw_circle_by_cords(5 * MAX_ROWS / 6 - 1, MAX_COLS / 6);
        break;
    case 8:
        draw_circle_by_cords(5 * MAX_ROWS / 6 - 1, MAX_COLS / 2);
        break;
    case 9:
        draw_circle_by_cords(5 * MAX_ROWS / 6 - 1, 5 * MAX_COLS / 6);
        break;
    default:
        break;
    }
}

void draw_line_by_cords(int r1, int c1, int r2, int c2)
{
    int i;
    if (r1 == r2)
    {
        for (i = 1; i < MAX_COLS; i++)
        {
            kprint_at("-", i, r1, 0x0f);
        }
    }
    else if (c1 == c2)
    {
        for (i = 1; i < MAX_ROWS; i++)
        {
            kprint_at("|", c1, i, 0x0f);
        }
    }
    else
    {
        if (c1 == 1)
            for (i = r1; i < r2; i++)
            {
                kprint_at("\\", (i * 3.3) - 1, i, 0x0f);
            }
        else
            for (i = r1; i < r2; i++)
            {
                kprint_at("/", MAX_COLS - (i * 3.3) - 1, i, 0x0f);
            }
    }
}

void draw_line(int condition)
{
    switch (condition)
    {
    case 1:
        draw_line_by_cords(MAX_ROWS / 6, 1, MAX_ROWS / 6, MAX_COLS - 1);
        break;
    case 2:
        draw_line_by_cords(MAX_ROWS / 2, 1, MAX_ROWS / 2, MAX_COLS - 1);
        break;
    case 3:
        draw_line_by_cords(5 * MAX_ROWS / 6, 1, 5 * MAX_ROWS / 6, MAX_COLS - 1);
        break;
    case 4:
        draw_line_by_cords(1, MAX_COLS / 6, MAX_ROWS, MAX_COLS / 6);
        break;
    case 5:
        draw_line_by_cords(1, MAX_COLS / 2, MAX_ROWS, MAX_COLS / 2);
        break;
    case 6:
        draw_line_by_cords(1, 5 * MAX_COLS / 6, MAX_ROWS, 5 * MAX_COLS / 6);
        break;
    case 7:
        draw_line_by_cords(1, 1, MAX_ROWS, MAX_COLS);
        break;
    case 8:
        draw_line_by_cords(1, MAX_COLS, MAX_ROWS, 1);
        break;
    default:
        break;
    }
}

void set_stats(char *msg, char color)
{
    kprint_at(msg, 0, 24, color);
}

void clear_status()
{
    kprint_at(" ", 78, 24, 0x00);
    clear_line();
}

void draw_score_board(int s1, int s2)
{
    clear_screen();
    int i;
    for (i = MAX_COLS / 3; i <= 2 * MAX_COLS / 3; i++)
    {
        kprint_at(" ", i, MAX_ROWS / 3, 0xff);
    }
    for (i = MAX_COLS / 3; i <= 2 * MAX_COLS / 3; i++)
    {
        kprint_at(" ", i, 2 * MAX_ROWS / 3, 0xff);
    }
    for (i = MAX_ROWS / 3; i <= 2 * MAX_ROWS / 3; i++)
    {
        kprint_at(" ", MAX_COLS / 3, i, 0xff);
    }
    for (i = MAX_ROWS / 3; i <= 2 * MAX_ROWS / 3; i++)
    {
        kprint_at(" ", 2 * MAX_COLS / 3, i, 0xff);
    }
    for (i = MAX_ROWS / 3 + 1; i < 2 * MAX_ROWS / 3; i++)
    {
        kprint_at("|", MAX_COLS / 2, i, 0x0f);
    }
    for (i = MAX_COLS / 3 + 1; i < 2 * MAX_COLS / 3; i++)
    {
        kprint_at("-", i, MAX_ROWS / 2 - 1, 0x0f);
    }
    kprint_at("CROSS", MAX_COLS / 3 + 5, MAX_ROWS / 3 + 2, 0x0a);
    kprint_at("ROUND", 2 * MAX_COLS / 3 - 9, MAX_ROWS / 3 + 2, 0x0c);
    kprint_at(" ", MAX_COLS / 3 + 6, MAX_ROWS / 3 + 5, 0x00);
    if (s1 == 0)
        kprint("0", 0x0a);
    else
        kprint_int(s1, 0x0a);
    kprint_at(" ", 2 * MAX_COLS / 3 - 8, MAX_ROWS / 3 + 5, 0x00);
    if (s2 == 0)
        kprint("0", 0x0c);
    else
        kprint_int(s2, 0x0c);
}