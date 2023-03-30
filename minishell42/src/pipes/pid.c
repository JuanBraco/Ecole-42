/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 09:47:25 by avast             #+#    #+#             */
/*   Updated: 2023/03/27 17:39:43 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"

int	list_create_pid(t_pid *new, t_cmds *cmd, char *path, pid_t pid)
{
	struct stat	path_stat;

	stat(path, &path_stat);
	(*new).cmd = cmd;
	(*new).path = ft_strdup(path);
	(*new).pid = pid;
	(*new).next = NULL;
	if (pid == 0 || pid == -1 || pid == HEREDOC)
		new->error = NO_ERROR;
	else if (pid == NO_FILE)
		new->error = NO_FILE;
	else if (pid == INFILE_PERM_DENIED)
		new->error = INFILE_PERM_DENIED;
	else if (pid == OUTFILE_PERM_DENIED)
		new->error = OUTFILE_PERM_DENIED;
	else if (pid == WRITE)
		new->error = WRITE;
	else
		new->error = define_error_type(path);
	return (0);
}

int	list_add_pid(t_pid **list, t_cmds *cmd, char *path, pid_t pid)
{
	t_pid	*new;
	t_pid	*cur;

	new = malloc(sizeof (t_pid));
	if (!new)
		return (-1);
	if (list_create_pid(new, cmd, path, pid) == -1)
		return (-1);
	if (*list == 0)
	{
		*list = new;
		return (0);
	}
	cur = *list;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
	return (0);
}

int	wait_all_pids(t_pid *pid, t_pipex pipex)
{
	int		status;
	int		type;

	status = 0;
	if (!pid)
		return (0);
	while (pid->next)
	{
		if (pid->pid > 0)
			waitpid(pid->pid, NULL, 0);
		exec_error_msg(pid->cmd, pid->error);
		pid = pid->next;
	}
	if (pid->pid > 0)
		waitpid(pid->pid, &status, 0);
	exec_error_msg(pid->cmd, pid->error);
	type = check_if_builtin(pid->cmd);
	if (pid->cmd->file_out.fd < 0 || pid->cmd->file_in.fd < 0)
		pipex.data->rv = 1;
	else
		pipex.data->rv = get_return_value(&status, pipex, type);
	return (0);
}

void	free_pid_list(t_pid *list)
{
	t_pid	*tmp;

	if (!list)
		return ;
	while (list)
	{
		tmp = list;
		list = list->next;
		if (tmp->path)
			free(tmp->path);
		free(tmp);
	}
}

int	get_return_value(int *status, t_pipex pipex, int type)
{
	if (!type)
	{
		if (WIFEXITED(*status))
			return (WEXITSTATUS(*status));
		if (WIFSIGNALED(*status))
			return (128 + WTERMSIG(*status));
		else
			return (0);
	}
	if (pipex.data->rv > 0)
		return (pipex.data->rv);
	return (0);
}
