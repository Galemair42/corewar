/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 10:48:17 by jabt              #+#    #+#             */
/*   Updated: 2018/09/19 11:24:17 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_buffer_in_hexa(unsigned char *buffer, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < 16)
		{
			printf("%02x ", buffer[i]);
			j++;
			i++;
		}
		printf("\n");
	}
}
