/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:13:30 by dmacmill          #+#    #+#             */
/*   Updated: 2022/06/25 17:56:33 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_data(t_philo *philo, t_all *all)
{
	int	i;

	i = 0;
	while (i < all->n_philo)
	{
		philo[i].last_eat = 0;
		philo[i].all = all;
		philo[i].index = i;
		philo[i].count_eat = 0;
		if (i == 0)
		{
			philo[i].lf = &all->forks[i];
			philo[i].rf = &all->forks[all->n_philo - 1];
		}
		else
		{
			philo[i].lf = &all->forks[i];
			philo[i].rf = &all->forks[i - 1];
		}
		i++;
	}
}

int	initalize_philos(t_philo **philo, t_all *all)
{
	int	i;

	i = 0;
	all->must_die = 1;
	*philo = malloc(sizeof(t_philo) * all->n_philo);
	if (!philo)
		return (ft_error("Error malloc", NULL, NULL));
	all->forks = malloc(sizeof(pthread_mutex_t) * all->n_philo);
	if (!all->forks)
		return (ft_error("Error malloc", *philo, NULL));
	while (i < all->n_philo)
	{
		if (pthread_mutex_init(&all->forks[i], NULL))
			return (ft_error("Error mutex", *philo, all->forks));
		i++;
	}
	set_data(*philo, all);
	return (0);
}

int	crt_threads(t_philo *philo)
{
	int	i;

	i = 0;
	philo->all->t_start = current_time();
	while (philo->all->n_philo > i)
	{
		philo[i].last_eat = current_time();
		if (pthread_create(&philo[i].pt_id, NULL, &loop_philo, &philo[i]) != 0)
			return (ft_error("Error thread", philo, philo->all->forks));
		pthread_detach(philo[i].pt_id);
		usleep(50);
		i++;
	}
	check_philos(philo);
	i = 0;
	while (i < philo->all->n_philo)
	{
		pthread_mutex_destroy(&philo->all->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&philo->all->mut_print);
	return (0);
}
