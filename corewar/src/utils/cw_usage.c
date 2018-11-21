/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_usage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <galemair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 08:44:58 by galemair          #+#    #+#             */
/*   Updated: 2018/11/21 13:51:23 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cw_usage(void)
{
	ft_printf("Usage: ./corewar [-d -dump N] [-n N] <champion1.cor> <...>\n");
	ft_printf("    -n N       : Gives the ID N no to the champion ");
	ft_printf("following the flag\n");
	ft_printf("    -d         : Ncurses output mode\n");
	ft_printf("    -dump N    : Dumps memory after N cycles then exits\n");
}
