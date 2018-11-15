#include "corewar.h"

void        cw_update_cycle(void)
{
    static unsigned int     cur_cycle;

    cur_cycle++;
    mvwprintw(arena.visu_score, SC_HEIGHT + 2, SC_FIRST_COL + 9, "%u", cur_cycle);
    mvwprintw(arena.visu_score, SC_HEIGHT_PROC, SC_FOURTH_COL + 12, "%u", arena.cur_processus);
    wrefresh(arena.visu_score);
    wrefresh(arena.visu_fight);
}