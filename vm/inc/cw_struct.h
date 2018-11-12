/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 13:22:45 by jabt              #+#    #+#             */
/*   Updated: 2018/11/09 13:46:09 by galemair         ###   ########.fr       */
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

typedef	struct		s_processus	t_processus;

struct		s_processus
{
	int				opcode;
	int				id;
	unsigned int	ocp;
	unsigned int	pc;
	unsigned int	nb_live;
	unsigned int	carry;
	unsigned int	reg[REG_NUMBER];
	int				params[4];
//	int				color_pair;
	t_processus		*next;
//	WINDOW			*win;
};

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
	unsigned char		*mem_color;
	t_list	 	   		*champion;
	t_list				*process;
	t_processus			*process_to_exec[CYCLE_TO_DIE];
	size_t				nb_champ;
	unsigned int 	   	cycle_to_die;//
	unsigned int 	   	max_check;//
	int					cycle_live;	
	int			 	   	id_last_player_alive;
	int					current_process_id;
	unsigned int		max_cycle;//
	unsigned int		cur_cycle;
	unsigned int		cycle_to_dump;
	WINDOW				*visu_score;
	WINDOW				*visu_fight;
}					t_processeur;

typedef struct		s_cw_op_tab
{
	short unsigned int	nb_instru;
	unsigned int		param;
	short unsigned int	opcode;
	short unsigned int	nb_cycle;
	short unsigned int	bool_ocp;
}					t_cw_op_tab;

#endif
