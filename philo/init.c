/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelmrabe <nelmrabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:27:22 by nelmrabe          #+#    #+#             */
/*   Updated: 2023/11/06 21:28:30 by nelmrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_init(&data->lock, 0);
	pthread_mutex_init(&data->full, 0);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_of_philo);
	while (i < data->num_of_philo)
	{
		pthread_mutex_init(&data->forks[i], 0);
		i++;
	}
}

void	init_philos(t_data *data)
{
	int			i;
	long long	creation_time;

	i = 0;
	creation_time = get_time();
	data->philos = malloc(sizeof(t_philo) * data->num_of_philo);
	while (i < data->num_of_philo)
	{
		data->philos[i].start_time = creation_time;
		data->philos[i].id = i + 1;
		data->philos[i].eat_count = 0;
		data->philos[i].r_fork = i;
		data->philos[i].l_fork = (i + 1) % data->num_of_philo;
		data->philos[i].last_eat = creation_time;
		data->philos[i].full = false;
		data->philos[i].dead = false;
		data->philos[i].data = data;
		pthread_create(&data->philos[i].thread, NULL, \
			routine, &data->philos[i]);
		i++;
	}
}

void	init_all(t_data *data)
{
	data->finish = 0;
	init_mutex(data);
	init_philos(data);
}
