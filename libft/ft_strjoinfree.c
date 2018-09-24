/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 11:00:18 by jabt              #+#    #+#             */
/*   Updated: 2018/04/19 11:19:14 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2, int wfree)
{
	size_t	len;
	char	*newstr;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(newstr = (char *)malloc(len * sizeof(char))))
		return (NULL);
	while (s1[i])
	{
		newstr[i] = (char)s1[i];
		i++;
	}
	while (s2[j])
	{
		newstr[i] = s2[j];
		i++;
		j++;
	}
	newstr[i] = '\0';
	if (wfree == 1 || wfree == 3)
		free((void *)s1);
	else if (wfree == 2 || wfree == 3)
		free((void *)s2);
	return (newstr);
}
