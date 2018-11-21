/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_inst_ld.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <galemair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:10:34 by galemair          #+#    #+#             */
/*   Updated: 2018/11/20 17:04:56 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		cw_inst_ld(t_processus *process)
{
	int		ret;
	int		landing;

	if ((ret = get_params(process)) == -1)
	{
		cw_reset_process(process);
		return ;
	}
	if (((process->ocp >> 6) & 3) == DIR_CODE)
		process->reg[process->params[1]] = process->params[0];
	else if (((process->ocp >> 6) & 3) == IND_CODE)
	{
		landing = apply_idx_mod(process->pc,
				MEM_MASK(process->pc + process->params[0]));
		process->reg[process->params[1]] =
			cw_calculate_value_on_ram(landing, 4);
	}
	process->carry = (process->reg[process->params[1]] == 0) ? 1 : 0;
	if (g_arena.visu_fight)
		cw_visu_incr_process(process, MEM_MASK(ret));
	process->pc = ret;
	cw_reset_process(process);
}
