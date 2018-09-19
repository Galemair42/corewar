/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_read_champ.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 17:39:18 by jabt              #+#    #+#             */
/*   Updated: 2018/09/19 17:30:54 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include "corewar.h"

/*
** 		INPUT
** 		the content of my champion file in an unsigned char buffer and its size
**		i'll parse it and put it in the header of the arena.champion list
**		wich just has been added
*/

static int		cw_add_header(unsigned char *buff_file, size_t size)
{
	unsigned char	*buf_iter;
	unsigned int	champ_size;
	t_champion		*champ;

	if (size < HEADER_SIZE)
	{
		printf("corewar : Invalid Champion %s\n", champ->name);
		return (-1);
	}
	champ = (t_champion *)arena.champion->content;
	champ->header.magic = (buff_file[0] << 24) + (buff_file[1] << 16)
		+ (buff_file[2] << 8) + buff_file[3];
	ft_memcpy(champ->header.prog_name, &buff_file[4], PROG_NAME_LENGTH);
	buf_iter = &buff_file[PROG_NAME_LENGTH + 4];
	if (buf_iter[0] || buf_iter[1] || buf_iter[2] || buf_iter[3])
	{
		printf("corewar : Invalid Champion %s\n", champ->name);
		return (-1);
	}
	buf_iter += 4;
	champ_size = buf_iter[0] << 24;
	champ_size += buf_iter[1] << 16;
	champ_size += buf_iter[2] << 8;
	champ_size += buf_iter[3];
	if (champ_size > CHAMP_MAX_SIZE)
	{
		printf("corewar : Champion %s too large\n", champ->name);
		return (-1);
	}
	buf_iter += 4;
	ft_memcpy(champ->header.comment, buf_iter, COMMENT_LENGTH);
	buf_iter += COMMENT_LENGTH;
	if (buf_iter[0] || buf_iter[1] || buf_iter[2] || buf_iter[3])
	{
		printf("corewar : Invalid Champ : %s\n", champ->name);
		return (-1);
	}
	return (champ_size);
}

/*
** 		OUTPUT
** 		-1 if wrong
**		else the size of the instruction's part of the champ
*/

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
	champ->name = champ_name;
	champ->id = id;
	champ->nb_live = 0;
	ft_bzero(champ->header.prog_name, PROG_NAME_LENGTH + 1);
	ft_bzero(champ->header.comment, COMMENT_LENGTH + 1);
	new_node->next = arena.champion;
	new_node->content = (void *)champ;
	arena.champion = new_node;
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
	int				fd;
	int				max_len_file;
	unsigned char	*buffer;
	int				ret;
	unsigned int	champ_size;

	max_len_file = 4 + PROG_NAME_LENGTH + 8 + COMMENT_LENGTH + 4 + CHAMP_MAX_SIZE;
	if (!(buffer = ft_memalloc(max_len_file)))
		return (-1);
	if ((fd = open(champ_name, O_RDONLY)) == -1)
	{
		perror("corewar ");
		free(buffer);
		return (-1);
	}
	if ((ret = read(fd, buffer, max_len_file)) == -1)
	{
		perror("corewar :");
		free(buffer);
		return (-1);
	}
	cw_add_new_champ(champ_name, id);
	if ((champ_size = cw_add_header(buffer, ret)) == -1)
	{
		free(buffer);
		return (-1);
	}
	if (ret != HEADER_SIZE + champ_size)
	{
		printf("Corewar : Invalid Champion %s\n", champ_name);
		free(buffer);
		return (-1);
	}
	// en gos ici je veux stock les instruction dans l'arenne
	close(fd);
	exit(8);
}

