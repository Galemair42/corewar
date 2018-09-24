/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:11:03 by jabt              #+#    #+#             */
/*   Updated: 2017/11/21 12:30:21 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*newstr;
	size_t		i;

	if (!s)
		return (NULL);
	i = 0;
	if (!(newstr = (char *)malloc((len * sizeof(*newstr)) + 1)))
		return (NULL);
	while (i < len)
	{
		newstr[i] = s[start];
		start++;
		i++;
	}
	newstr[len] = '\0';
	return (newstr);
}
