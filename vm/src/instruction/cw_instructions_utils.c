/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_instructions_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <galemair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 13:39:56 by galemair          #+#    #+#             */
/*   Updated: 2018/11/08 12:26:57 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**		prend le pc et l'endroit ou ca doit atterir
*/

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
			diff2 -= former_pc;
			if (diff2 < 0)
				diff2 = 0;
			return (0xFFF & (MEM_SIZE - diff2));
		}
	}
}
