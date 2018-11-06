/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <galemair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 16:27:31 by galemair          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/11/06 10:40:27 by jabt             ###   ########.fr       */
=======
/*   Updated: 2018/11/06 11:26:07 by galemair         ###   ########.fr       */
>>>>>>> a4442cc348eb72c604901f836f93aaf7021374f0
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstappend(t_list *lst, t_list *to_add)
{
	while (lst)
<<<<<<< HEAD
		lst = lst->next;
=======
		lst = (lst)->next;
>>>>>>> a4442cc348eb72c604901f836f93aaf7021374f0
	lst->next = to_add;
}
