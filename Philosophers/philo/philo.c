/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:13:19 by dmacmill          #+#    #+#             */
/*   Updated: 2022/06/25 17:56:57 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_philo(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->all->mut_print);
	if (philo->all->must_die)
		printf("%lld	%d	%s\n", current_time() - philo->all->t_start,
			philo->index + 1, str);
	pthread_mutex_unlock(&philo->all->mut_print);
}

int	check_philos(t_philo *philo)
{
	int	i;

	while (philo->all->must_die)
	{
		i = 0;
		philo->all->philos_eat = 1;
		while (i < philo->all->n_philo && philo->all->must_die)
		{
			if (current_time() - philo[i].last_eat > philo->all->t_die)
			{
				pthread_mutex_lock(&philo->all->mut_print);
				printf("%lld	%d	%s\n", current_time() - philo->all->t_start,
					philo->index + 1, "died");
				philo->all->must_die = 0;
				break ;
			}
			if (philo->all->tl_eat != -1
				&& philo[i].count_eat < philo->all->tl_eat)
				philo->all->philos_eat = 0;
			i++;
		}
		if (philo->all->tl_eat != -1 && philo->all->philos_eat)
			philo->all->must_die = 0;
	}
	return (0);
}

void	take_fork(t_philo *philo)
{
	if (philo->index != 0)
	{
		pthread_mutex_lock(philo->rf);
		print_philo(philo, "has taken fork");
		pthread_mutex_lock(philo->lf);
		print_philo(philo, "has taken fork");
	}
	else
	{
		pthread_mutex_lock(philo->lf);
		print_philo(philo, "has taken fork");
		pthread_mutex_lock(philo->rf);
		print_philo(philo, "has taken fork");
	}
}

void	*loop_philo(void *info)
{
	t_philo	*philo;

	philo = (t_philo *)info;
	while (philo->all->must_die)
	{
		print_philo(philo, "is thinking");
		take_fork(philo);
		print_philo(philo, "has eating");
		ft_usleep(philo->all->t_eat, philo);
		philo->last_eat = current_time();
		if (philo->all->must_die)
			philo->count_eat++;
		pthread_mutex_unlock(philo->lf);
		pthread_mutex_unlock(philo->rf);
		print_philo(philo, "is sleeping");
		ft_usleep(philo->all->t_sleep, philo);
	}
	return (NULL);
}

int	main(int argc, char *argv[])
{
	t_all	all;
	t_philo	*philo;

	if (pthread_mutex_init(&all.mut_print, NULL))
		return (0);
	if (ft_initalize(argc, argv, &all) == -1)
		return (ft_error("Error arguments\n", NULL, NULL));
	if (initalize_philos(&philo, &all) == -1)
		return (0);
	crt_threads(philo);
	free(philo);
	free(all.forks);
	return (0);
}
