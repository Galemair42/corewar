/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:04:17 by jabt              #+#    #+#             */
/*   Updated: 2018/01/10 12:33:17 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*newstr;

	newstr = NULL;
	if (!(newstr = malloc(size + 1)))
		return (NULL);
	newstr[size] = '\0';
	ft_memset(newstr, 0, size);
	return (newstr);
}
