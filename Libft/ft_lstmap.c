/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:28:33 by thrio             #+#    #+#             */
/*   Updated: 2022/11/18 16:01:08 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*cell;

	list = 0;
	if (!lst || !f)
		return (NULL);
	while ((lst))
	{
		cell = ft_lstnew((*f)(lst->content));
		if (!cell)
		{
			ft_lstclear(&list, del);
			return (NULL);
		}
		ft_lstadd_back(&list, cell);
		lst = lst->next;
	}
	return (list);
}
