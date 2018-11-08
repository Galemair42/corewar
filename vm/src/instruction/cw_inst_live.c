/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_inst_live.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 17:06:24 by jabt              #+#    #+#             */
/*   Updated: 2018/11/08 17:31:46 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
// ici je dois allez chercher a opcode + 1 4 octets

void    cw_inst_live(t_processus *process)
{
    int             id_champ;
    unsigned char   *memory;
    int             ret;

    memory = arena.memory;
    process->nb_live++;
    id_champ = cw_calculate_value_on_ram(MEM_MASK(process->pc + 1), 4);
    cw_update_champ_live(id_champ);
    process->pc = MEM_MASK(process->pc + 5);
    cw_reset_process(process);
}
