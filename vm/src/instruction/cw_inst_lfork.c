/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_inst_lfork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <galemair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:10:49 by galemair          #+#    #+#             */
/*   Updated: 2018/11/12 15:07:57 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void    cw_inst_lfork(t_processus *process)
{
	unsigned int	param;
	unsigned int	pc;
	t_processus		*new_processus;

	param = cw_calculate_value_on_ram(process->pc + 1, 2);
	pc = MEM_MASK(process->pc + param);
	new_processus = malloc(sizeof(t_processus));
	memcpy(new_processus, process, sizeof(t_processus));
	new_processus->pc = pc;
	new_processus->id = arena.current_process_id;
	arena.current_process_id++;
	ft_lstappend(&arena.process, ft_lstnew(new_processus, sizeof(t_processus)));
	free(new_processus);
	if (arena.visu_fight)
	{
		cw_visu_incr_process(process, MEM_MASK(process->pc + 3));
		cw_highlight(pc);
		wrefresh(arena.visu_fight);
	}
	process->pc = MEM_MASK(process->pc + 3);
	cw_reset_process(process);
}
