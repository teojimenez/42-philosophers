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

//COLORS

#define RESET   "\x1B[0m"
#define RED     "\x1B[31m"
#define GREEN   "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define BLUE    "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN    "\x1B[36m"
#define WHITE   "\x1B[37m"

//DEFINES

# define S_FORK_TAKEN "has taken a fork"
# define S_EATING "is eating"
# define S_SLEEPING "is sleeping"
# define S_THINKING "is thinking"
# define S_DIED "died"

// STRUCTS
typedef struct s_fork
{
	pthread_mutex_t mtx_fork;
} t_fork;

typedef struct s_philo {
	struct s_data			*data;
	int						id;
	pthread_t				thread_id;
	int						count_meals;
	int						status;
	u_int64_t				last_meal_time;
	struct s_fork			*leftFork; //cada uno
	struct s_fork			*rightFork; //cada uno
	// pthread_mutex_t	lock;
} t_philo;

typedef struct s_data {
	struct s_philo		*philos;
	struct s_fork		*forks; //array de todos
	u_int64_t			start_time;
	int					nb_philos;
	u_int64_t			t_to_die;
	u_int64_t			t_to_eat;
	u_int64_t			t_to_sleep;
	int					ts_must_eat;
	int					philo_already_eat;
	int					anyDead;
	pthread_t			monitor;
} t_data;
// number_of_philosophers      time_to_die       time_to_eat       time_to_sleep
// [number_of_times_each_philosopher_must_eat]


// FUNCTIONS
int	check_inputs(int argc, char **argv);

// UTILS
int			ft_atoi(const char *str);
u_int64_t	ft_get_time();
int			ft_usleep(useconds_t time);
#endif