/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:39:10 by jabt              #+#    #+#             */
/*   Updated: 2017/11/21 12:38:05 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	c = (n % 10) + 48;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_putnbr_fd(n / 10, fd);
			write(fd, "8", 1);
		}
		else
		{
			write(fd, "-", 1);
			ft_putnbr_fd(n * -1, fd);
		}
	}
	if (n == 0)
		write(fd, "0", 1);
	if (n > 0 && n < 10)
		write(fd, &c, 1);
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		write(fd, &c, 1);
	}
}
