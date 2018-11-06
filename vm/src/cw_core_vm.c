/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_core_vm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 15:43:55 by jabt              #+#    #+#             */
/*   Updated: 2018/11/06 18:08:41 by galemair         ###   ########.fr       */
/*   Updated: 2018/11/06 10:15:56 by galemair         ###   ########.fr       */
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

	tab = arena.process_to_exec[index];
	while (tab->next)
		tab = tab->next;
	tab = malloc(sizeof(t_processus));
	memcpy(tab, process, sizeof(t_processus));
	tab->opcode = opc;
}

static void		cw_exec_instructions(int index)
{
	static void		(*ptr[16]) (t_processus *);
	t_processus		*process;

	if (!*ptr)
		cw_init_funtab(ptr);
	process = arena.process_to_exec[index];
	while (process)
	{
		(*ptr[process->opcode - 1])(process);
		process = process->next;
		ft_lstappend(&arena.process, ft_lstnew(process, sizeof(process)));
	}
}

void		cw_read_processus_opc(int index, int ctd)
{
	t_list			*lst_process;
	t_processus		*process;
	unsigned int	opc_tmp;

	lst_process = arena.process;
	while (lst_process)
	{
		process = (t_processus *)lst_process->content;
		opc_tmp = cw_calculate_value_on_ram(process->pc, 1);
		//printf("opc = %u\n", opc_tmp);
		if (opc_tmp >= 1 && opc_tmp <= 16)
		{
			if (op_tab[opc_tmp].cycle <= (ctd - index))
			{
				printf("salut a tous\n");
			//	add_instruction_to_tab(process, (op_tab[opc_tmp].cycle + index), opc_tmp); // sinon le processus est kill
			}
		}
		else
		{
			process = (t_processus *)lst_process->content;
			process->pc++;
			ft_lstappend(&lst_process, ft_lstnew(process, sizeof(process)));
		}
		lst_process = lst_process->next;
	}
	ft_lstappend(&lst_process, ft_lstnew("delimiter", sizeof(char) * 10));
	arena.process = lst_process;
	print_all_process();
	cw_clean_lst();
}

int				cw_fight(void)
{
	t_list			*process;
	unsigned int	ctd;
	int				i;

	process = arena.process;
	ctd = arena.cycle_to_die;
	i = 0;
	while (1)
	{
		cw_read_processus_opc(i, ctd); // execution d'un cycle
		exit (0);
		cw_exec_instructions(i);
		i++;
		if (i >= ctd)
		{
			;
		}
	}
	return (1);
}
