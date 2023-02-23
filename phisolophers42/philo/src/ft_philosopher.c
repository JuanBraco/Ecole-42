/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosopher.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanbraco <juanbraco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:59:31 by jde-la-f          #+#    #+#             */
/*   Updated: 2023/02/23 20:35:09 by juanbraco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*int	is_dead(t_philo *philo, int nb)
{
	pthread_mutex_lock(&philo->data->dead);
	if (nb)
		philo->data->stop = 1;
	if (philo->data->stop)
	{
		pthread_mutex_unlock(&philo->data->dead);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->dead);
	return (0);
}*/

/*void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->fork_l));
	print(philo, " has taken a fork\n");
	if (philo->data->input.nb_philo == 1)
	{
		ft_usleep(philo->data->input.t_before_die * 2);
		return ;
	}
	pthread_mutex_lock((philo->fork_r));
	print(philo, " has taken a fork\n");
}*/

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->forks[philo->l_fork_id]));
	print(philo->data, philo->id, "has taken a fork");
	pthread_mutex_lock(&(philo->data->forks[philo->r_fork_id]));
	print(philo->data, philo->id, "has taken a fork");
	pthread_mutex_lock(&(philo->data->ph_eating));
	print(philo->data, philo->id, " is eating");
	philo->t_last_eat = actual_time();
	philo->meal_count++;
	pthread_mutex_unlock(&(philo->data->ph_eating));
	ft_usleep(philo->data, philo->data->input.t_to_eat);
	pthread_mutex_unlock(&(philo->data->forks[philo->l_fork_id]));
	pthread_mutex_unlock(&(philo->data->forks[philo->r_fork_id]));
}

/*void	*check_death(void *phi)
{
	t_philo	*philo;

	philo = (t_philo *)phi;
	ft_usleep(philo->data->input.t_before_die + 1);
	pthread_mutex_lock(&philo->data->ph_eating);
	pthread_mutex_lock(&philo->data->m_stop);
	if (!is_dead(philo, 0) && actual_time() - philo->last_eat >= (long)(philo->data->input.t_before_die))
	{
		pthread_mutex_unlock(&philo->data->ph_eating);
		pthread_mutex_unlock(&philo->data->m_stop);
		print(philo, " died\n");
		is_dead(philo, 1);
	}
	pthread_mutex_unlock(&philo->data->ph_eating);
	pthread_mutex_unlock(&philo->data->m_stop);
	return (NULL);
}*/

void	*philosopher(void *phi)
{
	t_philo		*philo;

	philo = (t_philo *)phi;
	if (philo->id % 2)
		ft_usleep(philo->data, philo->data->input.t_to_eat / 10);
	while (!philo->data->philo_died)
	{
		//pthread_create(&philo->thread_death, NULL, check_death, phi);
		//take_fork(philo);
		philo_eat(philo);
		//pthread_detach(philo->thread_death);
		if (philo->data->all_ate)
			break ;
		print(philo->data, philo->id, " is sleeping");
		ft_usleep(philo->data, philo->data->input.t_to_sleep);
		print(philo->data, philo->id, " is thinking");
		/*if (philo->meal_count == philo->data->input.nb_meal_to_stop)
		{
			pthread_mutex_lock(&philo->data->m_stop);
			if (++philo->data->philo_done == philo->data->input.nb_philo)
			{
				pthread_mutex_unlock(&philo->data->m_stop);
				is_dead(philo, 2);
			}
			pthread_mutex_unlock(&philo->data->m_stop);
			return (NULL);
		}*/
	}
	return (NULL);
}
