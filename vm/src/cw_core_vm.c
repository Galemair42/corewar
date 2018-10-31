/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_core_vm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 15:43:55 by jabt              #+#    #+#             */
/*   Updated: 2018/09/24 16:26:55 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"


static void		cw_exec_cycle(void)
{
	t_list			*lst_process;
	t_processus		*process;

	lst_process = arena.process;
	while (lst_process)
	{
		process = (t_processus *)lst_process->content;
		if (process->opcode != 0 && process->nb_live == 0)
		{
			cw_exec_process(process);// japelle la fonction d'execution qui correspond
		}
		else if (process->opcode == 0)
			cw_read_instruction(process);// fonction pour lire un param
		else
			process->nb_live--;
		lst_process = lst_process->next;
	}
}

int				cw_fight(void)
{
	t_list			*process;
	unsigned int	ctd;
	size_t			i;

	process = arena.process;
	ctd = arena.cycle_to_die;
	i = 0;
	while (process)
	{
		cw_exec_cycle();
		i++;
		if (i == MAX_CHECKS)
		{
			ctd -= CYCLE_DELTA;
			i = 0;
		}
	}
	return (1);
}
