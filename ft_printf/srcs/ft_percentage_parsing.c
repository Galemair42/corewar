/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percentage_parsing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:14:21 by galemair          #+#    #+#             */
/*   Updated: 2018/05/16 14:31:28 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_update_struct(char c, t_parse *datas)
{
	if (c == '#')
		datas->hashtag = 1;
	else if (c == '0' && datas->minus == 0)
		datas->zero = 1;
	else if (c == '+')
		datas->plus = 1;
	else if (c == '-')
	{
		datas->minus = 1;
		datas->zero = 0;
	}
	else if (c == ' ')
		datas->space = 1;
}

void	ft_get_modifiers2(char *modifiers, t_parse *datas)
{
	if (modifiers[0] == 'h' && modifiers[1] == 'h')
		datas->identifier = hh;
	else if (modifiers[0] == 'l' && modifiers[1] == 'l')
		datas->identifier = ll;
	else if (modifiers[0] == 'h')
		datas->identifier = h;
	else if (modifiers[0] == 'l')
		datas->identifier = l;
	else if (modifiers[0] == 'j')
		datas->identifier = j;
	else if (modifiers[0] == 'z')
		datas->identifier = z;
}

int		ft_get_modifiers(char **str, t_parse *datas)
{
	char	modifiers[3];
	char	*flags;
	size_t	index;

	index = 0;
	flags = MODIFIERS;
	while (**str != *flags)
		flags++;
	while (*flags != ' ' && **str == *flags)
	{
		modifiers[index] = **str;
		flags++;
		index++;
		(*str)++;
	}
	if (index > 0)
		(*str)--;
	modifiers[index] = '\0';
	ft_get_modifiers2(modifiers, datas);
	return (1);
}

t_parse	init_datas_struct(void)
{
	t_parse datas;

	ft_bzero(&datas, sizeof(t_parse));
	datas.precision = -1;
	datas.converter = '0';
	return (datas);
}

char	*ft_percentage_parsing(char *str, t_buffer *buff, va_list args)
{
	t_parse		datas;

	datas = init_datas_struct();
	while (*str)
	{
		if (ft_isdigit(*str) && *str != '0')
			datas.width = ft_atoi_custom(&str, 0);
		else if (*str == '.')
			datas.precision = ft_atoi_custom(&str, 1);
		else if (ft_char_in_str(FLAGS, *str))
			ft_update_struct(*str, &datas);
		else if (ft_char_in_str(MODIFIERS, *str) && datas.identifier == none)
			ft_get_modifiers(&str, &datas);
		else if (ft_char_in_str(CONVERTERS, *str))
		{
			datas.converter = *str;
			break ;
		}
		else
			return (manage_undefined_converter(&datas, str, buff));
		str++;
	}
	if (datas.converter != '0')
		ft_manage_conv(datas, buff, args);
	return (str);
}
