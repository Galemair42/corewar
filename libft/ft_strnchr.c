/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:14:03 by jabt              #+#    #+#             */
/*   Updated: 2018/01/18 16:13:17 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnchr(const char *s, int c, size_t len)
{
	char	letter;
	int		i;

	i = 0;
	letter = (char)c;
	while (s[i] && len > 0)
	{
		if (s[i] == letter)
			return ((char *)&s[i]);
		i++;
		len--;
	}
	return (NULL);
}
