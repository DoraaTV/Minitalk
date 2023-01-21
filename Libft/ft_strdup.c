/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:32:34 by thrio             #+#    #+#             */
/*   Updated: 2022/11/17 14:45:55 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*sortie;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(s);
	sortie = (char *) malloc(sizeof(char) * (size + 1));
	while (s[i])
	{
		sortie[i] = s[i];
		i++;
	}
	sortie[i] = '\0';
	return (sortie);
}
