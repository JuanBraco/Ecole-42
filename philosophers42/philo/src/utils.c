/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:57:09 by jde-la-f          #+#    #+#             */
/*   Updated: 2023/04/17 14:57:01 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	actual_t(void)
{
	struct timeval	t;

	if (gettimeofday(&t, NULL) == -1)
		exit(1);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	ft_usleep(long int time_in_ms)
{
	long int	start_time;

	start_time = 0;
	start_time = actual_t();
	while ((actual_t() - start_time) < time_in_ms)
		usleep(time_in_ms / 10);
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

int	ft_isdigit(int character)
{
	if (character >= '0' && character <= '9')
		return (1);
	return (0);
}

void	ft_utils_death(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&(data->ph_eating));
	pthread_mutex_lock(&(data->ending));
	while (data->input.nb_meal_to_stop != -1 && i < data->input.nb_philo
		&& data->philos[i].meal_count >= data->input.nb_meal_to_stop)
		i++;
	pthread_mutex_unlock(&(data->ph_eating));
	pthread_mutex_unlock(&(data->ending));
	if (i == data->input.nb_philo)
	{
		pthread_mutex_lock(&(data->ending));
		data->all_ate = 1;
		pthread_mutex_unlock(&(data->ending));
	}
}
