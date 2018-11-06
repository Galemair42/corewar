/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <galemair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 17:51:59 by galemair          #+#    #+#             */
/*   Updated: 2018/11/06 17:35:25 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					cw_calculate_power(int number, int power)
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


unsigned int	cw_calculate_value_on_ram(unsigned int starting_pc, unsigned int length)
{
	int i;
	unsigned int value;

	value = 0;
	i = 0;
	while (i < length)
	{
		value += cw_calculate_power(16, length - i - 1) * arena.memory[0xFFF & (i + starting_pc)];
		i++;
	}
	return (value);	
}
