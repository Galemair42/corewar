/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:29:10 by jabt              #+#    #+#             */
/*   Updated: 2018/01/24 09:36:41 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		ft_numlen(int n)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			return (2 + (ft_numlen((n / 10) * -1)));
		}
		return (1 + (ft_numlen(n * -1)));
	}
	if (n > 9)
		return (1 + ft_numlen(n / 10));
	if (n > 0 && n < 10)
		return (1);
	if (n == 0)
		return (1);
	return (0);
}

static char		*ft_fillstr(char *str, int n, int len)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		while (0 < len)
		{
			str[len--] = (n % 10) + 48;
			n = n / 10;
		}
	}
	else
	{
		while (0 <= len--)
		{
			str[len] = (n % 10) + 48;
			n = n / 10;
		}
	}
	return (str);
}

char			*ft_itoa(int n)
{
	int		len;
	char	*str;
	int		i;

	i = 0;
	len = ft_numlen(n);
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		if (n == -2147483648)
		{
			str[10] = '8';
			n = n / 10;
			len--;
		}
		len--;
		str[0] = '-';
	}
	str = ft_fillstr(str, n, len);
	return (str);
}
