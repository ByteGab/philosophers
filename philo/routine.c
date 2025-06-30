/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:25:03 by gafreire          #+#    #+#             */
/*   Updated: 2025/06/30 11:28:23 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	check_philo(t_philosopher *philo)
{
	usleep(500);
	pthread_mutex_lock(&philo->eat_mutex);
	pthread_mutex_unlock(&philo->eat_mutex);
	if (one_philo(philo))
	{
		return (1);
	}
	if ((philo->id % 2) == 0)
		usleep(philo->statistic->time_eat * 1000 / 2);
	return (0);
}

int	take_forks_even(t_philosopher *philo)
{
	pthread_mutex_lock(philo->fork_left);
	if (is_philo_dead(philo) == 1)
	{
		pthread_mutex_unlock(philo->fork_left);
		return (1);
	}
	printf("%5ld %2d has taken a fork 🍴\n", (get_time()
			- philo->statistic->start_time), philo->id);
	pthread_mutex_lock(philo->fork_right);
	if (is_philo_dead(philo) == 1)
	{
		pthread_mutex_unlock(philo->fork_right);
		pthread_mutex_unlock(philo->fork_left);
		return (1);
	}
	printf("%5ld %2d has taken a fork 🍴\n", (get_time()
			- philo->statistic->start_time), philo->id);
	return (0);
}

int	take_forks_odd(t_philosopher *philo)
{
	pthread_mutex_lock(philo->fork_right);
	if (is_philo_dead(philo) == 1)
	{
		pthread_mutex_unlock(philo->fork_right);
		return (1);
	}
	printf("%5ld %2d has taken a fork 🍴\n", (get_time()
			- philo->statistic->start_time), philo->id);
	pthread_mutex_lock(philo->fork_left);
	if (is_philo_dead(philo) == 1)
	{
		pthread_mutex_unlock(philo->fork_right);
		pthread_mutex_unlock(philo->fork_left);
		return (1);
	}
	printf("%5ld %2d has taken a fork 🍴\n", (get_time()
			- philo->statistic->start_time), philo->id);
	return (0);
}

int	eat_and_sleep(t_philosopher *philo)
{
	printf("%5ld %2d is eating 🍝\n", (get_time()
			- philo->statistic->start_time), philo->id);
	pthread_mutex_lock(&philo->eat_mutex);
	philo->last_eat = get_time();
	pthread_mutex_unlock(&philo->eat_mutex);
	philo->count_eat++;
	smart_sleep(philo->statistic->time_eat, philo);
	pthread_mutex_unlock(philo->fork_right);
	pthread_mutex_unlock(philo->fork_left);
	if (is_philo_dead(philo) == 1)
	{
		return (1);
	}
	printf("%5ld %2d is sleeping 😴\n", (get_time()
			- philo->statistic->start_time), philo->id);
	smart_sleep(philo->statistic->time_sleep, philo);
	return (0);
}

void	*routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	if (check_philo(philo))
		return (NULL);
	while (!is_philo_dead(philo) && (philo->statistic->nbr_eats == 0
			|| philo->count_eat < philo->statistic->nbr_eats))
	{
		printf("%5ld %2d is thinking 💭\n", (get_time()
				- philo->statistic->start_time), philo->id);
		if (philo->id % 2 == 0)
		{
			if (take_forks_even(philo))
				return (NULL);
		}
		else
		{
			if (take_forks_odd(philo))
				return (NULL);
		}
		if (eat_and_sleep(philo))
			return (NULL);
	}
	return (NULL);
}
