/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelmrabe <nelmrabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:48:13 by nelmrabe          #+#    #+#             */
/*   Updated: 2023/11/06 21:25:46 by nelmrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	signe;
	int	res;

	i = 0;
	res = 0;
	signe = 1;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (str[i])
	{
		if(!(str[i] >= '0' && str[i] <= '9'))
			return (-1);
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * signe);
}

void	get_data(t_data *data, char **av)
{
	data->num_of_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		data->must_eat_count = ft_atoi(av[5]);
	else
		data->must_eat_count = -1;
}

int	check_args(int ac, t_data *data, char **av)
{
	if (ac != 5 && ac != 6)
	{
		write(2, "Error\nInvalid num of arguments\n", 31);
		return (0);
	}
	get_data(data, av);
	if (data->num_of_philo <= 0 || data->time_to_die <= 0 || \
		data->time_to_eat <= 0 || data->time_to_sleep <= 0 || \
		(data->must_eat_count <= 0 && ac == 6))
	{
		write(2, "Error\nInvalid arguments\n", 25);
		return (0);
	}
	return (1);
}

int	parsing(int ac, char **av, t_data *data)
{
	if (!check_args(ac, data, av))
		return (0);
	return (1);
}
