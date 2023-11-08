/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelmrabe <nelmrabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:56:46 by nelmrabe          #+#    #+#             */
/*   Updated: 2023/11/06 16:59:26 by nelmrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	print_msg(t_philo *philo, char *ms)
{
	bool	finish;

	pthread_mutex_lock(&philo->data->lock);
	finish = philo->data->finish;
	pthread_mutex_unlock(&philo->data->lock);
	if (!finish)
		printf("%lld %d %s\n", get_time() - philo->start_time, philo->id, ms);
}
