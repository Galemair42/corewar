/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_inst_sti.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:11:06 by jabt              #+#    #+#             */
/*   Updated: 2018/11/16 15:32:14 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		cw_inst_sti(t_processus *process)
{
	unsigned int	landing;
	unsigned int	ret;

	landing = 0;
	if ((ret = get_params(process)) == -1)
	{
		cw_reset_process(process);
		return ;
	}
	landing = cw_get_one_params(process, 2, true);
	if ((((process->ocp >> 2) & 3) == DIR_CODE))
		landing += process->params[2];
	else if (((process->ocp >> 2) & 3) == REG_CODE)
		landing += process->reg[process->params[2]];
	landing = apply_IDX_MOD(process->pc, MEM_MASK(process->pc + landing));
	if (arena.visu_fight)
	{
		cw_put_four_octet_visu(landing, process->reg[process->params[0]],
				arena.mem_color[process->pc]);
		cw_visu_incr_process(process, ret);
	}
	else
		cw_put_four_octet(landing, process->reg[process->params[0]]);
	process->pc = ret;
	cw_reset_process(process);
}
