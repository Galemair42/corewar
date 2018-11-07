/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_lst_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <galemair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 16:34:40 by galemair          #+#    #+#             */
/*   Updated: 2018/11/07 10:41:16 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cw_free_content(void *content, __unused size_t size)
{
	free(content);
}

void	cw_clean_lst()
{
	t_list	*tmp;
	int		delimiter_flag;
	void	(*free_ptr)(void *, size_t);

	free_ptr = &cw_free_content;
	delimiter_flag = 0;
	while (arena.process && delimiter_flag == 0)
	{
		if (((t_processus *)arena.process)->id == 0)
			delimiter_flag++;
		tmp = arena.process;
		arena.process = arena.process->next;
		ft_lstdelone(&tmp, free_ptr);
	}
}
