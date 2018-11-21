/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 22:17:47 by galemair          #+#    #+#             */
/*   Updated: 2018/09/18 10:55:52 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_svalue(t_parse *datas, va_list args, wchar_t **str_l, char **str)
{
	if (datas->identifier == l || datas->converter == 'S')
	{
		*str_l = (wchar_t*)va_arg(args, void*);
		*str = NULL;
	}
	else
	{
		*str_l = NULL;
		*str = (char*)va_arg(args, void*);
	}
}

void	manage_strl(t_parse *datas, wchar_t *str, t_buffer *buff)
{
	int size;

	size = datas->precision != 0 ? ft_strlenbytes(str) : 0;
	if (datas->minus == 0 && size < datas->width)
		ft_putnchar_buff(buff, datas->zero == 1 ? '0' : ' ',
		datas->width - size);
	while (*str && size > 0)
	{
		if (*str <= 127)
			ft_putnchar_buff(buff, *str, 1);
		else if (*str <= 2047)
			octets2_unicode(*str, buff);
		else if (*str <= 65535)
			octets3_unicode(*str, buff);
		else
			octets4_unicode(*str, buff);
		str++;
	}
	if (datas->minus == 1 && size < datas->width)
		ft_putnchar_buff(buff, ' ', datas->width - size);
}

void	manage_string(t_parse *datas, t_buffer *buff, va_list args)
{
	wchar_t *str_l;
	char	*str;
	int		size;

	get_svalue(datas, args, &str_l, &str);
	if (str == NULL && str_l == NULL)
		str = "(null)";
	if (str)
	{
		size = datas->precision < (int)ft_strlen(str) ?
		datas->precision : (int)ft_strlen(str);
		if (datas->minus == 0 && size < datas->width)
			ft_putnchar_buff(buff, datas->zero == 1 ?
			'0' : ' ', datas->width - size);
		ft_putstrn_buff(buff, str, size);
		if (datas->minus == 1 && size < datas->width)
			ft_putnchar_buff(buff, ' ', datas->width - size);
	}
	else if (str_l)
		manage_strl(datas, str_l, buff);
}
