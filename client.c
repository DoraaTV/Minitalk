/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <thrio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 07:17:59 by thrio             #+#    #+#             */
/*   Updated: 2023/02/01 18:03:27 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_status;

void	handler(int sig)
{
	if (sig == SIGUSR2)
		ft_printf("Data has been sent and received\n");
	else
		g_status = 1;
}

struct sigaction	helper(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sa.sa_handler = &handler;
	return (sa);
}

void	send(char **av, unsigned long int len)
{
	unsigned int	bit;

	while (len--)
	{
		bit = 0x80;
		while (bit)
		{
			if (*av[2] & bit)
			{
				if (kill(ft_atoi(av[1]), SIGUSR1) == -1)
					exit(1);
			}
			else
			{
				if (kill(ft_atoi(av[1]), SIGUSR2) == -1)
					exit(1);
			}
			while (g_status == 0)
				pause();
			g_status = 0;
			bit >>= 1;
		}
		av[2]++;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa;
	unsigned long int	len;

	g_status = 0;
	len = ft_strlen(av[2]) + 1;;
	if (ac != 3)
	{
		ft_printf("Wrong Argument\n");
		return (-1);
	}
	sa = helper();
	sigaction(SIGUSR2, &sa, 0);
	sigaction(SIGUSR1, &sa, 0);
	send(av, len);
	return (0);
}
