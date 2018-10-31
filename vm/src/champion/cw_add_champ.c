/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_add_cham.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 10:54:56 by jabt              #+#    #+#             */
/*   Updated: 2018/10/30 19:30:45 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h" 

static void		cw_print_init_champ(header_t *header_champ)
{
	printf("* Player 1, weighing %u bytes, \"%s\" (\"%s\") !\n",
			header_champ->prog_size, header_champ->prog_name,
			header_champ->comment);
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

	if (size < HEADER_SIZE || !cw_header_verif_null_byte(buff_file))
	{
		printf("corewar : Invalid Champion %s\n", champ->name);
		return (-1);
	}
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
	cw_print_init_champ(&champ->header);	
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

int			cw_add_new_champ(unsigned char *buffer,
		size_t size_buf, char *champ_name, int id)
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
	ft_bzero(champ->instruction, CHAMP_MAX_SIZE + 1);
	ft_bzero(champ->header.prog_name, PROG_NAME_LENGTH + 1);
	ft_bzero(champ->header.comment, COMMENT_LENGTH + 1);
	new_node->content = (void *)champ;
	new_node->next = NULL;
	if (!arena.champion)
		arena.champion = new_node;
	else
		cw_insert_champion(new_node, champ);
	if (cw_add_header(buffer, size_buf, champ) == -1)
		return (-1);
	return (1);
}

/*
** 		RETURN -1 if fail or 1
*/

/*
** 		INPUT
** 		new_lst is the new_node already malocated and init new_champ
** 		is the new_node->champion value
*/

void			cw_insert_champion(t_list *new_lst, t_champion *new_champ)
{
	t_champion	*cur_champ;
	t_list		*cur_lst;
	t_list		*cur_lst_tmp;

	cur_lst = arena.champion;
	cur_lst_tmp = NULL;
	while (cur_lst)
	{
		cur_champ = (t_champion *)cur_lst->content;
		if (new_champ->id < cur_champ->id)//je dois inserer avant le cur_champ
		{
			new_lst->next = cur_lst;
			if (cur_lst_tmp == NULL)
				arena.champion = new_lst;
			else
				cur_lst_tmp->next = new_lst;
			return ;
		}
		cur_lst_tmp = cur_lst;
		cur_lst = cur_lst->next;
	}
	cur_lst_tmp->next = new_lst;
}
