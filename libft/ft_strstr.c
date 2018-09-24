/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:42:16 by jabt              #+#    #+#             */
/*   Updated: 2017/11/21 12:12:13 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;
	int	secondi;

	j = 0;
	i = 0;
	if (!needle[0])
		return ((char *)haystack);
	while (haystack[i])
	{
		if (haystack[i] == needle[j])
		{
			secondi = i;
			while (haystack[secondi] == needle[j] || !needle[j])
			{
				if (needle[j] == '\0')
					return ((char *)&haystack[i]);
				j++;
				secondi++;
			}
			j = 0;
		}
		i++;
	}
	return (NULL);
}
