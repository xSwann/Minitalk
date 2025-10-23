/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slatrech <slatrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:40:56 by slatrech          #+#    #+#             */
/*   Updated: 2025/04/03 12:48:42 by slatrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"
#include <aio.h>

volatile int	g_received_bit = 0;

void	make_buffer_empty(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		buffer[i] = 0;
		i++;
	}
}

pid_t	buffer_filler(char c, pid_t client_pid)
{
	static char	buffer[100000];
	static int	i;

	if (c == '\0')
	{
		i = 0;
		while (buffer[i])
		{
			write(1, &buffer[i], 1);
			i++;
		}
		i = 0;
		make_buffer_empty(buffer);
		write(1, "\n", 1);
		i = 0;
		client_pid = 0;
	}
	else
	{
	buffer[i] = c;
	i++;
	}
	return (client_pid);
}

void	signalhandler(int signal, siginfo_t *info, void *context)
{
	static unsigned char	c = 0;
	static int				bit_position = 7;
	static pid_t			client_pid = 0;

	(void)context;
	if (client_pid == 0 || client_pid != info->si_pid)
	{
		client_pid = info->si_pid;
		c = 0;
		bit_position = 7;
	}
	if (signal == SIGUSR1)
		g_received_bit = 0;
	else if (signal == SIGUSR2)
		g_received_bit = 1;
	c |= (g_received_bit << bit_position);
	bit_position--;
	if (bit_position < 0)
	{
		client_pid = buffer_filler(c, client_pid);
		c = 0;
		bit_position = 7;
	}
	usleep(100);
	kill (info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = signalhandler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Serveur PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
