/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_put_champ_mem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 16:59:55 by jabt              #+#    #+#             */
/*   Updated: 2018/11/20 11:33:58 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static size_t		cw_get_nb_champ(void)
{
	size_t		nb_champ;
	t_list		*lst;

	lst = arena.champion;
	nb_champ = 0;
	while (lst)
	{
		nb_champ++;
		lst = lst->next;
	}
	return (nb_champ);
}

void				cw_put_champion_in_memory(void)
{
	t_champion		*champ;
	t_list			*lst;
	size_t			nb_champ;
	size_t			loc_champ;
	int				i;

	i = 1;
	loc_champ = 0;
	nb_champ = cw_get_nb_champ();
	lst = arena.champion;
	printf("Introducing contestants...\n");
	while (lst)
	{
		champ = (t_champion *)lst->content;
		ft_memcpy(arena.memory + (loc_champ * (MEM_SIZE / nb_champ)),
				champ->instruction, champ->header.prog_size);
		printf("* Player %d, weighing %u bytes, \"%s\" (\"%s\") !\n", i, champ->header.prog_size, champ->header.prog_name, champ->header.comment);
		lst = lst->next;
		loc_champ++;
		i++;
	}
}
