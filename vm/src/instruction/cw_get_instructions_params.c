/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_get_instructions_params.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <galemair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 14:17:12 by galemair          #+#    #+#             */
/*   Updated: 2018/10/31 13:05:36 by galemair         ###   ########.fr       */
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
unsigned int		get_value(unsigned char cmp)
{
	unsigned char hexa[17];
	unsigned int i;

	i = 0;
	hexa = "0123456789abcdef";
	while (hexa[i] && hexa[i] != cmp)
		i++;
	return(i);
}

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

int		get_params(unsigned int ocp, unsigned int *current_pc)
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
	while (i < get_size(ocp))
	{
		value += calculate_power(16, (get_size(ocp) - i - 1)) * get_value(memory[0xFFF & (i + *current_pc)]);
		i++;
	}
	*current_pc += i;
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
	current_pc = 0xFFF & (process->pc + 4);
	ocp = process->ocp;
	if (ocp > 255 || process.opc > 16)
		return (-1);
	ocp = opc << 24;//Met le bit interessant tout a gauche
	while (i < op_tab[process->opc - 1].ewqreqw)
	{
		tab[i] = get_params(ocp, &current_pc);
		i++;
		ocp = ocp << 2;
	}
	return (1);
}
//int		main(int argc, char **argv)
//{
//	t_processus processus;
//	processus.opcode = atoi(argv[1]);
//	processus.ocp = atoi(argv[2]);
//	get_params(NULL, processus);
//	return (0);
//}
