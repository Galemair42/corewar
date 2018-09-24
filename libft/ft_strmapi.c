/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:16:13 by jabt              #+#    #+#             */
/*   Updated: 2017/11/21 12:28:40 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		newstr[i] = f((unsigned int)i, (char)s[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
