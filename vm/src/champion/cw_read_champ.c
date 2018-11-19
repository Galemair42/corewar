/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_read_champ.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 17:39:18 by jabt              #+#    #+#             */
/*   Updated: 2018/11/19 17:40:03 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include "corewar.h"

char				*get_champs_name_by_id(int id)
{
	t_list		*lst_champ;
	t_champion	*champ;

	lst_champ = arena.champion;
	while (lst_champ)
	{
		champ = (t_champion *)lst_champ->content;
		if (champ->id == id)
			return (champ->header.prog_name);
		lst_champ = lst_champ->next;
	}
	return (NULL);
}

int					cw_header_verif_null_byte(unsigned char *buff_file)
{
	buff_file = buff_file + (PROG_NAME_LENGTH + 4);
	if (buff_file[0] || buff_file[1] || buff_file[2] || buff_file[3])
		return (0);
	buff_file = buff_file + (COMMENT_LENGTH + 8);
	if (buff_file[0] || buff_file[1] || buff_file[2] || buff_file[3])
		return (0);
	return (42);
}

/*
** 		for understanding max_len_file :
** 		https://42born2code.slack.com/messages/GCTSC1V39/convo
**		/C3QG85SG6-1536486698.000100/
*/

int					cw_read_champion(char *champ_name, int id)
{
	int				fd;
	unsigned char	buffer[MAX_LEN_FILE];
	size_t			ret;

	if (arena.nb_champ >= MAX_PLAYERS)
	{
		printf("Corewar : too much champion\n");
		return (-1);
	}
	arena.nb_champ++;
	if ((fd = open(champ_name, O_RDONLY)) == -1 ||
			(ret = read(fd, buffer, MAX_LEN_FILE)) == -1)
	{
		perror("corewar ");
		return (-1);
	}
	if (cw_add_new_champ(buffer, ret, champ_name, id) == -1)
		return (-1);
	close(fd);
	return (1);
}
