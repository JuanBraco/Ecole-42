/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 01:56:32 by avast             #+#    #+#             */
/*   Updated: 2023/03/27 15:30:05 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"

int	redirect_fds(t_cmds *cmd, int i, t_pipex pipex, char *path)
{
	if (pipex.nb_cmds > 1)
	{
		if (cmd->file_out.fd <= 0
			&& (i == 1 || (i < pipex.nb_cmds && cmd->file_in.fd > 0)))
		{
			if (dup2(pipex.pipes[1], 1) < 0)
				return (ft_free_str(path), exit_and_free(0, DUP2, pipex));
		}
		else if (cmd->file_in.fd <= 0
			&& (i == pipex.nb_cmds || (i > 1 && cmd->file_out.fd > 0)))
		{
			if (dup2(pipex.last_pipes[0], 0) < 0)
				return (ft_free_str(path), exit_and_free(0, DUP2, pipex));
		}
		else if (cmd->file_out.fd <= 0
			&& cmd->file_in.fd <= 0 && i > 1 && i < pipex.nb_cmds)
		{
			if (dup2(pipex.last_pipes[0], 0) < 0 || dup2(pipex.pipes[1], 1) < 0)
				return (ft_free_str(path), exit_and_free(0, DUP2, pipex));
		}
	}
	redirect_infile_outfile(cmd, pipex, path);
	return (close_pipes(pipex), 0);
}

int	redirect_infile_outfile(t_cmds *cmd, t_pipex pipex, char *path)
{
	if (cmd->file_in.fd > 0)
	{
		if (dup2(cmd->file_in.fd, 0) < 0)
			return (ft_free_str(path), exit_and_free(0, DUP2, pipex));
	}
	if (cmd->file_out.fd > 0)
	{
		if (dup2(cmd->file_out.fd, 1) < 0)
			return (ft_free_str(path), exit_and_free(0, DUP2, pipex));
	}
	close_command_fds(cmd);
	return (0);
}

int	close_pipes(t_pipex pipex)
{
	if (pipex.pipes[0] > 0)
		close(pipex.pipes[0]);
	if (pipex.pipes[1] > 0)
		close(pipex.pipes[1]);
	if (pipex.last_pipes[0] > 0)
		close(pipex.last_pipes[0]);
	if (pipex.last_pipes[1] > 0)
		close(pipex.last_pipes[1]);
	return (0);
}

void	close_command_fds(t_cmds *cmd)
{
	if (cmd->file_in.fd > 0)
		close(cmd->file_in.fd);
	if (cmd->file_out.fd > 0)
		close(cmd->file_out.fd);
}

int	update_pipes(t_pipex *pipex, int i)
{
	if (pipex->last_pipes[0] > 0)
		close(pipex->last_pipes[0]);
	pipex->last_pipes[0] = pipex->pipes[0];
	pipex->last_pipes[1] = pipex->pipes[1];
	if (pipex->last_pipes[1] > 0)
		close(pipex->last_pipes[1]);
	pipex->pipes[0] = -1;
	pipex->pipes[1] = -1;
	if (i < pipex->nb_cmds - 1)
	{
		if (pipe(pipex->pipes) == -1)
			return (exit_and_free(0, PIPER, *pipex));
	}
	return (0);
}
