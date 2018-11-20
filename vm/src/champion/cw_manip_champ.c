/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_manip_champ.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 16:54:30 by jabt              #+#    #+#             */
/*   Updated: 2018/11/20 16:59:03 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		cw_is_valid_id(int id)
{
	t_list			*lst_champ;
	t_champion		*champ;

	lst_champ = g_arena.champion;
	while (lst_champ)
	{
		champ = (t_champion *)lst_champ->content;
		if (champ->id == id)
			return (0);
		lst_champ = lst_champ->next;
	}
	return (1);
}

int		cw_get_new_champ_id(void)
{
	int				id;

	if (!g_arena.champion)
		return (1);
	id = 1;
	while (!cw_is_valid_id(id))
		id++;
	return (id);
}

/*
**		INPUT
**		take a number as input ans search in all the champions if
**		it's a valid champ's id, if it is , then the nb_live of
**		the champion is incremented else nothing
*/

int		cw_update_champ_live(int id_champ)
{
	t_list			*lst_champ;
	t_champion		*champ;
	int				i;

	i = 0;
	lst_champ = g_arena.champion;
	while (lst_champ)
	{
		champ = (t_champion *)lst_champ->content;
		if (champ->id == id_champ)
		{
			champ->nb_live++;
			g_arena.id_last_player_alive = id_champ;
			g_arena.cycle_live++;
			if (!g_arena.visu_fight)
				printf("|Player 1 (%s) is said to be alive|\n", champ->name);
			else
				mvwprintw(g_arena.visu_score, SC_HEIGHT + (i * 2) + 1 + i,
						SC_SECOND_COL + 15, "%u", champ->nb_live);
			return (1);
		}
		i++;
		lst_champ = lst_champ->next;
	}
	return (0);
}

/*
**		return 0 if none champion are find with the id else 1
*/
