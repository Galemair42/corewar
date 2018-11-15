/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_inst_live.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 17:06:24 by jabt              #+#    #+#             */
/*   Updated: 2018/11/14 17:53:06 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void    cw_inst_live(t_processus *process)
{
    unsigned int	id_champ;
    unsigned char   *memory;
    static int      stop;
    stop++;

    memory = arena.memory;
    process->nb_live++;
    id_champ = cw_calculate_value_on_ram(MEM_MASK(process->pc + 1), 4);
    cw_update_champ_live(id_champ);
    if (arena.visu_fight)
        cw_visu_incr_process(process, MEM_MASK(process->pc + 5));
    process->pc = MEM_MASK(process->pc + 5);
    cw_reset_process(process);
}
