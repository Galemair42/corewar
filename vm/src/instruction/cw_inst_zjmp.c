/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_inst_zjmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:23:43 by jabt              #+#    #+#             */
/*   Updated: 2018/11/20 14:45:33 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		cw_inst_zjmp(t_processus *process)
{
	unsigned int	param;
	int				new_pc;

	param = cw_calculate_value_on_ram(process->pc + 1, 2);
	if (process->carry == 1)
	{
		new_pc = apply_idx_mod(process->pc, MEM_MASK(process->pc + param));
		if (g_arena.visu_fight)
			cw_visu_incr_process(process, new_pc);
		process->pc = new_pc;
	}
	else
	{
		if (g_arena.visu_fight)
			cw_visu_incr_process(process, MEM_MASK(process->pc + 3));
		process->pc = MEM_MASK(process->pc + 3);
	}
	cw_reset_process(process);
}
