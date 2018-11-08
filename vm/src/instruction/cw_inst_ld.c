/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_inst_ld.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <galemair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:10:34 by galemair          #+#    #+#             */
/*   Updated: 2018/11/07 18:42:18 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void        cw_inst_ld(t_processus *process)
{
    int     dir_1;
    int     reg_2;
    int     ret;
    int     landing;

printf("fin le pc : %d\n", process->pc);
    if ((ret = get_params(process)) == -1)
    {
        cw_reset_process(process);
        return ;
    }
    if (((process->ocp >> 6) & 3) == DIR_CODE)
    {
        process->reg[process->params[1]] = process->params[0];
    }
    else if (((process->ocp >> 6) & 3) == IND_CODE)
    {
        landing = apply_IDX_MOD(process->pc, process->pc + process->params[0]);
        process->reg[process->params[1]] = cw_calculate_value_on_ram(process->pc + landing, 4);
    }
    process->pc = ret;
    cw_reset_process(process);
}
