/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_parse_varg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 13:54:40 by jabt              #+#    #+#             */
/*   Updated: 2018/09/18 17:39:16 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "corewar.h"


/*
**		INPUT 
**		one string begining by '-'
**		the goal is to see if its a good flag or not, if it is, then indicate
**		it in arena->arg flag in question
*/

static int	cw_parse_flag(char **argv, int cur)
{
	int		i;
	char	*arg;

	arg = &argv[cur][1];
	if (ft_strequ(arg, "v"))
	{
		printf("t'as pas encore fait le mode verbose parsing/cw_parsing_args.c\n");
		exit(8);
	}
	else if (ft_strequ(arg, "n"))
	{
		printf("aucun visu\n");
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
	else if (ft_strequ(arg, "n"))
	{
		//arena.cycle_to_dump = atoichelou; // faire le atoi chelou
		printf("gerer ca : [-n number] champion.cor\n");
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
			id = cw_get_new_champ_id(); // essayer de parser en tant que file
			if (cw_read_champion(argv[i], id) == -1)
				return (0);
		}
		i++;
	}
	return (0);
}

/*
**		RETURN
**		1 if success
**		0 if fail, and if fail this function should print the error message
**		on the standart outpout the calling procedure only need
**		to quit properly
*/
