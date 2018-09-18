/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 13:22:45 by jabt              #+#    #+#             */
/*   Updated: 2018/09/18 17:19:21 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		CW_STRUCT_H
# define	CW_STRUCT_H

# include 	"cw_op.h"

typedef struct		s_args
{
	int		f_s;
	int		f_v; // a defnir comment ce truc marche
}					t_args;

/*
typedef struct		s_instruction
{
	int		opcode;
	int		param1;
	int		param2;
	int		param3;
}					t_instruction
*/

typedef struct		s_processus
{
	int				id;
	int				pc;
	int				carry;
	int				reg[REG_NUMBER];
	int				id_player;
//	t_instruction	instru;		alors j'en ai besoins ou pas ??	pk pas un mode verbose
}					t_processus;

typedef struct		s_champion
{
	int			id;	
	header_t	header;
	int			nb_live;
}					t_champion;

typedef struct		s_processeur
{
	unsigned char		memory[MEM_SIZE];
	t_list	 	   		*champion;
	unsigned int 	   	cycle_to_die;
	unsigned int 	   	max_check;
	int			 	   	id_last_player_alive;
	unsigned long long	max_cycle;
	unsigned long long	cur_cycle;
	unsigned long long	cycle_to_dump;	
//	t_args				args;
}					t_processeur;

#endif
