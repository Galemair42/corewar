#include "corewar.h"

void        cw_update_cycle(void)
{
    static unsigned int     cur_cycle;

    cur_cycle++;
    mvwprintw(arena.visu_score, SC_HEIGHT, SC_FIRST_COL + 9, "%u", cur_cycle);
    wrefresh(arena.visu_score);
}