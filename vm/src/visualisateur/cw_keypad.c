#include "corewar.h"

void    cw_key_space()
{
    int     c;

    wmove(arena.visu_score, 0, 0);
    refresh();
    mvwprintw(arena.visu_score, SC_PAUSE_HEIGHT, SC_PAUSE_WIDTH, "**PAUSED**");// refresh ??
    wrefresh(arena.visu_score);
    while (1)
    {
        c = getch();
        if (c == CW_KEY_SPACE)
            break;
        else 
            cw_manage_getch(c);
    }
    mvwprintw(arena.visu_score, SC_PAUSE_HEIGHT, SC_PAUSE_WIDTH, "**RUNNING**");
    wrefresh(arena.visu_score);
}

void    cw_key_speed(int c)
{
    static int      speed;

    if (!speed)
        speed = 20;
    if (c == CW_KEY_Q && speed > 1)
    {
        if (speed <= 10)
            speed = 1;
        else
            speed -= 10;
    }
    else if (c == CW_KEY_W && speed > 1)
        speed -= 1;
    else if (c == CW_KEY_E && speed < 500)
        speed += 1;
    else if (c == CW_KEY_R && speed < 500)
    {
        if (speed >= 491)
            speed = 500;
        else
            speed += 10;
    }
    timeout(505 - speed);
    mvwprintw(arena.visu_score, SC_SPEED_HEIGHT + 2, SC_SPEED_WIDTH, "%02d", speed);
    wrefresh(arena.visu_score);
}