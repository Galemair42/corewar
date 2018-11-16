/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_inst_ldi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:02:34 by jabt              #+#    #+#             */
/*   Updated: 2018/11/16 10:03:14 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		cw_inst_ldi(t_processus *process)
{
	unsigned int	landing;
	unsigned int	ret;

	if ((ret = get_params(process, 1)) == -1)
	{
		cw_reset_process(process);
		return ;
	}
	landing = cw_get_one_params(process, 1, true);
	if ((((process->ocp >> 4) & 3) == DIR_CODE))
		landing += process->params[1];
	else if ((((process->ocp >> 4) & 3) == REG_CODE))
		landing += process->reg[process->params[1]];
	landing = apply_IDX_MOD(process->pc, MEM_MASK(process->pc + landing));
	if (arena.visu_fight)
		cw_visu_incr_process(process, ret);
	process->reg[process->params[2]] = cw_calculate_value_on_ram(landing, 4);
	process->pc = ret;
	cw_reset_process(process);
}
