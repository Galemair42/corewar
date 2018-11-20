/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_core_vm_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <galemair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 09:55:19 by galemair          #+#    #+#             */
/*   Updated: 2018/11/20 17:38:04 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_list	*cw_increment_pc(t_processus *process)
{
	t_list	*tmp;

	if (arena.visu_fight)
		cw_visu_incr_process(process, MEM_MASK(process->pc + 1));
	process->pc = MEM_MASK(process->pc + 1);
	tmp = arena.process->next;
	arena.process->next = NULL;
	ft_lstappend(&tmp, arena.process);
	return (tmp);
}

int	cw_manage_ctd(void)
{
	t_processus *delimiter;
	static int cycle_decrementation = 0;

	if (arena.cycle_live >= NBR_LIVE || cycle_decrementation == MAX_CHECKS - 1)
	{
		arena.ctd = (int)(arena.ctd - CYCLE_DELTA) >= 0 ? arena.ctd - CYCLE_DELTA : 0;
		cycle_decrementation = 0;
	}
	else
		cycle_decrementation++;
	cw_reset_live();
	if (arena.cycle_live == 0)
	{
		if (visu == 1)
			cw_wait_and_quit_properly();
		else if (arena.id_last_player_alive == 0)
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
	return (0);	
}
