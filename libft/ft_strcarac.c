/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcarac.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 12:14:04 by jabt              #+#    #+#             */
/*   Updated: 2018/02/26 12:23:32 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcarac(const char *s, int c)
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
	return (NULL);
}
