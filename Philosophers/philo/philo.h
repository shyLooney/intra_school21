/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:13:26 by dmacmill          #+#    #+#             */
/*   Updated: 2022/06/20 15:31:11 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

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
	pthread_mutex_t	*forks;
	pthread_mutex_t	mut_print;
}	t_all;

typedef struct s_philo
{
	pthread_t		pt_id;
	pthread_mutex_t	*rf;
	pthread_mutex_t	*lf;
	long long int	last_eat;
	int				index;
	int				count_eat;
	t_all			*all;
}	t_philo;

long long		current_time(void);
int				ft_atoi(char *str);
int				ft_initalize(int argc, char *argv[], t_all *all);
int				ft_error(char *str, t_philo *ptr, pthread_mutex_t *ptr2);
int				initalize_philos(t_philo **philo, t_all *all);
void			ft_usleep(long long int ms, t_philo *philo);
int				crt_threads(t_philo *philo);
void			*loop_philo(void *info);
int				check_philos(t_philo *philo);

#endif