/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 14:36:23 by jabt              #+#    #+#             */
/*   Updated: 2017/11/21 12:28:52 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*newstr;
	size_t	len;

	if (!s || !f)
		return (NULL);
	newstr = NULL;
	len = ft_strlen(s);
	if (!(newstr = (char *)malloc((sizeof(char) * len) + 1)))
		return (NULL);
	i = 0;
	while (s[i])
	{
		newstr[i] = f((char)s[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
