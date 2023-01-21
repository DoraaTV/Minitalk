/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:49:45 by thrio             #+#    #+#             */
/*   Updated: 2022/11/17 14:42:58 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(const char s, const char *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	size_t		j;
	char		*res;

	i = 0;
	j = ft_strlen(s1);
	while (s1[i] && check(s1[i], set))
	{
		i++;
	}
	while (j > 0 && check(s1[j - 1], set) && i < j)
	{
		j--;
	}	
	res = malloc(sizeof(char) * ((j - i) + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1 + i, (j - i) + 1);
	return (res);
}

static int	check(const char s, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s)
			return (1);
		i++;
	}
	return (0);
}
