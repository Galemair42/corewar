/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 14:00:14 by jabt              #+#    #+#             */
/*   Updated: 2018/11/06 13:33:02 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** 	INPUT
** 	global_var processeur
*/

void		cw_init_processeur(void)
{
	ft_bzero(arena.memory, MEM_SIZE);
	arena.champion = NULL;
	ft_bzero(arena.process, sizeof(t_list *) * CYCLE_TO_DIE);
	arena.nb_champ = 0;
	arena.cycle_to_die = CYCLE_TO_DIE;	
	arena.max_check = MAX_CHECKS;
	arena.id_last_player_alive = 0;
	arena.max_cycle = ~0;
	arena.cur_cycle = 0;
	arena.cycle_to_dump = ~0;
}
