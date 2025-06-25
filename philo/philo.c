/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:02:43 by gafreire          #+#    #+#             */
/*   Updated: 2025/06/25 12:51:04 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	simple_philo(unsigned int philos, unsigned int die, unsigned int eat,
		unsigned int sleep)
{
	t_statistics	statistic;
	t_philosopher	*philo;
	pthread_t		keeper_thread;
	unsigned int	i;

	// creo os datos
	// t_philosopher philos;
	if (philos == 0 || die == 0 || eat == 0 || sleep == 0)
		printf("Os argumetos deberian ser maiores que cero\n");
	statistic.nbr_philos = philos;
	statistic.time_die = die; // ten que ser xa en milisegundos ?
	statistic.time_eat = eat;
	statistic.time_sleep = sleep;
	// deber ter menos de cen numeros os filos? e mentira e na folla de correciones
	// deber ter menos de doscentos numeros as demais variables? e mentira e na folla de correciones
	// empezo os filosofos
	philo = malloc(philos * sizeof(t_philosopher));
	if (!philo)
	{
		// liberalo
		// return (1); // cambialo
	}
	statistic.forks = malloc(philos * sizeof(pthread_mutex_t));
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
	statistic.nbr_eats = 0; // cambialo
	start_forks(philos, &statistic);
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
void	advanced_philo(unsigned int philos, unsigned int die, unsigned int eat,
		unsigned int sleep, unsigned int must_eat)
{
	t_statistics	statistic;
	t_philosopher	*philo;

	// creo os datos
	if (philos == 0 || die == 0 || eat == 0 || sleep == 0 || must_eat == 0)
		printf("Os argumetos deberian ser maiores que cero\n");
	statistic.nbr_philos = philos;
	statistic.time_die = die; // ten que ser xa en milisegundos ?
	statistic.time_eat = eat;
	statistic.time_sleep = sleep;
	statistic.nbr_eats = must_eat;
	// empezo os filosofos
	philo = malloc(philos * sizeof(t_philosopher));
	if (!philo)
	{
		// liberar todo
		// return (1); // cambialo
	}
	statistic.forks = malloc(philos * sizeof(pthread_mutex_t));
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
	start_forks(philos, &statistic);
	start_philo(philo, &statistic);
	statistic.start_time = get_time();
	printf("%lu\n", statistic.start_time);
	start_threads(philo);
	// pthread_create(&keeper_thread, NULL, keeper_function, philo);
	// pthread_join(keeper_thread,NULL);
}
