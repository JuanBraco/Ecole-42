/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:38:14 by jde-la-f          #+#    #+#             */
/*   Updated: 2023/02/13 16:38:02 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_close_all(t_pip *pipex)
{
	close(pipex->fd_infile);
	close(pipex->fd_outfile);
	close(pipex->pipefd[0]);
	close(pipex->pipefd[1]);
	ft_free_tab(pipex->paths_cmd);
}

void	ft_err_pipe(t_pip *pipex)
{
	write(2, "Error : pipe\n", 13);
	close(pipex->fd_infile);
	close(pipex->fd_outfile);
	ft_free_tab(pipex->paths_cmd);
	exit(1);
}

void	ft_err_fork(t_pip *pipex)
{
	close(pipex->fd_infile);
	close(pipex->fd_outfile);
	close(pipex->pipefd[0]);
	close(pipex->pipefd[1]);
	perror("Error fork1");
	exit(EXIT_FAILURE);
}

void	ft_no_cmd(char *cmd, t_pip *pipex)
{
	write(2, "pipex: ", 7);
	write(2, cmd, ft_strlen(cmd));
	write(2, ": command not found\n", 21);
	close(pipex->pipefd[0]);
	close(pipex->pipefd[1]);
	close(pipex->fd_infile);
	close(pipex->fd_outfile);
	ft_free_tab(pipex->paths_cmd);
}

void	ft_msg_err_open(char *cmd, char *msg)
{
	write(2, "pipex: ", 7);
	write(2, cmd, strlen(cmd));
	write(2, msg, strlen(msg));
}
