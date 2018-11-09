/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 13:48:58 by jabt              #+#    #+#             */
/*   Updated: 2018/11/07 10:44:18 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				main(int argc, char **argv)
{
//	t_list		*process;

	cw_init_processeur();
	if (!cw_parse_arg(argv, argc))
		return (42);
	cw_put_champion_in_memory();
	//print_buffer_in_hexa(arena.memory, 4096);
	if (!(arena.process = cw_init_process()))
	{
		printf("sa\n");
		return (42);
	}
	cw_fight();
	
	getch();	
	// attention a bien free ton ncurse a la fin;

	// allez c'est parti pour la giga boucle de l'enfer ha ouiouiouji
}
