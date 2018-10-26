/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_core_vm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 15:43:55 by jabt              #+#    #+#             */
/*   Updated: 2018/10/26 14:20:13 by galemair         ###   ########.fr       */
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
	static void (*ptr[16]) (t_processus *);

	if (!*ptr)
	{
		cw_init_funtab(ptr);
		(ptr[11])(arena.process->content);
	}
	printf("ici whesh tas fait de la merde");
	exit(5);
	lst_process = arena.process;
	while (lst_process)
	{
		process = (t_processus *)lst_process->content;
		//exec mon opcode
		// si opcode == 0, -> lire
		// sinon -> exec

		lst_process = lst_process->next;
	}
}

int				cw_fight(void)
{
	t_list			*process;
	unsigned int	ctd;
	int				i;
	size_t			k;

	k = 0;
	process = arena.process;
	ctd = arena.cycle_to_die;
	i = 0;
	while (process)
	{
		//iterer sur tous les proc, exec leurs instru etc...`
		// fonction pour boucler sur tous les process

		cw_exec_cycle();

		while (i < ctd)
		{
			;// iterer sur tous les process et exec leurs instru
			i++;
		}
		k++;
		if (k == MAX_CHECKS /*|| nb_live >= NBR_LIVE */)
		{
			ctd -= CYCLE_DELTA;
			k = 0;
		}
	}
	return (1);
}
