/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:25:03 by gafreire          #+#    #+#             */
/*   Updated: 2025/06/28 22:26:45 by gafreire         ###   ########.fr       */
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

void	smart_sleep(unsigned int duration, t_philosopher *philo)
{
	unsigned long	start;

	start = get_time();
	while (!is_philo_dead(philo) && get_time() - start < duration)
		usleep(100); // duerme en pequeñas dosis
}

void	*keeper_function(void *arg)
{
	unsigned int	i;
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	while (philo[0].statistic->is_dead != 1)
	{
		usleep(1000);
		i = 0;
		while (i < philo[0].statistic->nbr_philos)
		{
			pthread_mutex_lock(&philo[i].eat_mutex);
			if (get_time() - philo[i].last_eat > philo[0].statistic->time_die)
			{
				printf("\033[1;36m%5ld\033[0m \033[1;35m%2d\033[0m \033[1;31m💀 died\033[0m\n",
					(get_time() - philo->statistic->start_time), philo->id);
				pthread_mutex_lock(philo[i].statistic->death);
				philo[i].statistic->is_dead = 1;
				pthread_mutex_unlock(philo[i].statistic->death);
				return (NULL);
			}
			pthread_mutex_unlock(&philo[i].eat_mutex);
			i++;
		}
	}
	return (NULL);
}

void	*routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	usleep(500);
	pthread_mutex_lock(&philo->eat_mutex);
	// philo->last_eat = get_time();
	pthread_mutex_unlock(&philo->eat_mutex);
	if (one_philo(philo))
	{
		return (NULL);
	}
	if ((philo->id % 2) == 0)
		usleep(philo->statistic->time_eat * 1000 / 2);
	while (!is_philo_dead(philo) && (philo->statistic->nbr_eats == 0
			|| philo->count_eat < philo->statistic->nbr_eats))
	{
		printf("\033[1;36m%5ld\033[0m \033[1;35m%2d\033[0m \033[1;34m💭 is thinking\033[0m\n",
			(get_time() - philo->statistic->start_time), philo->id);
		if (philo->id % 2 == 0)
		{
			pthread_mutex_lock(philo->fork_left);
			if (is_philo_dead(philo) == 1)
			{
				pthread_mutex_unlock(philo->fork_left);
				return (NULL);
			}
			printf("\033[1;36m%5ld\033[0m \033[1;35m%2d\033[0m \033[1;33m🍴 has taken a fork\033[0m\n",
				(get_time() - philo->statistic->start_time), philo->id);
			pthread_mutex_lock(philo->fork_right);
			if (is_philo_dead(philo) == 1)
			{
				pthread_mutex_unlock(philo->fork_right);
				pthread_mutex_unlock(philo->fork_left);
				return (NULL);
			}
			printf("\033[1;36m%5ld\033[0m \033[1;35m%2d\033[0m \033[1;33m🍴 has taken a fork\033[0m\n",
				(get_time() - philo->statistic->start_time), philo->id);
		}
		else
		{
			pthread_mutex_lock(philo->fork_right);
			if (is_philo_dead(philo) == 1)
			{
				pthread_mutex_unlock(philo->fork_left);
				return (NULL);
			}
			printf("\033[1;36m%5ld\033[0m \033[1;35m%2d\033[0m \033[1;33m🍴 has taken a fork\033[0m\n",
				(get_time() - philo->statistic->start_time), philo->id);
			pthread_mutex_lock(philo->fork_left);
			if (is_philo_dead(philo) == 1)
			{
				pthread_mutex_unlock(philo->fork_right);
				pthread_mutex_unlock(philo->fork_left);
				return (NULL);
			}
			printf("\033[1;36m%5ld\033[0m \033[1;35m%2d\033[0m \033[1;33m🍴 has taken a fork\033[0m\n",
				(get_time() - philo->statistic->start_time), philo->id);
		}
		if (is_philo_dead(philo) == 1)
		{
			pthread_mutex_unlock(philo->fork_right);
			pthread_mutex_unlock(philo->fork_left);
			return (NULL);
		}
		printf("\033[1;36m%5ld\033[0m \033[1;35m%2d\033[0m \033[1;32m🍝 is eating\033[0m\n",
			(get_time() - philo->statistic->start_time), philo->id);
		pthread_mutex_lock(&philo->eat_mutex);
		philo->last_eat = get_time();
		pthread_mutex_unlock(&philo->eat_mutex);
		philo->count_eat++;
		// usleep(philo->statistic->time_eat * 1000);
		smart_sleep(philo->statistic->time_eat, philo);
		pthread_mutex_unlock(philo->fork_right);
		pthread_mutex_unlock(philo->fork_left);
		if (is_philo_dead(philo) == 1)
		{
			return (NULL);
		}
		printf("\033[1;36m%5ld\033[0m \033[1;35m%2d\033[0m \033[1;34m😴 is sleeping\033[0m\n",
			(get_time() - philo->statistic->start_time), philo->id);
		// usleep(philo->statistic->time_sleep * 1000);
		smart_sleep(philo->statistic->time_sleep, philo);
	}
	return (NULL);
}
