/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_instructions_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <galemair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 13:39:56 by galemair          #+#    #+#             */
/*   Updated: 2018/11/13 14:26:01 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int	apply_IDX_MOD(unsigned int former_pc, unsigned int new_pc)
{
	int diff1;
	int	diff2;
	int	tmp;
	
	diff1 = (former_pc >= new_pc ? former_pc : new_pc) - (former_pc >= new_pc ? new_pc : former_pc);
	diff2 = (MEM_SIZE) - (former_pc >= new_pc ? former_pc : new_pc) + (former_pc >= new_pc ? new_pc : former_pc);
	if (diff1 <= diff2)
	{
		if (former_pc >= new_pc)
			return (0xFFF & (former_pc - (diff1 % IDX_MOD)));
		else
			return (0xFFF & (former_pc + (diff1 % IDX_MOD)));
	}
	else
	{
		if (former_pc >= new_pc)
			return (0xFFF & (former_pc + (diff2 % IDX_MOD)));
		else
		{
			diff2 %= IDX_MOD;
			tmp = (int)(former_pc - diff2) >= 0 ? 0 : diff2 - former_pc; 
			if (tmp == 0)
				return (former_pc - diff2);
			else
				return (0xFFF & (MEM_SIZE - tmp));
		}
	}
}
