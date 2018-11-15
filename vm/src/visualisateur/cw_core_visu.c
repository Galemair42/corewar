#include "corewar.h"

void			cw_wait_and_quit_properly(void)
{
	t_champion		*champ;

	//champ = cw_get_champ_by_id(arena.id_last_player_alive);	
	if (!champ || arena.id_last_player_alive == 0)
		mvwprintw(arena.visu_score, SC_HEIGHT, SC_FIRST_COL + 25, "No Winner");
	else
	{
		cw_print_winner_visu();
	}
	timeout(-1);
	getch();
	endwin();
}

static void            cw_begin_visu(t_list *lst_champ)
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
    //    mvwprintw(arena.visu_score, (SC_HEIGHT + (i * 2)) + 2 + i, SC_SECOND_COL, "total_live : 0");
        lst_champ = lst_champ->next;
        i++;
    }
	mvwprintw(arena.visu_score, SC_HEIGHT_PROC + 2, SC_FOURTH_COL, "%d", i);
    wrefresh(arena.visu_score);
	wrefresh(arena.visu_fight);
}

void            cw_manage_getch(int c)
{
    if (c == CW_KEY_SPACE)
        cw_key_space();
    else if (c == CW_KEY_W || c == CW_KEY_Q || c == CW_KEY_E || c == CW_KEY_R)
        cw_key_speed(c);
}

int				cw_fight_visu(void)
{
	unsigned int	ctd;
	int				cycle;
	int				cycle_decrementation;
    int             c;

    cw_key_space();
    cw_begin_visu(arena.champion); // a tester !!!!
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
		c++;
		if (cycle == ctd)
		{
			if (arena.cycle_live >= NBR_LIVE || cycle_decrementation == MAX_CHECKS - 1)
			{
				ctd = (int)(ctd - CYCLE_DELTA) >= 0 ? ctd - CYCLE_DELTA : 1;
				cycle_decrementation = 0;
			}
			else
				cycle_decrementation++;
			cw_reset_live();
			if (arena.cycle_live == 0)
			{
				/*if (arena.id_last_player_alive == 0)
					printw("No Winner");
				else
					printw("The winner is %s!\n", get_champs_name_by_id(arena.id_last_player_alive));*/
				cw_wait_and_quit_properly();
				return (1);
			}
			ft_lstadd(&arena.process, ft_lstnew(ft_memalloc(sizeof(t_processus)), sizeof(t_processus)));
			arena.cycle_live = 0;
			cycle = 0;
        }
        cw_update_cycle();
	}
    return (1);
}
