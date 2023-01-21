/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <thrio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:35:35 by thrio             #+#    #+#             */
/*   Updated: 2023/01/21 07:47:55 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;
	size_t	mult;

	mult = nmemb * size;
	if (nmemb <= 0 || size <= 0)
		return (malloc(0));
	if (size != mult / nmemb)
		return (NULL);
	res = (char *)malloc(size * nmemb);
	if (!res)
		exit(EXIT_FAILURE);
	res = ft_memset(res, 0, nmemb * size);
	return (res);
}
