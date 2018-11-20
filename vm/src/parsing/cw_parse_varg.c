/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_parse_varg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 13:54:40 by jabt              #+#    #+#             */
/*   Updated: 2018/11/20 17:09:29 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int			cw_is_valid_id(int id)
{
	t_list		*lst;
	t_champion	*champ;

	lst = g_arena.champion;
	while (lst)
	{
		champ = (t_champion *)lst->content;
		if (champ->id == id)
		{
			printf("Corewar : Two champ has the same ID\n");
			return (0);
		}
		lst = lst->next;
	}
	return (1);
}

/*
**		INPUT
**		one string begining by '-'
**		the goal is to see if its a good flag or not, if it is, then indicate
**		it in g_arena->arg flag in question
*/

static int			cw_gflag(char **argv, int cur, int *index)
{
	char	*arg;

	arg = &argv[cur][1];
	if (ft_strequ(arg, "dump"))
	{
		if (argv[cur + 1])
			g_arena.cycle_to_dump = ft_atoi(argv[cur + 1]);
		else
			return (-1);
		*index += 1;
		return (1);
	}
	else if (ft_strequ(arg, "d"))
	{
		cw_init_visu();
		return (1);
	}
	return (0);
}

/*
** 		RETURN 0 when has found that it's not an arg
**		RETURN the number of argv to skip
**		meaning by arg -s or -dump
*/

int					cw_parse_arg(char **argv, int argc)
{
	int		i;
	int		id;
	int		ret;

	i = 0;
	while (++i < argc)
	{
		if ((argv[i][0] != '-' || !(ret = cw_gflag(argv, i, &i))) && ret != -1)
		{
			if (ft_strequ(&argv[i][1], "n"))
			{
				if (!argv[i + 1] || !argv[i + 2] ||
						!cw_is_valid_id((id = ft_atoi(argv[i + 1]))))
					return (cw_putstr_quit("Corewar : Wrong Argument\n"));
				i += 2;
			}
			else
				id = cw_get_new_champ_id();
			if (cw_read_champion(argv[i], id) == -1)
				return (0);
		}
		if (ret == -1)
			return (cw_putstr_quit("Corewar : Error\n"));
	}
	return (1);
}

/*
**		RETURN
**		1 if success
**		0 if fail, and if fail this function should print the error message
**		on the standart outpout the calling procedure only need
**		to quit properly
*/
