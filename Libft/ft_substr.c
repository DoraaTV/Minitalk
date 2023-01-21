/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:04:42 by thrio             #+#    #+#             */
/*   Updated: 2022/11/14 18:17:54 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	size_t			i;
	size_t			j;

	j = 0;
	i = start;
	if (start > ft_strlen(s))
		res = malloc(sizeof(char));
	else if (len < ft_strlen(s + i))
		res = malloc(sizeof(char) * (len + 1));
	else
		res = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	if (!res)
		return (NULL);
	while (!(start > ft_strlen(s)) && s[i] && j < len)
	{
		res[j] = s[i];
		i++;
		j++;
	}
	res[j] = '\0';
	return (res);
}
