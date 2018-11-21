/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_core_vm_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <galemair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 09:55:19 by galemair          #+#    #+#             */
/*   Updated: 2018/11/21 13:51:23 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cw_manage_visu_getchar(void)
{
	int	c;

	c = getch();
	if (c != 1)
		cw_manage_getch(c);
	cw_update_cycle();
}

t_list	*cw_increment_pc(t_processus *process)
{
	t_list	*tmp;

	if (g_arena.visu_fight)
		cw_visu_incr_process(process, MEM_MASK(process->pc + 1));
	process->pc = MEM_MASK(process->pc + 1);
	tmp = g_arena.process->next;
	g_arena.process->next = NULL;
	ft_lstappend(&tmp, g_arena.process);
	return (tmp);
}

int		manage_winner(int visu)
{
	if (visu == 1)
		cw_wait_and_quit_properly();
	else if (g_arena.id_last_player_alive == 0)
		ft_printf("No Winner");
	else
		ft_printf("The winner is %s!\n",
			get_champs_name_by_id(g_arena.id_last_player_alive));
	return (1);
}

int		cw_manage_ctd(int visu)
{
	t_processus *delimiter;
	static int	cycle_decrementation = 0;

	if (g_arena.cycle_live >= NBR_LIVE
		|| cycle_decrementation == MAX_CHECKS - 1)
	{
		g_arena.ctd = (int)(g_arena.ctd - CYCLE_DELTA) >= 0
			? g_arena.ctd - CYCLE_DELTA : 0;
		cycle_decrementation = 0;
	}
	else
		cycle_decrementation++;
	cw_reset_live();
	if (g_arena.cycle_live == 0)
		return (manage_winner(visu));
	if (!(delimiter = (t_processus *)ft_memalloc(sizeof(t_processus))))
		return (-1);
	ft_lstprepend(&g_arena.process, ft_lstnew(delimiter, sizeof(t_processus)));
	free(delimiter);
	g_arena.cycle_live = 0;
	return (0);
}

int		cw_putstr_quit(char *str)
{
	write(1, str, ft_strlen(str));
	return (0);
}
