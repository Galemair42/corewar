/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:51:14 by jabt              #+#    #+#             */
/*   Updated: 2018/11/16 10:53:06 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**      INPUT :
**      pointer on the good case of the tab of t_list * process
**		in the s_processeur struct
*/

t_list		*cw_list_pop(t_list **tab_lst)
{
	t_list		*tmp;

	tmp = *tab_lst;
	*tab_lst = (*tab_lst)->next;
	tmp->next = NULL;
	return (tmp);
}

/*
**          A TESTER JAI FAIS CA VITE FAIT !!!
*/

void		cw_insert_process(t_list **process_tab, t_list *process)
{
	t_list		*lst_iter;
	t_list		*before;

	lst_iter = *process_tab;
	if (((t_processus *)lst_iter->content)->id <
			((t_processus *)process->content)->id)
	{
		process->next = *process_tab;
		*process_tab = process;
		return ;
	}
	before = lst_iter;
	lst_iter = lst_iter->next;
	while (lst_iter)
	{
		if (((t_processus *)lst_iter->content)->id <
				((t_processus *)process->content)->id)
		{
			before->next = process;
			process->next = lst_iter;
			return ;
		}
		before = lst_iter;
		lst_iter = lst_iter->next;
	}
	before->next = process;
}
