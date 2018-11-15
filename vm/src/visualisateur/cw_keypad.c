#include "corewar.h"

void    cw_key_space()
{
    int     c;

    mvwprintw(arena.visu_score, SC_HEIGHT, SC_FIRST_COL, "**PAUSED**");// refresh ??
    wrefresh(arena.visu_score);
    while (1)
    {
        c = getch();
        if (c == CW_KEY_SPACE)
            break;
        else 
            cw_manage_getch(c);
    }
    mvwprintw(arena.visu_score, SC_HEIGHT, SC_FIRST_COL, "**RUNNING**");
    wrefresh(arena.visu_score);
}

void    cw_key_speed(int c)
{
    static int      speed;

    if (!speed)
        speed = 2;
    if (c == CW_KEY_Q)
    {
        if (speed > 1)
            speed--;
    }
    else if (c == CW_KEY_R)
    {
        if (speed < 4)
            speed++;
    }
    if (speed == 1)
    {
        mvwprintw(arena.visu_score, SC_HEIGHT + 2, SC_FOURTH_COL, "slow        ");
        timeout(100);
    }
    else if (speed == 2)
    {
        mvwprintw(arena.visu_score, SC_HEIGHT + 2, SC_FOURTH_COL, "normal      ");
        timeout(10);
    }
    else if (speed == 3)
    {
        mvwprintw(arena.visu_score, SC_HEIGHT + 2, SC_FOURTH_COL, "fast      ");
        timeout(1);
    }
    else
    {
        mvwprintw(arena.visu_score, SC_HEIGHT + 2, SC_FOURTH_COL, "ultra fast  ");
        timeout(0);
    }
    wrefresh(arena.visu_score);
}