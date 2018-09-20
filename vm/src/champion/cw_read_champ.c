/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_read_champ.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 17:39:18 by jabt              #+#    #+#             */
/*   Updated: 2018/09/20 18:47:22 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include "corewar.h"

static void			cw_insert_champion(t_list *new_lst, t_champion *new_champ)
{
	t_champion	*cur_champ;
	t_list		*cur_lst;
	t_list		*cur_lst_tmp;

	cur_lst = arena.champion;
	cur_lst_tmp = NULL;
	if (!cur_lst)//je dois l'add au debut de la liste
	{
		new_lst->next = NULL;
		arena.champion = new_lst;
		return ;
	}
	while (cur_lst)
	{
		cur_champ = (t_champion *)cur_lst->content;
		if (new_champ->id < cur_champ->id)
		{
			if (cur_lst_tmp == NULL)
			{
				new_lst->next = arena.champion;
				arena.champion = new_lst;
			}
			else
			{
				new_lst->next = cur_lst;
				cur_lst_tmp->next = new_lst;
			}
			return ;
		}
		if (!cur_lst->next)
		{
			cur_lst->next = new_lst;
			return ;
		}
		cur_lst_tmp = cur_lst;
		cur_lst = cur_lst->next;
	}
}

static int			cw_is_possible_add_champ(void)
{
	t_list		*lst;
	int			i;

	i = 0;
	lst = arena.champion;
	while (lst)
	{
		i++;
		if (i >= MAX_PLAYERS)
		{
			printf("Corewar : Two much champion\n");
			return (0);
		}
		lst = lst->next;
	}
	return (1);
}

static int		cw_header_verif_null_byte(unsigned char *buff_file)
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
** 		INPUT
** 		the content of my champion file in an unsigned char buffer and its size
**		i'll parse it and put it in the header of the arena.champion list
**		wich just has been added
*/

static int		cw_add_header(unsigned char *buff_file, size_t size, t_champion *champ)
{
	unsigned char	*buf_iter;
	unsigned int	champ_size;
//	t_champion		*champ;

	if (size < HEADER_SIZE || !cw_header_verif_null_byte(buff_file))
	{
		printf("corewar : Invalid Champion %s\n", champ->name);
		return (-1);
	}
//	champ = (t_champion *)arena.champion->content;
	champ->header.magic = (buff_file[0] << 24) + (buff_file[1] << 16)
		+ (buff_file[2] << 8) + buff_file[3];
	ft_memcpy(champ->header.prog_name, &buff_file[4], PROG_NAME_LENGTH);
	buf_iter = &buff_file[PROG_NAME_LENGTH + 8];
	champ_size = (buf_iter[0] << 24) + (buf_iter[1] << 16)
		+ (buf_iter[2] << 8) + buf_iter[3];
	if (champ_size > CHAMP_MAX_SIZE || size != HEADER_SIZE + champ_size)
	{
		printf("corewar : Champion %s too large\n", champ->name);
		return (-1);
	}
	champ->header.prog_size = champ_size;
	buf_iter += 4;
	ft_memcpy(champ->header.comment, buf_iter, COMMENT_LENGTH);
	ft_memcpy(champ->instruction, &buf_iter[COMMENT_LENGTH + 4], champ_size);
	return (1);
}

/*
** 		OUTPUT
** 		-1 if wrong 1 if ok
*/

/*
** 		INPUT
**		champ name and his id
**		create a new champ and store it in the processor struct
*/

static int		cw_add_new_champ(unsigned char *buffer,
		size_t size_buf, char *champ_name, int id)
{
	t_champion	*champ;
	t_list		*new_node;

//	printf("GO TRIER LES CHAMP EN ORDRE !!!\n\n");
//	mettre le add head ici
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
	ft_bzero(champ->instruction, CHAMP_MAX_SIZE + 1);
	ft_bzero(champ->header.prog_name, PROG_NAME_LENGTH + 1);
	ft_bzero(champ->header.comment, COMMENT_LENGTH + 1);
	new_node->content = (void *)champ;
	
	cw_insert_champion(new_node, champ);
	if (cw_add_header(buffer, size_buf, champ) == -1)
		return (-1);
//	new_node->next = arena.champion;
//	arena.champion = new_node;
	return (1);
}

/*
** 		RETURN -1 if fail or 1
*/

/*
** 		for understanding max_len_file :
** 		https://42born2code.slack.com/messages/GCTSC1V39/convo
**		/C3QG85SG6-1536486698.000100/
*/

int				cw_read_champion(char *champ_name, int id)
{
	int				fd;
	int				max_len_file;
	unsigned char	*buffer;
	size_t			ret;
	
	if (!cw_is_possible_add_champ())
		return (-1);
	max_len_file = 16 + PROG_NAME_LENGTH + COMMENT_LENGTH + CHAMP_MAX_SIZE;
	if (!(buffer = ft_memalloc(max_len_file)))
		return (-1);
	if ((fd = open(champ_name, O_RDONLY)) == -1 ||
			(ret = read(fd, buffer, max_len_file)) == -1)
	{
		perror("corewar ");
		free(buffer);
		return (-1);
	}
	if (cw_add_new_champ(buffer, ret, champ_name, id) == -1)
	{
		free(buffer);
		return (-1);
	}
	close(fd);
	return (1);
}
