/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_clear_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:49:38 by jabt              #+#    #+#             */
/*   Updated: 2018/11/17 17:37:26 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		cw_clear_process(t_processus *process)
{
	process->opcode = 0;
	process->ocp = 0;
	ft_bzero(process->reg, sizeof(unsigned int) * REG_NUMBER);
	ft_bzero(process->params, sizeof(unsigned int) * 3);
}
