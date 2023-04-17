/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:57:23 by jde-la-f          #+#    #+#             */
/*   Updated: 2023/04/17 14:52:04 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include <pthread.h>

int	init_input(t_data *data, char **argv)
{
	if (check_num(argv))
	{
		write(2, "Invalid Arguments\n", 18);
		exit(1);
	}
	data->input.nb_philo = ft_atoi(argv[1]);
	data->input.t_to_die = ft_atoi(argv[2]);
	data->input.t_to_eat = ft_atoi(argv[3]);
	data->input.t_to_sleep = ft_atoi(argv[4]);
	if (data->input.nb_philo == 1)
	{
		printf("0 1 has taken a left fork\n");
		printf("%i 1 died\n", data->input.t_to_die);
		exit(1);
	}
	if (data->input.t_to_die < 0 || data->input.t_to_eat < 0
		|| data->input.nb_philo < 1 || data->input.t_to_sleep < 0
		|| data->input.nb_philo > 200)
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

	i = data->input.nb_philo;
	while (--i >= 0)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL))
			return (1);
	}
	if (pthread_mutex_init(&data->print, NULL))
		return (1);
	if (pthread_mutex_init(&data->ph_eating, NULL))
		return (1);
	if (pthread_mutex_init(&data->ending, NULL))
		return (1);
	i = -1;
	while (++i < data->input.nb_philo)
	{
		data->philos[i].id = i + 1;
		data->philos[i].t_last_eat = 0;
		data->philos[i].data = data;
		data->philos[i].meal_count = 0;
		if (i == data->input.nb_philo - 1)
		{
			data->philos[i].lf_id = 0;
			data->philos[i].rf_id = i;
		}
		else
		{
			data->philos[i].lf_id = i;
			data->philos[i].rf_id = (i + 1) % data->input.nb_philo;
		}
	}
	return (0);
}

void	death_checker(t_data *data)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < data->input.nb_philo && !data->philo_died)
		{
			pthread_mutex_lock(&(data->ph_eating));
			if (actual_t() - data->philos[i].t_last_eat >= data->input.t_to_die)
			{
				print(data, i + 1, " died");
				pthread_mutex_lock(&(data->ending));
				data->philo_died = 1;
				pthread_mutex_unlock(&(data->ending));
			}
			pthread_mutex_unlock(&(data->ph_eating));
			ft_usleep(5);
		}
		if (data->philo_died || data->all_ate)
			break ;
		ft_utils_death(data);
	}
}

static int	start_simulation(t_data *data)
{
	int	i;

	data->start_time = actual_t();
	i = 0;
	while (i < data->input.nb_philo)
	{
		data->philos[i].t_last_eat = actual_t();
		if (pthread_create(&data->philos[i].thread, NULL, &philosopher,
				&(data->philos[i])))
			return (-1);
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
		if (init_input(&data, argv))
			return (1);
		data.forks = malloc(data.input.nb_philo * sizeof(pthread_mutex_t));
		if (!data.forks)
			return (0);
		data.philo_died = 0;
		data.all_ate = 0;
		if (init_philo(&data))
			return (1);
		data.start_time = actual_t();
		if (start_simulation(&data))
			return (EXIT_FAILURE);
		pthread_mutex_destroy(&data.ph_eating);
	}
	else
		write(2, "Invalid number of arguments.\n", 28);
	return (0);
}
