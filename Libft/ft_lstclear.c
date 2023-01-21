/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:50:50 by thrio             #+#    #+#             */
/*   Updated: 2022/11/18 12:23:21 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*buf;

	if (lst)
	{
		while ((*lst))
		{
			buf = (*lst)->next;
			ft_lstdelone((*lst), del);
			(*lst) = buf;
		}
	}
}
