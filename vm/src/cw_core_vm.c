/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_core_vm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 15:43:55 by jabt              #+#    #+#             */
/*   Updated: 2018/11/19 10:56:51 by galemair         ###   ########.fr       */
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
	t_processus		*process;
	unsigned int	opc_tmp;

	ft_lstappend(&arena.process, arena.process);
	while (arena.process && ((t_processus *)arena.process->content)->id != 0)
	{
		process = (t_processus *)arena.process->content;
		opc_tmp = cw_calculate_value_on_ram(process->pc, 1);
		if (opc_tmp >= 1 && opc_tmp <= 16)
		{
			if (!(op_tab[opc_tmp - 1].cycle >
				(ctd - index) && process->nb_live == 0))
				arena.process = add_instruction_to_tab(arena.process,
				(op_tab[opc_tmp - 1].cycle + index - 1) % ctd, opc_tmp);
			else
			{
				arena.cur_processus--;
				if (arena.visu_fight)
					cw_unhighlight_octet(process->pc,
					arena.mem_color[process->pc]);
				arena.process = free_list_elem(arena.process);
			}
		}
		else
			arena.process = cw_increment_pc(process);
	}
}

int				cw_fight(void)
{
	int				cycle;
	int				cycle_decrementation;
	t_processus		*delimiter;

	arena.ctd = arena.cycle_to_die;
	cycle_decrementation = 0;
	cycle = 0;
	while (1)
	{
		cw_read_processus_opc(cycle, arena.ctd);
		cw_exec_instructions(cycle);
		cycle++;
		arena.cur_cycle++;
		if (cycle == arena.ctd)
		{
			if (arena.cycle_live >= NBR_LIVE || cycle_decrementation == MAX_CHECKS - 1)
			{
				arena.ctd = (int)(arena.ctd - CYCLE_DELTA) >= 0 ? arena.ctd - CYCLE_DELTA : 1;
				cycle_decrementation = 0;
			}
			else
				cycle_decrementation++;
			cw_reset_live();
			if (arena.cycle_live == 0)
			{
				printf("Total cycle : %d\n", arena.cur_cycle);
				if (arena.id_last_player_alive == 0)
					printf("No Winner");
				else
					printf("The winner is %s!\n", get_champs_name_by_id(arena.id_last_player_alive));
				return (1);
			}
			if (!(delimiter = (t_processus *)ft_memalloc(sizeof(t_processus))))
				return (-1);
			ft_lstadd(&arena.process, ft_lstnew(delimiter, sizeof(t_processus)));
			free(delimiter);
			arena.cycle_live = 0;
			cycle = 0;
		}
	}
	return (1);
}
