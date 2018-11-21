/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 16:56:38 by galemair          #+#    #+#             */
/*   Updated: 2018/05/15 20:03:43 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	manage_ptr(t_parse *datas, t_buffer *buff, va_list args)
{
	uintmax_t	value;
	int			size;

	value = (uintmax_t)va_arg(args, void*);
	size = calc_uintsize(value, 16) + 2;
	if (value == 0)
		size++;
	if (datas->minus == 0 && datas->width > size && datas->zero == 0)
		ft_putnchar_buff(buff, ' ', datas->width - size);
	ft_putstr_buff(buff, "0x");
	if (datas->minus == 0 && datas->width > size && datas->zero == 1)
		ft_putnchar_buff(buff, '0', datas->width - size);
	if (!(datas->precision == 0 && value == 0))
		ft_uputnbr_buff(value, buff, 16, 0);
	if (datas->minus == 1 && datas->width > size)
		ft_putnchar_buff(buff, ' ', datas->width - size);
}
