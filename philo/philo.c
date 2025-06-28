/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:02:43 by gafreire          #+#    #+#             */
/*   Updated: 2025/06/28 22:14:42 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	simple_philo(t_statistics statistic)
{
	t_philosopher	*philo;
	pthread_t		keeper_thread;
	unsigned int	i;

	// t_statistics	statistic;
	// creo os datos
	// t_philosopher philos;
	if (statistic.nbr_philos == 0 || statistic.time_die == 0
		|| statistic.time_eat == 0 || statistic.time_sleep == 0)
		printf("Os argumetos deberian ser maiores que cero\n");
	// empezo os filosofos
	philo = malloc(statistic.nbr_philos * sizeof(t_philosopher));
	if (!philo)
	{
		// liberalo
		// return (1); // cambialo
	}
	//memset(philo, 0, statistic.nbr_philos * sizeof(t_philosopher));
	statistic.forks = malloc(statistic.nbr_philos * sizeof(pthread_mutex_t));
	if (!statistic.forks)
	{
		// liberalo
		// return (1); // cambialo
	}
	//memset(statistic.forks, 0, statistic.nbr_philos * sizeof(pthread_mutex_t));
	statistic.death = malloc(sizeof(pthread_mutex_t));
	if (!statistic.forks)
	{
		// liberalo
		// return (1); // cambialo
	}
	//memset(statistic.death, 0, statistic.nbr_philos * sizeof(pthread_mutex_t));
	pthread_mutex_init(statistic.death, NULL);
	statistic.nbr_eats = 0; // cambialo
	start_forks(statistic.nbr_philos, &statistic);
	statistic.start_time = get_time();
	start_philo(philo, &statistic);
	printf("%lu\n", statistic.start_time);
	start_threads(philo);
	pthread_create(&keeper_thread, NULL, keeper_function, philo);
	pthread_join(keeper_thread, NULL);
	i = 0;
	while (i < statistic.nbr_philos)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
}
void	advanced_philo(t_statistics statistic, unsigned int must_eat)
{
	t_philosopher	*philo;

	// t_statistics	statistic;
	// creo os datos
	if (statistic.nbr_philos == 0 || statistic.time_die == 0
		|| statistic.time_eat == 0 || statistic.time_sleep == 0)
		// cinco argumentos podo?
		printf("Os argumetos deberian ser maiores que cero\n");
	// statistic.nbr_philos = philos;
	// statistic.time_die = die; // ten que ser xa en milisegundos ?
	// statistic.time_eat = eat;
	// statistic.time_sleep = sleep;
	statistic.nbr_eats = must_eat;
	// empezo os filosofos
	philo = malloc(statistic.nbr_philos * sizeof(t_philosopher));
	if (!philo)
	{
		// liberar todo
		// return (1); // cambialo
	}
	statistic.forks = malloc(statistic.nbr_philos * sizeof(pthread_mutex_t));
	if (!statistic.forks)
	{
		// liberalo
		// return (1); // cambialo
	}
	statistic.death = malloc(sizeof(pthread_mutex_t));
	if (!statistic.forks)
	{
		// liberalo
		// return (1); // cambialo
	}
	pthread_mutex_init(statistic.death, NULL);
	start_forks(statistic.nbr_philos, &statistic);
	statistic.start_time = get_time();
	start_philo(philo, &statistic);
	statistic.start_time = get_time();
	printf("%lu\n", statistic.start_time);
	start_threads(philo);
	// pthread_create(&keeper_thread, NULL, keeper_function, philo);
	// pthread_join(keeper_thread,NULL);
}
