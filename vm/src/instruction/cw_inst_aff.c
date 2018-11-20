/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_inst_aff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 09:56:57 by jabt              #+#    #+#             */
/*   Updated: 2018/11/20 14:45:33 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		cw_inst_aff(t_processus *process)
{
	char	c;
	int		ret;

	if ((ret = get_params(process)) == -1)
	{
		cw_reset_process(process);
		return ;
	}
	c = process->reg[process->params[0]] % 256;
	write(1, &c, 1);
	if (c == 0)
		process->carry = 1;
	else
		process->carry = 0;
	if (g_arena.visu_fight)
		cw_visu_incr_process(process, ret);
	process->pc = ret;
	cw_reset_process(process);
}
