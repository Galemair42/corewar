/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_core_visu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:59:07 by jabt              #+#    #+#             */
/*   Updated: 2018/11/20 14:45:33 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				cw_wait_and_quit_properly(void)
{
	t_champion		*champ;

	if (g_arena.id_last_player_alive == 0)
		mvwprintw(g_arena.visu_score, SC_HEIGHT, SC_FIRST_COL + 25, "No Winner");
	else
		cw_print_winner_visu();
	timeout(-1);
	getch();
	endwin();
}

static void			cw_begin_visu(t_list *lst_champ)
{
	t_champion		*champ;
	t_processus		*process;
	int				i;

	i = 0;
	g_arena.cur_processus = g_arena.nb_champ;
	while (lst_champ)
	{
		champ = (t_champion *)lst_champ->content;
		mvwprintw(g_arena.visu_score, SC_HEIGHT + (i * 2) + i, SC_SECOND_COL,
				"champion : %s :", champ->header.prog_name);
		mvwprintw(g_arena.visu_score, (SC_HEIGHT + (i * 2)) + 1 + i,
				SC_SECOND_COL, "current_live : 0");
		lst_champ = lst_champ->next;
		i++;
	}
	mvwprintw(g_arena.visu_score, SC_HEIGHT_PROC, SC_FOURTH_COL + 12, "%d",
			g_arena.cur_processus);
	wrefresh(g_arena.visu_score);
	wrefresh(g_arena.visu_fight);
}

void				cw_manage_getch(int c)
{
	if (c == CW_KEY_SPACE)
		cw_key_space();
	else if (c == CW_KEY_W || c == CW_KEY_Q || c == CW_KEY_E || c == CW_KEY_R)
		cw_key_speed(c);
}

int					cw_fight_visu(void)
{
	int				cycle;
	int				cycle_decrementation;
	int				c;
	t_processus		*delimiter;


	cw_key_space();
	cw_begin_visu(g_arena.champion);
	cycle_decrementation = 0;
	cycle = 0;
	while (1)
	{
		c = getch();
		if (c != -1)
			cw_manage_getch(c);
		if (cycle == g_arena.ctd)
		{
			if (g_arena.cycle_live >= NBR_LIVE ||
					cycle_decrementation == MAX_CHECKS - 1)
			{
				g_arena.ctd = (int)(g_arena.ctd - CYCLE_DELTA) >= 0 ? g_arena.ctd - CYCLE_DELTA : 1;
				cycle_decrementation = 0;
			}
			else
				cycle_decrementation++;
			//cw_clean_process_excedent();
			cw_reset_live();
			if (g_arena.cycle_live == 0)
			{
				cw_wait_and_quit_properly();
				return (1);
			}
			if (!(delimiter = (t_processus *)ft_memalloc(sizeof(t_processus))))
				return (-1);
			ft_lstadd(&g_arena.process, ft_lstnew(delimiter, sizeof(t_processus)));
			free (delimiter);
			g_arena.cycle_live = 0;
			cycle = 0;
		}
		cw_read_processus_opc(cycle, g_arena.ctd);
		cw_exec_instructions();
		g_arena.cur_cycle++;
		cycle++;
		c++;
	cw_update_cycle();
	}
	return (1);
}
