/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_score.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 11:41:00 by jabt              #+#    #+#             */
/*   Updated: 2018/11/19 13:27:59 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		cw_update_cycle(void)
{
	mvwprintw(arena.visu_score, SC_HEIGHT + 2, SC_FIRST_COL + 9, "%u        ",
			arena.cur_cycle);
	mvwprintw(arena.visu_score, SC_HEIGHT_PROC, SC_FOURTH_COL + 12, "%u       ",
			arena.cur_processus);
	mvwprintw(arena.visu_score, SC_HEIGHT + 6, SC_FIRST_COL, "ctd : %u        ",
			arena.ctd);
	wrefresh(arena.visu_score);
	wrefresh(arena.visu_fight);
}
