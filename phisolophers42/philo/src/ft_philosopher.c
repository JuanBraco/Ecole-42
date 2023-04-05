/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosopher.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:59:31 by jde-la-f          #+#    #+#             */
/*   Updated: 2023/03/29 09:35:43 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	s;
	int	nb;

	i = 0;
	s = 1;
	nb = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			s *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = 10 * nb + nptr[i] - 48;
		i++;
	}
	return (nb * s);
}

void	print(t_data *data, int id, char *string)
{
	pthread_mutex_lock(&(data->print));
	pthread_mutex_lock(&(data->ending));
	if (!(data->philo_died))
	{
		printf("%lli ", actual_t() - data->start_time);
		printf("%i ", id);
		printf("%s\n", string);
	}
	pthread_mutex_unlock(&(data->ending));
	pthread_mutex_unlock(&(data->print));
	return ;
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->forks[philo->lf_id]));
	print(philo->data, philo->id, "has taken a fork");
	pthread_mutex_lock(&(philo->data->forks[philo->rf_id]));
	print(philo->data, philo->id, "has taken a fork");
	pthread_mutex_lock(&(philo->data->ph_eating));
	print(philo->data, philo->id, "is eating");
	philo->t_last_eat = actual_t();
	philo->meal_count++;
	pthread_mutex_unlock(&(philo->data->ph_eating));
	ft_usleep(philo->data->input.t_to_eat);
	pthread_mutex_unlock(&(philo->data->forks[philo->rf_id]));
	pthread_mutex_unlock(&(philo->data->forks[philo->lf_id]));
}

void	*philosopher(void *phi)
{
	t_philo	*philo;

	philo = (t_philo *)phi;
	if (philo->id % 2)
		ft_usleep(philo->data->input.t_to_eat / 50);
	while (1)
	{
		philo_eat(philo);
		pthread_mutex_lock(&(philo->data->ending));
		if (philo->data->all_ate || philo->data->philo_died)
		{
			pthread_mutex_unlock(&(philo->data->ending));
			break ;
		}
		pthread_mutex_unlock(&(philo->data->ending));
		print(philo->data, philo->id, "is sleeping");
		ft_usleep(philo->data->input.t_to_sleep);
		print(philo->data, philo->id, "is thinking");
	}
	return (NULL);
}
