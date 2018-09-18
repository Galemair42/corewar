/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parse_body.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 15:40:56 by femaury           #+#    #+#             */
/*   Updated: 2018/09/18 22:32:06 by femaury          ###   ########.fr       */
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

static int	set_dir(t_asm_file *fl, char *str, t_param param, unsigned type)
{
	if ((type & T_DIR) && str[0] == DIRECT_CHAR)
	{
		param.type = T_DIR;
		if (str[1] == LABEL_CHAR && ft_strisonly(str + 2, LABEL_CHARS))
		{
			if (!(param.label = ft_memalloc(ft_strlen(str + 2))))
				return (exit_parsing(fl, E_MALLOC));
			param.label = ft_strcpyto(param.label, str + 2, SEPAR_CHAR);
			param.size = 2;
		}
		else if (ft_strisonly(str + 1, "0123456789"))
		{
			param.value = ft_atoi(str + 1);
			param.size = 4;
		}
	}
	return (1);
}

static int	set_ind(t_asm_file *fl, char *str, t_param param, unsigned type)
{
	if (type & T_IND)
	{
		if (str[0] == LABEL_CHAR)
		{
			if (!(param.label = ft_memalloc(ft_strlen(str + 1))))
				return (exit_parsing(fl, E_MALLOC));
			param.label = ft_strcpyto(param.label, str + 1, SEPAR_CHAR);
			param.size = 2;
			param.type = T_IND;
		}
		else if (ft_strisonly(str, "0123456789"))
		{
			param.value = ft_atoi(str);
			param.size = 2;
			param.type = T_IND;
		}
	}
	return (1);
}

static int	set_reg(t_asm_file *fl, char *str, t_param param, unsigned type)
{
	if ((type & T_REG) && str[0] == REG_CHAR)
	{
		if (ft_strisonly(str + 1, "0123456789")
				&& ft_atoi(str + 1) <= REG_NUMBER)
		{
			param.type = T_REG;
			param.value = ft_atoi(str + 1);
			param.size = 1;
		}
	}
	return (1);
}

static int	set_params(t_asm_file *fl, char **table)
{
	unsigned int	i;

	i = 0;
	while (table[i])
	{
		if (!set_dir(fl, table[i], fl->bd.op.params[i], fl->bd.op.info.p_type[i]))
			return (0);
		if (!set_ind(fl, table[i], fl->bd.op.params[i], fl->bd.op.info.p_type[i]))
			return (0);
		set_reg(fl, table[i], fl->bd.op.params[i], fl->bd.op.info.p_type[i]);
		i++
	}
	return (1);
}

static int	get_params(t_asm_file *fl, char **table)
{
	char	**extra;

	if (fl->bd.op.info.p_count == 1)
	{
		if (ft_strtabsize(table) == 1 && !ft_strhasc(table[0], SEPAR_CHAR))
		{
			if (!set_dir(fl, table[0], fl->bd.op.params[0], fl->bd.op.info.p_type[0]))
				return (0);
			set_reg(fl, table[0], fl->bd.op.params[0], fl->bd.op.info.p_type[0]);
		}
	}
	else if (fl->bd.op.info.p_count == 2)
	{
		if (ft_strtabsize(table) == 2 && ft_strhasc(table[0], SEPAR_CHAR)
				&& !ft_strhasc(table[1], SEPAR_CHAR))
		{
			if (!ft_strchr(table[0], SEPAR_CHAR) + 1)
				if (!set_params(fl, table))
					return (0);
		}
		else if (ft_strtabsize(table) == 1 && ft_strcountc(table[0], SEPAR_CHAR) == 1)
		{
			extra = ft_strsplit(table[0], SEPAR_CHAR);
			if (!set_params(fl, extra))
				return (0);
		}
	}
	else
	{
		if (ft_strtabsize(table) == 3 && ft_strhasc(table[0], SEPAR_CHAR)
				&& ft_strhasc(table[1], SEPAR_CHAR)
				&& !ft_strhasc(table[2], SEPAR_CHAR))
		{
		}
		else if (ft_strtabsize(table) == 2 && ((ft_strhas(table[0], SEPAR_CHAR)
				&& ft_strcountc(table[1], SEPAR_CHAR) == 1)
				|| (ft_strcountc(table[0], SEPAR_CHAR) == 2
				&& !ft_strhasc(table[1], SEPAR_CHAR))))
		{
		}
		else if (ft_strtabsize(table) == 3 && ft_strhasc(table[0], SEPAR_CHAR)
				&& ft_strhasc(table[1], SEPAR_CHAR)
				&& !ft_strhasc(table[2], SEPAR_CHAR))
		{
		}
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
