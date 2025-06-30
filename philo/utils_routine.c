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
	else
		return (0);
}

void	smart_sleep(unsigned int duration, t_philosopher *philo)
{
	unsigned long	start;

	start = get_time();
	while (!is_philo_dead(philo) && get_time() - start < duration)
		usleep(100);
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
				printf("%5ld %2d died 💀\n", (get_time()
						- philo->statistic->start_time), philo->id);
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
