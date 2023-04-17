/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:26:57 by jde-la-f          #+#    #+#             */
/*   Updated: 2023/03/28 17:09:55 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

struct	s_data;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				meal_count;
	bool			is_eating;
	int				lf_id;
	int				rf_id;
	long int		t_last_eat;
	struct s_data	*data;

}					t_philo;

typedef struct s_input
{
	int				nb_philo;
	int				t_to_die;
	int				t_to_eat;
	int				t_to_sleep;
	int				nb_meal_to_stop;
}					t_input;

typedef struct s_data
{
	pthread_mutex_t	print;
	pthread_mutex_t	ph_eating;
	pthread_mutex_t	ending;
	int				all_ate;
	int				philo_died;
	long int		start_time;
	pthread_mutex_t	*forks;
	t_input			input;
	struct s_philo	philos[250];
}					t_data;

int					ft_atoi(const char *nptr);

void				ft_usleep(long int time_in_ms);

void				*philosopher(void *phi);

long long			actual_t(void);

void				print(t_data *data, int id, char *string);

int					check_num(char **str);

int					ft_isdigit(int character);

void				ft_utils_death(t_data *data);

#endif