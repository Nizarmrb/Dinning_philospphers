/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelmrabe <nelmrabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:21:39 by nelmrabe          #+#    #+#             */
/*   Updated: 2023/11/06 18:04:53 by nelmrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;
	int		i;

	i = -1;
	if (!parsing(ac, av, &data))
		return (1);
	init_all(&data);
	if (check_finish(&data) == true)
	{
		while (++i < data.num_of_philo)
			pthread_join(data.philos[i].thread, NULL);
	}
	free(data.philos);
	free(data.forks);
	return (0);
}
