/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <galemair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 17:51:59 by galemair          #+#    #+#             */
/*   Updated: 2018/10/31 18:30:27 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int		get_value(unsigned char cmp)
{
	unsigned char hexa[17];
	unsigned int i;

	i = 0;
	hexa = "0123456789abcdef";
	while (hexa[i] && hexa[i] != cmp)
		i++;
	return(i);
}

int					calculate_power(int number, int power)
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


unsigned int	calculate_value_on_ram(unsigned int starting_pc, unsigned int length)
{
	int i;
	unsigned int value;

	value = 0;
	i = 0;
	while (i < length)
	{
		value += calculate_power(16, length - i - 1) * get_value(memory[0xFFF & (i + starting_pc)]);
		i++;
	}
	return (value);	
}
