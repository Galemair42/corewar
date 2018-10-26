/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 13:22:45 by jabt              #+#    #+#             */
/*   Updated: 2018/10/26 17:42:03 by galemair         ###   ########.fr       */
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

typedef struct		s_processus
{
	int				opcode;
	int				id;
	unsigned int	ocp;
	unsigned int	pc;
	unsigned int	nb_live;
	unsigned int	carry;
	unsigned int	reg[REG_NUMBER];
	int				param1;
	int				param2;
	int				param3;
//	int				id_player;
}					t_processus;

typedef struct		s_champion
{
	char				*name;
	int					id;	
	int					nb_live;
	header_t			header;
	unsigned char		instruction[CHAMP_MAX_SIZE + 1];
}					t_champion;

typedef struct		s_processeur
{
	unsigned char		memory[MEM_SIZE];
	t_list	 	   		*champion;
	t_list				*process;
	size_t				nb_champ;
	unsigned int 	   	cycle_to_die;
	unsigned int 	   	max_check;
	int			 	   	id_last_player_alive;
	unsigned int		max_cycle;
	unsigned int		cur_cycle;
	unsigned int		cycle_to_dump;
}					t_processeur;

#endif
