/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <galemair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 17:51:59 by galemair          #+#    #+#             */
/*   Updated: 2018/11/21 13:51:23 by femaury          ###   ########.fr       */
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
		result += g_arena.memory[MEM_MASK(j)] << (i * 8);
		i--;
		j++;
	}
	return (result);
}

void			print_buffer_in_hexa(unsigned char *buffer, size_t size)
{
	size_t			i;
	size_t			j;
	unsigned int	line;

	i = 0;
	line = 0;
	ft_printf("0x0000 : ");
	while (i < size)
	{
		j = 0;
		if (line > 0)
			ft_printf("%#.4x : ", line * 64);
		while (j < 64 && i < size)
		{
			ft_printf("%02x ", buffer[i]);
			j++;
			i++;
		}
		ft_printf("\n");
		line++;
	}
}
