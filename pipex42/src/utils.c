/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:17:14 by jde-la-f          #+#    #+#             */
/*   Updated: 2023/02/13 16:34:24 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n - 1)
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*find_paths(char **envp, char *cmd)
{
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH", 4) == 0)
			return (*envp + 5);
		envp++;
	}
	if (cmd[0] == '.' && cmd[1] == '/')
		return (0);
	write(2, "pipex: ", 7);
	write(2, cmd, ft_strlen(cmd));
	write(2, ": command not found\n", 21);
	exit(127);
}

char	*check_paths(char **paths_cmd, t_pip *pipex)
{
	char	*tmp;
	char	*cmd;

	while (*paths_cmd)
	{
		tmp = ft_strjoin(*paths_cmd, "/");
		cmd = ft_strjoin(tmp, pipex->args_cmd[0]);
		free(tmp);
		if (access(cmd, X_OK) == 0)
			return (cmd);
		free(cmd);
		paths_cmd++;
	}
	return (NULL);
}

void	ft_open(t_pip *pipex, char **argv)
{
	if (access(argv[1], F_OK) == -1)
	{
		ft_msg_err_open(argv[1], ": No such file or directory\n");
		pipex->err_f1 = 1;
		pipex->fd_infile = 0;
	}
	else if (access(argv[1], R_OK) == -1)
	{
		ft_msg_err_open(argv[1], ": Permission denied\n");
		pipex->err_f1 = 1;
		pipex->fd_infile = 0;
	}
	else
		pipex->fd_infile = open(argv[1], O_RDONLY);
	if (access(argv[4], W_OK) == -1 && access(argv[4], F_OK) == 0)
	{
		ft_msg_err_open(argv[4], ": Permission denied\n");
		pipex->fd_outfile = 0;
		pipex->exit_msg = 1;
		close(pipex->fd_infile);
		ft_free_tab(pipex->paths_cmd);
		exit(1);
	}
	else
		pipex->fd_outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
}
