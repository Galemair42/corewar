/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_inst_lfork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <galemair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:10:49 by galemair          #+#    #+#             */
/*   Updated: 2018/11/20 14:46:47 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		cw_inst_lfork(t_processus *process)
{
	unsigned int	param;
	unsigned int	pc;
	t_processus		*new_processus;

	g_arena.cur_processus++;
	param = cw_calculate_value_on_ram(process->pc + 1, 2);
	pc = MEM_MASK(process->pc + param);
	if ((new_processus = malloc(sizeof(t_processus))) == NULL)
		exit(-1);
	memcpy(new_processus, process, sizeof(t_processus));
	ft_bzero(new_processus->params, 4 * sizeof(int));
	new_processus->pc = pc;
	new_processus->id = g_arena.current_process_id;
	g_arena.current_process_id++;
	ft_lstappend(&g_arena.process, ft_lstnew(new_processus,
				sizeof(t_processus)));
	free(new_processus);
	if (g_arena.visu_fight)
	{
		cw_visu_incr_process(process, MEM_MASK(process->pc + 3));
		cw_highlight_octet(pc, g_arena.mem_color[pc]);
		wrefresh(g_arena.visu_fight);
	}
	process->pc = MEM_MASK(process->pc + 3);
	cw_reset_process(process);
}
