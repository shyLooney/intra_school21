/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initalize_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:13:30 by dmacmill          #+#    #+#             */
/*   Updated: 2022/06/28 17:12:49 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
		philo[i].die = 1;
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
		ft_error("Error malloc", NULL);
	sem_unlink("sem_print");
	sem_unlink("forks");
	all->forks = sem_open("forks", O_CREAT, 0644, all->n_philo);
	all->sem_print = sem_open("sem_print", O_CREAT, 0644, 1);
	if (all->forks <= 0 || all->sem_print <= 0)
		ft_error("Error: semaphore open error", *philo);
	set_data(*philo, all);
	return (0);
}

void	forks_wait(t_philo *philo)
{
	int	i;
	int	stat;

	i = 0;
	while (philo->all->n_philo > i)
	{
		waitpid(philo[i].fk_id, &stat, 0);
		if (stat)
			kill_all(philo, 1);
		i++;
	}
	sem_close(philo->all->forks);
	sem_close(philo->all->sem_print);
	sem_unlink("sem_print");
	sem_unlink("forks");
	free(philo);
}

int	crt_threads(t_philo *philo)
{
	int	i;

	i = 0;
	philo->all->t_start = current_time();
	while (philo->all->n_philo > i)
	{
		philo[i].fk_id = fork();
		philo[i].last_eat = current_time();
		if (philo[i].fk_id == 0)
			loop_philo(&philo[i]);
		usleep(100);
		i++;
	}
	forks_wait(philo);
	return (0);
}

void	kill_all(t_philo *philo, int a)
{
	t_philo	*arr;
	int		i;

	i = 0;
	arr = philo - philo->index;
	while (philo->all->n_philo > i)
	{
		if (arr[i].fk_id != 0 && arr[i].fk_id != philo->fk_id)
			kill(arr[i].fk_id, SIGKILL);
		i++;
	}
	if (a == 0)
		exit(1);
}
