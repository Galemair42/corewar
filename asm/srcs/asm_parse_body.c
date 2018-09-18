/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parse_body.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 15:40:56 by femaury           #+#    #+#             */
/*   Updated: 2018/09/18 18:35:01 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	get_label(t_asm_file *fl, char *str)
{
	while (str[fl->ch] && ft_strhasc(LABEL_CHARS, str[fl->ch]))
		fl->ch++;
	if (!str[fl->ch] && str[fl->ch - 1] == LABEL_CHAR)
	{
		if (!(fl->bd.op.label = ft_memalloc(ft_strlen(str))))
			return (exit_parsing(fl, E_MALLOC));
		fl->bd.op.label = ft_strcpyto(fl->bd.op.label, str, LABEL_CHAR);
		return (1);
	}
	else
		return (exit_parsing(fl, E_BODY_LABEL);
}

static int	find_operation(t_asm_file *fl, char *str)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		if (!ft_strcmp(str, g_op_tab[i].name))
			return (fl->bd.op.info = g_op_tab[i]);
		i++;
	}
	return (exit_parsing(fl, E_BODY_BADOP));
}

static int	get_params(t_asm_file *fl, char **table)
{
	if (fl->bd.op.info.p_count == 1)
	{
		if (ft_strtabsize(table) == 1 && !ft_strhasc(table[0], SEPAR_CHAR))
		{
			if (fl->bd.op.info.p_type[0] == T_DIR && table[0][0] == DIRECT_CHAR)
			{
				fl->bd.op.params[0].type = T_DIR;
				if (table[0][1] == LABEL_CHAR
						&& ft_strisonly(table[0] + 2, LABEL_CHARS))
				{
					if (!(fl->bd.op.params[0].label = ft_strdup(table[0] + 2)))
						return (exit_parsing(fl, E_MALLOC));
					fl->bd.op.params[0].size = 2;
				}
				else if (ft_strisonly(table[0] + 1, "0123456789"))
				{
					fl->bd.op.params[0].value = ft_atoi(table[0] + 1);
					fl->bd.op.params[0].size = 4;
				}
			}
			else (fl->bd.op.info.p_type[0] == T_REG && table[0][0] == REG_CHAR 
					&& ft_strisonly(table[0] + 1, "0123456789")
					&& ft_atoi(table[0] + 1) <= REG_NUMBER)
			{
				fl->bd.op.params[0].type = T_REG;
				fl->bd.op.params[0].value = ft_atoi(table[0] + 1);
				fl->bd.op.params[0].size = 1;
			}
		}
	}
	else if (fl->bd.op.info.p_count == 2)
	{
		if (ft_strtabsize(table) == 2 && ft_strhas(table[0], SEPAR_CHAR)
				&& !ft_strhasc(table[1], SEPAR_CHAR))
		{
			if (!ft_strchr(table[0], SEPAR_CHAR) + 1)
			{
				if (table[0][0] == LABEL_CHAR
						&& (fl->bd.op.info.p_type[0] & T_IND))
				{
					if (!(fl->bd.op.params[0].label = ft_strdup(table[0] + 1)))
						return (exit_parsing(fl, E_MALLOC));
					fl->bd.op.params[0].size = 2;
					fl->bd.op.params[0].type = T_IND;
				}
				else if (table[0][0] == DIRECT_CHAR
						&& (fl->bd.op.info.p_type[0] & T_DIR))
				{
					if (table[0][1] == LABEL_CHAR
							&& ft_strisonly(table[0] + 2, LABEL_CHARS))
					{
						if (!(fl->bd.op.params[0].label = ft_strdup(table[0] + 2)))
							return (exit_parsing(fl, E_MALLOC));
						fl->bd.op.params[0].size = 2;
					}
					else if (ft_strisonly(table[0] + 1, "0123456789"))
					{
						fl->bd.op.params[0].value = ft_atoi(table[0] + 1);
						fl->bd.op.params[0].size = 4;
					}
				}
				else if (table[0][0] == REG_CHAR
						&& (fl->bd.op.info.p_type[0] & T_REG))
				{
				}
				else if (ft_strhasc("0123456789", table[0][0])
						&& (fl->bd.op.info.p_type[0] & T_IND))
				{
				}
			}
		}
		else if (ft_strtabsize(table) == 1 && ft_strhasc(table[0], SEPAR_CHAR))
		{
		}
	}
	else
	{
	}
	return (exit_parsing(fl, E_BODY_PARAM));
}

static int	parse_instruction(t_asm_file *fl, char *ln)
{
	char	**table;

	table = ft_splitwhite(ln);
	if (ft_strhasc(table[0], LABEL_CHAR))
	{
		if (get_label(fl, table[0]) && table[1])
			if (find_operation(fl, table[1]) && get_params(fl, table + 2))
				return (1);
	}
	else
		if (find_operation(fl, table[0]) && get_params(fl, table + 1))
			return (1);
	return (0);
}

int			parse_body(t_asm_file *fl, int fd)
{
	char	*ln;

	ln = NULL;
	fl->ch = 0;
	while (ft_gnl(fd, &ln) > 0)
	{
		if (ln[0] && !ft_striswhiteuntil(ln, COMMENT_CHAR))
		{
			if (!parse_instruction(fl, ln))
				return (0);
		}
		ft_strdel(&ln);
		fl->ln++;
	}
	return (1);
}
