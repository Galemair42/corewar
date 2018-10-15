/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_verif_dump.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 13:50:59 by jabt              #+#    #+#             */
/*   Updated: 2018/09/25 15:01:02 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cw_roam_of_the_bat(void)
{
	t_list			*lst_process;
	t_list			*tmp_before;
	t_list			*tmp_after;
	t_processus		*cur_process;
	void			(*del)(void *, size_t);

	((t_processus *)arena.process->content)->nb_live = 5;
	printf("voici la liste de process avant : \n");
	print_all_process();

	lst_process = arena.process;
	tmp_before = NULL;
	tmp_after = NULL;
	del = &cw_free_process;
	while (lst_process)
	{
		cur_process = (t_processus *)lst_process->content;
		if (!cur_process->nb_live)
		{
			tmp_after = lst_process->next;
			ft_lstdelone(&lst_process, del);//fonction libft pour free
			lst_process = tmp_after;
			if (tmp_before)
				tmp_before->next = lst_process;
			else
				arena.process = lst_process;
		}
		else
		{
			tmp_before = lst_process;
			lst_process = lst_process->next;
		}
	}
	printf("\n\nvoici la liste de process apres : \n\n\n");
	print_all_process();
	arena.process = NULL;
	while (1)
		;
	exit(5);
}
