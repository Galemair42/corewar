/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_verif_processes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <galemair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:26:15 by galemair          #+#    #+#             */
/*   Updated: 2018/11/17 17:06:18 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cw_reset_tab_live(void)
{
	int			i;
	t_list		*lst;
	t_processus *processus;

	i = 0;
	while (i < CYCLE_TO_DIE)
	{
		lst = arena.process_to_exec[i];
		while (lst)
		{
			processus = (t_processus *)(lst->content);
			processus->nb_live = 0;
			lst = lst->next;
		}
		i++;
	}
}

void	cw_reset_champs_live(void)
{
	t_list		*champs;
	t_champion	*champion;
	int			i;

	i = 0;
	champs = arena.champion;
	while (champs)
	{
		champion = (t_champion *)champs->content;
		champion->nb_live = 0;
		if (arena.visu_fight)
			mvwprintw(arena.visu_score, SC_HEIGHT + (i * 2) + 1 + i,
					SC_SECOND_COL + 15, "0          ");
		champs = champs->next;
	}
}

void	cw_verif_processes(void)
{
	t_list			*lst;
	t_list			*tmp;
	void			(*free_ptr)(void *, size_t);

	free_ptr = &cw_free_content;
	while (arena.process &&
			((t_processus *)(arena.process)->content)->nb_live <= 0)
	{
		if (((t_processus *)arena.process->content)->id != 0)
		{
			arena.cur_processus--;
			if (arena.visu_fight)
				cw_unhighlight_octet( ((t_processus *)(arena.process)->content)->pc, arena.mem_color[((t_processus *)(arena.process)->content)->pc]);
		}
		tmp = (arena.process)->next;
		ft_lstdelone(&arena.process, free_ptr);
		arena.process = tmp;
	}
	lst = arena.process;
	while (lst)
	{
		((t_processus *)lst->content)->nb_live = 0;
		if (lst->next && ((t_processus *)lst->next->content)->nb_live <= 0)
		{
			arena.cur_processus--;
			//printf("Processus * verif * %d died at cycle %d\n", ((t_processus *)lst->next->content)->id, arena.cur_cycle);
			if (arena.visu_fight)
				cw_unhighlight_octet( ((t_processus *)lst->next->content)->pc, arena.mem_color[((t_processus *)(arena.process)->next->content)->pc]);
			tmp = lst->next->next;
			ft_lstdelone(&lst->next, free_ptr);
			lst->next = tmp;
		}
		else
			lst = lst->next;
	}
}

void	cw_reset_live(void)
{
	cw_verif_processes();
	cw_reset_champs_live();
	cw_reset_tab_live();
}
