/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelmrabe <nelmrabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 21:15:31 by nelmrabe          #+#    #+#             */
/*   Updated: 2023/11/06 20:13:49 by nelmrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	snooze(t_data *data, int time)
{
	long long	current;
	int			stop;

	stop = 1;
	current = get_time();
	while (stop)
	{
		pthread_mutex_lock(&data->lock);
		stop = !data->finish;
		pthread_mutex_unlock(&data->lock);
		if (get_time() - current >= time)
			break ;
		usleep(100);
	}
}

void	add_meals(t_philo *philo)
{
	philo->eat_count++;
	if (philo->eat_count >= philo->data->must_eat_count \
		&& philo->data->must_eat_count != -1)
	{
		pthread_mutex_lock(&philo->data->full);
		philo->full = true;
		pthread_mutex_unlock(&philo->data->full);
	}
	pthread_mutex_unlock(&philo->data->lock);
}

int	dining(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->l_fork]);
	print_msg(philo, "has taken a fork");
	if (philo->data->num_of_philo == 1)
	{
		snooze(philo->data, philo->data->time_to_die);
		pthread_mutex_unlock(&philo->data->forks[philo->l_fork]);
		return (1);
	}
	pthread_mutex_lock(&philo->data->forks[philo->r_fork]);
	print_msg(philo, "has taken a fork");
	print_msg(philo, "is eating");
	pthread_mutex_lock(&philo->data->lock);
	philo->last_eat = get_time();
	pthread_mutex_unlock(&philo->data->lock);
	snooze(philo->data, philo->data->time_to_eat);
	pthread_mutex_lock(&philo->data->lock);
	add_meals(philo);
	pthread_mutex_unlock(&philo->data->forks[philo->l_fork]);
	pthread_mutex_unlock(&philo->data->forks[philo->r_fork]);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	int		finish;

	philo = (t_philo *)arg;
	if (philo->id % 2 != 0)
	{
		snooze(philo->data, philo->data->time_to_eat);
		print_msg(philo, "is thinking");
	}
	finish = 1;
	while (finish)
	{
		pthread_mutex_lock(&philo->data->lock);
		finish = !philo->data->finish;
		pthread_mutex_unlock(&philo->data->lock);
		if (dining(philo))
			return (NULL);
		print_msg(philo, "is sleeping");
		snooze(philo->data, philo->data->time_to_sleep);
		print_msg(philo, "is thinking");
	}
	return (NULL);
}
