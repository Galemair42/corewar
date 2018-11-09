/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 13:41:57 by jabt              #+#    #+#             */
/*   Updated: 2018/11/05 17:32:19 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		COREWAR_H
# define	COREWAR_H

# include	<string.h>
# include	<unistd.h>
# include	<stdlib.h>
# include   <ncurses.h>
# include	"stdio.h"
# include	"libft.h"
# include	"cw_struct.h"
# include	"cw_op.h"
# include	"cw_prototype.h"

# define HEADER_SIZE	16 + PROG_NAME_LENGTH + COMMENT_LENGTH
# define MEM_MASK(x) x & 0xFFF
# define __unused __attribute__((unused))

/*
 *      visu
*/

# define CW_GREEN 1
# define CW_PROCESS_GREEN 2
# define CW_BLUE 3
# define CW_PROCESS_BLUE 4
# define CW_RED 5
# define CW_PROCESS_RED 6
# define CW_CYAN 7
# define CW_PROCESS_CYAN 8
# define CW_INVERSE_COLOR(x) x + 1
# define COLOR_GREY 15
# define WIN_HEIGHT 66

/*
**		global var
*/

t_processeur	arena;

#endif
