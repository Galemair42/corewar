/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 18:35:34 by femaury           #+#    #+#             */
/*   Updated: 2018/09/19 18:09:39 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		print_ops(t_op *op)
{
	t_op	*curr;

	curr = op;
	while (curr)
	{
		ft_printf("Label: %s\nSize: %u\nInfo: %s (%#x)\nParams:\n\n\tLabel[1]: %s\n\tType[1]: %u\n\tSize[1]: %u\n\tValue[1]: %u\n\n\tLabel[2]: %s\n\tType[2]: %u\n\tSize[2]: %u\n\tValue[2]: %u\n\n\tLabel[3]: %s\n\tType[3]: %u\n\tSize[3]: %u\n\tValue[3]: %u\n\n", curr->label, curr->size, curr->info.name, curr->info.opcode, curr->params[0].label, curr->params[0].type, curr->params[0].size, curr->params[0].value, curr->params[1].label, curr->params[1].type, curr->params[1].size, curr->params[1].value, curr->params[2].label, curr->params[2].type, curr->params[2].size, curr->params[2].value);
		curr = curr->next;
	}
}

static int	exit_parsing_ext(int er)
{
	if (er == E_BODY_BADOP)
		ft_printf("Invalid instruction.\n");
	else if (er == E_BODY_LABEL)
		ft_printf("Invalid label.\n");
	else if (er == E_BODY_PARAM)
		ft_printf("Instruction parameters are invalid.\n");
	return (0);
}

int			exit_parsing(t_asm_file *fl, int er)
{
	if ((fl->exit = 1) && er == E_OPEN)
		ft_printf("ERROR: Couldn't open file...\n");
	else if (er == E_HEAD_MISS)
		ft_printf("ERROR: %s is missing...\n",
				fl->status & S_NAME ? "comment" : "name");
	else if (er == E_MALLOC)
		ft_printf("Couldn't find enough memory to allocate...\n");
	else
	{
		ft_printf("ERROR [%03u:%03u]: ", fl->ln + 1, fl->ch);
		if (er == E_HEAD_CMD)
			ft_printf("Invalid command...\n");
		else if (er == E_NAME_OPEN || er == E_COMM_OPEN)
			ft_printf("%s command's argument isn't a string.\n",
					er == E_NAME_OPEN ? ".name" : ".comment");
		else if (er == E_NAME_LEN || er == E_COMM_LEN)
			ft_printf("%s is too long...\n",
					er == E_NAME_LEN ? "name" : "comment");
		else if (er == E_NAME_EXTRA || er == E_COMM_EXTRA)
			ft_printf("%s has trailing characters after closing double "
					"quote...\n", er == E_NAME_EXTRA ? "name" : "comment");
		else if (er == E_NAME_NOEND || er == E_COMM_NOEND)
			ft_printf("%s doesn't have a closing quote...\n",
					er == E_NAME_NOEND ? "name" : "comment");
		else
			exit_parsing_ext(er);
	}
	return (0);
}

static void	init_file(t_asm_file *fl)
{
	fl->tmp_ln = NULL;
	fl->ln = 0;
	fl->ch = 0;
	fl->status = 0;
	fl->exit = 0;
	fl->onull = 0;
	fl->hd.magic = ft_revbits(COREWAR_EXEC_MAGIC);
	ft_bzero((void *)fl->hd.prog_name, PROG_NAME_LENGTH + 1);
	fl->hd.prog_size = 0;
	ft_bzero((void *)fl->hd.comment, COMMENT_LENGTH + 1);
	fl->bd.op_size = 0;
	fl->bd.op = NULL;
}

int			parse_file(char *file_name)
{
	int			fd;
	t_asm_file	fl;

	init_file(&fl);
	if ((fd = open(file_name, O_RDONLY)) < 0)
		return (exit_parsing(&fl, E_OPEN));
	if (!parse_header(&fl, fd))
		return (0);
	if (!parse_body(&fl, fd))
		return (0);
	print_ops(fl.bd.op);
	create_binary(&fl, file_name);
	close(fd);
	return (1);
}
