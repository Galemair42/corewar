/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parse_body.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 15:40:56 by femaury           #+#    #+#             */
/*   Updated: 2018/09/19 19:05:23 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	get_label(t_asm_file *fl, char *str, t_op *op)
{
	while (str[fl->ch] && ft_strhasc(LABEL_CHARS, str[fl->ch]))
		fl->ch++;
	if (str[fl->ch] == LABEL_CHAR && !str[fl->ch + 1])
	{
		if (!(op->label = ft_memalloc(ft_strlen(str))))
			return (exit_parsing(fl, E_MALLOC));
		op->label = ft_strcpyto(op->label, str, LABEL_CHAR);
		return (1);
	}
	else
		return (exit_parsing(fl, E_BODY_LABEL));
}

static int	find_operation(t_asm_file *fl, char *str, t_op *op)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		if (ft_strequ(str, g_op_tab[i].name))
		{
			op->info = g_op_tab[i];
			return (1);
		}
		i++;
	}
	return (exit_parsing(fl, E_BODY_BADOP));
}

static char	**prepare_params(char *ln, int nb)
{
	char	*trimmed;
	char	**params;
	unsigned int	i;

	i = 0;
	if (!(trimmed = ft_strstrip(ft_skipnwhite(ln, nb))))
		return (NULL);
	if (!(params = ft_strsplit(trimmed, SEPAR_CHAR)))
		return (NULL);
	ft_strdel(&trimmed);
	return (params);
}

static int	parse_instruction(t_asm_file *fl, char *ln, t_op *op)
{
	char	**table;

	table = ft_splitwhite(ln);
	if (ft_strhasc(table[0], LABEL_CHAR))
	{
		if (get_label(fl, table[0], op) && table[1])
			if (find_operation(fl, table[1], op)
					&& get_params(fl, prepare_params(ln, 2),
					ft_strcountc(ln, SEPAR_CHAR), op))
				return (1);
	}
	else
	{
		if (find_operation(fl, table[0], op)
				&& get_params(fl, prepare_params(ln, 1),
				ft_strcountc(ln, SEPAR_CHAR), op))
			return (1);
	}
	return (0);
}

int			parse_body(t_asm_file *fl, int fd)
{
	char	*ln;
	t_op	*new;

	ln = NULL;
	fl->ch = 0;
	fl->bd.op = NULL;
	while (ft_gnl(fd, &ln) > 0)
	{
		fl->status = 0;
		if (ln[0] && !ft_striswhiteuntil(ln, COMMENT_CHAR))
		{
			if (!(new = new_op()))
				return (exit_parsing(fl, E_MALLOC));
			if (!parse_instruction(fl, ln, new))
				return (0);
			if (!fl->bd.op)
				fl->bd.op = new;
			else
				add_op(&fl->bd.op, new);
		}
		ft_strdel(&ln);
		fl->ln++;
	}
	fl->bd.op_size = ft_revbits(size_op(&fl->bd.op));
	return (1);
}
