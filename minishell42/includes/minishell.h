/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:48:08 by jde-la-f          #+#    #+#             */
/*   Updated: 2023/03/03 14:43:08 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
#include <sys/ioctl.h>

typedef struct s_data
{
	char			**env;
	char			*pwd;
    char            *old_pwd;
    //char            **path;
	//pid_t			pid;
	char			*text;
}			t_data;

typedef struct s_env
{
	char			*variable;
	int				set;
	struct s_env	*next;

}		t_env;

/*ENVIRONNEMENT*/
void	clear_env(t_env **env);
t_env	**create_env(t_env **env, char **environ);
t_env	*create_var(char *variable);
void	display_env(t_env **env);
void	env_add_back(t_env **env, t_env *var);
t_env	*find_var(t_env	**env, char *name);
char	*find_var_content(t_env	**env, char *name);

/*VARIABLES*/
char	*get_var_name(char *var);
char	*replace_var_value(char *nl, char *var, int *i, t_env **env);
char	*update_var_line(char *line, t_env **env);


#endif