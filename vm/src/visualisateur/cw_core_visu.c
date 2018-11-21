/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_core_visu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:59:07 by jabt              #+#    #+#             */
/*   Updated: 2018/11/21 09:08:32 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				cw_wait_and_quit_properly(void)
{
	if (g_arena.id_last_player_alive == 0)
		mvwprintw(g_arena.visu_score, SC_HEIGHT, SC_FIRST_COL + 25,
				"No Winner");
	else
		cw_print_winner_visu();
	timeout(-1);
	getch();
	endwin();
}

void				cw_begin_visu(t_list *lst_champ)
{
	t_champion		*champ;
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
