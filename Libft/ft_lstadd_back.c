/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:06:20 by thrio             #+#    #+#             */
/*   Updated: 2022/11/18 12:23:04 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*buf;

	if (!lst || !new)
		return ;
	if (lst && (*lst))
	{
		buf = (*lst);
		while (buf->next)
			(buf) = (buf)->next;
		buf->next = new;
	}
	else
		*lst = new;
}
