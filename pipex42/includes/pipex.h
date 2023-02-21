/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:26:57 by jde-la-f          #+#    #+#             */
/*   Updated: 2023/02/13 16:33:35 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <errno.h>
# include <fcntl.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pip
{
	char	*path_env;
	char	**paths_cmd;
	char	**args_cmd;
	char	*cmd_with_path;
	int		pipefd[2];
	pid_t	pid_child_1;
	pid_t	pid_child_2;
	int		fd_infile;
	int		fd_outfile;
	int		err_f1;
	int		err_f2;
	int		exit_msg;
}			t_pip;

char		**ft_split(char const *s, char c);
size_t		ft_strlen(const char *str);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_free_tab(char **tab);

char		*find_paths(char **envp, char *cmd);
char		*check_paths(char **paths_cmd, t_pip *pipex);
void		ft_open(t_pip *pipex, char **argv);

//error.c

void		ft_close_all(t_pip *pipex);
void		ft_err_pipe(t_pip *pipex);
void		ft_err_fork(t_pip *pipex);
void		ft_no_cmd(char *cmd, t_pip *pipex);
void		ft_msg_err_open(char *cmd, char *msg);

void		ft_exit(t_pip *pipex, int exit_value);

#endif