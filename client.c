/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <thrio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 07:17:59 by thrio             #+#    #+#             */
/*   Updated: 2023/01/22 13:19:05 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void casesuccess(int sig)
{
	(void)sig;
	ft_printf("Data sent and received\n");
	exit(0);
}

void handler(int sig)
{
	(void)sig;
	s_bits.bit >>= 1;
	ft_printf("Bit received\n");
}

struct sigaction	options(unsigned long int *len, char **av)
{
	struct sigaction sa;
	
	*len = ft_strlen(av[2]) + 1;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sa.sa_handler = &handler;
	return (sa);
}

int	main(int ac, char **av)
{
	struct sigaction	sa;
	unsigned long int	len;

	if (ac != 3)
	{
		ft_printf("Wrong Argument\n");
		return (-1);
	}
	sa = options(&len, av);
	sigaction(SIGUSR1, &sa, 0);
	while (len--)
	{
		s_bits.bit = 0x80;
		while(s_bits.bit)
		{
			if (*av[2] & s_bits.bit)
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
			usleep(50);
		}
		av[2]++;
	}
	return (0);
}
