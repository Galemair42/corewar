/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:32:04 by jabt              #+#    #+#             */
/*   Updated: 2017/11/21 11:27:56 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	carac;
	char			*str;
	size_t			i;

	i = 0;
	str = (char *)s;
	carac = (unsigned char)c;
	while (i < n)
	{
		if ((unsigned char)str[i] == carac)
			return ((void *)&s[i]);
		i++;
	}
	return (NULL);
}
