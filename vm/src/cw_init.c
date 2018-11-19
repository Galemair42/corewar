/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 14:00:14 by jabt              #+#    #+#             */
/*   Updated: 2018/11/19 09:51:25 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_processus		*cw_init_process_champ(t_champion *champ, int id)
{
	t_processus		*new_process;

	if (!(new_process = malloc(sizeof(t_processus))))
		return (NULL);
	new_process->id = id;
	new_process->pc = (id - 1) * (MEM_SIZE / arena.nb_champ);
	new_process->nb_live = 0;
	new_process->carry = 0;
	new_process->opcode = 0;
	ft_memset(new_process->reg, 0, sizeof(unsigned int) * REG_NUMBER + 1);
	new_process->reg[1] = champ->id;
	ft_memset(new_process->params, 0, sizeof(int) * 4);
	if (arena.visu_fight)
		cw_display_champ_on_ram(champ, new_process);
	return (new_process);
}

t_list					*cw_init_process(void)
{
	t_list			*cur_lst;
	t_list			*new_proc_lst;
	t_list			*tmp;
	t_processus		*cur_process;

	new_proc_lst = NULL;
	cur_lst = arena.champion;
	while (cur_lst)
	{
		if (!(cur_process = cw_init_process_champ(
		(t_champion *)cur_lst->content, arena.current_process_id)))
			return (NULL);
		tmp = new_proc_lst;
		if (!(new_proc_lst = ft_lstnew(NULL,
			sizeof(t_processus))))
			return (NULL);
		new_proc_lst->content = (void *)cur_process;
		new_proc_lst->next = tmp;
		cur_lst = cur_lst->next;
		arena.current_process_id++;
	}
	if (!(cur_process = ft_memalloc(sizeof(t_processus))))
			exit (-1);
	ft_lstadd(&new_proc_lst, ft_lstnew(cur_process,
				sizeof(t_processus)));
	free(cur_process);
	arena.process = new_proc_lst;
	return (new_proc_lst);
}

void					cw_init_processeur(void)
{
	ft_bzero(arena.memory, MEM_SIZE);
	arena.champion = NULL;
	ft_bzero(arena.process_to_exec, sizeof(t_list *) * CYCLE_TO_DIE);
	arena.nb_champ = 0;
	arena.cycle_to_die = CYCLE_TO_DIE;
	arena.max_check = MAX_CHECKS;
	arena.id_last_player_alive = 0;
	arena.cycle_live = 0;
	arena.max_cycle = ~0;
	arena.cur_cycle = 0;
	arena.cycle_to_dump = ~0;
	arena.current_process_id = 1;
	arena.cur_processus = 0;
	arena.visu_score = NULL;
	arena.visu_fight = NULL;
}
