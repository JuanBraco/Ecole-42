/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanbraco <juanbraco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:26:57 by jde-la-f          #+#    #+#             */
/*   Updated: 2023/02/23 20:26:09 by juanbraco        ###   ########.fr       */
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

typedef struct s_philo	t_philo;

struct s_data;

typedef struct s_philo
{
	pthread_t			thread;
	int					id;
	int					meal_count;
	bool				is_eating;
	int					l_fork_id;
	int					r_fork_id;
	long int			t_last_eat;
	struct s_data		*data;

}						t_philo;

typedef struct s_input
{
	int					nb_philo;
	int					t_before_die;
	int					t_to_eat;
	int					t_to_sleep;
	int					nb_meal_to_stop;
}						t_input;

typedef struct s_data
{
	pthread_mutex_t		print;
	pthread_mutex_t		ph_eating;
	int					all_ate;
	int					philo_died;
	long int			start_time;
	pthread_mutex_t		forks[250];
	t_input				input;
	struct s_philo				philos[250];
}						t_data;


char					**ft_split(char const *s, char c);
size_t					ft_strlen(const char *str);
char					*ft_strjoin(char const *s1, char const *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
void					ft_free_tab(char **tab);

//error.c

void					ft_close_all(t_philo *pipex);
void					ft_err_pipe(t_philo *pipex);
void					ft_err_fork(t_philo *pipex);
void					ft_no_cmd(char *cmd, t_philo *pipex);
void					ft_msg_err_open(char *cmd, char *msg);

int						ft_atoi(const char *nptr);

void					ft_usleep(t_data *data, long int time_in_ms);
void					*philosopher(void *phi);
long long				actual_time(void);
int						is_dead(t_philo *philo, int nb);
void	print(t_data *data, int id, char *string);
void	freeall(t_data *data);
long long	time_diff(long long past, long long pres);
int	check_num(char **str);
int	ft_isdigit(int character);
#endif