/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:37:00 by thrio             #+#    #+#             */
/*   Updated: 2022/11/18 11:32:44 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	size2;
	size_t	size3;

	size3 = ft_strlen(src);
	i = 0;
	j = 0;
	while (dest[j] != '\0' && j < size)
		j++;
	size2 = j;
	if (size == 0 || size <= size2)
		return (size3 + size);
	while (src[i] != '\0' && size - size2 - 1 > i)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	if (size2 < size)
		dest[j] = '\0';
	return (size2 + size3);
}
