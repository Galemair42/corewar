/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:58:45 by jabt              #+#    #+#             */
/*   Updated: 2017/11/21 12:13:28 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int						i;
	const	unsigned char	*us1;
	const	unsigned char	*us2;

	i = 0;
	us1 = (const unsigned char *)s1;
	us2 = (const unsigned char *)s2;
	while (us1[i] || us2[i])
	{
		if (us1[i] != us2[i])
			return ((int)(us1[i] - us2[i]));
		i++;
	}
	return (0);
}
