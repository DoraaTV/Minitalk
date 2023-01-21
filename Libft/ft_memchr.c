/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:45:01 by thrio             #+#    #+#             */
/*   Updated: 2022/11/13 12:10:22 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	f;

	f = (unsigned char) c;
	str = (unsigned char *)s;
	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (str[i] == f)
			return (str + i);
		i++;
	}
	return (0);
}
