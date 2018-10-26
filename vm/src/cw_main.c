/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 13:48:58 by jabt              #+#    #+#             */
/*   Updated: 2018/10/18 18:40:24 by galemair         ###   ########.fr       */
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
	{
		printf("sa\n");
		return (42);
	}
	
	//print_all_champ();
//	print_all_process();

//	process = arena.process;

	cw_fight();

	// allez c'est parti pour la giga boucle de l'enfer ha ouiouiouji
}
