/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_unsignedint.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 14:46:49 by galemair          #+#    #+#             */
/*   Updated: 2018/09/18 10:56:47 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		calc_uintsize(uintmax_t value, int base)
{
	int size;

	size = 0;
	while (value >= 1)
	{
		size++;
		value /= base;
	}
	return (size);
}

void	ft_uputnbr_buff(uintmax_t value, t_buffer *buff, int base, int maj)
{
	if (value >= (uintmax_t)base)
		ft_uputnbr_buff(value / base, buff, base, maj);
	ft_putnchar_buff(buff, get_rank(value % base, maj), 1);
}

void	manage_uint_flag(t_parse *datas, t_buffer *buff, uintmax_t value,
		int precision)
{
	if (datas->minus == 0 && datas->zero == 0)
		ft_putnchar_buff(buff, ' ', datas->width);
	if (datas->hashtag == 1 && (datas->converter == 'x' ||
		datas->converter == 'X') && value > 0)
		ft_putstr_buff(buff, datas->converter == 'x' ? "0x" : "0X");
	if (datas->hashtag == 1 && (datas->converter == 'o' ||
		datas->converter == 'O') && ((value > 0) || precision >= 0))
		ft_putnchar_buff(buff, '0', 1);
	if (datas->zero == 1)
		ft_putnchar_buff(buff, '0', datas->width);
	ft_putnchar_buff(buff, '0', datas->precision);
}

void	get_uvalue(t_parse *datas, va_list args, uintmax_t *value)
{
	if (datas->identifier == l || ft_char_in_str("OU", datas->converter))
		*value = (unsigned long int)va_arg(args, long int);
	else if (datas->identifier == hh)
		*value = (unsigned char)va_arg(args, int);
	else if (datas->identifier == ll)
		*value = (unsigned long long int)va_arg(args, long long int);
	else if (datas->identifier == h)
		*value = (unsigned short int)va_arg(args, int);
	else if (datas->identifier == j)
		*value = va_arg(args, uintmax_t);
	else if (datas->identifier == z)
		*value = (size_t)va_arg(args, size_t);
	else
		*value = (unsigned int)va_arg(args, int);
}

void	manage_unsignedint(t_parse *datas, t_buffer *buff, va_list args)
{
	uintmax_t	value;
	int			size;
	int			precision;
	int			base;

	base = 10;
	if (ft_char_in_str("Xx", datas->converter))
		base = 16;
	if (ft_char_in_str("oO", datas->converter))
		base = 8;
	precision = datas->precision;
	get_uvalue(datas, args, &value);
	size = calc_uintsize(value, base);
	if (precision == -1 && value == 0)
		size++;
	calc_uint_flags(size, datas);
	manage_uint_flag(datas, buff, value, precision);
	if (!(value == 0 && (precision >= 0)))
		datas->converter == 'X' ? ft_uputnbr_buff(value, buff, base, 1) :
		ft_uputnbr_buff(value, buff, base, 0);
	if (datas->minus == 1)
		ft_putnchar_buff(buff, ' ', datas->width);
}
