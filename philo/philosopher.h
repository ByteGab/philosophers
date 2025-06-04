/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:38:00 by gafreire          #+#    #+#             */
/*   Updated: 2025/06/04 12:49:30 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_statistics
{
	unsigned int	nbr_philos;
	unsigned int	nbr_eats;
	// os argumentos
	unsigned int	time_eat;
	unsigned int	time_sleep;
	unsigned int	time_die;
	// comenzo do tempo
	unsigned int	start_time;
	// control do mutex
	pthread_mutex_t	*forks;
	pthread_mutex_t	*death;
	// mirar si morreu os filosofos
	int				is_dead;
}					t_statistics;

typedef struct s_philosopher
{
	int				id;
	pthread_t		thread;
	// son punteros porque apuntan aos elementos especificos do array de forks (chequear)
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	// a ultima vez que comeu (en microsegundos)
	unsigned int	last_eat;
	// cantas veces comeu
	unsigned int	count_eat;
	// punteiro a outra estructura (cambiar o nome)
	t_statistics	*statistic;
}					t_philosopher;

void				simple_philo(char *philo, char *die);
void				advanced_philo(void);
#endif