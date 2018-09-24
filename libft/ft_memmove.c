/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:59:19 by jabt              #+#    #+#             */
/*   Updated: 2017/11/21 12:02:08 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dstchar;
	char	*srcchar;
	size_t	i;

	i = -1;
	dstchar = (char *)dst;
	srcchar = (char *)src;
	if (srcchar > dstchar)
	{
		while (++i < len)
			dstchar[i] = srcchar[i];
	}
	else
	{
		while ((int)--len >= 0)
			dstchar[len] = srcchar[len];
	}
	return (dst);
}
