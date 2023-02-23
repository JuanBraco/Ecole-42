/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanbraco <juanbraco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:57:23 by jde-la-f          #+#    #+#             */
/*   Updated: 2023/02/23 20:34:06 by juanbraco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include <pthread.h>

void	print(t_data *data, int id, char *string)
{
	pthread_mutex_lock(&(data->print));
	if (!(data->philo_died))
	{
		printf("%lli ", actual_time() - data->start_time);
		printf("%i ", id + 1);
		printf("%s\n", string);
	}
	pthread_mutex_unlock(&(data->print));
	return ;
}

int	init_input(t_data *data, char **argv)
{
	if (check_num(argv))
	{
		write(2, "Invalid Arguments\n", 18);
		exit(1);
	}
	data->input.nb_philo = ft_atoi(argv[1]);
	data->input.t_before_die = ft_atoi(argv[2]);
	data->input.t_to_eat = ft_atoi(argv[3]);
	data->input.t_to_sleep = ft_atoi(argv[4]);
	if (data->input.nb_philo < 2 || data->input.t_before_die < 0 || data->input.t_to_eat < 0
		|| data->input.t_to_sleep < 0 || data->input.nb_philo > 200)
		return (1);
	if (argv[5])
		data->input.nb_meal_to_stop = ft_atoi(argv[5]);
	else
		data->input.nb_meal_to_stop = -1;
	return (0);
}

int	init_philo(t_data *data)
{
	int	i;

	data->start_time = actual_time();
	i = data->input.nb_philo;
	while (--i >= 0)
	{
		data->philos[i].id = i;
		data->philos[i].t_last_eat = 0;
		data->philos[i].l_fork_id = i;
		data->philos[i].r_fork_id = (i + 1) % data->input.nb_philo;
		data->philos[i].data = data;
		data->philos[i].meal_count = 0;
		if (pthread_mutex_init(&data->forks[i], NULL))
			return (1);
	}
	return (0);
}

void	death_checker(t_data *data)
{
	int i;

	while (!(data->all_ate))
	{
		i = -1;
		while (++i < data->input.nb_philo && !(data->philo_died))
		{
			pthread_mutex_lock(&(data->ph_eating));
			if (time_diff(data->philos[i].t_last_eat, actual_time()) > data->input.t_before_die)
			{
				print(data, i, " died");
				data->philo_died = 1;
			}
			pthread_mutex_unlock(&(data->ph_eating));
			usleep(100);
		}
		if (data->philo_died)
			break ;
		i = 0;
		while (data->input.nb_meal_to_stop != -1 && i < data->input.nb_philo && data->philos[i].meal_count >= data->input.nb_meal_to_stop)
			i++;
		if (i == data->input.nb_philo)
			data->all_ate = 1;
	}
}


static int	start_simulation(t_data *data)
{
	int	i;

	data->start_time = actual_time();
	i = 0;
	while (i < data->input.nb_philo)
	{
		//printf("%i", i);
		if (pthread_create(&data->philos[i].thread, NULL, &philosopher, &(data->philos[i])))
			return (-1);
		data->philos[i].t_last_eat = actual_time();
		i++;
	}
	death_checker(data);
	i = -1;
	while (++i < data->input.nb_philo)
	{
		if (pthread_join(data->philos[i].thread, NULL) != 0)
			return (-1);
	}
	i = -1;
	while (++i < data->input.nb_philo)
		pthread_mutex_destroy(&(data->forks[i]));
	pthread_mutex_destroy(&data->print);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		init_input(&data, argv);
		if (pthread_mutex_init(&data.print, NULL))
			return (1);
		if (pthread_mutex_init(&data.ph_eating, NULL))
			return (1);
		data.philo_died = 0;
		data.all_ate = 0;
		init_philo(&data);
		//printf("%i %i %i %i %i", data.input.nb_philo, data.input.t_before_die, data.input.t_to_eat, data.input.t_to_sleep, data.input.nb_meal_to_stop);
		if (start_simulation(&data))
			return (EXIT_FAILURE);
		freeall(&data);
	}
	else
		write(2, "Invalid number of arguments.\n", 28);
	return (0);
}

