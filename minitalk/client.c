/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:00:02 by dmacmill          #+#    #+#             */
/*   Updated: 2022/03/05 18:23:24 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "ft_printf/ft_printf.h"

void	send_signal(int pid, char c)
{
	int	counter;

	counter = 8;
	while (counter--)
	{
		if ((c >> counter) & 1)
		{
			if (kill (pid, SIGUSR2) == -1)
				exit(0);
		}
		else
			if (kill (pid, SIGUSR1) == -1)
				exit(0);
		if (usleep(100))
			exit(0);
	}
}

void	send_line(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_signal(pid, str[i]);
		i++;
	}
}

void	receive_signal(int a)
{
	(void)a;
	ft_printf("Message received\n");
	exit(0);
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	signal(SIGUSR2, receive_signal);
	if (argc == 3)
		send_line(atoi(argv[1]), argv[2]);
	else
	{
		ft_printf("Error arguments");
		return (-1);
	}
	send_signal(atoi(argv[1]), 0);
	return (0);
}
