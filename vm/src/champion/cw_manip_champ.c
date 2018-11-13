/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_manip_champ.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 16:54:30 by jabt              #+#    #+#             */
/*   Updated: 2018/11/12 14:59:12 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		cw_get_new_champ_id(void)
{
	int				id;
	int				error;
	t_list			*lst_champ;
	t_champion		*champ;

	error = 1;
	if (!arena.champion)
		return (1);
	id = 0;
	while (error == 1)
	{
		id++;
		error = 0;
		lst_champ = arena.champion;
		while (lst_champ)
		{
			champ = (t_champion *)lst_champ->content;
			if (champ->id == id)
			{
				error = 1;
				break ;
			}
			lst_champ = lst_champ->next;
		}
	}
	return (id);
}


/*
**		INPUT
**		take a number as input ans search in all the champions if it's a valid champ's id,
**		if it is , then the nb_live of the champion is incremented else nothing
*/

int		cw_update_champ_live(int id_champ)
{
	t_list			*lst_champ = arena.champion;
	t_champion 		*champ;
	int				i;


	while (lst_champ)
	{
		champ = (t_champion *)lst_champ->content;
		if (champ->id == id_champ)
		{
			champ->nb_live++;
			arena.id_last_player_alive = id_champ;
			arena.cycle_live++;
			if (!arena.visu_fight)
				printf("Player 1 (%s) is said to be alive\n", champ->name);
			//else
			//	cw_update_live_visu(i);
			return (1);
		}
		i++;
		lst_champ = lst_champ->next;
	}
	mvwprintw(arena.visu_score, SC_HEIGHT + (i * 2) + i, SC_SECOND_COL, "champion : %s :", champ->header.prog_name);
    mvwprintw(arena.visu_score, (SC_HEIGHT + (i * 2)) + 1 + i, SC_SECOND_COL, "current_live : 0");
    mvwprintw(arena.visu_score, (SC_HEIGHT + (i * 2)) + 2 + i, SC_SECOND_COL, "total_live : 0");
	return (0);
}

/*
**		return 0 if none champion are find with the id else 1
*/
