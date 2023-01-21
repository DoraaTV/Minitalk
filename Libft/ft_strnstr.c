/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:18:38 by thrio             #+#    #+#             */
/*   Updated: 2022/11/14 13:56:08 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*str;
	char	*str2;
	size_t	i;
	size_t	j;

	i = 0;
	str = (char *)big;
	str2 = (char *)little;
	if (str2[0] == '\0')
		return (str);
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		while (str[i + j] == str2[j] && len - i > j)
		{
			if (j + 1 == ft_strlen(little))
				return (str + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
