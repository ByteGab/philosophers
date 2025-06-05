/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:01:46 by gafreire          #+#    #+#             */
/*   Updated: 2025/06/05 16:40:19 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int argc, char *argv[])
{
	if (argc == 5)
	{
		simple_philo(ft_atoui(argv[1]),ft_atoui(argv[2]),ft_atoui(argv[3]),ft_atoui(argv[4]));
	}
	else if (argc == 6)
		advanced_philo(ft_atoui(argv[1]),ft_atoui(argv[2]),ft_atoui(argv[3]),ft_atoui(argv[4]),ft_atoui(argv[5]));
	else
		printf("Error\n");
	return (0);
}
