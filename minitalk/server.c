/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:00:13 by dmacmill          #+#    #+#             */
/*   Updated: 2022/03/05 18:25:42 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "ft_printf/ft_printf.h"

int	len_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

void	catch(int sig, siginfo_t *info, void *context)
{
	static int	byte;
	static int	digit;
	char		c;

	(void)context;
	if (sig == SIGUSR2)
		byte += 1 << (7 - digit);
	digit++;
	if (digit == 8)
	{
		if (!byte)
		{
			kill(info->si_pid, SIGUSR2);
			write(1, "\n\n", 2);
		}
		else
		{
			c = byte;
			write(1, &c, 1);
		}
		digit = 0;
		byte = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = catch;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR2, &sa, NULL) == -1
		|| sigaction(SIGUSR1, &sa, NULL) == -1)
		return (-1);
	ft_printf("\n%d\n\n", getpid());
	while (1)
		pause();
	return (0);
}
