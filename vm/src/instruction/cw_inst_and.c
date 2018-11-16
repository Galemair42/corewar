/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_inst_and.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 09:57:34 by jabt              #+#    #+#             */
/*   Updated: 2018/11/16 09:58:06 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		cw_inst_and(t_processus *process)
{
	int		reg_1;
	int		reg_2;
	int		reg_3;
	int		ret;

	if ((ret = get_params(process, 0)) == -1)
	{
		cw_reset_process(process);
		return ;
	}
	reg_1 = process->reg[process->params[0]];
	reg_2 = process->reg[process->params[1]];
	reg_3 = process->params[2];
	if (!(process->reg[reg_3] = reg_1 & reg_2))
		process->carry = 1;
	else
		process->carry = 0;
	if (arena.visu_fight)
		cw_visu_incr_process(process, ret);
	process->pc = MEM_MASK(ret);
	cw_reset_process(process);
}
