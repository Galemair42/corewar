/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_core_vm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 15:43:55 by jabt              #+#    #+#             */
/*   Updated: 2018/11/09 18:20:33 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		cw_init_funtab(void (**ptr)(t_processus *))
{
	ptr[0] = &cw_inst_live;
	ptr[1] = &cw_inst_ld;
	ptr[2] = &cw_inst_st;
	ptr[3] = &cw_inst_add;
	ptr[4] = &cw_inst_sub;
	ptr[5] = &cw_inst_and;
	ptr[6] = &cw_inst_or;
	ptr[7] = &cw_inst_xor;
	ptr[8] = &cw_inst_zjmp;
	ptr[9] = &cw_inst_ldi;
	ptr[10] = &cw_inst_sti;
	ptr[11] = &cw_inst_fork;
	ptr[12] = &cw_inst_lld;
	ptr[13] = &cw_inst_lldi; 
	ptr[14] = &cw_inst_lfork;
	ptr[15] = &cw_inst_aff;
}

void			add_instruction_to_tab(t_processus *process, int index, unsigned int opc)
{
	t_processus 	*tab;

	tab = malloc(sizeof(t_processus));
	memcpy(tab, process, sizeof(t_processus));
	tab->opcode = opc;
	if (!arena.process_to_exec[index])
		arena.process_to_exec[index] = tab;
	else
		cw_insert_process(&arena.process_to_exec[index], tab);
}

static void		cw_exec_instructions(int index)
{
	static void		(*ptr[16]) (t_processus *);
	t_processus		*process;
	t_processus		*tmp;

	if (!*ptr)
		cw_init_funtab(ptr);
	process = arena.process_to_exec[index];
	while (process)
	{
		tmp = process->next;
		printf("*Execution de l'instruction -%s-*\n", op_tab[process->opcode - 1].name);
		(*ptr[process->opcode - 1])(process);
		ft_lstappend(&arena.process, ft_lstnew(process, sizeof(t_processus)));
		free(process);
		process = tmp;
	}
	arena.process_to_exec[index] = NULL;
}

void		cw_read_processus_opc(int index, int ctd)
{
	t_list			*lst_process;
	t_processus		*process;
	unsigned int	opc_tmp;

	ft_lstappend(&arena.process, ft_lstnew(ft_memalloc(sizeof(t_processus)), sizeof(t_processus)));
	lst_process = arena.process;
	while (lst_process && ((t_processus *)lst_process->content)->id != 0)
	{
		process = (t_processus *)lst_process->content;
		opc_tmp = cw_calculate_value_on_ram(process->pc, 1);
		if (opc_tmp >= 1 && opc_tmp <= 16)
		{
			if (!(op_tab[opc_tmp - 1].cycle > (ctd - index) && process->nb_live == 0))
				add_instruction_to_tab(process, (op_tab[opc_tmp - 1].cycle + index) % ctd, opc_tmp);
		}
		else
		{
			process = (t_processus *)lst_process->content;
			process->pc++;
			ft_lstappend(&arena.process, ft_lstnew(process, sizeof(t_processus)));
		}
		lst_process = lst_process->next;
	}
	cw_clean_lst();
}

int				cw_fight(void)
{
	unsigned int	ctd;
	int				cycle;
	int				cycle_decrementation;

	ctd = arena.cycle_to_die;
	cycle_decrementation = 0;
	cycle = 0;
	while (1)
	{
		printf("cycle numero: %d\n", cycle);
		print_all_process();
		cw_read_processus_opc(cycle, ctd);
		printf("\n");
		cw_exec_instructions(cycle);
		cycle++;
		if (cycle == ctd)
		{
			exit (0);
			if (arena.cycle_live >= NBR_LIVE || cycle_decrementation == MAX_CHECKS - 1)
			{
				ctd -= CYCLE_DELTA;
				cycle_decrementation = 0;
			}
			else
				cycle_decrementation++;
			cw_verif_processes();
			//cw_clear_exec_tab();
			printf("%d\n", arena.cycle_live);
			if (arena.cycle_live == 0)
			{
				printf("Nous avons un winner !\n");
				return (1);
			}
			arena.cycle_live = 0;
			cycle = 0;
		}
	}
	return (1);
}
