/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_exit_properly.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <galemair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 16:49:23 by galemair          #+#    #+#             */
/*   Updated: 2018/11/21 14:27:02 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cw_free_champs_ptr(void *content, size_t size)
{
	t_champion		*to_free;

	(void)size;
	to_free = (t_champion *)content;
	free(to_free->name);
	free(to_free);
}

void	cw_free_process_tab(void (*free_ptr)(void*, size_t))
{
	int			i;
	t_list		*lst;
	t_list		*tmp;

	i = 0;
	while (i < CYCLE_TO_DIE)
	{
		lst = g_arena.process_to_exec[i];
		while (lst)
		{
			tmp = lst->next;
			ft_lstdelone(&lst, free_ptr);
			lst = tmp;
		}
		i++;
	}
}

void	cw_free_processes(void (*free_ptr)(void*, size_t))
{
	t_list			*lst;
	t_list			*tmp;

	lst = g_arena.process;
	while (lst)
	{
		tmp = lst->next;
		ft_lstdelone(&lst, free_ptr);
		lst = tmp;
	}
}

void	cw_free_champs(void (*free_champs_ptr)(void *, size_t))
{
	t_list *lst;
	t_list *tmp;

	lst = g_arena.champion;
	while (lst)
	{
		tmp = lst->next;
		ft_lstdelone(&lst, free_champs_ptr);
		lst = tmp;
	}
}

void	cw_clean_everything(void)
{
	void			(*free_ptr)(void *, size_t);
	void			(*free_champs_ptr)(void *, size_t);

	free_ptr = &cw_free_content;
	free_champs_ptr = &cw_free_champs_ptr;
	cw_free_process_tab(free_ptr);
	cw_free_processes(free_ptr);
	cw_free_champs(free_ptr);
}
