/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_verif_processes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <galemair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:26:15 by galemair          #+#    #+#             */
/*   Updated: 2018/11/07 16:00:40 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		cw_verif_processes(void)
{
	t_list			*lst;
	t_list			*tmp;
	int				live_total;
	void			(*free_ptr)(void *, size_t);
	
	free_ptr = &cw_free_content;	
	live_total = 0;
	while (arena.process && ((t_process *)(arena.process)->content).nb_live =< 0)
	{
		tmp = lst->next;
		ft_lstdelone(&arena.process, free_ptr);
		arena.process = tmp;
	}
	lst = arena.process;
	while (lst && lst->next)
	{
		live_total += ((t_process *)lst->content).nb_live;
		if (((t_process *)lst->next->content).nb_live =< 0)
		{
			tmp	= lst->next->next;
			ft_lstdelone(&lst->next, free_ptr);
			lst->next = tmp;
		}
		lst = lst->next;
	}
	return (live_total);
}
