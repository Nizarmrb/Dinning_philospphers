/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelmrabe <nelmrabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:42:37 by nelmrabe          #+#    #+#             */
/*   Updated: 2023/11/06 20:13:41 by nelmrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_data	t_data;
typedef struct s_philo	t_philo;

struct s_philo
{
	int			id;
	int			eat_count;
	int			l_fork;
	int			r_fork;
	long long	last_eat;
	long long	start_time;
	pthread_t	thread;
	bool		full;
	bool		dead;
	t_data		*data;
};

struct s_data
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_count;
	bool			finish;
	pthread_mutex_t	*forks;
	pthread_mutex_t	full;
	pthread_mutex_t	lock;
	t_philo			*philos;
};

// parsing
int			ft_atoi(const char *str);
void		get_data(t_data *data, char **av);
int			check_args(int ac, t_data *data, char **av);
int			parsing(int ac, char **av, t_data *data);

// init
long long	get_time(void);
void		init_philos(t_data *data);
void		init_mutex(t_data *data);
void		init_all(t_data *data);

// routine
void		*routine(void *arg);

// print_msg
void		print_msg(t_philo *philo, char *msg);

// finish
bool		check_death(t_data *data);
bool		check_all_full(t_data *data);
bool		check_finish(t_data *data);

#endif