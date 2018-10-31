/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_parse_varg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 13:54:40 by jabt              #+#    #+#             */
/*   Updated: 2018/10/30 19:32:41 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "corewar.h"

static int			cw_is_valid_id(int id)
{
	int			ret;
	t_list		*lst;
	t_champion	*champ;

	lst = arena.champion;
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
**		it in arena->arg flag in question
*/

static int			cw_parse_flag(char **argv, int cur)
{
	int		i;
	char	*arg;

	arg = &argv[cur][1];
	if (ft_strequ(arg, "v"))
	{
		printf("t'as pas encore fait le mode verbose parsing/cw_parsing_args.c\n");
		exit(8);
	}
	else if (ft_strequ(arg, "dump"))
	{
	//	arena.dump_limit = ft_atoi();// enfaite juste gerer ce parsing
		printf("fais ton atoi bizarre\n");
		exit(5);
	}
	else if (ft_strequ(arg, "s"))
	{
		//arena.cycle_to_dump = atoichelou; // faire le atoi chelou
		printf("fais ton atoi bizarre\n");
		exit(5);
	}
	return (0);
}

/*
** 		RETURN 0 when has found that it's not an arg
**		RETURN the number of argv to skip
**		meaning by arg -s or -dump
*/

int			cw_parse_arg(char **argv, int argc)
{
	int		i;
	int		id;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] != '-' || !(cw_parse_flag(argv, i)))
		{
			if (ft_strequ(&argv[i][1], "n"))
			{
				if (!argv[i + 1] || !argv[i + 2] ||
						!cw_is_valid_id((id = ft_atoi(argv[i + 1]))))
				{
					printf("Corewar : Wrong Arguement\n");
					return (0);
				}
				i += 2;
			}
			else
				id = cw_get_new_champ_id();
			if (cw_read_champion(argv[i], id) == -1)
				return (0);
		}
		i++;
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
