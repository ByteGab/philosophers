/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:25:03 by gafreire          #+#    #+#             */
/*   Updated: 2025/06/18 16:40:34 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*routine(void *arg)
{
	int i;
	t_philosopher *philo;
	
    i = 0;
    philo = (t_philosopher *)arg;
	while (philo->statistic->nbr_eats == 0 || philo->count_eat > philo->statistic->nbr_eats)
	{
		// pensar
        printf("Think\n");
		// coger forks  
		// comer
		// dormir
	}
}