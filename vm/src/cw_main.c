/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 13:48:58 by jabt              #+#    #+#             */
/*   Updated: 2018/09/26 10:38:39 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"


int		main(int argc, char **argv)
{
//	t_list		*process;

	cw_init_processeur();
	if (!cw_parse_arg(argv, argc))
	{
		return (42);
	}
	cw_put_champion_in_memory();
	if (!(arena.process = cw_init_process()))
		return (42);
//	process = arena.process;
	cw_fight();
//	while (process)
//	{
//		
//	}

	// allez c'est parti pour la giga boucle de l'enfer ha ouiouiouji
}
