/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_inst_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:13:17 by jabt              #+#    #+#             */
/*   Updated: 2018/11/20 14:44:19 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**      this function reads a param a retrun its value when the param can
**      be REG / DIR / IND number is its position into the ocp
*/

unsigned int		cw_get_first_params_sti(t_processus *process, int number)
{
	unsigned int	ret;
	unsigned int	landing;

	number = 8 - (number * 2);
	if (((process->ocp >> number) & 3) == DIR_CODE)
		ret = process->params[1];
	else if (((process->ocp >> number) & 3) == REG_CODE)
		ret = process->reg[process->params[1]];
	else if (((process->ocp >> number) & 3) == IND_CODE)
	{
		landing = apply_idx_mod(process->pc, MEM_MASK(process->pc +
					process->params[1]));
		ret = cw_calculate_value_on_ram(landing, 4);
	}
	else
		return (-1);
	return (ret);
}
