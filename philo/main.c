/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:08:48 by gafreire          #+#    #+#             */
/*   Updated: 2025/06/28 22:08:49 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	check_params(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atoui(argv[i]) == 0)
			return (printf("Argumento no valido: %s\n", argv[i]), 0);
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_statistics	statistic;

	if (argc == 5 || argc == 6)
	{
		if (!check_params(argc, argv))
			return (0);
		statistic.nbr_philos = ft_atoui(argv[1]);
		statistic.time_die = ft_atoui(argv[2]);
		statistic.time_eat = ft_atoui(argv[3]);
		statistic.time_sleep = ft_atoui(argv[4]);
		simple_philo(statistic);
		if (argc == 6)
			advanced_philo(statistic, ft_atoui(argv[5]));
	}
	else
		return (printf("Error\n"), 0);
	return (0);
}
