/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 19:45:25 by galemair          #+#    #+#             */
/*   Updated: 2018/05/17 17:47:26 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNICODE_H
# define UNICODE_H

typedef	struct			s_mask
{
	const unsigned int	m1;
	const unsigned int	m2;
	const unsigned int	m3;
}						t_mask;

const t_mask g_mask =
{
	.m1 = 49280,
	.m2 = 14712960,
	.m3 = 4034953344,
};
#endif
