/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:13:19 by dmacmill          #+#    #+#             */
/*   Updated: 2022/06/26 18:15:32 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_philo(t_philo *philo, char *str)
{
	sem_wait(philo->all->sem_print);
	if (philo->all->must_die)
		printf("%lld %d %s\n", current_time() - philo->all->t_start,
			philo->index + 1, str);
	sem_post(philo->all->sem_print);
}

void	*check_philos(void *info)
{
	t_philo	*philo;

	philo = (t_philo *)info;
	while (philo->die)
	{
		usleep(500);
		if (current_time() - philo->last_eat > philo->all->t_die)
		{
			sem_wait(philo->all->sem_print);
			printf("%lld %d %s\n", current_time() - philo->all->t_start,
				philo->index + 1, "died");
			philo->die = 0;
			kill_all(philo, 0);
		}
		if (philo->all->tl_eat != -1 && philo->count_eat == philo->all->tl_eat)
		{
			philo->die = 0;
		}
	}
	return (0);
}

void	loop_philo(t_philo *philo)
{
	if (pthread_create(&philo->check, NULL, &check_philos, philo) != 0)
		ft_error("Error thread", NULL);
	pthread_detach(philo->check);
	while (philo->die)
	{
		print_philo(philo, "is thinking");
		sem_wait(philo->all->forks);
		print_philo(philo, "has taken a fork");
		sem_wait(philo->all->forks);
		print_philo(philo, "has taken a fork");
		print_philo(philo, "is eating");
		ft_usleep(philo->all->t_eat, philo);
		philo->last_eat = current_time();
		philo->count_eat++;
		print_philo(philo, "is sleeping");
		sem_post(philo->all->forks);
		sem_post(philo->all->forks);
		ft_usleep(philo->all->t_sleep, philo);
	}
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_all	all;
	t_philo	*philo;

	if (ft_initalize(argc, argv, &all) == -1)
		ft_error("Error arguments\n", NULL);
	if (initalize_philos(&philo, &all) == -1)
		return (0);
	crt_threads(philo);
	return (0);
}
