/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:38:00 by gafreire          #+#    #+#             */
/*   Updated: 2025/06/30 13:13:48 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_statistics
{
	unsigned int	nbr_philos;
	unsigned int	nbr_eats;
	unsigned int	time_eat;
	unsigned int	time_sleep;
	unsigned int	time_die;
	unsigned long	start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*death;
	int				is_dead;
}					t_statistics;

typedef struct s_philosopher
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	unsigned long	last_eat;
	pthread_mutex_t	eat_mutex;
	unsigned int	count_eat;
	t_statistics	*statistic;
}					t_philosopher;

void				execute_philo(t_statistics statistic,
						unsigned int must_eat);
// utils
unsigned int		ft_atoui(char *str);
unsigned long		get_time(void);
// init
void				start_forks(int nbr_philo, t_statistics *statistics);
void				start_philo(t_philosopher *philo, t_statistics *statistics);
void				start_threads(t_philosopher *philo);
// routine
void				*routine(void *arg);
void				*keeper_function(void *arg);
int					is_philo_dead(t_philosopher *philo);

int					one_philo(t_philosopher *philo);
void				smart_sleep(unsigned int duration, t_philosopher *philo);
void				*keeper_function(void *arg);

#endif