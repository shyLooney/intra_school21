/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:13:22 by dmacmill          #+#    #+#             */
/*   Updated: 2022/06/26 18:19:41 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long long	current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	ft_atoi(char *str)
{
	long int	num;
	int			i;

	num = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' || \
			str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] && num != -1)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			num = num * 10 + str[i] - '0';
		}
		else
			num = -1;
		if (num > 2147483647)
			num = -1;
		i++;
	}
	return (num);
}

int	ft_initalize(int argc, char *argv[], t_all *all)
{
	all->tl_eat = -1;
	if (argc > 4 && argc < 7)
	{
		all->n_philo = ft_atoi(argv[1]);
		all->t_die = ft_atoi(argv[2]);
		all->t_eat = ft_atoi(argv[3]);
		all->t_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			all->tl_eat = ft_atoi(argv[5]);
	}
	else
		return (-1);
	if (all->n_philo < 1 || all->t_die == -1 || all->t_eat == -1
		|| all->t_sleep == -1)
		return (-1);
	if (argc == 6 && all->tl_eat < 1)
		return (-1);
	return (0);
}

void	ft_error(char *str, t_philo *ptr)
{
	if (!ptr)
		free(ptr);
	printf("%s", str);
	exit(0);
}

void	ft_usleep(long long int ms, t_philo *philo)
{
	long long int	start;
	long long int	end;

	start = current_time();
	end = current_time();
	while (philo->all->must_die && end - start < ms)
	{
		usleep(500);
		end = current_time();
	}
}
