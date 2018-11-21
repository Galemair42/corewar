/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:05:28 by jabt              #+#    #+#             */
/*   Updated: 2018/11/20 16:05:35 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				main(int argc, char **argv)
{
	cw_init_processeur();
	if (!cw_parse_arg(argv, argc))
		return (42);
	cw_put_champion_in_memory();
	if (!(g_arena.process = cw_init_process()))
		return (42);
	if (g_arena.visu_fight)
		cw_fight(1);
	else
		cw_fight(0);
	cw_clean_everything();
	free(g_arena.visu_fight);
	free(g_arena.visu_score);
	free(g_arena.mem_color);
}
