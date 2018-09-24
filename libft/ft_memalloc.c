/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 11:34:22 by jabt              #+#    #+#             */
/*   Updated: 2017/11/21 12:23:20 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*memzone;

	memzone = NULL;
	if (!(memzone = malloc(size)))
		return (NULL);
	ft_memset(memzone, 0, size);
	return (memzone);
}
