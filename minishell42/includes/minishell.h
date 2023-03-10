/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanbraco <juanbraco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:48:08 by jde-la-f          #+#    #+#             */
/*   Updated: 2023/03/10 15:06:32 by juanbraco        ###   ########.fr       */
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
# include <sys/ioctl.h>
# include <dirent.h>

typedef struct s_data
{
	char			**env;
	char			*pwd;
    char            *old_pwd;
	t_list			*cmds;
    //char            **path;
	//pid_t			pid;
	char			*text;
	pid_t	pid;
}			t_data;

typedef struct s_node
{
	char	**full_cmd;
	char	*full_path;
	int		infile;
	int		outfile;
}			t_node;

typedef struct s_env
{
	char			*variable;
	int				set;
	struct s_env	*next;

}		t_env;

enum	e_mini_error
{
	QUOTE = 1,
	NDIR = 2,
	NPERM = 3,
	NCMD = 6,
	DUPERR = 7,
	FORKERR = 8,
	PIPERR = 9,
	PIPENDERR = 10,
	MEM = 11,
	IS_DIR = 12,
	NOT_DIR = 13
};

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

//ft_cmdsubsplit.c

char	**ft_cmdsubsplit(char const *s, char *set);

// fill_nodes.c

t_list	*fill_nodes(char **args);

// main.c

void	prompt_loop(t_data *data);
void	find_pwd(t_data  *data, char **envp);

// error.c

void	ft_free_tab(char ***m);
void	free_content(void *content);
void	*ft_perror(int err_type, char *param, int err);

// ft_strtrim_all.c

char	*ft_strtrim_all(char const *s1, int squote, int dquote);

// init_pars.c

void	remove_double_spaces(char *str);
char	**ft_cmdtrim(char const *s, char *set);

// signal.c

void	sigint_handler(int sig);
void	sigquit_handler(int sig);

// ft_tab.c

char	**ft_tab_replace_in(char ***big, char **small, int n);
int		ft_tablen(char **m);
char	**ft_tabdup(char **tab);
char	**ft_extend_tab(char **in, char *newstr);

// utils.c

int	ft_strchr_i(const char *s, int c);
int	ft_strchars_i(const char *s, char *set);

#endif