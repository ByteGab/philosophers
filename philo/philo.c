/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:02:43 by gafreire          #+#    #+#             */
/*   Updated: 2025/06/13 17:30:48 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

// cambiar segundos y micro a milisegundos
void	simple_philo(unsigned int philos, unsigned int die, unsigned int eat,
		unsigned int sleep)
{
	t_statistics	statistic;
	t_philosopher	*philo;

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
		return (1); // cambialo
	}
	statistic.forks = malloc(philos * sizeof(pthread_mutex_t));
	if (!statistic.forks)
	{
		// liberalo
		return (1); // cambialo
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
		return (1); // cambialo
	}
	statistic.forks = malloc(philos * sizeof(pthread_mutex_t));
	if (!statistic.forks)
	{
		// liberalo
		return (1); // cambialo
	}
	start_forks(philos, &statistic);
}

void	start_forks(int nbr_philo, t_statistics *statistics)
		// punteiro para que asi o cambio no queda en local
{
	int i;

	i = 0;

	while (i < nbr_philo)
	{
		pthread_mutex_init(&statistics->forks[i], NULL);
		i++;
	}
}

void	start_philo(t_philosopher *philo, t_statistics *statistics)
{
	int i;

	i = 0;
}