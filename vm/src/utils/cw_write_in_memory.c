/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_write_in_memory.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:53:32 by jabt              #+#    #+#             */
/*   Updated: 2018/11/16 10:54:50 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			cw_put_four_octet_visu(unsigned int index,
		unsigned int four_octet, int color_pair)
{
	arena.memory[index] = four_octet >> 24;
	arena.memory[MEM_MASK(index + 1)] = (four_octet >> 16) & 0xFF;
	arena.memory[MEM_MASK(index + 2)] = (four_octet >> 8) & 0xFF;
	arena.memory[MEM_MASK(index + 3)] = four_octet & 0xFF;
	ft_memset(&arena.mem_color[index], color_pair, 4);
	wattron(arena.visu_fight, COLOR_PAIR(color_pair));
	mvwprintw(arena.visu_fight, (index / 64) + 1, ((index % 64) * 3) + 3,
			"%.2X", arena.memory[index]);
	mvwprintw(arena.visu_fight, ((MEM_MASK(index + 1)) / 64) + 1,
			(((MEM_MASK(index + 1)) % 64) * 3) + 3,
			"%.2X", arena.memory[MEM_MASK(index + 1)]);
	mvwprintw(arena.visu_fight, ((MEM_MASK(index + 2)) / 64) + 1,
			(((MEM_MASK(index + 2)) % 64) * 3) + 3,
			"%.2X", arena.memory[MEM_MASK(index + 2)]);
	mvwprintw(arena.visu_fight, ((MEM_MASK(index + 3)) / 64) + 1,
			(((MEM_MASK(index + 3)) % 64) * 3) + 3,
			"%.2X", arena.memory[MEM_MASK(index + 3)]);
	wattroff(arena.visu_fight, COLOR_PAIR(color_pair));
	wrefresh(arena.visu_fight);
}

void			cw_put_four_octet(unsigned int index, unsigned int four_octet)
{
	arena.memory[index] = four_octet >> 24;
	arena.memory[MEM_MASK(index + 1)] = (four_octet >> 16) & 0xFF;
	arena.memory[MEM_MASK(index + 2)] = (four_octet >> 8) & 0xFF;
	arena.memory[MEM_MASK(index + 3)] = four_octet & 0xFF;
}

unsigned int	cw_get_four_octet(unsigned int index)
{
	unsigned int result;

	result = arena.memory[index] << 24;
	result += arena.memory[MEM_MASK(index + 1)] << 16;
	result += arena.memory[MEM_MASK(index + 2)] << 8;
	result += arena.memory[MEM_MASK(index + 3)];
	return (result);
}
