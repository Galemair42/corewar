/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parse_body.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 15:40:56 by femaury           #+#    #+#             */
/*   Updated: 2018/09/24 16:39:50 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	**prepare_params(char *ln, int nb)
{
	char			*trimmed;
	char			**params;
	unsigned int	i;
	unsigned int	kill;

	i = 0;
	kill = 0;
	if (!(trimmed = ft_strstrip(ft_skipnwhite(ln, nb))))
		return (NULL);
	if (!(params = ft_strsplit(trimmed, SEPAR_CHAR)))
		return (NULL);
	ft_strdel(&trimmed);
	while (params[i])
	{
		if (kill)
			ft_strdel(&params[i]);
		if (ft_strhasc(params[i], COMMENT_CHAR))
		{
			ft_strclrfrom(params[i], COMMENT_CHAR);
			kill = 1;
		}
		i++;
	}
	return (params);
}

static int	parse_instruction(t_asm_file *fl, char *ln, t_op *op)
{
	char	**table;

	table = ft_splitwhite(ln);
	if (ft_strhasc(table[0], LABEL_CHAR))
	{
		if (get_label(fl, table[0]) && find_operation(fl, table[1], op)
				&& get_params(fl, prepare_params(ln, 2),
				ft_strcountc(ln, SEPAR_CHAR), op))
			return (1);
	}
	else
	{
		if (find_operation(fl, table[0], op) && get_params(fl,
				prepare_params(ln, 1), ft_strcountc(ln, SEPAR_CHAR), op))
			return (1);
	}
	return (0);
}

char		*prepare_label(t_asm_file *fl, char *ln)
{
	while (ft_iswhite(ln[fl->ch]))
		fl->ch++;
	while (ft_strhasc(LABEL_CHARS, ln[fl->ch]))
		fl->ch++;
	if (ln[fl->ch] == LABEL_CHAR && ft_striswhiteuntil(ln + fl->ch + 1, '\0'))
	{
		fl->ch = 0;
		return (ft_strtrim(ln));
	}
	return (NULL);
}

int			parse_body_ext(t_asm_file *fl, char *ln)
{
	t_op	*new;

	if (!(new = new_op()))
		return (exit_parsing(fl, E_MALLOC));
	if (!parse_instruction(fl, ln, new))
		return (0);
	new->line = fl->ln;
	if (!fl->bd.op)
		fl->bd.op = new;
	else
		add_op(&fl->bd.op, new);
	return (1);
}

int			parse_body(t_asm_file *fl, int fd)
{
	char	*ln;
	char	*tmp;

	ln = NULL;
	while (!(fl->status = 0) && ft_gnl(fd, &ln) > 0)
	{
		fl->ch = 0;
		if (ln[0] && !ft_striswhiteuntil(ln, COMMENT_CHAR))
		{
			if ((tmp = prepare_label(fl, ln)))
			{
				if (!get_label(fl, tmp))
					return (0);
			}
			else
			{
				if (!parse_body_ext(fl, ln))
					return (0);
			}
		}
		ft_strdel(&ln);
		fl->ln++;
	}
	fl->bd.op_size = ft_revbits(size_op(&fl->bd.op));
	return (1);
}
