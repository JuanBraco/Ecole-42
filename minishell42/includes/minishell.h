/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:48:08 by jde-la-f          #+#    #+#             */
/*   Updated: 2023/03/27 16:55:30 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <dirent.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/ioctl.h>
# include <unistd.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <limits.h>
# include <sys/stat.h>

# define INFILE 1
# define OUTFILE 0
# define NO_ERROR 0
# define NO_COMMAND -2
# define NO_FILE -3
# define INFILE_PERM_DENIED -4
# define OUTFILE_PERM_DENIED -5
# define PERMISSION_DENIED -6
# define ENV -7
# define ARG -8
# define PIPER -9
# define FORK -10
# define MALLOC -11
# define CLOSE -12
# define DUP2 -13
# define OPEN -14
# define HEREDOC -15
# define IS_DIRECTORY -16
# define NO_FILE_CMD -17
# define FILENAME -18
# define WRITE -19

# define SIG_INT 1

# define NO 0
# define YES 1

# define CD_BUILTIN 1
# define ECHO_BUILTIN 2
# define ENV_BUILTIN 3
# define EXPORT_BUILTIN 4
# define PWD_BUILTIN 5
# define UNSET_BUILTIN 6
# define EXIT_BUILTIN 7

# define TOO_MANY_ARG 1
# define NOT_ENOUGH_ARG 2
# define NUMERIC_ARG 3
# define EXPORT_IDENT 4
# define INVALID_PARAM_NAME 5
# define HOME_NOT_SET 6

# define PIPE 1
# define GREAT 2
# define GREAT_GREAT 3
# define LESS 4
# define LESS_LESS 5
# define IN 0
# define OUT 1

typedef struct s_node
{
	char			*str;
	int				token;
	int				i;
	struct s_node	*next;
}					t_node;

typedef struct s_file
{
	char			*str;
	int				fd;
}					t_file;

typedef struct s_cmds
{
	char			**tab;
	int				built_in;
	int				flag_var;
	int				num_redir;
	char			*hd_file_name;
	t_node			*redir;
	t_file			file_in;
	t_file			file_out;
	struct s_cmds	*next;
}						t_cmds;

typedef struct s_parser
{
	t_node				*node_list;
	t_node				*redir;
	int					num_redir;
	struct s_data		*data;
}						t_parser;

typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;

}					t_env;

typedef struct s_data
{
	t_env			**env;
	char			**envp;
	t_node			*node_list;
	struct s_cmds	*list_cmds;
	int				nb_pipe;
	char			*text;
	int				rv;
}					t_data;

typedef struct s_flag
{
	int	single_q;
	int	double_q;
}		t_flag;

typedef struct s_pid
{
	t_cmds			*cmd;
	char			*path;
	pid_t			pid;
	int				error;
	struct s_pid	*next;
}			t_pid;

typedef struct s_pipex
{
	t_data	*data;
	t_env	**env;
	char	***envp;
	t_cmds	*list_cmds;
	char	*text;
	int		nb_cmds;
	int		pipes[2];
	int		last_pipes[2];
	t_pid	*errors;
}	t_pipex;

typedef struct s_gobal
{
	sig_atomic_t	g_status;
	t_pipex			g_pipex;
}	t_global;

/* Variable globale */
extern volatile t_global	g_global;

/* MAIN */
void		del_quotes(t_data *data);
int			prompt_loop(t_data *data, t_env **env);
int			reset_prompt(t_data *data, t_env **env);

/* ERROR */
void		ft_free_tab(char **tab);
int			ft_error(int error, t_data *data);
int			token_error(t_data *data, t_node *list_node, int token);

/* SIGNALS */
void		child_sig(int signal);
void		here_sig(int signal);
void		sig_int(int signal);

/* ENVIRONNEMENT SETTING */
void		clear_env(t_env **env);
t_env		**create_env(t_env **env, char **environ);
char		**create_env_char(t_env **env);
t_env		*create_var(char *name, char *value);
void		env_add_var(t_env **env, t_env *var);
int			env_delete_var(t_env **env, char *var);
int			get_var_count(t_env **env);
char		**update_env_char(t_env **env, char ***tab);

/* VARIABLES */
int			check_var_name(char *name);
t_env		*find_var(t_env **env, char *name);
char		*get_var_name(char *var);
char		*replace_var_value(char *nl, char *name, int *start, t_data *data);
char		*update_var_line(char *line, t_data *data, int flag_hd);

/* LEXER */
int			add_node(char *str, int token, t_node **node_list);
int			check_token(int c);
int			count_quotes(char *line);
char		*delete_quotes(char *str);
int			find_matching_quote(char *line, int i, int *num_del, int del);
t_node		*ft_new_node(char *str, int token);
void		ft_node_add_back(t_node **lst, t_node *new);
int			handle_quotes(int i, char *str, char del);
int			handle_token(char *str, int i, t_node **node_list);
int			is_whitespace(char c);
int			read_words(int i, char *str, t_node **node_list);
void		skip_spaces(char *str, int *i);
int			text_reader(t_data *data);

/* PARSING */
int			count_args(t_node *node_list);
void		count_pipes(t_node *node_list, t_data *tools);
int			check_same_redir(t_node *redir);
int			create_new_node_redir(t_node *tmp, t_parser *parser);
int			handle_pipe_errors(t_data *data, int token);
t_cmds		*initialize_cmd(t_parser *parser_tools);
t_parser	init_parser(t_node *node_list, t_data *data);
void		ft_add_back_lst_cmd(t_cmds **lst, t_cmds *new);
t_node		*ft_clear_first_node(t_node **lst);
void		ft_clear_list_cmd(t_cmds **lst);
void		ft_clear_list_node(t_node **lst);
t_cmds		*ft_new_list_cmd(char **tab, int num_redir, t_node *redir);
void		ft_rm_first_node(t_node **lst);
void		ft_rm_node_i(t_node **lst, int key);
int			parser(t_data *data);
void		rm_redir(t_parser *parser_tools);

/* PIPES */
int			check_path(char **envp);
void		close_command_fds(t_cmds *cmd);
int			close_pipes(t_pipex pipex);
int			define_error_type(char *path);
void		display_heredoc(int cmds);
int			error_msg(int type, char *str);
int			execute_builtin_command(t_cmds *cmd, int i, t_pipex *pipex, int t);
int			execute_execve_command(t_cmds *cmd, int i, t_pipex *pipex);
int			execute_command(t_cmds *cmd, int i, t_pipex *pipex);
int			exec_error_msg(t_cmds *cmd, int type);
int			exit_and_free(int code, int type, t_pipex pipex);
int			exit_command(char *path, t_pipex pipex);
void		free_pid_list(t_pid *list);
char		*ft_strjoin_cmd(char const *s1, char const *s2);
char		**get_command_arg(char *cmd);
int			get_command_fds(t_cmds *cmd, t_pipex *pipex);
char		*get_command_path(char *cmd, t_env **environ);
int			get_return_value(int *status, t_pipex pipex, int type);
int			list_add_pid(t_pid **list, t_cmds *name, char *path, pid_t pid);
int			list_create_pid(t_pid *new, t_cmds *cmd, char *path, pid_t pid);
int			pipex(t_data *data);
int			redirect_infile_outfile(t_cmds *cmd, t_pipex pipex, char *path);
int			redirect_fds(t_cmds *cmd, int i, t_pipex pipex, char *path);
int			reset_pipes(t_pipex *pipex, int i);
int			update_pipes(t_pipex *pipex, int i);
int			wait_all_pids(t_pid *list, t_pipex pipex);

/* BUILTINS */
int			display_env(t_cmds *cmd, int type, t_pipex *pipex, int fdout);
int			builtin_cd(t_cmds *cmd, t_pipex *pipex, int fdout);
int			builtin_error_msg(int type, char *cmd, char *file, t_pipex *pipex);
int			builtin_echo(t_cmds *cmd, t_env **env, int fdout);
int			builtin_exit(t_cmds *cmd, t_pipex *pipex);
int			builtin_export(t_cmds *cmd, t_pipex *pipex, int fdout);
int			builtin_pwd(t_cmds *cmd, int fdout, t_pipex *pipex);
int			builtin_unset(t_cmds *cmd, t_pipex *pipex);
int			check_if_builtin(t_cmds *cmd);
int			get_buitlin_fdout(t_cmds *cmd, t_pipex *pipex, int i);

#endif