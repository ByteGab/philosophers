/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:02:43 by gafreire          #+#    #+#             */
/*   Updated: 2025/06/30 09:25:18 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	free_resources(t_statistics *statistic, t_philosopher *philo)
{
	unsigned int	i;

	i = 0;
	while (i < statistic->nbr_philos)
	{
		pthread_mutex_destroy(&statistic->forks[i]);
		i++;
	}
	pthread_mutex_destroy(statistic->death);
	free(statistic->forks);
	free(statistic->death);
	free(philo);
}
int	init_resources(t_statistics *statistic, t_philosopher **philo)
{
	*philo = malloc(statistic->nbr_philos * sizeof(t_philosopher));
	if (!*philo)
		return (0);
	statistic->forks = malloc(statistic->nbr_philos * sizeof(pthread_mutex_t));
	if (!statistic->forks)
	{
		free(*philo);
		return (0);
	}
	statistic->death = malloc(sizeof(pthread_mutex_t));
	if (!statistic->death)
	{
		free(statistic->forks);
		free(*philo);
		return (0);
	}
	pthread_mutex_init(statistic->death, NULL);
	return (1);
}

void	execute_philo(t_statistics statistic, unsigned int must_eat)
{
	t_philosopher	*philo;
	pthread_t		keeper_thread;
	unsigned int	i;

	if (!init_resources(&statistic, &philo))
		return ;
	statistic.nbr_eats = must_eat;
	start_forks(statistic.nbr_philos, &statistic);
	statistic.start_time = get_time();
	start_philo(philo, &statistic);
	start_threads(philo);
	pthread_create(&keeper_thread, NULL, keeper_function, philo);
	pthread_join(keeper_thread, NULL);
	i = 0;
	while (i < statistic.nbr_philos)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	free_resources(&statistic, philo);
}
