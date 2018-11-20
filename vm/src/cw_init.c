/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 14:00:14 by jabt              #+#    #+#             */
/*   Updated: 2018/11/20 16:04:18 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_processus		*cw_init_process_champ(t_champion *champ, int id)
{
	t_processus		*new_process;

	if (!(new_process = malloc(sizeof(t_processus))))
		return (NULL);
	new_process->id = id;
	new_process->pc = (id - 1) * (MEM_SIZE / g_arena.nb_champ);
	new_process->nb_live = 0;
	new_process->carry = 0;
	new_process->opcode = 0;
	ft_memset(new_process->reg, 0, sizeof(unsigned int) * REG_NUMBER + 1);
	new_process->reg[1] = champ->id;
	ft_memset(new_process->params, 0, sizeof(int) * 4);
	if (g_arena.visu_fight)
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
	cur_lst = g_arena.champion;
	while (cur_lst)
	{
		if (!(cur_process = cw_init_process_champ(
		(t_champion *)cur_lst->content, g_arena.current_process_id)))
			return (NULL);
		tmp = new_proc_lst;
		if (!(new_proc_lst = ft_lstnew(NULL, sizeof(t_processus))))
			return (NULL);
		new_proc_lst->content = (void *)cur_process;
		new_proc_lst->next = tmp;
		cur_lst = cur_lst->next;
		g_arena.current_process_id++;
	}
	ft_bzero(cur_process, sizeof(t_processus));
	ft_lstadd(&new_proc_lst, ft_lstnew(cur_process, sizeof(t_processus)));
	g_arena.process = new_proc_lst;
	return (new_proc_lst);
}

void					cw_init_processeur(void)
{
	ft_bzero(g_arena.memory, MEM_SIZE);
	g_arena.champion = NULL;
	ft_bzero(g_arena.process_to_exec, sizeof(t_list *) * CYCLE_TO_DIE);
	g_arena.nb_champ = 0;
	g_arena.ctd = CYCLE_TO_DIE;
	g_arena.max_check = MAX_CHECKS;
	g_arena.id_last_player_alive = 0;
	g_arena.cycle_live = 0;
	g_arena.max_cycle = ~0;
	g_arena.current_process_to_exec = 0;
	g_arena.cur_cycle = 0;
	g_arena.cycle_to_dump = ~0;
	g_arena.current_process_id = 1;
	g_arena.cur_processus = 0;
	g_arena.visu_score = NULL;
	g_arena.visu_fight = NULL;
}
