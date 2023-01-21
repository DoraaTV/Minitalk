/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <thrio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 07:17:59 by thrio             #+#    #+#             */
/*   Updated: 2023/01/21 18:30:24 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	error(char *str)
{
	ft_printf("%s\n", str);
	exit (1);
}

void	casesuccess(int sig)
{
	(void)sig;
	ft_printf("Data has been sent and received");
}

void handler(int pid, char *message)
{
	uint8_t	c;

	c = 1 << 6;
	while (*message)
	{
		while (c)
		{
			if (*message & c)
			{
				if (kill(pid, SIGUSR1) == -1)
					error("PID is wrong");
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					error("PID is wrong");
			}
			c >>= 1;
			usleep(600);
		}
		++message;
	}
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		ft_printf("Wrong arguments");
		return (1);
	}
	signal(SIGUSR1, casesuccess);
	handler(ft_atoi(av[1]), av[2]);
	return (0);
}
