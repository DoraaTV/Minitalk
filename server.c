/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <thrio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 07:18:03 by thrio             #+#    #+#             */
/*   Updated: 2023/01/22 13:22:26 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int	sig, siginfo_t *info, void *ptr1)
{
	(void)ptr1;
	if (sig == SIGUSR1)
		s_bits.symbol += s_bits.bit;
	s_bits.bit >>=1;
	if (!s_bits.bit)
	{
		if (!s_bits.symbol)
			ft_printf("\n");
		else
		{
			if (s_bits.symbol == '\0')
				printf("ici");
			ft_printf("%c", s_bits.symbol);
		}
		s_bits.bit = 0x80;
		s_bits.symbol = 0;
	}
	usleep(50);
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction sa;
	
	s_bits.symbol = 0;
	s_bits.bit = 0x80;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handler;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	ft_printf("Server PID : %d\n", getpid());
	while (1)
		pause();
}