/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_prototype.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 14:11:12 by jabt              #+#    #+#             */
/*   Updated: 2018/09/20 17:13:13 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	CW_PROTOTYPE_H
# define	CW_PROTOTYPE_H

/*
**		processeur, c'est la struct globale qui represente l'arene
*/

void		cw_init_processeur(void);
int			cw_parse_arg(char **argv, int argc);

/*
** 		memory's arena
*/

void		cw_put_champion_in_memory(void);

/*
**		champion
*/

int			cw_get_new_champ_id(void);
int			cw_read_champion(char *champ_name, int id);

/*
** 		debug
*/

void		print_buffer_in_hexa(unsigned char *buffer, size_t size);
void		print_one_champ(t_champion *champion);
void		print_all_champ(void);

#endif
