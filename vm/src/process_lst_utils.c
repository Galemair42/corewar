/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_lst_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <galemair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 16:34:40 by galemair          #+#    #+#             */
/*   Updated: 2018/11/05 18:00:00 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cw_free_content(t_process *content, __unused size_t size)
{
	free(content);
}

void	cw_clean_lst()
{
	t_list	*tmp;
	int		delimiter_flag;

	delimiter_flag = 0;
	while (arena.process && delimiter_flag == 0)
	{
		if (ft_strcmp((*char)arena.process->content, "delimiter") == 0)
			delimiter_flag++;
		tmp = arena.process;
		arena.process = arena.process->next;
		ft_lstdelone(&tmp, (*cw_free_content)(tmp->content, tmp->content_size));
	}
}
