/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <galemair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 16:27:31 by galemair          #+#    #+#             */
/*   Updated: 2018/11/06 18:03:00 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_lstappend(t_list **lst, t_list *to_add)
{
//	printf("sal\n");
	t_list *tmp;

	if (!(*lst))
	{
		*lst = to_add;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
	{
		printf("sal\n");
		tmp = tmp->next;
	}
	tmp->next = to_add;
}
