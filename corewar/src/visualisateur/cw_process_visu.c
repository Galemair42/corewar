/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_process_visu.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 13:18:28 by jabt              #+#    #+#             */
/*   Updated: 2018/11/20 14:45:33 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			cw_highlight_octet(unsigned int index, int color_pair)
{
	wattron(g_arena.visu_fight, COLOR_PAIR(color_pair));
	wattron(g_arena.visu_fight, A_STANDOUT);
	mvwprintw(g_arena.visu_fight, 1 + (index / 64), 3 + (3 * (index % 64)),
			"%.2x", g_arena.memory[index]);
	wattroff(g_arena.visu_fight, COLOR_PAIR(color_pair));
	wattroff(g_arena.visu_fight, A_STANDOUT);
}

void			cw_unhighlight_octet(unsigned int index, int color_pair)
{
	wattron(g_arena.visu_fight, COLOR_PAIR(color_pair));
	mvwprintw(g_arena.visu_fight, 1 + (index / 64), 3 + (3 * (index % 64)),
			"%.2x", g_arena.memory[index]);
	wattroff(g_arena.visu_fight, COLOR_PAIR(color_pair));
}
