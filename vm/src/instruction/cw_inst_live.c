/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_inst_live.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 17:06:24 by jabt              #+#    #+#             */
/*   Updated: 2018/10/18 18:00:30 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

// ici je dois allez chercher a opcode + 1 4 octets

void    cw_inst_live(t_processus *process)
{
    int             id_champ;
    unsigned char   *memory;

    memory = arena.memory;
    process->nb_live++;
    id_champ = memory[(process->pc) +1] << 24;
    id_champ += memory[(process->pc + 2)] << 16;
    id_champ += memory[(process->pc + 3)] << 8;
    id_champ += memory[process->pc + 4];
    cw_update_champ_live(id_champ);
    process->pc += 5;
}

// augmenter le nb_live du proc current
// augmenter le nb_live du champ present a op + 1 si ca correspond a un champ
// qui existe
// et changer le last champ qui live
