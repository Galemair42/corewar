/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 13:48:58 by jabt              #+#    #+#             */
/*   Updated: 2018/09/20 18:50:14 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"



int		main(int argc, char **argv)
{
	cw_init_processeur();
	if (!cw_parse_arg(argv, argc))
	{
		printf("lol\n");
		return (42);
	}
	cw_put_champion_in_memory();
	print_buffer_in_hexa(arena.memory, MEM_SIZE);
	//fonction pour ecrire les champion en memoire

	// dans un premier temps recup mes params	
	// parsing du header
}
