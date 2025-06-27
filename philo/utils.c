/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:48:28 by gafreire          #+#    #+#             */
/*   Updated: 2025/06/27 20:36:39 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

unsigned int	ft_atoui(char *str)
{
	unsigned int	nbr;
	int				i;

	nbr = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r' || str[i] == '\n'
		|| str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '-')
	{
		return (0);
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	return (nbr);
}
// cambiar segundos y micro a milisegundos
unsigned long	get_time(void)
{
	struct timeval	current_time;
	unsigned long			time;

	time = 0;
	gettimeofday(&current_time, NULL);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}

int	is_philo_dead(t_philosopher *philo)
{
	int	dead;

	pthread_mutex_lock(philo->statistic->death);
	dead = philo->statistic->is_dead;
	pthread_mutex_unlock(philo->statistic->death);
	return (dead);
}
