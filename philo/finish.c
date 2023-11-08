/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelmrabe <nelmrabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:28:14 by nelmrabe          #+#    #+#             */
/*   Updated: 2023/11/06 17:03:19 by nelmrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_all_full(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philo)
	{
		if (data->philos[i].full == false)
			return (false);
		i++;
	}
	return (true);
}

bool	check_death(t_data *data)
{
	int			i;
	long long	timee;

	i = 0;
	while (i < data->num_of_philo)
	{
		pthread_mutex_lock(&data->lock);
		timee = get_time() - data->philos[i].last_eat;
		pthread_mutex_unlock(&data->lock);
		if (timee > data->time_to_die)
		{
			pthread_mutex_lock(&data->lock);
			printf("%lld %d died\n", get_time() - \
				data->philos[i].start_time, data->philos[i].id);
			data->philos[i].dead = true;
			data->finish = true;
			pthread_mutex_unlock(&data->lock);
			return (true);
		}
		i++;
	}
	return (false);
}

bool	check_finish(t_data *data)
{
	while (!data->finish)
	{
		if (check_all_full(data) == true || check_death(data) == true)
		{
			pthread_mutex_lock(&data->lock);
			data->finish = true;
			pthread_mutex_unlock(&data->lock);
			return (true);
		}
	}
	return (false);
}
