/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 11:23:50 by galemair          #+#    #+#             */
/*   Updated: 2018/05/17 18:25:22 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	calc_int_flags(int size, t_parse *datas, char signe)
{
	if (datas->precision >= 0)
		datas->zero = 0;
	datas->precision -= size;
	datas->precision = datas->precision >= 0 ? datas->precision : 0;
	if ((datas->plus == 1 && signe == '+') || signe == '-' || datas->space == 1)
		size++;
	datas->width -= (datas->precision + size);
}

void	calc_uint_flags(int size, t_parse *datas)
{
	if (datas->precision >= 0)
		datas->zero = 0;
	datas->precision -= size;
	if ((datas->converter == 'o' || datas->converter == 'O') &&
		datas->hashtag == 1)
		datas->precision -= 1;
	datas->precision = datas->precision >= 0 ? datas->precision : 0;
	if (ft_char_in_str("Xx", datas->converter) && datas->hashtag == 1)
		size += 2;
	if (ft_char_in_str("Oo", datas->converter) && datas->hashtag == 1)
		size++;
	datas->width -= (datas->precision + size);
}
