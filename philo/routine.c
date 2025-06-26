/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:25:03 by gafreire          #+#    #+#             */
/*   Updated: 2025/06/26 20:25:42 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	one_philo(t_philosopher *philo)
{
	if (philo->statistic->nbr_philos == 1)
	{
		pthread_mutex_lock(philo->fork_left);
		printf("%ld O filosofo %d colleu un garfo\n", (get_time()
				- philo->statistic->start_time), philo->id);
		usleep(philo->statistic->time_die * 1000);
		pthread_mutex_unlock(philo->fork_left);
		return (1);
	}
	else
		return (0);
}

void	*keeper_function(void *arg)
{
	unsigned int	i;
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	while (philo[0].statistic->is_dead != 1)
	{
		usleep(10000);
		i = 0;
		while (i < philo[0].statistic->nbr_philos)
		{
			if (get_time() - philo[i].last_eat > philo[0].statistic->time_die)
			{
				// imprimo
				printf("%ld O filosofo %d morreu 💀\n", (get_time()
						- philo->statistic->start_time), philo[i].id);
				// bloqueo a morte
				pthread_mutex_lock(philo[i].statistic->death);
				// Poño a morte en un
				philo[i].statistic->is_dead = 1;
				// desbloqueo a morte
				pthread_mutex_unlock(philo[i].statistic->death);
				return (NULL);
			}
			i++;
		}
	}
	return (NULL);
}

void	*routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	if (one_philo(philo))
	{
		return (NULL);
	}
	if ((philo->id % 2) == 0)
		usleep(philo->statistic->time_eat * 1000 / 2);
	while (!philo->statistic->is_dead && (philo->statistic->nbr_eats == 0
			|| philo->count_eat < philo->statistic->nbr_eats))
	{
		// pensar
		printf("%ld Think %d\n", (get_time() - philo->statistic->start_time),
			philo->id);
		// coller forks
		if (philo->id % 2 == 0)
		{
			pthread_mutex_lock(philo->fork_left);
			if (is_philo_dead(philo) == 1)
			{
				pthread_mutex_unlock(philo->fork_left);
				return (NULL);
			}
			printf("%ld O filosofo %d colleu un garfo\n", (get_time()
					- philo->statistic->start_time), philo->id);
			pthread_mutex_lock(philo->fork_right);
			if (is_philo_dead(philo) == 1)
			{
				pthread_mutex_unlock(philo->fork_right);
				return (NULL);
			}
			printf("%ld O filosofo %d colleu outro garfo\n", (get_time()
					- philo->statistic->start_time), philo->id);
		}
		else
		{
			pthread_mutex_lock(philo->fork_right);
			if (is_philo_dead(philo) == 1)
			{
				pthread_mutex_unlock(philo->fork_left);
				return (NULL);
			}
			printf("%ld O filosofo %d colleu un garfo\n", (get_time()
					- philo->statistic->start_time), philo->id);
			pthread_mutex_lock(philo->fork_left);
			if (is_philo_dead(philo) == 1)
			{
				pthread_mutex_unlock(philo->fork_right);
				return (NULL);
			}
			printf("%ld O filosofo %d colleu outro garfo\n", (get_time()
					- philo->statistic->start_time), philo->id);
		}
		// comer
		if (is_philo_dead(philo) == 1)
		{
			pthread_mutex_unlock(philo->fork_right);
			pthread_mutex_unlock(philo->fork_left);
			return (NULL);
		}
		printf("%ld O filosofo %d está comendo\n", (get_time()
				- philo->statistic->start_time), philo->id);
		philo->last_eat = get_time();
		philo->count_eat++;
		usleep(philo->statistic->time_eat * 1000);
		// se soltan no orden inverso porque e boa practica revisalo
		pthread_mutex_unlock(philo->fork_right);
		pthread_mutex_unlock(philo->fork_left);
		// dormir
		if (is_philo_dead(philo) == 1)
		{
			return (NULL);
		}
		printf("%ld O filosofo %d está durmindo\n", (get_time()
				- philo->statistic->start_time), philo->id);
		usleep(philo->statistic->time_sleep * 1000);
	}
	return (NULL);
}
