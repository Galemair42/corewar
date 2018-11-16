/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <galemair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 17:51:59 by galemair          #+#    #+#             */
/*   Updated: 2018/11/16 18:27:35 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				cw_calculate_power(int number, int power)
{
	int i;
	int return_value;

	return_value = 1;
	i = 0;
	while (i < power)
	{
		return_value *= number;
		i++;
	}
	return (return_value);
}

unsigned int	cw_calculate_value_on_ram(unsigned int starting_pc,
		unsigned int length)
{
	unsigned int	result;
	int				i;
	int				j;

	i = length - 1;
	j = starting_pc;
	result = 0;
	while (i >= 0)
	{
		result += arena.memory[MEM_MASK(j)] << (i * 8);
		i--;
		j++;
	}
	return (result);
}
