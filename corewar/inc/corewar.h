/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 13:41:57 by jabt              #+#    #+#             */
/*   Updated: 2018/11/21 14:23:29 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <ncurses.h>
# include <stdbool.h>
# include "stdio.h"
# include "../../libft/incs/libft.h"
# include "cw_struct.h"
# include "cw_op.h"
# include "cw_prototype.h"

# define HEADER_SIZE	16 + PROG_NAME_LENGTH + COMMENT_LENGTH
# define MEM_MASK(x) x & 0xFFF
# define MAX_LEN_FILE (16 + PROG_NAME_LENGTH + COMMENT_LENGTH + CHAMP_MAX_SIZE)

/*
**      visu
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
# define SC_HEIGHT_PROC SC_HEIGHT + 8

# define SC_HEIGHT          2
# define SC_FIRST_COL       4
# define SC_SECOND_COL      65
# define SC_THIRD_COL       110
# define SC_FOURTH_COL      165

/*
**      keypad
*/

# define CW_KEY_SPACE   32
# define CW_KEY_Q       113
# define CW_KEY_W       119
# define CW_KEY_E       101
# define CW_KEY_R       114

/*
**		global var
*/

t_processeur	g_arena;

#endif
