/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_get_instructions_params.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:00:47 by jabt              #+#    #+#             */
/*   Updated: 2018/11/20 16:09:31 by jabt             ###   ########.fr       */
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
**		!! STILL HAVE TO MANAGE DIRECT PARAMETERS !! CARE IF IT STANDS FOR
**		AN ADDRESS OR AN INTEGER	**
*/

static int			manage_error(unsigned int pc, t_processus *process)
{
	process->pc = pc;
	return (-1);
}

static int			get_params1(unsigned int ocp, unsigned int *current_pc,
		int opc, int index)
{
	int	value;
	int i;

	i = 0;
	value = 0;
	ocp = ocp >> 30;
	if ((ocp == REG_CODE && !(g_op_tab[opc].types[index] & T_REG)) ||
			(ocp == DIR_CODE && !(g_op_tab[opc].types[index] & T_DIR)) ||
			(ocp == IND_CODE && !(g_op_tab[opc].types[index] & T_IND)))
		return (-1);
	if (ocp == 0)
		return (-1);
	value = cw_calculate_value_on_ram(*current_pc,
			get_size(ocp, g_op_tab[opc].f));
	if (ocp == REG_CODE && (value < 1 || value > 16))
		return (-1);
	*current_pc = MEM_MASK(*current_pc + get_size(ocp, g_op_tab[opc].f));
	return (value);
}

unsigned int		get_size(unsigned int ocp, int flag_chelou)
{
	if (ocp == 1)
		return (1);
	if (ocp == 2 && flag_chelou == 0)
		return (4);
	if (ocp == 3 || flag_chelou == 1)
		return (2);
	return (0);
}

/*
**		If an instruction has an OCP, this function is called
**		It will read the params in the virtual memory and stock
**		them in the variable params of the structure t_processus
*/

int					get_params(t_processus *process)
{
	unsigned int	ocp;
	int				i;
	unsigned int	current_pc;
	unsigned int	error_pc;

	i = 0;
	ocp = cw_calculate_value_on_ram(MEM_MASK(process->pc + 1), 1);
	process->ocp = ocp;
	current_pc = MEM_MASK(process->pc + 2);
	error_pc = current_pc;
	if (ocp > 0xFC || process->opcode > 16)
		return (manage_error(error_pc, process));
	ocp = ocp << 24;
	while (i < g_op_tab[process->opcode - 1].nb_args)
	{
		if ((process->params[i] = get_params1(ocp, &current_pc,
						process->opcode - 1, i)) == -1)
		{
			if (g_arena.visu_fight)
				cw_visu_incr_process(process, current_pc);
			process->pc = current_pc;
			return (manage_error(error_pc, process));
		}
		i++;
		ocp = ocp << 2;
	}
	return (current_pc);
}

unsigned int		cw_get_one_params(t_processus *process, int number,
		_Bool apply_modulo)
{
	unsigned int	ret;
	int				padding;
	unsigned int	landing;

	padding = 8 - (number * 2);
	if (((process->ocp >> padding) & 3) == DIR_CODE)
		ret = process->params[number - 1];
	else if (((process->ocp >> padding) & 3) == REG_CODE)
		ret = process->reg[process->params[number - 1]];
	else if (((process->ocp >> padding) & 3) == IND_CODE)
	{
		if (apply_modulo)
			landing = apply_idx_mod(process->pc, MEM_MASK(process->pc +
						process->params[number - 1]));
		else
			landing = MEM_MASK(process->pc + process->params[number - 1]);
		ret = cw_calculate_value_on_ram(landing, 4);
	}
	return (ret);
}
