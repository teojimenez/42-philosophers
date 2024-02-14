/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:40:51 by teojimen          #+#    #+#             */
/*   Updated: 2024/02/14 14:40:51 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	is_num(char *str)
{
	char	*regex;
	int		i;

	i = -1;
	regex = "0123456789";
	while (*str)
	{
		i = -1;
		while (regex[++i] != '\0')
		{
			if (regex[i] == *str)
				break ;
		}
		if (regex[i] == '\0' && regex[i - 1] != *str)
			return (0);
		str++;
	}
	return (1);
}

int	check_inputs(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (!is_num(argv[i]))
			return (0);
	}
	return (1);
}
