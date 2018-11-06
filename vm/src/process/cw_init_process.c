/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_init_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 12:58:01 by jabt              #+#    #+#             */
/*   Updated: 2018/11/05 18:03:52 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_processus	*cw_init_process_champ(t_champion *champ, int id)
{
	t_processus		*new_process;

	if (!(new_process = malloc(sizeof(t_processus))))
		return (NULL);
	new_process->id = id;
	new_process->pc = (id - 1) * (MEM_SIZE / arena.nb_champ);
	new_process->nb_live = 0;
	new_process->carry = 0;
	new_process->nb_cycle = 0;
	new_process->opcode = 0;
	ft_memset(new_process->reg, 0, sizeof(unsigned int) * REG_NUMBER);
	new_process->reg[1] = champ->id;
	ft_memset(new_process->params, 0, sizeof(int) * 4);

	return (new_process);
}

/*
** 		INPUT
** 		global var arena which contain normally all my champion
** 		and the number of champion sorted in growing order
*/

t_list				*cw_init_process(void)
{
	t_list			*cur_lst;
	t_list			*new_proc_lst;
	t_list			*tmp;
	t_processus		*cur_process;
	int				id_proc;

	id_proc = 1;
	new_proc_lst = NULL;
	cur_lst = arena.champion;
	while (cur_lst)
	{
		if (!(cur_process = cw_init_process_champ((t_champion *)cur_lst->content,
				id_proc)))
			return (NULL); // les procedure de free encore et encore
		tmp = new_proc_lst;
		if (!(new_proc_lst = ft_lstnew(NULL,
						sizeof(t_processus))))
			return (NULL);
		new_proc_lst->content = (void *)cur_process;
		new_proc_lst->next = tmp;
		cur_lst = cur_lst->next;
		id_proc++;
	}
	arena.process = new_proc_lst;
	return (new_proc_lst);
}
