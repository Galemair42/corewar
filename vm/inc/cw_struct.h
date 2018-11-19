/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 13:22:45 by jabt              #+#    #+#             */
/*   Updated: 2018/11/19 17:20:55 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CW_STRUCT_H
# define CW_STRUCT_H

# include "cw_op.h"

typedef struct s_processus	t_processus;

struct						s_processus
{
	int				opcode;
	int				id;
	unsigned int	ocp;
	unsigned int	pc;
	unsigned int	nb_live;
	unsigned int	carry;
	unsigned int	reg[REG_NUMBER + 1];
	int				params[4];
};

typedef struct				s_champion
{
	char				*name;
	int					id;
	int					nb_live;
	header_t			header;
	unsigned char		instruction[CHAMP_MAX_SIZE + 1];
	int					color;
}							t_champion;

typedef struct				s_processeur
{
	unsigned char		memory[MEM_SIZE];
	unsigned char		*mem_color;
	t_list				*champion;
	t_list				*process;
	t_list				*process_to_exec[CYCLE_TO_DIE];
	size_t				nb_champ;
	int					current_process_to_exec;
	unsigned int		ctd;
	unsigned int		max_check;
	int					cycle_live;
	int					id_last_player_alive;
	int					current_process_id;
	unsigned int		cur_processus;
	unsigned int		max_cycle;
	unsigned int		cur_cycle;
	unsigned int		cycle_to_dump;
	WINDOW				*visu_score;
	WINDOW				*visu_fight;
}							t_processeur;

#endif
