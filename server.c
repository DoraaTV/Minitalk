/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrio <thrio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 07:18:03 by thrio             #+#    #+#             */
/*   Updated: 2023/02/01 18:05:14 by thrio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_straddc_first(char c)
{
	char	*add;

	add = (char *)malloc(sizeof(char) * 2);
	if (!add)
		return (NULL);
	add[0] = c;
	add[1] = '\0';
	return (add);
}

char	*ft_straddc(char *str, char c)
{
	char	*add;
	int		i;

	if (!c)
		return (NULL);
	if (!str)
		return (ft_straddc_first(c));
	add = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!add)
	{
		free(str);
		return (NULL);
	}
	i = -1;
	while (str[++i])
		add[i] = str[i];
	free(str);
	add[i++] = c;
	add[i] = '\0';
	return (add);
}

void	handler(int sig, siginfo_t *info, void *ptr1)
{
	static char			*message;
	static unsigned int	bit = 0x80;
	static char			symbol = 0;

	(void)ptr1;
	if (sig == SIGUSR1)
		symbol += bit;
	bit >>= 1;
	if (!bit)
	{
		if (!symbol)
		{
			ft_printf("%s\n", message);
			kill(info->si_pid, SIGUSR2);
			free(message);
			message = 0;
		}
		else
			message = ft_straddc(message, symbol);
		bit = 0x80;
		symbol = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handler;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	ft_printf("Server PID : %d\n", getpid());
	while (1)
		continue ;
}
