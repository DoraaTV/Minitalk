/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:01:54 by thrio             #+#    #+#             */
/*   Updated: 2022/11/13 15:00:49 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str;
	unsigned char	*str2;
	size_t			i;

	i = 0;
	str = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (str[i] == str2[i] && i < n)
	{
			i++;
	}
	if (i == n)
		return ((int)str[i - 1] - (int)str2[i - 1]);
	return ((int)str[i] - (int)str2[i]);
}
