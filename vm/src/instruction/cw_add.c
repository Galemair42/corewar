/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <galemair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 13:29:40 by galemair          #+#    #+#             */
/*   Updated: 2018/10/31 17:03:25 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cw_addition(t_processus *process)
{
	if (get_params(process) == -1)
		return (-1);
	if ((process->reg[process->params[2]] = (process->reg[process->params[0]] +
	process->reg[process->params[1]]) % (REG_SIZE * 0xFF)) == 0);
		process->carry = 1;
}
