/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:02:43 by gafreire          #+#    #+#             */
/*   Updated: 2025/06/21 19:17:29 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

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
	int	i;

	i = 0;
	while (i < philo->statistic->nbr_philos)
	{
		pthread_create(&philo[i].thread, NULL, routine, &philo[i]);
		i++;
	}
}

unsigned int	get_time(void)
{
	struct timeval	current_time;
	long			time;

	time = 0;
	gettimeofday(&current_time, NULL);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}
// cambiar segundos y micro a milisegundos
void	simple_philo(unsigned int philos, unsigned int die, unsigned int eat,
		unsigned int sleep)
{
	t_statistics	statistic;
	t_philosopher	*philo;
	pthread_t keeper_thread;

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
	start_forks(philos, &statistic);
	start_philo(philo, &statistic);
	statistic.start_time = get_time();
	printf("%lu\n", statistic.start_time);
	start_threads(philo);
	pthread_create(&keeper_thread, NULL, keeper_function, philo);
	pthread_join(keeper_thread,NULL);
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
	pthread_create(&keeper_thread, NULL, keeper_function, philo);
	pthread_join(keeper_thread,NULL);
}
