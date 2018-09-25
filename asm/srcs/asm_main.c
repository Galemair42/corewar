/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 11:57:20 by femaury           #+#    #+#             */
/*   Updated: 2018/09/25 16:40:19 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			main(int ac, char **av)
{
	int		i;

	i = 0;
	if (ac > 1)
		while (++i < ac)
		{
			if (ft_stratcmp(av[i], "s", '.'))
				parse_file(av[i]);
			else
				ft_dprintf(2, "{RED}ERROR{EOC}: %s is not an asm file.\n", av[i]);
		}
	else
		ft_dprintf(2, "usage: ./asm file_name.s\n\n"
				"   {YELLOW}->{EOC}   Can take multiple files.\n"
				"   {YELLOW}->{EOC}   All files need a .s extension.\n");
	return (0);
}
