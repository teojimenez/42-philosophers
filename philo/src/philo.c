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
u_int64_t	init_time()
{
	struct timeval	tv;
	if (gettimeofday(&tv, NULL) == -1)
	{
		write(2, "ERROR!", 7);
		return (0);
	}
	printf("Seconds since epoch: %li\n", tv.tv_sec);
    printf("Microseconds: %u\n", tv.tv_usec);
	printf("%li", (tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

// number_of_philosophers      time_to_die       time_to_eat       time_to_sleep
// [number_of_times_each_philosopher_must_eat]
void	init(int argc, char **argv, t_data	*data)
{
	if (argc == 6)
		data->ts_must_eat = ft_atoi(argv[4]);
	else
		data->ts_must_eat = -1;
	data->nb_philos = ft_atoi(argv[0]);
	data->t_to_die = ft_atoi(argv[1]);
	data->t_to_eat = ft_atoi(argv[2]);
	data->t_to_sleep = ft_atoi(argv[3]);
	data->start_time = init_time();
	if(!data->start_time)
		return ; //error
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
