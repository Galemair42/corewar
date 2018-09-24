/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:38:00 by jabt              #+#    #+#             */
/*   Updated: 2017/11/21 11:29:06 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*dstchar;
	const char		*srcchar;
	size_t			i;
	unsigned char	carac;

	carac = (unsigned char)c;
	i = 0;
	dstchar = (char *)dst;
	srcchar = (const char *)src;
	while (i < n)
	{
		dstchar[i] = srcchar[i];
		if ((unsigned char)srcchar[i] == carac)
			return (&dst[i + 1]);
		i++;
	}
	return (NULL);
}
