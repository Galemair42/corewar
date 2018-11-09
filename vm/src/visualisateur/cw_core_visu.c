#include "corewar.h"

static void     cw_set_score_win(void)
{
    arena.visu_score = subwin(stdscr, 15, COLS - 2,
    WIN_HEIGHT + 2, 1);
    box(arena.visu_score, ACS_VLINE, ACS_HLINE);
    mvwprintw(arena.visu_score, 1, 1, "toutes les infos utiles de corewar ici :\n");
}

static void     cw_set_fight_window(void)
{
    int     i;

    i = 1;
    arena.visu_fight = subwin(stdscr, WIN_HEIGHT, COLS - 2, 1, 1);
    box(arena.visu_fight, ACS_VLINE, ACS_HLINE);
    while (i <= 64)
    {
        mvwprintw(arena.visu_fight, i, 3, "00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00\n");
        i++;
    }
}

static void     cw_init_color(void)
{
    start_color();

    init_pair(CW_GREEN, COLOR_GREEN, COLOR_BLACK);
    init_pair(CW_PROCESS_GREEN, COLOR_BLACK, COLOR_GREEN);
    init_pair(CW_BLUE, COLOR_BLUE, COLOR_BLACK);
    init_pair(CW_PROCESS_BLUE, COLOR_BLACK, COLOR_BLUE);
    init_pair(CW_RED, COLOR_RED, COLOR_BLACK);
    init_pair(CW_PROCESS_RED, COLOR_BLACK, COLOR_RED);
    init_pair(CW_CYAN, COLOR_CYAN, COLOR_BLACK);
    init_pair(CW_PROCESS_CYAN, COLOR_BLACK, COLOR_CYAN);
}

/*
*         
*/

void            cw_init_proces_visu(t_processus *process)
{
    static int  i;

    process->win = subwin(arena.visu_fight, WIN_HEIGHT, COLS - 2, 1, 1);
    if (i == 0)
        wattron(process->win, COLOR_PAIR(CW_GREEN));
    else if (i == 1)
        wattron(process->win, COLOR_PAIR(CW_BLUE));
    else if (i == 2)
        wattron(process->win, COLOR_PAIR(CW_RED));
    else if (i == 3)
        wattron(process->win, COLOR_PAIR(CW_CYAN));
    i++;
}

void 		    cw_init_visu(void)
{
	int i;

	i = 1;
	initscr();
    curs_set(0);
    noecho();
    cw_init_color();
    cw_set_score_win();
    cw_set_fight_window();
}