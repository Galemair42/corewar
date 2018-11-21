/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_keypad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 11:23:07 by jabt              #+#    #+#             */
/*   Updated: 2018/11/20 14:45:33 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		cw_key_space(void)
{
	int		c;

	mvwprintw(g_arena.visu_score, SC_HEIGHT, SC_FIRST_COL, "**PAUSED**");
	wrefresh(g_arena.visu_score);
	while (1)
	{
		refresh();
		c = getch();
		if (c == CW_KEY_SPACE)
			break ;
		else
			cw_manage_getch(c);
	}
	mvwprintw(g_arena.visu_score, SC_HEIGHT, SC_FIRST_COL, "**RUNNING**");
	wrefresh(g_arena.visu_score);
}

void		cw_key_speed(int c)
{
	static int		speed;
	static char		*tab[4];

	tab[0] = "slow        ";
	tab[1] = "normal      ";
	tab[2] = "fast        ";
	tab[3] = "ultra fast  ";
	if (!speed)
		speed = 1;
	if (c == CW_KEY_Q && speed > 1)
		speed--;
	else if (c == CW_KEY_R && speed < 4)
		speed++;
	if (speed == 1)
		timeout(100);
	else if (speed == 2)
		timeout(10);
	else if (speed == 3)
		timeout(1);
	else
		timeout(0);
	mvwprintw(g_arena.visu_score, SC_HEIGHT + 2, SC_FOURTH_COL, tab[speed - 1]);
	wrefresh(g_arena.visu_score);
}
