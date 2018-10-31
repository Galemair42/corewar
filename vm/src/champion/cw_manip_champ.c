/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_manip_champ.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 16:54:30 by jabt              #+#    #+#             */
/*   Updated: 2018/10/18 18:01:13 by galemair         ###   ########.fr       */
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

	while (lst_champ)
	{
		champ = (t_champion *)lst_champ->content;
		if (champ->id == id_champ)
		{
			champ->nb_live++;
			printf("Player 1 (%s) is said to be alive\n", champ->name);
			return (1);
		}
		lst_champ = lst_champ->next;
	}
	return (0);
}

/*
**		return 0 if none champion are find with the id else 1
*/
