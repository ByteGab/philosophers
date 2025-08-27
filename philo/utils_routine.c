/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 11:24:57 by gafreire          #+#    #+#             */
/*   Updated: 2025/06/30 13:14:48 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

// int	one_philo(t_philosopher *philo)
// {
// 	if (philo->statistic->nbr_philos == 1)
// 	{
// 		pthread_mutex_lock(philo->fork_left);
// 		printf("%5ld %2d has taken a fork 🍴\n", (get_time()
// 				- philo->statistic->start_time), philo->id);
// 		usleep(philo->statistic->time_die * 1000);
// 		pthread_mutex_unlock(philo->fork_left);
// 		return (1);
// 	}
// 	else
// 		return (0);
// }

// void	smart_sleep(unsigned int duration, t_philosopher *philo)
// {
// 	unsigned long	start;

// 	start = get_time();
// 	while (!is_philo_dead(philo) && get_time() - start < duration)
// 		usleep(50);
// }

// void	*keeper_function(void *arg)
// {
// 	t_philosopher	*philo;
// 	unsigned int	i;
// 	unsigned int	done;

// 	philo = (t_philosopher *)arg;
// 	while (1)
// 	{
// 		usleep(100);
// 		i = 0;
// 		done = 0;
// 		while (i < philo[0].statistic->nbr_philos)
// 		{
// 			pthread_mutex_lock(&philo[i].eat_mutex);
// 			if (philo->statistic->nbr_eats
// 				&& philo[i].count_eat >= philo->statistic->nbr_eats)
// 			{
// 				done++;
// 				pthread_mutex_unlock(&philo[i].eat_mutex);
// 				i++;
// 				continue ;
// 			}
// 			if (get_time() - philo[i].last_eat > philo->statistic->time_die)
// 			{
// 				printf("%5ld %2d died 💀\n", get_time()
// 					- philo->statistic->start_time, philo[i].id);
// 				pthread_mutex_lock(philo[i].statistic->death);
// 				philo[i].statistic->is_dead = 1;
// 				pthread_mutex_unlock(philo[i].statistic->death);
// 				pthread_mutex_unlock(&philo[i].eat_mutex);
// 				return (NULL);
// 			}
// 			pthread_mutex_unlock(&philo[i].eat_mutex);
// 			i++;
// 		}
// 		if (philo->statistic->nbr_eats && done == philo->statistic->nbr_philos)
// 			return (NULL);
// 	}
// }

int	one_philo(t_philosopher *philo)
{
	if (philo->statistic->nbr_philos == 1)
	{
		pthread_mutex_lock(philo->fork_left);
		printf("%5ld %2d has taken a fork 🍴\n", (get_time()
				- philo->statistic->start_time), philo->id);
		usleep(philo->statistic->time_die * 1000);
		pthread_mutex_unlock(philo->fork_left);
		return (1);
	}
	return (0);
}

void	smart_sleep(unsigned int duration, t_philosopher *philo)
{
	unsigned long	start;

	start = get_time();
	while (!is_philo_dead(philo) && get_time() - start < duration)
		usleep(50);
}

/* ---- Helpers para mantener keeper_function corta ---- */

static int	is_philo_done(t_philosopher *p)
{
	int	done;

	if (!p->statistic->nbr_eats)
		return (0);
	pthread_mutex_lock(&p->eat_mutex);
	done = (p->count_eat >= p->statistic->nbr_eats);
	pthread_mutex_unlock(&p->eat_mutex);
	return (done);
}

static int	has_died_and_mark(t_philosopher *p)
{
	int	died;

	pthread_mutex_lock(&p->eat_mutex);
	died = (get_time() - p->last_eat > p->statistic->time_die);
	if (died)
	{
		printf("%5ld %2d died 💀\n", get_time() - p->statistic->start_time,
			p->id);
		pthread_mutex_lock(p->statistic->death);
		p->statistic->is_dead = 1;
		pthread_mutex_unlock(p->statistic->death);
	}
	pthread_mutex_unlock(&p->eat_mutex);
	return (died);
}

void	*keeper_function(void *arg)
{
	t_philosopher	*ph;
	unsigned int	i;
	unsigned int	done;

	ph = (t_philosopher *)arg;
	while (1)
	{
		i = 0;
		done = 0;
		usleep(100);
		while (i < ph[0].statistic->nbr_philos)
		{
			if (is_philo_done(&ph[i]))
			{
				done++;
				i++;
				continue ;
			}
			if (has_died_and_mark(&ph[i]))
				return (NULL);
			i++;
		}
		if (ph->statistic->nbr_eats && done == ph->statistic->nbr_philos)
			return (NULL);
	}
}
