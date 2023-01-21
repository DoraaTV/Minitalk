/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:00:34 by thrio             #+#    #+#             */
/*   Updated: 2022/11/21 13:30:39 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		lst = lst -> next;
		len++;
	}
	return (len);
}


#include <stdio.h>
int	main(void)
{
	t_list	**lst;
	t_list	*new;

	lst = 0;
	new->content = (void *)5887;
	ft_lstadd_front((t_list **)lst, new);
	ft_lstadd_front((t_list **)lst, new);
	ft_lstadd_front((t_list **)lst, new);
	ft_lstadd_front((t_list **)lst, new);
	printf("%d\n", ft_lstsize((t_list *)lst));
	return (0);
}
