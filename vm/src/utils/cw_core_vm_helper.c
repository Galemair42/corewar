/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_core_vm_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <galemair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 09:55:19 by galemair          #+#    #+#             */
/*   Updated: 2018/11/20 15:41:56 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_list	*cw_increment_pc(t_processus *process)
{
	t_list	*tmp;

	if (g_arena.visu_fight)
		cw_visu_incr_process(process, MEM_MASK(process->pc + 1));
	process->pc = MEM_MASK(process->pc + 1);
	tmp = g_arena.process->next;
	g_arena.process->next = NULL;
	ft_lstappend(&tmp, g_arena.process);
	return (tmp);
}

int		cw_putstr_quit(char *str)
{
	write(1, str, ft_strlen(str));
	return (0);
}
