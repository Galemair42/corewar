
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 13:48:58 by jabt              #+#    #+#             */
/*   Updated: 2018/11/17 17:51:13 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				main(int argc, char **argv)
{
	cw_init_processeur();
	if (!cw_parse_arg(argv, argc))
		return (42);
	cw_put_champion_in_memory();
	if (!(arena.process = cw_init_process()))
		return (42);
	if (arena.visu_fight)
		cw_fight_visu();
	else
		cw_fight();
	cw_clean_everything();
	free(arena.visu_fight);
	free(arena.visu_score);
	free(arena.mem_color);
	while (1);
}
