/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_converter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 12:57:45 by galemair          #+#    #+#             */
/*   Updated: 2018/05/15 14:23:17 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "manage_conv.h"

void	ft_manage_conv(t_parse datas, t_buffer *buff, va_list args)
{
	size_t	i;

	i = 0;
	while (i < FUNCTION_NUMBER)
	{
		if (ft_char_in_str(g_conv[i].str, datas.converter))
			g_conv[i].f(&datas, buff, args);
		i++;
	}
}
