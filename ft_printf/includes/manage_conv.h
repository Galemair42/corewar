/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_conv.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 12:56:22 by galemair          #+#    #+#             */
/*   Updated: 2018/05/15 20:52:43 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANAGE_CONV_H
# define MANAGE_CONV_H

typedef struct	s_conv
{
	char		*str;
	void		(*f)(t_parse*, t_buffer*, va_list);
}				t_conv;

void			manage_int(t_parse *datas, t_buffer *buff, va_list args);
void			manage_char(t_parse *datas, t_buffer *buff, va_list args);
void			manage_string(t_parse *datas, t_buffer *buff, va_list args);
void			manage_ptr(t_parse *datas, t_buffer *buff, va_list args);
void			manage_pct(t_parse *datas, t_buffer *buff, va_list args);
void			manage_unsignedint(t_parse *datas, t_buffer *buff,
				va_list args);

# define FUNCTION_NUMBER 6

const t_conv g_conv[] =
{
	{"diD", &manage_int},
	{"ouxXOU", &manage_unsignedint},
	{"Cc", &manage_char},
	{"Ss", &manage_string},
	{"p", &manage_ptr},
	{"%", &manage_pct}
};

#endif
