/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_manip_champ.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 16:54:30 by jabt              #+#    #+#             */
/*   Updated: 2018/09/18 17:31:08 by jabt             ###   ########.fr       */
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
	id = 1;
	while (error == 1)
	{
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
		id++;
	}
	return (id);
}
