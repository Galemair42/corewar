/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_pct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 16:56:22 by galemair          #+#    #+#             */
/*   Updated: 2018/09/18 10:51:46 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	manage_pct(t_parse *datas, t_buffer *buff, va_list args)
{
	if (args)
		;
	if (datas->minus == 0)
		datas->zero == 1 ? ft_putnchar_buff(buff, '0', (datas->width - 1)) :
		ft_putnchar_buff(buff, ' ', (datas->width - 1));
	ft_putnchar_buff(buff, '%', 1);
	if (datas->minus == 1)
		ft_putnchar_buff(buff, ' ', (datas->width - 1));
}
