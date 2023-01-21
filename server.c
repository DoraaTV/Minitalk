/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <thrio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 07:18:03 by thrio             #+#    #+#             */
/*   Updated: 2023/01/21 18:27:46 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig, siginfo_t *lst, void *ptr1)
{
	static char c = 0xFF;
	static int	bits = 0;
	static int	pid = 0;
	static char	*s = 0;

	(void)ptr1;
	printf("%d", sig);
	if (lst->si_pid)
		pid = lst->si_pid;
	if (sig == SIGUSR1)
		c ^= 0x80 >> bits;
	else if (sig == SIGUSR2)
		c |= 0x80 >> bits;
	if (++bits == 8)
	{
		if (c)
			s = ft_straddc(s, c);
		else
		{
			ft_printf("%s", s);
			free(s);
		}
		bits = 0;
		c = 0xFF;
	}
	if (kill(pid, SIGUSR1) == -1)
	{
		ft_printf("Error\n");
		exit (1);
	}
}

int	main(void)
{
	struct sigaction sa;
	sigset_t	block_mask;
	
	sigemptyset(&block_mask);
	sigaddset(&block_mask, SIGINT);
	sigaddset(&block_mask, SIGQUIT);
	sa.sa_handler = 0;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_mask = block_mask;
	sa.sa_sigaction = handler;
	if (sigaction(SIGUSR1, &sa, NULL) != 0)
		exit(1);
	if (sigaction(SIGUSR2, &sa, NULL) != 0)
		exit(1);
	ft_printf("Server PID : %d\n", getpid());
	while (1)
		pause();
	return (0);
}