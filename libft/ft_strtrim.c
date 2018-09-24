/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:11:51 by jabt              #+#    #+#             */
/*   Updated: 2017/11/21 10:49:22 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*ft_strfill(char *dst, const char *src, int index, int max)
{
	int	i;

	i = 0;
	if (!(dst = (char *)malloc((max - index) + 2)))
		return (NULL);
	while (index <= max)
	{
		dst[i] = (char)src[index];
		index++;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char		*ft_strtrim(char const *s)
{
	int		k;
	int		i;
	int		j;
	char	*newstr;

	if (!s)
		return (NULL);
	newstr = NULL;
	j = ft_strlen(s);
	i = -1;
	k = 0;
	while (s[++i])
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
		{
			k = 1;
			j--;
			while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
				j--;
			return (ft_strfill(newstr, s, i, j));
		}
	}
	if (k != 1)
		return (ft_strfill(newstr, s, 0, -1));
	return (ft_strfill(newstr, s, 0, j - 1));
}
