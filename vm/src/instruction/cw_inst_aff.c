/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_inst_aff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 09:56:57 by jabt              #+#    #+#             */
/*   Updated: 2018/11/16 09:57:25 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		cw_inst_aff(t_processus *process)
{
	char	c;
	int		ret;

	if ((ret = get_params(process, 0)) == -1)
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
	cw_reset_process(process);
}
