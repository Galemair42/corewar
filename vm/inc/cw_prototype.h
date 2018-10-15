/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_prototype.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 14:11:12 by jabt              #+#    #+#             */
/*   Updated: 2018/09/25 14:26:59 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	CW_PROTOTYPE_H
# define	CW_PROTOTYPE_H

/*
**		processeur, c'est la struct globale qui represente l'arene
*/

void		cw_init_processeur(void);
int			cw_parse_arg(char **argv, int argc);
	int			cw_fight(void);

/*
** 		memory's arena
*/

void		cw_put_champion_in_memory(void);

/*
**		champion
*/

int			cw_get_new_champ_id(void);
int			cw_read_champion(char *champ_name, int id);
int			cw_add_new_champ(unsigned char *buffer, size_t size_buf,
		char *champ_name, int id);
void		cw_insert_champion(t_list *new_lst, t_champion *new_champ);
int			cw_header_verif_null_byte(unsigned char *buf_file);

/*
** 		process
*/

t_list		*cw_init_process(void);
void		cw_roam_of_the_bat(void);

/*
** 		free procedure
*/

void		cw_free_process(void *process, size_t size);

/*
** 		debug
*/

void		print_buffer_in_hexa(unsigned char *buffer, size_t size);
void		print_one_champ(t_champion *champion);
void		print_all_champ(void);
void		print_all_process(void);
void		print_process(t_processus *process);

#endif
