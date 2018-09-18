/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 13:48:58 by jabt              #+#    #+#             */
/*   Updated: 2018/09/18 16:33:04 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"



int		main(int argc, char **argv)
{
	cw_init_processeur();
	cw_parse_arg(argv, argc);
	printf("je sors du parsing\n");
	exit(5);

	// dans un premier temps recup mes params	
	// parsing du header
}
