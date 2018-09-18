/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_read_champ.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 17:39:18 by jabt              #+#    #+#             */
/*   Updated: 2018/09/18 18:22:06 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include "corewar.h"

/*
** 		INPUT
**		champ name and his id
**		create a new champ and store it in the processor struct
*/

static int		cw_add_new_champ(char *champ_name, int id)
{
	t_champion	*champ;
	t_list		*new_node;

	if (!(champ = malloc(sizeof(t_champion))))
		return (-1);
	if (!(new_node = ft_lstnew((void *)champ, sizeof(t_champion))))
	{
		free(champ);
		return (-1);
	}
	return (1);
}

/*
** 		RETURN -1 if fail or 1
*/

/*
** 		for understanding max_len_file :
** 		https://42born2code.slack.com/messages/GCTSC1V39/convo/C3QG85SG6-1536486698.000100/
*/

int					cw_read_champion(char *champ_name, int id)
{
	int		fd;
	int		max_len_file;
	char	*buffer;

	max_len_file = 4 + PROG_NAME_LENGTH + 8 + COMMENT_LENGTH + 4 + CHAMP_MAX_SIZE;
	if (!(buffer = ft_strnew(max_len_file + 1)))
		return (-1);
	if ((fd = open(champ_name, O_RDONLY)) == -1)
	{
		perror("corewar ");
		free(buffer);
		return (-1);
	}
	read(fd, buffer, max_len_file);

	printf("donc la un truc super bizarre normalement\n");
	write(1, buffer, max_len_file);
	exit(8);
	close(fd);
	exit(8);
}

