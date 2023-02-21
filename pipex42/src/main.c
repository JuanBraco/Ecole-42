/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:23:56 by jde-la-f          #+#    #+#             */
/*   Updated: 2023/02/13 16:32:37 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_child_1(t_pip *pipex, char **envp, char **argv)
{
	dup2(pipex->fd_infile, 0);
	close(pipex->pipefd[0]);
	dup2(pipex->pipefd[1], 1);
	pipex->args_cmd = ft_split(argv[2], ' ');
	if (argv[2][0] == '.' && argv[2][1] == '/')
	{
		pipex->cmd_with_path = argv[2];
		if (access(pipex->cmd_with_path, X_OK) == -1)
		{
			ft_msg_err_open(argv[2], ": Permission denied\n");
			ft_exit(pipex, 126);
		}
	}
	else
	{
		pipex->cmd_with_path = check_paths(pipex->paths_cmd, pipex);
		if (!pipex->cmd_with_path)
		{
			free(pipex->cmd_with_path);
			ft_no_cmd(argv[2], pipex);
			ft_exit(pipex, 127);
		}
	}
	execve(pipex->cmd_with_path, pipex->args_cmd, envp);
}

void	ft_child_2(t_pip *pipex, char **envp, char **argv)
{
	dup2(pipex->pipefd[0], 0);
	close(pipex->pipefd[1]);
	dup2(pipex->fd_outfile, 1);
	pipex->args_cmd = ft_split(argv[3], ' ');
	if (argv[3][0] == '.' && argv[3][1] == '/')
	{
		pipex->cmd_with_path = argv[3];
		if (access(pipex->cmd_with_path, X_OK) == -1)
		{
			ft_msg_err_open(argv[3], ": Permission denied\n");
			ft_exit(pipex, 126);
		}
	}
	else
	{
		pipex->cmd_with_path = check_paths(pipex->paths_cmd, pipex);
		if (!pipex->cmd_with_path)
		{
			free(pipex->cmd_with_path);
			ft_no_cmd(argv[3], pipex);
			ft_exit(pipex, 127);
		}
	}
	execve(pipex->cmd_with_path, pipex->args_cmd, envp);
}

void	init(t_pip *pipex, char **envp, char **argv)
{
	pipex->exit_msg = 0;
	pipex->err_f1 = 0;
	pipex->path_env = find_paths(envp, argv[2]);
	pipex->paths_cmd = ft_split(pipex->path_env, ':');
	ft_open(pipex, argv);
	if (pipe(pipex->pipefd) < 0)
	{
		write(2, "Error pipe", 10);
		exit(1);
	}
}

void	ft_close_end(t_pip *pipex)
{
	int	status_2;

	status_2 = 0;
	close(pipex->pipefd[1]);
	close(pipex->pipefd[0]);
	waitpid(pipex->pid_child_1, NULL, 0);
	waitpid(pipex->pid_child_2, &status_2, 0);
	if (WIFEXITED(status_2))
		pipex->exit_msg = WEXITSTATUS(status_2);
	close(pipex->fd_infile);
	close(pipex->fd_outfile);
	ft_free_tab(pipex->paths_cmd);
}

int	main(int argc, char **argv, char **envp)
{
	t_pip	pipex;

	if (argc == 5 && envp)
	{
		init(&pipex, envp, argv);
		pipex.pid_child_1 = fork();
		if (pipex.pid_child_1 == 0 && pipex.err_f1 != 1)
			ft_child_1(&pipex, envp, argv);
		else if (pipex.pid_child_1 == 0 && pipex.err_f1 == 1)
		{
			ft_free_tab(pipex.paths_cmd);
			close(pipex.pipefd[1]);
			close(pipex.pipefd[0]);
			close(pipex.fd_outfile);
			exit(1);
		}
		pipex.pid_child_2 = fork();
		if (pipex.pid_child_2 == 0)
			ft_child_2(&pipex, envp, argv);
		ft_close_end(&pipex);
	}
	else
		write(2, "Invalid number of arguments.\n", 28);
	return (pipex.exit_msg);
}
