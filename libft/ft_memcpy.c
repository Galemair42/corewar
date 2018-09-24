/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:14:30 by jabt              #+#    #+#             */
/*   Updated: 2017/11/21 11:28:41 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dstchar;
	const char	*srcchar;
	size_t		i;

	i = 0;
	dstchar = (char *)dst;
	srcchar = (const char *)src;
	while (i < n)
	{
		dstchar[i] = srcchar[i];
		i++;
	}
	return (dst);
}
