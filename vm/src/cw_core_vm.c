/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_core_vm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 15:43:55 by jabt              #+#    #+#             */
/*   Updated: 2018/09/24 16:26:55 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			cw_fight(void)
{
	t_list			*process;
	unsigned int	ctd;
	int				i;
	size_t			k;

	k = 0;
	process = arena.process;
	ctd = arena.cycle_to_die;
	i = 0;
	while (process)
	{
		//iterer sur tous les proc, exec leurs instru etc...`

		while (i < ctd)
		{
			;// iterer sur tous les process et exec leurs instru
			i++;
		}
		k++;
		if (k == MAX_CHECK /*|| nb_live >= NBR_LIVE */)
		{
			ctd -= CYCLE_DELTA;
			k = 0;
		}
	}
}
