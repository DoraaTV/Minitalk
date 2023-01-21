/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:55:15 by thrio             #+#    #+#             */
/*   Updated: 2022/11/17 19:03:36 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(char const *s, char c)
{
	size_t	i;
	size_t	counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			counter++;
			while (s[i] && c != s[i])
				i++;
		}
		else
			i++;
	}
	return (counter);
}

static size_t	lettercount(const char *s, char c, size_t i)
{
	size_t	size;

	size = 0;
	while (s[i] && s[i] != c)
	{
		size++;
		i++;
	}
	return (size);
}

static void	*dofree(char **res, int j)
{
	while (j-- > 0)
		free(res[j]);
	free(res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**res;
	size_t	nb_mot;
	size_t	size;

	i = 0;
	j = -1;
	nb_mot = count_word(s, c);
	res = (char **)malloc(sizeof(char *) * (nb_mot + 1));
	if (!res)
		return (NULL);
	while (++j < nb_mot)
	{
		while (s[i] == c)
			i++;
		size = lettercount(s, c, i);
		res[j] = ft_substr(s, i, size);
		if (!res[j])
			return (dofree(res, j));
		i += size;
	}
	res[j] = 0;
	return (res);
}
