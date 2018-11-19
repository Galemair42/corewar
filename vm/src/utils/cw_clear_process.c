/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_clear_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:49:38 by jabt              #+#    #+#             */
/*   Updated: 2018/11/19 17:35:17 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		cw_clear_process(t_processus *process)
{
	process->opcode = 0;
	process->ocp = 0;
	ft_bzero(process->reg, sizeof(unsigned int) * REG_NUMBER);
	ft_bzero(process->params, sizeof(unsigned int) * 3);
}

//void         cw_cle(void)
//{
//     int i;
//     t_list *to_free;
//     t_list *tmp;
//
//     i = 0;
//     while (i < CYCLE_TO_DIE)
//     {
//		 to_free = arena.process_to_exec[i];
//		 while (to_free)
//		 {
//				 tmp = to_free->next;
//				 free(to_free);
//				 to_free = tmp;
//		 }
//		 arena.process_to_exec[i] = NULL;
//		 i++;
//     }
//}
