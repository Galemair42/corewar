/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 16:52:23 by galemair          #+#    #+#             */
/*   Updated: 2018/05/15 22:39:16 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		calc_intsize(intmax_t value, int base)
{
	int size;

	size = 0;
	if (value <= 0)
		value *= -1;
	while (value >= 1)
	{
		size++;
		value /= base;
	}
	return (size);
}

void	ft_putnbr_buff(intmax_t value, t_buffer *buff, int base)
{
	if (value == LONG_MIN)
	{
		ft_putstr_buff(buff, "9223372036854775808");
		return ;
	}
	if (value < 0)
		value *= -1;
	if (value >= base)
		ft_putnbr_buff(value / base, buff, base);
	ft_putnchar_buff(buff, (value % base) + '0', 1);
}

void	manage_int_flag(t_parse *datas, t_buffer *buff, intmax_t value)
{
	if (datas->minus == 0 && datas->zero == 0)
		ft_putnchar_buff(buff, ' ', datas->width);
	if (value < 0)
		ft_putnchar_buff(buff, '-', 1);
	else if (datas->plus == 1)
		ft_putnchar_buff(buff, '+', 1);
	else if (datas->space == 1)
		ft_putnchar_buff(buff, ' ', 1);
	if (datas->zero == 1)
		ft_putnchar_buff(buff, '0', datas->width);
	ft_putnchar_buff(buff, '0', datas->precision);
}

void	get_value(t_parse *datas, va_list args, intmax_t *value)
{
	if (datas->identifier == l || datas->converter == 'D')
		*value = (long int)va_arg(args, long int);
	else if (datas->identifier == hh)
		*value = (char)va_arg(args, int);
	else if (datas->identifier == ll)
		*value = (long long int)va_arg(args, long long int);
	else if (datas->identifier == h)
		*value = (short int)va_arg(args, int);
	else if (datas->identifier == j)
		*value = va_arg(args, intmax_t);
	else if (datas->identifier == z)
		*value = (size_t)va_arg(args, size_t);
	else
		*value = (int)va_arg(args, int);
}

void	manage_int(t_parse *datas, t_buffer *buff, va_list args)
{
	intmax_t	value;
	int			size;
	int			precision;

	precision = datas->precision;
	get_value(datas, args, &value);
	size = calc_intsize(value, 10);
	if (precision == -1 && value == 0)
		size++;
	calc_int_flags(size, datas, value >= 0 ? '+' : '-');
	manage_int_flag(datas, buff, value);
	if (!(value == 0 && (precision >= 0)))
		ft_putnbr_buff(value, buff, 10);
	if (datas->minus == 1)
		ft_putnchar_buff(buff, ' ', datas->width);
}
