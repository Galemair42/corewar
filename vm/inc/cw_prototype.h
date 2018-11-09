/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_prototype.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 14:11:12 by jabt              #+#    #+#             */
/*   Updated: 2018/11/08 17:39:05 by galemair         ###   ########.fr       */
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
int			cw_update_champ_live(int id_champ);

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
void		cw_reset_process(t_processus *process);
void		cw_clean_lst();

/*
**	instruction
*/

void		cw_inst_live(t_processus *process);
void		cw_inst_ld(t_processus *process);
void		cw_inst_st(t_processus *process);
void		cw_inst_add(t_processus *process);
void		cw_inst_sub(t_processus *process);
void		cw_inst_and(t_processus *process);
void		cw_inst_or(t_processus *process);
void		cw_inst_xor(t_processus *process);
void		cw_inst_zjmp(t_processus *process);
void		cw_inst_ldi(t_processus *process);
void		cw_inst_sti(t_processus *process);
void		cw_inst_fork(t_processus *process);
void		cw_inst_lld(t_processus *process);
void		cw_inst_lldi(t_processus *process);
void		cw_inst_lfork(t_processus *process);
void		cw_inst_aff(t_processus *process);

void		cw_read_instru(void);
int			get_params(t_processus *process, int flag_chelou);

/*
*		visu
*/

void			cw_init_visu(void);
void            cw_init_proces_visu(t_processus *process);
void        	cw_display_champ_on_ram(t_champion *champ, WINDOW *win, unsigned int pc);
void        	cw_visu_incr_process(t_processus *process, int next_pc);
void        	cw_put_four_octet_visu(unsigned int index,
        unsigned int four_octet, WINDOW *win);

/*
** 		debug
*/

void		print_buffer_in_hexa(unsigned char *buffer, size_t size);
void		print_one_champ(t_champion *champion);
void		print_all_champ(void);
void		print_all_process(void);
void		print_process(t_processus *process);
void 		print_register(t_processus *process);

/*
**		cw_instructions_utils.c
*/

unsigned int	apply_IDX_MOD(unsigned int former_pc, unsigned int new_pc);

/*
 *		utils 
*/

void			cw_put_four_octet(unsigned int index, unsigned int four_octet);
unsigned int	cw_calculate_value_on_ram(unsigned int starting_pc, unsigned int length);
unsigned int	get_size(unsigned int ocp, int flag_chelou);
void			cw_insert_process(t_processus **process_tab, t_processus *process);
int				cw_verif_processes(void);
void			cw_free_content(void *content, __unused size_t size);

#endif
