/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <thrio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:23:30 by thrio             #+#    #+#             */
/*   Updated: 2022/11/13 13:32:03 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*result;
	int		i;

	i = 0;
	result = NULL;
	while ((unsigned char)s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			result = (char *)s + i;
		i++;
	}
	if ((unsigned char)s[i] == (unsigned char)c)
		return ((char *)s + i);
	return (result);
}
