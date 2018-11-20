/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_inst_st.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:10:05 by jabt              #+#    #+#             */
/*   Updated: 2018/11/20 14:45:33 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		cw_inst_st(t_processus *process)
{
	int		param_2;
	int		ret;
	int		landing;

	if ((ret = get_params(process)) == -1)
	{
		cw_reset_process(process);
		return ;
	}
	if (((process->ocp >> 4) & 3) == IND_CODE)
	{
		landing = apply_idx_mod(process->pc, MEM_MASK(process->pc +
					process->params[1]));
		if (g_arena.visu_fight)
			cw_put_four_octet_visu(landing, process->reg[process->params[0]],
					g_arena.mem_color[process->pc]);
		else
			cw_put_four_octet(landing, process->reg[process->params[0]]);
	}
	else
		process->reg[process->params[1]] = process->reg[process->params[0]];
	if (g_arena.visu_fight)
		cw_visu_incr_process(process, ret);
	process->pc = MEM_MASK(ret);
	cw_reset_process(process);
}
