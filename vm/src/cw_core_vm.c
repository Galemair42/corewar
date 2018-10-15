/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_core_vm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 15:43:55 by jabt              #+#    #+#             */
/*   Updated: 2018/09/25 15:32:28 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			cw_fight(void)
{
	t_list			*process;
	unsigned int	ctd;
	size_t			i;
	size_t			k;
	size_t			dump;

	k = 0;
	process = arena.process;
	ctd = CYCLE_TO_DIE;
	i = 0;
	dump = 1;
	while (process)
	{
		while (i < ctd)
		{
			;// iterer sur tous les process et exec leurs instru (fonction de gautier)
			if ((arena.bool_dump))
				;
			i++;
		}
		cw_roam_of_the_bat();
		k++;
		if (k == MAX_CHECKS/* || nb_live >= NBR_LIVE*/)
		{
			ctd -= CYCLE_DELTA;
			k = 0;
		}
		arena.cur_cycle++;
		dump++;	
	}
	return (0);
}
