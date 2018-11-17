/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_core_vm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 15:43:55 by jabt              #+#    #+#             */
/*   Updated: 2018/11/17 19:01:44 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_list			*add_instruction_to_tab(t_list *process, int index,
		unsigned int opc)
{
	t_processus		*tmp;
	t_list			*to_return;

	to_return = process->next;
	process->next = NULL;
	tmp = (t_processus *)process->content;
	tmp->opcode = opc;
	if (!arena.process_to_exec[index])
		arena.process_to_exec[index] = process;
	else
		cw_insert_process(&arena.process_to_exec[index], process);
	return (to_return);
}

void			cw_exec_instructions(int index)
{
	static void		(*ptr[16]) (t_processus *);
	t_processus		*process;
	t_list			*tmp;
	t_list			*lst;

	if (!*ptr)
		cw_init_funtab(ptr);
	lst = arena.process_to_exec[index];
	while (lst)
	{
		process = (t_processus *)(lst->content);
		tmp = lst->next;
		//printf("Execution de l'instruction *%s* au cycle %d\n", op_tab[process->opcode - 1].name, arena.cur_cycle);
		(*ptr[process->opcode - 1])(process);
		lst->next = NULL;
		ft_lstappend(&arena.process, lst);
		lst = tmp;
	}
	arena.process_to_exec[index] = NULL;
}

void			cw_read_processus_opc(int index, int ctd)
{
	t_list			*lst_process;
	t_processus		*process;
	unsigned int	opc_tmp;
	t_list			*tmp;
	t_list			*tmp2;

	tmp = arena.process;
	ft_lstappend(&arena.process, arena.process);
	lst_process = arena.process;
//	if (arena.cur_cycle == 2362)
//	{
//		print_exec_tab();
//		printf("\n-----\n");
//		print_all_process();
//		exit (0);
//	}
	while (lst_process && ((t_processus *)lst_process->content)->id != 0)
	{
		process = (t_processus *)lst_process->content;
		opc_tmp = cw_calculate_value_on_ram(process->pc, 1);
		if (opc_tmp >= 1 && opc_tmp <= 16)
		{
//			if (opc_tmp == 10)
//			{
//				printf("gregewgrewrg\n");
//				exit(4);
//			}
			if (!(op_tab[opc_tmp - 1].cycle > (ctd - index) && process->nb_live == 0))
				lst_process = add_instruction_to_tab(lst_process, (op_tab[opc_tmp - 1].cycle + index - 1) % ctd, opc_tmp);
			else
			{
				//printf("Cycle %d died at cycle %d\n", process->id, arena.cur_cycle);
				arena.cur_processus--;
				if (arena.visu_fight)
					cw_unhighlight_octet(process->pc, arena.mem_color[process->pc]);
				lst_process = free_list_elem(lst_process);			
			}
		}
		else
		{
			process = (t_processus *)lst_process->content;
			if (arena.visu_fight)
				cw_visu_incr_process(process, MEM_MASK(process->pc + 1));
			process->pc = MEM_MASK(process->pc + 1);
			tmp2 = lst_process->next;
			lst_process->next = NULL;
			ft_lstappend(&tmp, lst_process);
			lst_process = tmp2;
		}
	}
	arena.process = tmp;
}

int				cw_fight(void)
{
	unsigned int	ctd;
	int				cycle;
	int				cycle_decrementation;
	t_processus		delimiter;

	ft_bzero(&delimiter, sizeof(t_processus));
	ctd = arena.cycle_to_die;
	cycle_decrementation = 0;
	cycle = 0;
	while (1)
	{
		cw_read_processus_opc(cycle, ctd);
		cw_exec_instructions(cycle);
		cycle++;
		arena.cur_cycle++;
//		if (arena.cur_cycle == 36000)
//		{
//			print_all_process();
//			printf("\n---\n");
//			print_exec_tab();
//			exit (0);
//		}
//		if (print_exec_tab() + print_all_process() > 24)
//		{
//			printf("%d\n", arena.cur_cycle);
//			exit (0);
//		}
		if (cycle == ctd)
		{
			if (arena.cycle_live >= NBR_LIVE || cycle_decrementation == MAX_CHECKS - 1)
			{
				ctd = (int)(ctd - CYCLE_DELTA) >= 0 ? ctd - CYCLE_DELTA : 1;
				cycle_decrementation = 0;
			}
			else
				cycle_decrementation++;
			cw_reset_live();
			if (arena.cycle_live == 0)
			//if (print_exec_tab() + print_all_process() == 0)
			{
				printf("FINAL CYCLE = %d\n", arena.cur_cycle);
				if (arena.id_last_player_alive == 0)
					printf("No Winner");
				else
					printf("The winner is %s!\n", get_champs_name_by_id(arena.id_last_player_alive));
				return (1);
			}
			ft_lstadd(&arena.process, ft_lstnew(ft_memalloc(sizeof(t_processus)), sizeof(t_processus)));
//			ft_lstadd(&arena.process, ft_lstnew(&delimiter, sizeof(t_processus)));
			arena.cycle_live = 0;
			cycle = 0;
		}
	}
	return (1);
}
