/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:37:39 by jabt              #+#    #+#             */
/*   Updated: 2018/05/28 15:02:12 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		ft_countstrings(const char *str, char c)
{
	int	i;
	int	result;

	result = 0;
	i = 0;
	while (str[i] == c)
		i++;
	while (str[i])
	{
		while (str[i] == c)
		{
			if (str[i + 1] == c)
				i++;
			if (!str[i + 1])
				result--;
			if (str[i + 1] != c)
			{
				i++;
				result++;
			}
		}
		i++;
	}
	return (result + 1);
}

static int		ft_strchrlen(char **str, char c)
{
	int	i;

	i = 0;
	while ((char)**str == c)
		*str = *str + 1;
	while (str[0][i])
	{
		if (str[0][i] == c)
			return (i);
		i++;
	}
	return (i);
}

static void		ft_fillstr(char *dest, char *src, char c)
{
	int	i;

	i = 0;
	while (src[i] != c && src[i])
	{
		dest[i] = src[i];
		i++;
	}
}

char			**ft_strsplit(const char *s, char c)
{
	int		i;
	int		nbstring;
	int		len;
	char	**tabstring;

	if (!s)
		return (NULL);
	i = 0;
	nbstring = ft_countstrings(s, c);
	tabstring = NULL;
	if (!(tabstring = malloc(sizeof(char *) * (nbstring + 1))))
		return (NULL);
	while (i < nbstring)
	{
		len = ft_strchrlen((char **)&s, c);
		if (!(tabstring[i] = malloc(len + 1)))
			return (NULL);
		tabstring[i][len] = '\0';
		if (len == 0)
			tabstring[i] = NULL;
		ft_fillstr(tabstring[i++], (char *)s, c);
		s += len + 1;
	}
	tabstring[nbstring] = NULL;
	return (tabstring);
}
