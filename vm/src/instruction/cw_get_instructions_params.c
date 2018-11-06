/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_get_instructions_params.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <galemair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 14:17:12 by galemair          #+#    #+#             */
/*   Updated: 2018/11/06 11:36:57 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**		Receive the OCP and the current PC
**		First, it will isolate the 2 lightest bits to determine the size of the
**		parameter
**		Then it will read on the memory to calculate the value of the 
**		parameters and will advance the current_PC
**		Return -1 when an error occurs
**		!! STILL HAVE TO MANAGE DIRECT PARAMETERS !! CARE IF IT STANDS FOR AN ADDRESS OR AN INTEGER	**
*/

unsigned int		get_size(unsigned int ocp)
{
	if (ocp == 1)
		return (1);
	if (ocp == 2)
		return (4);
	if (ocp == 3)
		return (2);
	return (0);
}

static	int		get_params1(unsigned int ocp, unsigned int *current_pc)
{
	int	value;
	int i;

	i = 0;
	value = 0;
	printf("before %u\n", ocp);	
	ocp = ocp >> 30;
	printf("after %u\n", ocp);
	if (ocp == 0)
	{
		printf("Parameters is non existant, how do we handle it ?\n");
		exit(0);
	}
	value = calculate_value_on_ram(*current_pc, get_size(ocp));
	*current_pc += get_size(ocp);
	return (value);
}

/*
**		If an instruction has an OCP, this function is called
**		It will read the params in the virtual memory and stock them in the variable 
**		params of the structure t_processus
*/

int		get_params(t_processus *process)
{
	unsigned int ocp;
	int	i;
	unsigned int current_pc;

	i = 0;
	current_pc = 0xFFF & (process->pc + 2);
	ocp = calculate_value_on_ram(current_pc, 2);
	if (ocp > 0xFC)
		return (-1);
	ocp = ocp << 24;//Met le bit interessant tout a gauche
	while (i < op_tab[process->opcode - 1].nb_args)
	{
		process->params[i] = get_params1(ocp, &current_pc);
		i++;
		ocp = ocp << 2;
	}
	return (1);
}
