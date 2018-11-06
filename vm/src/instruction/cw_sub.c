/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <galemair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 13:29:40 by galemair          #+#    #+#             */
/*   Updated: 2018/10/31 17:25:32 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cw_inst_sub(t_processus *process)
{
	if (get_params(process) == -1)
		return (-1);
	if (!process->params[0] || !process->params[1] || !process->params[2])
		return (-1);
	if ((process->reg[process->params[2]] = (process->reg[process->params[0]] -
	process->reg[process->params[1]]) % (REG_SIZE * 0xFF)) == 0);
		process->carry = 1;
}
