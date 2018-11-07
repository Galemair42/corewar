/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 10:48:17 by jabt              #+#    #+#             */
/*   Updated: 2018/11/07 18:54:21 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_buffer_in_hexa(unsigned char *buffer, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	printf("sa\n");
	while (i < size)
	{
		j = 0;
		while (j < 64 && i < size) // comme zaz
		{
			printf("%02x ", buffer[i]);
			j++;
			i++;
		}
		printf("\n");
	}
}

void	print_one_champ(t_champion *champ)
{
	
	printf("name : %s\n", champ->name);
	printf("prog_name : %s\n", champ->header.prog_name);
	printf("comment : %s\n", champ->header.comment);
	printf("prog_size : %u\n", champ->header.prog_size);
	printf("id : %d\n", champ->id);
//	print_buffer_in_hexa(champ->instruction, CHAMP_MAX_SIZE);
	printf("\n\n");
}

void	print_all_champ(void)
{
	t_list	*lst;
	t_champion	*champ;

	lst = arena.champion;
	while (lst)
	{
		champ = lst->content;
		print_one_champ(champ);
		lst = lst->next;
	}
}

void print_register(t_processus *process)
{
	unsigned int *reg;

	reg = process->reg;
	int i = 0;
	while (i < REG_NUMBER)
	{
		printf("process->reg[%d] : %u\n", i, process->reg[i]);
		i++;
	}
}

void	print_process(t_processus *process)
{
	printf("process id : %d\n", process->id);
	printf("process PC : %d\n", process->pc);
	printf("process carry : %u\n", process->carry);
	//printf("process id_player : %d\n", process->id_player);
	for (int i = 0; i < REG_NUMBER; i++)
	{
		printf("REG[%d] : %u\n", i, process->reg[i]);
	}
	printf("Params Value :\n");
	for (int i = 0; i < 5; i++)
	{
		printf("Params[%d] : %u\n", i, process->params[i]);
	}
}

void	print_all_process(void)
{
	t_processus		*cur_process;
	t_list			*process;

	process = arena.process;
	while (process)
	{
		cur_process = (t_processus *)process->content;
		print_process(cur_process);
		process = process->next;
		printf("\n");
	}
}
