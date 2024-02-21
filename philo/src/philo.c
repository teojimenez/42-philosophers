/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 07:18:48 by teojimene         #+#    #+#             */
/*   Updated: 2024/02/14 07:18:48 by teojimene        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// 1 second == 1000 mili s      -> 1 segundo es mas grande que 1 milisegundo
// 1 microsegundo == 0.001 mili s   -> 1 microsegundo es mas pequeño que 1 mili segundo

void	*routine(void *philo_void)
{
	t_philo	*philo;

	philo = (t_philo *)philo_void;
	while (*philo->data->anyDead < 1 && philo->count_meals != philo->data->nb_philos)
	{
		// pthread_mutex_lock(&philo->leftFork->mtx_fork);
		// pthread_mutex_unlock(&philo->leftFork->mtx_fork);
		//sleep
		//think
		if (philo->count_meals > 0)
		{
			if (sleep(philo) != 1)
				break ;
			if (think(philo) != 1)
				break ;
		}
		//eat
	}
	return (NULL);
}

int init_routine(t_data *data)
{
	int i;

	i = -1;
	while (++i < data->nb_philos)
	{
		if (pthread_create(&data->philos[i].thread_id, NULL, &routine, \
		(void *)&data->philos[i]) != 0)
			return (0); //false (error)
		ft_usleep(1);
	}
	i = -1;
	while (++i < data->nb_philos)
	{
		if (pthread_join(data->philos[i].thread_id, NULL) != 0)
			return (0); //false (error)
	}
	return (1);
}

void	give_philo_forks(t_data *data)
{
	int i;

	i = -1;
	if (data->nb_philos == 1)
	{
		data->philos[++i].leftFork = &data->forks[0];
		data->philos[i].rightFork = &data->forks[0];
	}
	while (++i < data->nb_philos)
	{
		if (i == data->nb_philos - 1)
			data->philos[i].leftFork = &data->forks[0];
		else
			data->philos[i].leftFork = &data->forks[i + 1];
		data->philos[i].rightFork = &data->forks[i];
	}
	// printf("\nPHILO %i:\nRIGHT %p\nLEFT %p", data->philos[i - 1].id, data->philos[i - 1].rightFork, data->philos[i - 1].leftFork);
}

void init_philos(t_data *data)
{
	int i;

	i = -1;

	data->philos = (t_philo *)malloc(data->nb_philos * sizeof(t_philo));
	while(++i < data->nb_philos)
	{
		data->philos[i].data = data;
		data->philos[i].id = i;
		data->philos[i].count_meals = 0;
		data->philos[i].status = 0; //just waiting, not thinking, sleeping or eating
		data->philos[i].thread_id = NULL;
		// printf("CONTENT: %p\n", (void *)&data->forks[i].mtx_fork);
	}
	give_philo_forks(data);
}

void	init_forks(t_data *data)
{
	int	i;

	i = -1;
	data->forks = (t_fork *)malloc(data->nb_philos * sizeof(t_fork));
	while(++i < data->nb_philos)
	{
		pthread_mutex_init(&data->forks[i].mtx_fork, NULL);
		// printf("CONTENT: %p\n", (void *)&data->forks[i].mtx_fork);
	}
}

// if(fork is locked)

// pthread_mutex_lock(&data->forks[i].mtx_fork);
// comer
// pthread_mutex_unlock(&data->forks[i].mtx_fork);


// number_of_philosophers      time_to_die       time_to_eat       time_to_sleep
// [number_of_times_each_philosopher_must_eat]
void	init(int argc, char **argv, t_data	*data)
{
	if (argc == 6)
		data->ts_must_eat = ft_atoi(argv[5]);
	else
		data->ts_must_eat = -1;
	data->nb_philos = ft_atoi(argv[1]);
	data->t_to_die = ft_atoi(argv[2]);
	data->t_to_eat = ft_atoi(argv[3]);
	data->t_to_sleep = ft_atoi(argv[4]);
	data->start_time = ft_get_time();
	data->anyDead = 0;
	if(!data->start_time)
		return ; //error
	init_forks(data);
	init_philos(data);
	if(!init_routine(data))
		return ;
	// init_philo(data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (argc == 5 || argc == 6)
	{
		if (!check_inputs(argc, argv))
			return (1);
		init(argc, argv, data);
	}
	return (0);
}

//TODO check for null arg, precise the inputs