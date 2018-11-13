#include "corewar.h"

void            cw_manage_getch(int c)
{
    if (c == CW_KEY_SPACE)
        cw_key_space();
    else if (c == CW_KEY_W || c == CW_KEY_Q || c == CW_KEY_E || c == CW_KEY_R)
        cw_key_speed(c);
}

static void            cw_print_live(t_list *lst_champ)
{
    t_champion      *champ;
    t_processus     *process;
    int            i;

    i = 0;
    while (lst_champ)
    {
        champ = (t_champion *)lst_champ->content;       
        mvwprintw(arena.visu_score, SC_HEIGHT + (i * 2) + i, SC_SECOND_COL, "champion : %s :", champ->header.prog_name);
        mvwprintw(arena.visu_score, (SC_HEIGHT + (i * 2)) + 1 + i, SC_SECOND_COL, "current_live : 0");
        mvwprintw(arena.visu_score, (SC_HEIGHT + (i * 2)) + 2 + i, SC_SECOND_COL, "total_live : 0");
        lst_champ = lst_champ->next;
        i++;
    }
    wrefresh(arena.visu_score);
	//while (1);
}

int				cw_fight_visu(void)
{
	unsigned int	ctd;
	int				cycle;
	int				cycle_decrementation;
    int             c;

    cw_key_space();
    cw_print_live(arena.champion); // a tester !!!!
	ctd = arena.cycle_to_die;
	cycle_decrementation = 0;
	cycle = 0;
	while (1)
	{
        c = getch();
        if (c != -1)
            cw_manage_getch(c);
		cw_read_processus_opc(cycle, ctd);
		cw_exec_instructions(cycle);
		cycle++;
		if (cycle == ctd)
		{
			exit (0);
			if (arena.cycle_live >= NBR_LIVE || cycle_decrementation == MAX_CHECKS - 1)
			{
				ctd -= CYCLE_DELTA;
				cycle_decrementation = 0;
			}
			else
				cycle_decrementation++;
			cw_verif_processes();
			if (arena.cycle_live == 0)
			{
				printf("Nous avons un winner !\n");
				return (1);
			}
			arena.cycle_live = 0;
			cycle = 0;
        }
        cw_update_cycle();
	}
    return (1);
}