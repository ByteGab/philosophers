/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:25:03 by gafreire          #+#    #+#             */
/*   Updated: 2025/06/23 19:28:04 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*keeper_function(void *arg)
{
	int				i;
	t_philosopher	*philo;

	
	philo = (t_philosopher *)arg;
	while (philo[0].statistic->is_dead != 1)
	{
		usleep(1000);
		i = 0;
		while (i < philo[0].statistic->nbr_philos)
		{
			if (get_time() - philo[i].last_eat > philo[0].statistic->time_die)
			{
				// imprimo
				printf("O filosofo %d morreu 💀\n", philo[i].id);
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
	t_philosopher *philo;

	philo = (t_philosopher *)arg;
	while (!philo->statistic->is_dead && (philo->statistic->nbr_eats == 0
			|| philo->count_eat < philo->statistic->nbr_eats))
	{
		// pensar
		printf("Think\n");
		// coller forks
		if (philo->id % 2 == 0)
		{
			pthread_mutex_lock(philo->fork_left);
			printf("O filosofo %d colleu un garfo\n", philo->id);
			pthread_mutex_lock(philo->fork_right);
			printf("O filosofo %d colleu outro garfo\n", philo->id);
		}
		else
		{
			pthread_mutex_lock(philo->fork_right);
			printf("O filosofo %d colleu un garfo\n", philo->id);
			pthread_mutex_lock(philo->fork_left);
			printf("O filosofo %d colleu outro garfo\n", philo->id);
		}
		// comer
		printf("O filosofo %d está comendo\n", philo->id);
		philo->last_eat = get_time();
		philo->count_eat++;
		usleep(philo->statistic->time_eat * 1000);
		// se soltan no orden inverso porque e boa practica revisalo
		pthread_mutex_unlock(philo->fork_right);
		pthread_mutex_unlock(philo->fork_left);
		// dormir
		printf("O filosofo %d está durmindo\n", philo->id);
		usleep(philo->statistic->time_sleep * 1000);
	}
	return (NULL);
}