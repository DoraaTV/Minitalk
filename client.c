/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <thrio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 07:17:59 by thrio             #+#    #+#             */
/*   Updated: 2023/02/03 15:26:32 by thrio            ###   ########.fr       */
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

void	send(char **av, unsigned long int len, int pid)
{
	unsigned int	bit;

	while (len--)
	{
		bit = 0x80;
		while (bit)
		{
			if (*av[2] & bit)
			{
				if (kill(pid, SIGUSR1) == -1)
					exit(1);
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
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

int	parse_arg(char *av)
{
	int	pid;
	int	i;

	i = 0;
	while (av[i])
	{
		if (!ft_isdigit(av[i]))
			return (0);
		i++;
	}
	pid = ft_atoi(av);
	if (pid < 1 || pid > 41943043)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	struct sigaction	sa;
	int					pid;
	unsigned long int	len;

	g_status = 0;
	if (ac != 3)
	{
		ft_printf("Wrong Argument\n");
		return (-1);
	}
	len = ft_strlen(av[2]) + 1;
	if (parse_arg(av[1]) == 0)
		return (0);
	pid = ft_atoi(av[1]);
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sa.sa_handler = &handler;
	sigaction(SIGUSR2, &sa, 0);
	sigaction(SIGUSR1, &sa, 0);
	send(av, len, pid);
	return (0);
}
