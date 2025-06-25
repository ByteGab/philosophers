/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:14:56 by gafreire          #+#    #+#             */
/*   Updated: 2025/06/25 13:41:44 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

// punteiro para que asi o cambio no queda en local
void	start_forks(int nbr_philo, t_statistics *statistics)
{
	int	i;

	i = 0;
	while (i < nbr_philo)
	{
		// if (pthread_mutex_init(&statistics->forks[i], NULL != 0))
		// {
		// 	while (i >= 0)
		// 	{
		// 		pthread_mutex_destroy(&statistics->forks[i]);
		// 		i--;
		// 	}
		// 	// free
		// 	//return (NULL);
		// 	return ;
		//}
		pthread_mutex_init(&statistics->forks[i], NULL);
		i++;
	}
}

void	start_philo(t_philosopher *philo, t_statistics *statistics)
{
	unsigned int	i;

	i = 0;
	while (i < statistics->nbr_philos)
	{
		philo[i].id = i;
		philo[i].fork_left = &statistics->forks[i];
		philo[i].fork_right = &statistics->forks[(i + 1)
			% statistics->nbr_philos];
		// volta circular
		philo[i].count_eat = 0;
		philo[i].last_eat = statistics->start_time;
		philo[i].statistic = statistics;
        philo[i].statistic->is_dead = 0;
		i++;
	}
	i = 0;
	while (i < statistics->nbr_philos)
	{
		printf("Id %d, Fork Left %p , Fork Rigth %p , Eat %d, Last Eat %lu\n",
			philo[i].id, philo[i].fork_left, philo[i].fork_right,
			philo[i].count_eat, philo[i].last_eat);
		i++;
	}
}

void	start_threads(t_philosopher *philo)
{
	unsigned int	i;

	i = 0;
	while (i < philo->statistic->nbr_philos)
	{
		pthread_create(&philo[i].thread, NULL, routine, &philo[i]);
		i++;
	}
}
