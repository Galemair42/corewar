/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parse_body_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 18:51:33 by femaury           #+#    #+#             */
/*   Updated: 2018/09/20 18:55:06 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		get_label(t_asm_file *fl, char *str)
{
	t_label	*new;

	while (str[fl->ch] && ft_strhasc(LABEL_CHARS, str[fl->ch]))
		fl->ch++;
	if (str[fl->ch] == LABEL_CHAR && !str[fl->ch + 1])
	{
		if (!(new = new_label(NULL, size_op(&fl->bd.op))))
			return (exit_parsing(fl, E_MALLOC));
		if (!(new->s = ft_memalloc(ft_strlen(str))))
			return (exit_parsing(fl, E_MALLOC));
		new->s = ft_strcpyto(new->s, str, LABEL_CHAR);
		if (fl->bd.label)
			add_label(&fl->bd.label, new);
		else
			fl->bd.label = new;
		return (1);
	}
	else
		return (exit_parsing(fl, E_BODY_LB_NAME));
}

int		find_operation(t_asm_file *fl, char *str, t_op *op)
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
