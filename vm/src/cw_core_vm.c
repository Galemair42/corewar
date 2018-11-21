/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_core_vm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 15:43:55 by jabt              #+#    #+#             */
/*   Updated: 2018/11/21 10:11:27 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_list			*add_instruction_to_tab(t_list *process, int index,
		unsigned int opc)
{
	t_processus		*tmp;
	t_list			*to_return;
	int				i;

	i = g_arena.current_process_to_exec;
	to_return = process->next;
	process->next = NULL;
	tmp = (t_processus *)process->content;
	tmp->opcode = opc;
	if (!g_arena.process_to_exec[(index + i) % CYCLE_TO_DIE])
		g_arena.process_to_exec[(index + i) % CYCLE_TO_DIE] = process;
	else
		cw_insert_process(&g_arena.process_to_exec[(index + i) % CYCLE_TO_DIE],
		process);
	return (to_return);
}

void			cw_exec_instructions(void)
{
	static void		(*ptr[16]) (t_processus *);
	t_processus		*process;
	t_list			*tmp;
	t_list			*lst;

	if (!*ptr)
		cw_init_funtab(ptr);
	lst = g_arena.process_to_exec[g_arena.current_process_to_exec];
	while (lst)
	{
		process = (t_processus *)(lst->content);
		tmp = lst->next;
		(*ptr[process->opcode - 1])(process);
		lst->next = NULL;
		ft_lstappend(&g_arena.process, lst);
		lst = tmp;
	}
	g_arena.process_to_exec[g_arena.current_process_to_exec] = NULL;
	g_arena.current_process_to_exec = (g_arena.current_process_to_exec + 1)
	% CYCLE_TO_DIE;
}

void			cw_manage_valide_opc(unsigned int opc_tmp, int index, int ctd,
		t_processus *process)
{
	if (!(g_op_tab[opc_tmp - 1].cycle >
		(ctd - index) && process->nb_live == 0) && (((2 * ctd) - index)
		>= g_op_tab[opc_tmp - 1].cycle))
		g_arena.process = add_instruction_to_tab(g_arena.process,
		(g_op_tab[opc_tmp - 1].cycle - 1), opc_tmp);
	else
	{
		g_arena.cur_processus--;
		if (g_arena.visu_fight)
			cw_unhighlight_octet(process->pc,
			g_arena.mem_color[process->pc]);
		g_arena.process = free_list_elem(g_arena.process);
	}
}

void			cw_read_processus_opc(int index, int ctd)
{
	t_processus		*process;
	unsigned int	opc_tmp;

	ft_lstappend(&g_arena.process, g_arena.process);
	while (g_arena.process
		&& ((t_processus *)g_arena.process->content)->id != 0)
	{
		process = (t_processus *)g_arena.process->content;
		opc_tmp = cw_calculate_value_on_ram(process->pc, 1);
		if (opc_tmp >= 1 && opc_tmp <= 16)
			cw_manage_valide_opc(opc_tmp, index, ctd, process);
		else
			g_arena.process = cw_increment_pc(process);
	}
}

int				cw_fight(int visu)
{
	int				cycle;

	cycle = 0;
	while (1)
	{
		if (g_arena.cur_cycle == g_arena.cycle_to_dump)
		{
			print_buffer_in_hexa(g_arena.memory, MEM_SIZE);
			return (1);
		}
		if (cycle >= (int)g_arena.ctd)
			if (((cycle = cw_manage_ctd(visu)) == 1))
				return (1);
		if (cycle == -1)
			return (-1);
		cw_read_processus_opc(cycle, g_arena.ctd);
		cw_exec_instructions();
		cycle++;
		g_arena.cur_cycle++;
		if (visu == 1)
			cw_manage_visu_getchar();
	}
	return (1);
}
