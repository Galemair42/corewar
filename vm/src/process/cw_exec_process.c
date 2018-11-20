/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_exec_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:45:30 by jabt              #+#    #+#             */
/*   Updated: 2018/11/20 17:10:29 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				cw_init_funtab(void (**ptr)(t_processus *))
{
	ptr[0] = &cw_inst_live;
	ptr[1] = &cw_inst_ld;
	ptr[2] = &cw_inst_st;
	ptr[3] = &cw_inst_add;
	ptr[4] = &cw_inst_sub;
	ptr[5] = &cw_inst_and;
	ptr[6] = &cw_inst_or;
	ptr[7] = &cw_inst_xor;
	ptr[8] = &cw_inst_zjmp;
	ptr[9] = &cw_inst_ldi;
	ptr[10] = &cw_inst_sti;
	ptr[11] = &cw_inst_fork;
	ptr[12] = &cw_inst_lld;
	ptr[13] = &cw_inst_lldi;
	ptr[14] = &cw_inst_lfork;
	ptr[15] = &cw_inst_aff;
}

void				cw_reset_process(t_processus *process)
{
	process->ocp = 0;
	ft_bzero(process->params, sizeof(int) * 4);
}
