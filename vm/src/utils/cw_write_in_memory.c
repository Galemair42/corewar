/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_write_in_memory.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:53:32 by jabt              #+#    #+#             */
/*   Updated: 2018/11/20 14:45:33 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			cw_put_four_octet_visu(unsigned int index,
		unsigned int four_octet, int color_pair)
{
	g_arena.memory[index] = four_octet >> 24;
	g_arena.memory[MEM_MASK(index + 1)] = (four_octet >> 16) & 0xFF;
	g_arena.memory[MEM_MASK(index + 2)] = (four_octet >> 8) & 0xFF;
	g_arena.memory[MEM_MASK(index + 3)] = four_octet & 0xFF;
	ft_memset(&g_arena.mem_color[index], color_pair, 4);
	wattron(g_arena.visu_fight, COLOR_PAIR(color_pair));
	mvwprintw(g_arena.visu_fight, (index / 64) + 1, ((index % 64) * 3) + 3,
			"%.2X", g_arena.memory[index]);
	mvwprintw(g_arena.visu_fight, ((MEM_MASK(index + 1)) / 64) + 1,
			(((MEM_MASK(index + 1)) % 64) * 3) + 3,
			"%.2X", g_arena.memory[MEM_MASK(index + 1)]);
	mvwprintw(g_arena.visu_fight, ((MEM_MASK(index + 2)) / 64) + 1,
			(((MEM_MASK(index + 2)) % 64) * 3) + 3,
			"%.2X", g_arena.memory[MEM_MASK(index + 2)]);
	mvwprintw(g_arena.visu_fight, ((MEM_MASK(index + 3)) / 64) + 1,
			(((MEM_MASK(index + 3)) % 64) * 3) + 3,
			"%.2X", g_arena.memory[MEM_MASK(index + 3)]);
	wattroff(g_arena.visu_fight, COLOR_PAIR(color_pair));
	wrefresh(g_arena.visu_fight);
}

void			cw_put_four_octet(unsigned int index, unsigned int four_octet)
{
	g_arena.memory[index] = four_octet >> 24;
	g_arena.memory[MEM_MASK(index + 1)] = (four_octet >> 16) & 0xFF;
	g_arena.memory[MEM_MASK(index + 2)] = (four_octet >> 8) & 0xFF;
	g_arena.memory[MEM_MASK(index + 3)] = four_octet & 0xFF;
}

unsigned int	cw_get_four_octet(unsigned int index)
{
	unsigned int result;

	result = g_arena.memory[index] << 24;
	result += g_arena.memory[MEM_MASK(index + 1)] << 16;
	result += g_arena.memory[MEM_MASK(index + 2)] << 8;
	result += g_arena.memory[MEM_MASK(index + 3)];
	return (result);
}
