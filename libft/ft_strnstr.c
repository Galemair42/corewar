/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:42:16 by jabt              #+#    #+#             */
/*   Updated: 2018/04/20 15:23:08 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	j = 0;
	i = 0;
	if (!needle[0])
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[j])
		{
			k = i;
			while ((haystack[k] == needle[j] || !needle[j]) && k <= len)
			{
				if (needle[j] == '\0')
					return ((char *)&haystack[i]);
				j++;
				k++;
			}
			j = 0;
		}
		i++;
	}
	return (NULL);
}
