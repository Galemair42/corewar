/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_core_vm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 15:43:55 by jabt              #+#    #+#             */
/*   Updated: 2018/10/31 13:17:51 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		cw_init_funtab(void (**ptr)(t_processus *))
{
	ptr[0] = &cw_inst_live;
//	ptr[1] = 
//	ptr[2] = 
//	ptr[3] = 
//	ptr[4] = 
//	ptr[5] = 
//	ptr[6] = 
//	ptr[8] = 
//	ptr[9] = 
//	ptr[10] = 
	ptr[11] = &cw_inst_fork;
//	ptr[12] = 
//	ptr[13] = 
//	ptr[14] = 
//	ptr[15] = 
}

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
		//iterer sur tous les proc, exec leurs instru etc...`
		// fonction pour boucler sur tous les process

		cw_exec_cycle(); // execution d'un cycle

	/*	while (i < ctd)
		{*/
			// iterer sur tous les process et exec leurs instru
		i++;
		if (i < ctd)
		{
			; // verif des process
			i = 0;
		}

		
		k++;
		if (k == MAX_CHECKS /*|| nb_live >= NBR_LIVE */)
		{
			ctd -= CYCLE_DELTA;
			i = 0;
		}
	}
	return (1);
}
