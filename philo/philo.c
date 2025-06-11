/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:02:43 by gafreire          #+#    #+#             */
/*   Updated: 2025/06/11 19:59:54 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

// cambiar segundos y micro a milisegundos
void	simple_philo(unsigned int philo, unsigned int die, unsigned int eat,
		unsigned int sleep)
{
	t_statistics	statistic;
	t_philosopher	*philos;
	
	struct timeval	current_time;
	
	// creo os datos
	// t_philosopher philos;
	if (philo == 0 || die == 0 || eat == 0 || sleep == 0)
		printf("Os argumetos deberian ser maiores que cero\n");
	statistic.nbr_philos = philo;
	statistic.time_die = die; // ten que ser xa en milisegundos
	statistic.time_eat = eat;
	statistic.time_sleep = sleep;
	// deber ter menos de cen numeros os filos? e mentira e na folla de correciones
	// deber ter menos de doscentos numeros as demais variables? e mentira e na folla de correciones
	usleep(2000000);
	printf("%s\n", "Cuatros argumentos");
	printf("Number of philosophers\n");
	printf("Philo: %d\n", statistic.nbr_philos);
	printf("Die: %d\n", statistic.time_die);
	printf("Eat: %d\n", statistic.time_eat);
	printf("Sleep: %d\n", statistic.time_sleep);
	gettimeofday(&current_time, NULL);
	printf("segundos: %ld\nmicrosegundos: %ld\n", current_time.tv_sec,
		current_time.tv_usec);
	//philos = malloc(sizeof(t_philosopher) * )
}
void	advanced_philo(unsigned int philo, unsigned int die, unsigned int eat,
		unsigned int sleep, unsigned int must_eat)
{
	// creo os datos
	t_statistics statistic;
	// t_philosopher philos;

	struct timeval current_time;
	if (philo == 0 || die == 0 || eat == 0 || sleep == 0 || must_eat == 0)
		printf("Os argumetos deberian ser maiores que cero\n");

	statistic.nbr_philos = philo;
	statistic.time_die = die; // ten que ser xa en milisegundos
	statistic.time_eat = eat;
	statistic.time_sleep = sleep;
	statistic.nbr_eats = must_eat;

	usleep(2000000);
	printf("%s\n", "Cinco argumentos");
	printf("Number of philosophers\n");
	printf("Philo: %d\n", statistic.nbr_philos);
	printf("Die: %d\n", statistic.time_die);
	printf("Eat: %d\n", statistic.time_eat);
	printf("Sleep: %d\n", statistic.time_sleep);
	printf("Must eat: %d\n", statistic.nbr_eats);
	gettimeofday(&current_time, NULL);
	printf("segundos: %ld\nmicrosegundos: %ld\n", current_time.tv_sec,
		current_time.tv_usec);
}

void	start_philo(int nbr_philo)
{
	int i;
	
	i = 0;
	
	while (i != nbr_philo)
	{
		pt
		i++;
	}
	
}