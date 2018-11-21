/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_unicode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 20:07:23 by galemair          #+#    #+#             */
/*   Updated: 2018/05/17 17:48:45 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unicode.h"
#include "ft_printf.h"

void	octets2_unicode(unsigned int value, t_buffer *buff)
{
	unsigned char o1;
	unsigned char o2;
	unsigned char octet;

	o1 = ((value >> 6) << 27) >> 27;
	o2 = (value << 26) >> 26;
	octet = (g_mask.m1 >> 8) | o1;
	ft_putnchar_buff(buff, octet, 1);
	octet = ((g_mask.m1 << 24) >> 24) | o2;
	ft_putnchar_buff(buff, octet, 1);
}

void	octets3_unicode(unsigned int value, t_buffer *buff)
{
	unsigned char	o1;
	unsigned char	o2;
	unsigned char	o3;
	unsigned char	octet;

	o1 = ((value >> 12) << 28) >> 28;
	o2 = ((value >> 6) << 26) >> 26;
	o3 = (value << 26) >> 26;
	octet = (g_mask.m2 >> 16) | o1;
	ft_putnchar_buff(buff, octet, 1);
	octet = ((g_mask.m2 << 16) >> 24) | o2;
	ft_putnchar_buff(buff, octet, 1);
	octet = ((g_mask.m2 << 24) >> 24) | o3;
	ft_putnchar_buff(buff, octet, 1);
}

void	octets4_unicode(unsigned int value, t_buffer *buff)
{
	unsigned char	o1;
	unsigned char	o2;
	unsigned char	o3;
	unsigned char	o4;
	unsigned		octet;

	o1 = ((value >> 18) << 29) >> 29;
	o2 = ((value >> 12) << 26) >> 26;
	o3 = ((value >> 6) << 26) >> 26;
	o4 = (value << 26) >> 26;
	octet = (g_mask.m3 >> 24) | o1;
	ft_putnchar_buff(buff, octet, 1);
	octet = ((g_mask.m3 << 8) >> 24) | o2;
	ft_putnchar_buff(buff, octet, 1);
	octet = ((g_mask.m3 << 16) >> 24) | o3;
	ft_putnchar_buff(buff, octet, 1);
	octet = ((g_mask.m3 << 24) >> 24) | o4;
	ft_putnchar_buff(buff, octet, 1);
}
