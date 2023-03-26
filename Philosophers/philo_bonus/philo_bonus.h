/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:13:26 by dmacmill          #+#    #+#             */
/*   Updated: 2022/06/26 18:15:15 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <semaphore.h>
# include <signal.h>
# include <limits.h>
# include <string.h>
# include <fcntl.h>

typedef struct s_all
{
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				tl_eat;
	int				must_die;
	long long int	t_start;
	int				philos_eat;
	sem_t			*forks;
	sem_t			*sem_print;
}	t_all;

typedef struct s_philo
{
	pid_t			fk_id;
	long long int	last_eat;
	int				index;
	int				count_eat;
	int				die;
	pthread_t		check;
	t_all			*all;
}	t_philo;

long long		current_time(void);
int				ft_atoi(char *str);
int				ft_initalize(int argc, char *argv[], t_all *all);
void			ft_error(char *str, t_philo *ptr);
int				initalize_philos(t_philo **philo, t_all *all);
void			ft_usleep(long long int ms, t_philo *philo);
int				crt_threads(t_philo *philo);
void			loop_philo(t_philo *philo);
void			*check_philos(void *info);
void			kill_all(t_philo *philo, int a);
#endif
