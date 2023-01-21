/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:52:49 by thrio             #+#    #+#             */
/*   Updated: 2022/11/16 15:55:20 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nbr;
	char		mdle1;

	nbr = n;
	if (nbr == -2147483647)
	{
		write(fd, &"-2147483647", 11);
		return ;
	}
	if (nbr < 0)
	{
		write(fd, &"-", 1);
		nbr = -nbr;
	}
	if (nbr > 9)
		ft_putnbr_fd(nbr / 10, fd);
	mdle1 = nbr % 10 + 48;
	write(fd, &mdle1, 1);
}
