/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_usage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <galemair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 08:44:58 by galemair          #+#    #+#             */
/*   Updated: 2018/11/21 09:09:39 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cw_usage(void)
{
	printf("Usage: ./corewar [-d -dump N] [-n N] <champion1.cor> <...>\n");
	printf("    -n N       : Gives the ID N no to the champion following the flag\n");
	printf("    -d         : Ncurses output mode\n");
	printf("    -dump N    : Dumps memory after N cycles then exits\n");
}
