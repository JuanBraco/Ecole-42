/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:55:15 by avast             #+#    #+#             */
/*   Updated: 2023/03/27 16:47:27 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"

static int	get_pipex_infos(t_data *data, t_pipex *pipex)
{
	pipex->data = data;
	pipex->env = data->env;
	pipex->envp = &(data->envp);
	pipex->list_cmds = data->list_cmds;
	pipex->text = data->text;
	pipex->nb_cmds = data->nb_pipe + 1;
	pipex->errors = NULL;
	if (pipex->nb_cmds > 1)
	{
		if (pipe(pipex->pipes) == -1)
			return (error_msg(PIPER, NULL), -1);
	}
	else
	{
		pipex->pipes[0] = -1;
		pipex->pipes[1] = -1;
	}
	pipex->last_pipes[0] = -1;
	pipex->last_pipes[1] = -1;
	return (0);
}

int	execute_execve_command(t_cmds *cmd, int i, t_pipex *pipex)
{
	pid_t	pid;
	char	*path;

	path = get_command_path(cmd->tab[0], pipex->env);
	pid = fork();
	(signal(SIGINT, &child_sig), signal(SIGQUIT, &child_sig));
	if (pid < 0)
		return (ft_free_str(path), exit_and_free(-1, FORK, *pipex));
	if (pid == 0)
	{
		redirect_fds(cmd, i, *pipex, path);
		if (path && cmd->file_out.fd >= 0 && cmd->file_in.fd >= 0)
			execve(path, cmd->tab, *(pipex->envp));
		exit_command(path, *pipex);
	}
	list_add_pid(&(pipex->errors), cmd, path, pid);
	close_command_fds(cmd);
	ft_free_str(path);
	update_pipes(pipex, i);
	return (0);
}

int	execute_builtin_command(t_cmds *cmd, int i, t_pipex *pipex, int type)
{
	int	fdout;
	int	a;

	pipex->data->rv = 0;
	if (cmd->file_in.fd >= 0)
	{
		fdout = get_buitlin_fdout(cmd, pipex, i);
		if (type == CD_BUILTIN)
			a = builtin_cd(cmd, pipex, fdout);
		if (type == ECHO_BUILTIN)
			a = builtin_echo(cmd, pipex->env, fdout);
		if (type == ENV_BUILTIN)
			a = display_env(cmd, ENV_BUILTIN, pipex, fdout);
		if (type == EXIT_BUILTIN)
			a = builtin_exit(cmd, pipex);
		if (type == EXPORT_BUILTIN)
			a = builtin_export(cmd, pipex, fdout);
		if (type == PWD_BUILTIN)
			a = builtin_pwd(cmd, fdout, pipex);
		if (type == UNSET_BUILTIN)
			a = builtin_unset(cmd, pipex);
		list_add_pid(&(pipex->errors), cmd, NULL, a);
	}
	update_pipes(pipex, i);
	return (close_command_fds(cmd), 0);
}

int	execute_command(t_cmds *cmd, int i, t_pipex *pipex)
{
	int	type;
	int	a;

	a = get_command_fds(cmd, pipex);
	if (a == -1)
	{
		pipex->data->rv = 1;
		update_pipes(pipex, i);
		return (close_command_fds(cmd), 0);
	}
	else if (a == HEREDOC)
		return (close_command_fds(cmd), -1);
	else if (!cmd->tab[0])
	{
		pipex->data->rv = 0;
		return (close_command_fds(cmd), 0);
	}
	type = check_if_builtin(cmd);
	if (!type)
		execute_execve_command(cmd, i, pipex);
	else
		execute_builtin_command(cmd, i, pipex, type);
	return (0);
}

int	pipex(t_data *data)
{
	t_pipex	pipex;
	t_cmds	*cmd;
	int		i;

	if (!data->envp)
		return (-1);
	if (get_pipex_infos(data, &pipex) == -1)
		return (-1);
	g_global.g_pipex = pipex;
	i = 1;
	cmd = data->list_cmds;
	while (cmd)
	{
		if (execute_command(cmd, i, &pipex) == -1)
			break ;
		i++;
		cmd = cmd->next;
	}
	close_pipes(pipex);
	wait_all_pids(pipex.errors, pipex);
	free_pid_list(pipex.errors);
	return (0);
}
