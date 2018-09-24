/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:30:59 by jabt              #+#    #+#             */
/*   Updated: 2017/11/21 12:11:43 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	letter;
	int		i;

	i = 0;
	letter = (char)c;
	while (s[i])
		i++;
	while (i != -1)
	{
		if (s[i] == letter)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
