/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_inst_ld.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <galemair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:10:34 by galemair          #+#    #+#             */
/*   Updated: 2018/11/08 17:12:43 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void        cw_inst_ld(t_processus *process)
{
    int     dir_1;
    int     reg_2;
    int     ret;
    int     landing;

    if ((ret = get_params(process, 0)) == -1)
    {
        cw_reset_process(process);
        return ;
    }
    if (((process->ocp >> 6) & 3) == DIR_CODE)
        process->reg[process->params[1]] = process->params[0];
    else if (((process->ocp >> 6) & 3) == IND_CODE)
    {
        landing = apply_IDX_MOD(process->pc, MEM_MASK(process->pc + process->params[0]));
        process->reg[process->params[1]] = cw_calculate_value_on_ram(landing, 4);
    }
    if (process->reg[process->params[1]] == 0)
        process->carry = 1;
    else
        process->carry = 0;
    if (arena.visu_fight)
        cw_visu_incr_process(process, ret);
    process->pc = ret;
    cw_reset_process(process);
}
