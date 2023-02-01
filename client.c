/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <thrio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 07:17:59 by thrio             #+#    #+#             */
/*   Updated: 2023/02/01 14:26:49 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig)
{
	if (sig == SIGUSR2)
		ft_printf("Data has been sent and received\n");
	else
		g_bits.bit >>= 1;
}

struct sigaction	helper(char **av)
{
	struct sigaction	sa;

	g_bits.len = ft_strlen(av[2]) + 1;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sa.sa_handler = &handler;
	return (sa);
}

void	send(char **av)
{
	while (g_bits.len--)
	{
		g_bits.bit = 0x80;
		while (g_bits.bit)
		{
			if (*av[2] & g_bits.bit)
			{
				if (kill(ft_atoi(av[1]), SIGUSR1) == -1)
					exit(1);
			}
			else
			{
				if (kill(ft_atoi(av[1]), SIGUSR2) == -1)
					exit(1);
			}
			pause();
			usleep(75);
		}
		av[2]++;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	if (ac != 3)
	{
		ft_printf("Wrong Argument\n");
		return (-1);
	}
	sa = helper(av);
	sigaction(SIGUSR2, &sa, 0);
	sigaction(SIGUSR1, &sa, 0);
	send(av);
	return (0);
}
