/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_core_vm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 15:43:55 by jabt              #+#    #+#             */
/*   Updated: 2018/11/14 18:23:47 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int c=1;
#include "corewar.h"

t_list			*add_instruction_to_tab(t_list *process, int index, unsigned int opc)
{
	t_processus 	*tmp;
	t_list			*to_return;

	to_return = process->next;
	process->next = NULL;
	tmp = (t_processus *)process->content;
	//printf("*Ajout de l'instruction -%s-* a la case %d cycle %d by processus : %d\n", op_tab[opc - 1].name, index, c, tmp->id);
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
		//printf("*Execution de l'instruction -%s-*, au cycle : %d\n", op_tab[process->opcode - 1].name, c);
		(*ptr[process->opcode - 1])(process);
		lst->next = NULL;
		ft_lstappend(&arena.process, lst);
		lst = tmp;
	}
	arena.process_to_exec[index] = NULL;
}

void		cw_read_processus_opc(int index, int ctd)
{
	t_list			*lst_process;
	t_processus		*process;
	unsigned int	opc_tmp;
	t_list			*tmp;

	tmp = arena.process;
	ft_lstappend(&arena.process, arena.process);
	lst_process = arena.process;
	while (lst_process && ((t_processus *)lst_process->content)->id != 0)
	{
		process = (t_processus *)lst_process->content;
		opc_tmp = cw_calculate_value_on_ram(process->pc, 1);
		if (opc_tmp >= 1 && opc_tmp <= 16)
		{
			if (!(op_tab[opc_tmp - 1].cycle > (ctd - index) && process->nb_live == 0))
				lst_process = add_instruction_to_tab(lst_process, (op_tab[opc_tmp - 1].cycle + index - 1) % ctd, opc_tmp);
			else
				lst_process = free_list_elem(lst_process);			
		}
		else
		{
			process = (t_processus *)lst_process->content;
			if (arena.visu_fight)
				cw_visu_incr_process(process, MEM_MASK(process->pc + 1));
			//printf("lol");
			process->pc++;
			lst_process->next = NULL;
			ft_lstappend(&arena.process, lst_process);
			lst_process = lst_process->next;
		}
	}
	arena.process = tmp;
}

int				cw_fight(void)
{
	static int 		stop;

	unsigned int	ctd;
	int				cycle;
	int				cycle_decrementation;

	ctd = arena.cycle_to_die;
	cycle_decrementation = 0;
	cycle = 0;
	while (1)
	{
		cw_read_processus_opc(cycle, ctd);
		cw_exec_instructions(cycle);
		cycle++;
		c++;
		if (cycle == ctd)
		{
			stop++;
			if (arena.cycle_live >= NBR_LIVE || cycle_decrementation == MAX_CHECKS - 1)
			{
				ctd = (int)(ctd - CYCLE_DELTA) >= 0 ? ctd - CYCLE_DELTA : 1;
				cycle_decrementation = 0;
			}
			else
				cycle_decrementation++;
			printf("ctd = %d\n", ctd);
			cw_reset_live();
			//printf("nb_live : %d\n", arena.cycle_live);
			if (arena.cycle_live == 0)
			{
				if (arena.id_last_player_alive == 0)
					printf("No Winner");
				else
					printf("The winner is %s!\n", get_champs_name_by_id(arena.id_last_player_alive));
				return (1);
			}
			ft_lstadd(&arena.process, ft_lstnew(ft_memalloc(sizeof(t_processus)), sizeof(t_processus)));
			arena.cycle_live = 0;
			cycle = 0;
		}
	}
	return (1);
}
