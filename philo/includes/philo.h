/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 07:18:07 by teojimene         #+#    #+#             */
/*   Updated: 2024/02/14 07:18:07 by teojimene        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "philo.h"
# include <stdio.h>
# include <stdlib.h> //free
# include <unistd.h> //sleep
# include <sys/time.h>
# include <pthread.h>

// STRUCTS

typedef struct s_philo {
	struct s_data			*data;
	int						id;
	int						nb_eat;
	int						status;
	pthread_mutex_t	lock;

} t_philo;

typedef struct s_data {
	struct s_philo		*philos;
	u_int64_t			start_time;
	int					nb_philos;
	u_int64_t			t_to_die;
	u_int64_t			t_to_eat;
	u_int64_t			t_to_sleep;
	int					ts_must_eat;
} t_data;
// number_of_philosophers      time_to_die       time_to_eat       time_to_sleep
// [number_of_times_each_philosopher_must_eat]


// FUNCTIONS
int	check_inputs(int argc, char **argv);
int	ft_atoi(const char *str);

#endif