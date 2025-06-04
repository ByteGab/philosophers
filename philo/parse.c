/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:01:46 by gafreire          #+#    #+#             */
/*   Updated: 2025/06/04 13:48:08 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int argc, char *argv[])
{
	if (argc == 5)
	{
		
		simple_philo(argv[2],argv[3]);
	}
	else if (argc == 6)
		advanced_philo();
	else
		printf("Error\n");
	return (0);
}
// cambiar segundos y micro a milisegundos