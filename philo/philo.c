/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:02:43 by gafreire          #+#    #+#             */
/*   Updated: 2025/06/04 13:04:57 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	simple_philo(char *philo, char *die)
{
	struct timeval	current_time;

	usleep(2000000);
	printf("%s\n", "Cuatros argumentos");
	printf("%s\n", "Cuatros argumentos");
	printf("Number of philosophers\n");
	gettimeofday(&current_time, NULL);
	printf("segundos: %ld\nmicrosegundos: %ld\n", current_time.tv_sec,
		current_time.tv_usec);
}
void	advanced_philo(void)
{
	struct timeval current_time;

	usleep(2000000);
	printf("%s\n", "Cinco argumentos");
	printf("Number of philosophers\n");
	gettimeofday(&current_time, NULL);
	printf("segundos: %ld\nmicrosegundos: %ld\n", current_time.tv_sec,
		current_time.tv_usec);
}