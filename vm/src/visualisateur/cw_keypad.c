/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_keypad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 11:23:07 by jabt              #+#    #+#             */
/*   Updated: 2018/11/16 11:40:34 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		cw_key_space(void)
{
	int		c;

	mvwprintw(arena.visu_score, SC_HEIGHT, SC_FIRST_COL, "**PAUSED**");
	wrefresh(arena.visu_score);
	while (1)
	{
		c = getch();
		if (c == CW_KEY_SPACE)
			break ;
		else
			cw_manage_getch(c);
	}
	mvwprintw(arena.visu_score, SC_HEIGHT, SC_FIRST_COL, "**RUNNING**");
	wrefresh(arena.visu_score);
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
	if (c == CW_KEY_Q && speed > 0)
		speed--;
	else if (c == CW_KEY_R && speed < 3)
		speed++;
	if (speed == 1)
		timeout(100);
	else if (speed == 2)
		timeout(10);
	else if (speed == 3)
		timeout(1);
	else
		timeout(0);
	mvwprintw(arena.visu_score, SC_HEIGHT + 2, SC_FOURTH_COL, tab[speed]);
	wrefresh(arena.visu_score);
}
