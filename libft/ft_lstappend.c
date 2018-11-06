/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <galemair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 16:27:31 by galemair          #+#    #+#             */
/*   Updated: 2018/11/05 16:34:00 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstappend(t_list *lst, t_list *to_add)
{
	while (*lst)
		*lst = (*lst)->next;
	*lst->next = *to_add;
}
