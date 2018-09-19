/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_write.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 22:37:35 by femaury           #+#    #+#             */
/*   Updated: 2018/09/19 21:23:36 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*modify_name(char *file_name)
{
	char			*new;
	size_t			len;
	unsigned int	i;

	i = 0;
	len = ft_strlen(file_name);
	if (!(new = (char *)malloc(len + 2)))
		return (NULL);
	new = ft_strcpy(new, file_name);
	new[len - 1] = 'c';
	new = ft_strcat(new, "or");
	return (new);
}

static void	write_ocp(t_op *op, int fd)
{
	unsigned int	ocp;
	unsigned int	i;
	unsigned int	magic;

	ocp = 0;
	i = 0;
	while (i < 3)
	{
		magic = 2 + (2 * i);
		if (op->params[2 - i].type == T_DIR)
			ocp |= (DIR_CODE << magic);
		else if (op->params[2 - i].type == T_IND)
			ocp |= (IND_CODE << magic);
		else if (op->params[2 - i].type == T_REG)
			ocp |= (REG_CODE << magic);
		i++;
	}
	write(fd, &ocp, 1);
}

static void	write_instructions(t_asm_file *fl, int fd)
{
	t_op			*curr;
	unsigned int	i;

	curr = fl->bd.op;
	while (curr)
	{
		i = 0;
		write(fd, &curr->info.opcode, 1);
		if (curr->info.ocp)
			write_ocp(curr, fd);
		while (curr->params[i].type)
		{
			write(fd, &curr->params[i].value, curr->params[i].size);
			i++;
		}
		curr = curr->next;
	}
}

void		create_binary(t_asm_file *fl, char *file_name)
{
	int		fd;
	char	*name;

	if (!(name = modify_name(file_name)))
		return ;
	if ((fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0)
		return ;
	write(fd, &fl->hd.magic, 4);
	write(fd, fl->hd.prog_name, PROG_NAME_LENGTH);
	write(fd, &fl->onull, 4);
	write(fd, &fl->bd.op_size, 4);
	write(fd, fl->hd.comment, COMMENT_LENGTH);
	write(fd, &fl->onull, 4);
	write_instructions(fl, fd);
	ft_printf("Writing output program to %s\n", name);
	close(fd);
}
