/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_prototype.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 14:11:12 by jabt              #+#    #+#             */
/*   Updated: 2018/11/17 18:30:27 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CW_PROTOTYPE_H
# define CW_PROTOTYPE_H

/*
**               core
*/

int				cw_fight_visu();
int				cw_fight(void);
void			cw_exec_instructions(int index);
void			cw_init_funtab(void (**ptr)(t_processus *));
void			cw_read_processus_opc(int index, int ctd);

/*
**		processeur, c'est la struct globale qui represente l'arene
*/

void			cw_init_processeur(void);
int				cw_parse_arg(char **argv, int argc);

/*
** 		memory's arena
*/

void			cw_put_champion_in_memory(void);
int				cw_update_champ_live(int id_champ);
void			cw_clean_everything(void);

/*
**		champion
*/

int				cw_get_new_champ_id(void);
int				cw_read_champion(char *champ_name, int id);
int				cw_add_new_champ(unsigned char *buffer, size_t size_buf,
		char *champ_name, int id);
void			cw_insert_champion(t_list *new_lst, t_champion *new_champ);
int				cw_header_verif_null_byte(unsigned char *buf_file);
char			*get_champs_name_by_id(int id);

/*
** 		process
*/

t_list			*cw_init_process(void);
void			cw_reset_process(t_processus *process);
void			cw_clean_lst();

/*
**	instruction
*/

void			cw_inst_live(t_processus *process);
void			cw_inst_ld(t_processus *process);
void			cw_inst_st(t_processus *process);
void			cw_inst_add(t_processus *process);
void			cw_inst_sub(t_processus *process);
void			cw_inst_and(t_processus *process);
void			cw_inst_or(t_processus *process);
void			cw_inst_xor(t_processus *process);
void			cw_inst_zjmp(t_processus *process);
void			cw_inst_ldi(t_processus *process);
void			cw_inst_sti(t_processus *process);
void			cw_inst_fork(t_processus *process);
void			cw_inst_lld(t_processus *process);
void			cw_inst_lldi(t_processus *process);
void			cw_inst_lfork(t_processus *process);
void			cw_inst_aff(t_processus *process);
void			cw_read_instru(void);
int				get_params(t_processus *process);
unsigned int	cw_get_one_params(t_processus *process, int number,
		_Bool apply_modulo);

/*
**		visu
*/

int				cw_init_visu(void);
void			cw_init_proces_visu(t_processus *process);
void			cw_display_champ_on_ram(t_champion *champ,
		t_processus *process);
void			cw_visu_incr_process(t_processus *process,
		int next_pc);
void			cw_put_four_octet_visu(unsigned int index,
		unsigned int four_octet, int color_pair);
void			cw_key_space(void);
void			cw_key_speed(int c);
void			cw_update_cycle(void);
void			cw_manage_getch(int c);
void			cw_highlight_octet(unsigned int index, int color_pair);
void			cw_unhighlight_octet(unsigned int index, int color_pair);
void			cw_print_winner_visu(void);

/*
** 		debug
*/

void			print_buffer_in_hexa(unsigned char *buffer, size_t size);
void			print_one_champ(t_champion *champion);
void			print_all_champ(void);
int				print_all_process(void);
void			print_process(t_processus *process);
void			print_register(t_processus *process);
void			debug_visu_process_orgin(t_list *lst_process);
int				print_exec_tab(void);

/*
**		cw_instructions_utils.c
*/

unsigned int	apply_IDX_MOD(unsigned int former_pc, unsigned int new_pc);

/*
**		utils
*/

void			cw_put_four_octet(unsigned int index, unsigned int four_octet);
unsigned int	cw_calculate_value_on_ram(unsigned int starting_pc,
		unsigned int length);
unsigned int	get_size(unsigned int ocp, int flag_chelou);
void			cw_insert_process(t_list **process_tab, t_list *process);
void			cw_reset_live(void);
void			cw_free_content(void *content, __unused size_t size);
void			cw_clear_exec_tab(void);
t_list			*free_list_elem(t_list *to_free);

#endif
