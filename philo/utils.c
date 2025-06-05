/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:48:28 by gafreire          #+#    #+#             */
/*   Updated: 2025/06/05 13:03:01 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
unsigned int	ft_atoui(char *str)
{
	unsigned int nbr;
	int i;

	nbr = 0;
	i = 0;

	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r'
		|| str[i] == '\n' || str[i] == '\f' || str[i] == '\v')
		i++;
    if (str[i] == '-')
    {
        printf("E numero negativo\n");
		exit(1);
        return (-1); // cambialo
    }
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	return (nbr);
}