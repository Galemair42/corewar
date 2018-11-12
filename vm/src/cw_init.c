/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 14:00:14 by jabt              #+#    #+#             */
/*   Updated: 2018/11/12 14:26:58 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_processus	*cw_init_process_champ(t_champion *champ, int id)
{
	t_processus		*new_process;

	if (!(new_process = malloc(sizeof(t_processus))))
		return (NULL);
	new_process->id = id;
	new_process->pc = (id - 1) * (MEM_SIZE / arena.nb_champ);
	new_process->nb_live = 0;
	new_process->carry = 0;
	new_process->opcode = 0;
	ft_memset(new_process->reg, 0, sizeof(unsigned int) * REG_NUMBER);
	new_process->reg[1] = champ->id;
	ft_memset(new_process->params, 0, sizeof(int) * 5);
	if (arena.visu_fight)
	{
	//	cw_init_proces_visu(new_process);
		cw_display_champ_on_ram(champ, new_process);
	}
	//else
		//new_process->color_pair = -1;
	return (new_process);
}

t_list				*cw_init_process(void)
{
	t_list			*cur_lst;
	t_list			*new_proc_lst;
	t_list			*tmp;
	t_processus		*cur_process;

	new_proc_lst = NULL;
	cur_lst = arena.champion;
	while (cur_lst)
	{
		if (!(cur_process = cw_init_process_champ((t_champion *)cur_lst->content,
				arena.current_process_id)))
			return (NULL); // les procedure de free encore et encore
		tmp = new_proc_lst;
		if (!(new_proc_lst = ft_lstnew(NULL,
						sizeof(t_processus))))
			return (NULL);
		new_proc_lst->content = (void *)cur_process;
		new_proc_lst->next = tmp;
		cur_lst = cur_lst->next;
		arena.current_process_id++;
	}
	ft_lstadd(&new_proc_lst, ft_lstnew(ft_memalloc(sizeof(t_processus)), sizeof(t_processus)));
	arena.process = new_proc_lst;
	return (new_proc_lst);
}

//void		cw_init_processeur(void)
//{
//	ft_bzero(&arena, sizeof(t_processeur));
//	ft_bzero(arena.memory, MEM_SIZE);
//	ft_bzero(arena.process_to_exec, sizeof(t_processus *) * CYCLE_TO_DIE);
//	arena.max_check = MAX_CHECKS;
//	arena.max_cycle = ~0;
//	arena.cycle_to_dump = ~0;
//	arena.current_process_id = 1;
//}
void		cw_init_processeur(void)
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
	arena.visu_score = NULL;
	arena.visu_fight = NULL;
}
