/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanbraco <juanbraco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:57:09 by jde-la-f          #+#    #+#             */
/*   Updated: 2023/02/23 20:06:07 by juanbraco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long		actual_time(void)
{
	struct timeval		t;

	if (gettimeofday(&t, NULL) == -1)
		exit(1);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	ft_usleep(t_data *data, long int time)
{
	long long i;

	i = actual_time();
	while (!(data->philo_died))
	{
		if (time_diff(i, actual_time()) >= time)
			break ;
		usleep(50);
	}
}

void	freeall(t_data *data)
{
	//free(data->philos);
	pthread_mutex_destroy(&data->ph_eating);
}

int	check_num(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

long long	time_diff(long long past, long long pres)
{
	return (pres - past);
}

int	ft_isdigit(int character)
{
	if (character >= '0' && character <= '9')
		return (1);
	return (0);
}
