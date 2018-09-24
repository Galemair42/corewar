/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:14:03 by jabt              #+#    #+#             */
/*   Updated: 2017/11/21 12:11:30 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	letter;
	int		i;

	i = 0;
	letter = (char)c;
	while (s[i])
	{
		if (s[i] == letter)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == letter)
		return ((char *)&s[i]);
	return (NULL);
}
