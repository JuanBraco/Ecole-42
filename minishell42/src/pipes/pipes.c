/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 01:56:32 by avast             #+#    #+#             */
/*   Updated: 2023/02/28 17:21:19 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipes.h"
#include "../../libft/libft.h"

int	*create_pipes(int nb_cmds)
{
	int	i;
	int	*pipes;

	pipes = malloc((nb_cmds - 1) * sizeof(int) * 2);
	if (!pipes)
		return (error_msg(MALLOC), NULL);
	i = 0;
	while (i < nb_cmds - 1)
	{
		if (pipe(pipes + (i * 2)) < 0)
			return (error_msg(PIPE), free(pipes), NULL);
		i++;
	}
	return (pipes);
}

int	redirect_fds(int i, t_pipex pipex, char *path, char **arg)
{
	if (i == 0)
	{
		if ((dup2(pipex.infile, 0) < 0 && pipex.infile > 0)
			|| dup2(pipex.pipes[1], 1) < 0)
			return (free_path(path, arg), exit_and_free(DUP2, pipex));
		if (pipex.infile < 0)
			return (free_path(path, arg), exit_and_free(0, pipex));
	}
	else if (i == pipex.nb_cmds - 1)
	{
		if (dup2(pipex.pipes[2 * i - 2], 0) < 0
			|| (pipex.outfile > 0 && dup2(pipex.outfile, 1) < 0))
			return (free_path(path, arg), exit_and_free(DUP2, pipex));
		if (pipex.outfile < 0)
			return (free_path(path, arg), exit_and_free(0, pipex));
	}
	else
	{
		if (dup2(pipex.pipes[2 * i - 2], 0) < 0
			|| dup2(pipex.pipes[2 * i + 1], 1) < 0)
			return (free_path(path, arg), exit_and_free(DUP2, pipex));
	}
	close_pipes(pipex);
	return (0);
}

int	close_pipes(t_pipex pipex)
{
	int	i;

	i = 0;
	while (i < pipex.nb_cmds - 1)
	{
		if (close(pipex.pipes[i * 2]) == 1
			|| close(pipex.pipes[i * 2 + 1]) == -1)
			return (exit_and_free(CLOSE, pipex));
		i++;
	}
	if (pipex.infile >= 0)
	{
		if (close(pipex.infile) == -1)
			return (exit_and_free(CLOSE, pipex));
	}
	if (pipex.outfile >= 0)
	{
		if (close(pipex.outfile) == -1)
			return (exit_and_free(CLOSE, pipex));
	}
	return (0);
}

int	exit_command(char *path, char **arg, t_cmd **list, t_pipex pipex)
{
	if (path == 0 || access(path, F_OK) == -1)
	{
		free_tab(arg, -1);
		if (path)
			free(path);
		free(pipex.pipes);
		free_cmd(list);
		exit (127);
	}
	else
	{
		free_tab(arg, -1);
		free(path);
		free(pipex.pipes);
		free_cmd(list);
		exit (126);
	}
}

int	execute_command(char *cmd, t_cmd **list, int i, t_pipex pipex)
{
	pid_t	pid;
	char	**arg;
	char	*path;

	arg = ft_split(cmd, 32);
	if (!arg)
		return (exit_and_free(MALLOC, pipex));
	path = get_command_path(arg[0]);
	pid = fork();
	if (pid < 0)
	{
		free_path(path, arg);
		return (exit_and_free(FORK, pipex));
	}
	if (pid == 0)
	{
		redirect_fds(i, pipex, path, arg);
		if (path)
			execve(path, arg, environ);
		exit_command(path, arg, list, pipex);
	}
	list_add_cmd(list, arg[0], path, pid);
	return (free_path(path, arg), 0);
}
