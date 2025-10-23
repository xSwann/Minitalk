/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slatrech <slatrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:41:03 by slatrech          #+#    #+#             */
/*   Updated: 2025/04/03 12:56:17 by slatrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <asm-generic/signal-defs.h>
#include "ft_printf.h"

volatile int	g_signal_received = 0;

void	ackhandler(int signum)
{
	(void)signum;
	g_signal_received = 1;
}

void	send_char(int pid, unsigned char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		g_signal_received = 0;
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (!g_signal_received)
			pause();
		i--;
	}
}

void	send_message(int pid, const char *message)
{
	while (*message)
		send_char(pid, *(message++));
	send_char(pid, '\0');
}

int	main(int argc, char **argv)
{
	int					pid;
	char				*message;
	struct sigaction	sa;

	if (argc != 3)
	{
		ft_printf("Usage: %s <PID_SERVEUR> Message\n", argv[0]);
		return (1);
	}
	message = argv[2];
	pid = atoi(argv[1]);
	if (pid == -1 || pid == 0)
	{
		ft_printf("Invalid PID");
		return (1);
	}
	sa.sa_handler = ackhandler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	send_message(pid, message);
	return (0);
}
