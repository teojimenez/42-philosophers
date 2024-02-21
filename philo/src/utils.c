/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:44:02 by teojimen          #+#    #+#             */
/*   Updated: 2024/02/14 14:44:02 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		nb = (nb * 10) + (str[i++] - '0');
	return (nb);
}

int	ft_usleep(useconds_t time)
{
	u_int64_t	start;
	start = ft_get_time();
	while ((ft_get_time() - start) < time)
		usleep(time / 10);
	return(0);
}

void	print_status(u_int64_t time, int nb_philo, char *status)
{
	printf("%llu %i %s\n", time, nb_philo, status);
}

u_int64_t	ft_get_time()
{
	struct timeval	tv;
	if (gettimeofday(&tv, NULL) == -1)
	{
		write(2, "ERROR!", 7);
		return (0);
	}
	// printf("Seconds since epoch: %li\n", tv.tv_sec);
    // printf("Microseconds: %u\n", tv.tv_usec);
	// printf("%li", (tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
