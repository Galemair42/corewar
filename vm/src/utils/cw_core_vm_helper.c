/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_core_vm_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <galemair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 09:55:19 by galemair          #+#    #+#             */
/*   Updated: 2018/11/19 10:49:00 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_list	*cw_increment_pc(t_processus *process)
{
	t_list	*tmp;

	if (arena.visu_fight)
			cw_visu_incr_process(process, MEM_MASK(process->pc + 1));
	process->pc = MEM_MASK(process->pc + 1);
	tmp = arena.process->next;
	arena.process->next = NULL;
	ft_lstappend(&tmp, arena.process);
	return(tmp);
}
