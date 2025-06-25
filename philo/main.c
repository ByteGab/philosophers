/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:08:48 by gafreire          #+#    #+#             */
/*   Updated: 2025/06/25 12:09:31 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int argc, char *argv[])
{
	if (argc == 5)
		simple_philo(ft_atoui(argv[1]), ft_atoui(argv[2]), ft_atoui(argv[3]),
			ft_atoui(argv[4]));
	else if (argc == 6) // no pode recibir mais de 4 argumentos unha funcion
		advanced_philo(ft_atoui(argv[1]), ft_atoui(argv[2]), ft_atoui(argv[3]),
			ft_atoui(argv[4]), ft_atoui(argv[5]));
	else
		printf("Error\n");
	return (0);
}
