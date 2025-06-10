/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:02:43 by gafreire          #+#    #+#             */
/*   Updated: 2025/06/09 17:16:26 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

// cambiar segundos y micro a milisegundos
void	simple_philo(unsigned int philo, unsigned int die, unsigned int eat,
		unsigned int sleep)
{
	struct timeval	current_time;
	if (philo == 0 || die  == 0 || eat == 0 || sleep == 0)
		printf("Os argumetos deberian ser maiores que cero\n");

	// deber ter menos de cen numeros os filos?
	// deber ter menos de doscentos numeros as demais variables?
	usleep(2000000);
	printf("%s\n", "Cuatros argumentos");
	printf("Number of philosophers\n");
	printf("Philo: %d\n", philo);
	printf("Die: %d\n", die);
	printf("Eat: %d\n", eat);
	printf("Sleep: %d\n", sleep);
	gettimeofday(&current_time, NULL);
	printf("segundos: %ld\nmicrosegundos: %ld\n", current_time.tv_sec,
		current_time.tv_usec);
}
void	advanced_philo(unsigned int philo, unsigned int die, unsigned int eat,
		unsigned int sleep, unsigned int must_eat)
{
	struct timeval current_time;
	if (philo == 0 || die  == 0 || eat == 0 || sleep == 0 || must_eat == 0)
		printf("Os argumetos deberian ser maiores que cero\n");
	usleep(2000000);
	printf("%s\n", "Cinco argumentos");
	printf("Number of philosophers\n");
	printf("Philo: %d\n", philo);
	printf("Die: %d\n", die);
	printf("Eat: %d\n", eat);
	printf("Sleep: %d\n", sleep);
	printf("Must eat: %d\n", must_eat);
	gettimeofday(&current_time, NULL);
	printf("segundos: %ld\nmicrosegundos: %ld\n", current_time.tv_sec,
		current_time.tv_usec);
}