/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_score.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 11:41:00 by jabt              #+#    #+#             */
/*   Updated: 2018/11/21 13:42:45 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		cw_update_cycle(void)
{
	mvwprintw(g_arena.visu_score, SC_HEIGHT + 2, SC_FIRST_COL + 9, "%u        ",
			g_arena.cur_cycle);
	mvwprintw(g_arena.visu_score, SC_HEIGHT_PROC, SC_FOURTH_COL + 12, "%u     ",
			g_arena.cur_processus);
	mvwprintw(g_arena.visu_score, SC_HEIGHT + 6, SC_FIRST_COL, "ctd : %u      ",
			g_arena.ctd);
	wrefresh(g_arena.visu_score);
	wrefresh(g_arena.visu_fight);
}
