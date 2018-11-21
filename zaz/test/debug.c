/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 10:48:17 by jabt              #+#    #+#             */
/*   Updated: 2018/11/21 10:12:32 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_one_champ(t_champion *champ)
{
	
	printf("name : %s\n", champ->name);
	printf("prog_name : %s\n", champ->header.prog_name);
	printf("comment : %s\n", champ->header.comment);
	printf("prog_size : %u\n", champ->header.prog_size);
	printf("id : %d\n", champ->id);
	printf("current_live = %d\n", champ->nb_live);
	//print_buffer_in_hexa(champ->instruction, CHAMP_MAX_SIZE);
	printf("\n\n");
}

void	print_all_champ(void)
{
	t_list	*lst;
	t_champion	*champ;

	lst = g_arena.champion;
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
	printf("process opc : %d\n", process->opcode);
	printf("process carry : %u\n", process->carry);
	printf("current_live : %u\n", process->nb_live);
	//printf("process id_player : %d\n", process->id_player);
//	for (int i = 0; i < REG_NUMBER; i++)
//	{
//		printf("REG[%d] : %u\n", i, process->reg[i]);
//	}
//	printf("Params Value :\n");
//	for (int i = 0; i < 5; i++)
//	{
//		printf("Params[%d] : %u\n", i, process->params[i]);
//	}
}

int		print_all_process(void)
{
	t_processus		*cur_process;
	t_list			*process;
	int				ret=0;

	process = g_arena.process;
	while (process)
	{
		cur_process = (t_processus *)process->content;
		print_process(cur_process);
		process = process->next;
		printf("\n");
		ret++;
	}
	return (ret - 1);
}

int		print_exec_tab(void)
{
	t_list *list;
	t_processus *cur_process;
	int ret=0;
	
	for (int i=0; i < CYCLE_TO_DIE;i++)
	{
		list = g_arena.process_to_exec[i];
		while (list)
		{
			cur_process = (t_processus *)list->content;
			printf("\ni = %d\n", i);
			printf("\ni = %d\n", i);
			print_process(cur_process);
			list = list->next;
			ret++;
		}
	}
	return (ret);
}

