/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_lst_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <galemair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 16:34:40 by galemair          #+#    #+#             */
/*   Updated: 2018/11/20 17:13:15 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		cw_free_content(void *content, __unused size_t size)
{
	free((t_processus *)content);
}

void		cw_clean_lst(void)
{
	t_list	*tmp;
	int		delimiter_flag;
	void	(*free_ptr)(void *, size_t);

	free_ptr = &cw_free_content;
	delimiter_flag = 0;
	while (g_arena.process && delimiter_flag == 0)
	{
		if (((t_processus *)g_arena.process->content)->id == 0)
			delimiter_flag++;
		tmp = g_arena.process;
		g_arena.process = g_arena.process->next;
		ft_lstdelone(&tmp, free_ptr);
	}
}

/*
**			FREE elem and iterate to the next list elem
*/

t_list		*free_list_elem(t_list *to_free)
{
	t_list		*to_return;
	void		(*free_ptr)(void *, size_t);

	free_ptr = &cw_free_content;
	to_return = to_free->next;
	ft_lstdelone(&to_free, free_ptr);
	return (to_return);
}
