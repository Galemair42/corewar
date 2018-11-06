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
# include	"stdio.h"
# include	"libft.h"
# include	"cw_struct.h"
# include	"cw_op.h"
# include	"cw_prototype.h"

# define HEADER_SIZE	16 + PROG_NAME_LENGTH + COMMENT_LENGTH
# define MEM_MASK(x) x & 0xFFF
# define __unused __attribute__((unused))

/*
**		global var
*/

t_processeur	arena;

#endif
