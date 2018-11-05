/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_inst_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 13:14:06 by jabt              #+#    #+#             */
/*   Updated: 2018/10/31 13:14:09 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void    cw_inst_fork(t_processus *process)
{
    unsigned int    pc;
    unsigned char   *memory;
	unsigned int jump = 0xFFFC;
	unsigned int	current_pc = 5;
	int	to_modulate;

    memory = arena.memory;
    pc = process->pc;
	pc = apply_IDX_MOD(current_pc, 0xFFF & (current_pc + jump)); //Correct way to calculate new PC
	printf("%d\n", pc);
	printf("%u\n", apply_IDX_MOD(0, 3000));
	printf("le fork n'est pas fait, go le faire");
	exit (0);
}
