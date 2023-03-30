/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:06:31 by avast             #+#    #+#             */
/*   Updated: 2023/03/27 17:27:53 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"

int	define_error_type(char *path)
{
	struct stat	path_stat;
	int			a;

	a = stat(path, &path_stat);
	if (path && (a == -1 || !S_ISDIR(path_stat.st_mode))
		&& access(path, X_OK) == 0)
		return (NO_ERROR);
	else if (path == NULL || (ft_strncmp(path, "./", 2) && path[0] != '/'
			&& access(path, F_OK) == -1) || !ft_strcmp(path, ".."))
		return (NO_COMMAND);
	else if (!ft_strcmp(path, "."))
		return (FILENAME);
	else if ((!ft_strncmp(path, "./", 2) || path[0] == '/')
		&& access(path, F_OK) == -1)
		return (NO_FILE_CMD);
	else if (!a && S_ISDIR(path_stat.st_mode))
		return (IS_DIRECTORY);
	else if (access(path, F_OK) == 0)
		return (PERMISSION_DENIED);
	return (0);
}

int	error_msg(int type, char *str)
{
	if (!type || type == ENV)
		return (-1);
	if (type == ARG)
		ft_putstr_fd("too few arguments\n", 2);
	if (type == PIPER)
		ft_putstr_fd("pipe failed\n", 2);
	if (type == FORK)
		ft_putstr_fd("fork failed\n", 2);
	if (type == MALLOC)
		ft_putstr_fd("malloc failed\n", 2);
	if (type == DUP2)
		ft_putstr_fd("dup2 failed\n", 2);
	if (type == CLOSE)
		ft_putstr_fd("close failed\n", 2);
	if (type == HEREDOC)
	{
		ft_printf_err("minishell: warning: here-document delimited ");
		ft_printf_err("by end-of-file (wanted `%s')\n", str);
	}
	return (-1);
}

int	exec_error_msg(t_cmds *cmd, int type)
{
	if (type == NO_ERROR)
		return (0);
	ft_printf_err("minishell: ");
	if (type == NO_FILE)
		ft_printf_err("%s: No such file or directory\n", cmd->file_in.str);
	if (type == NO_FILE_CMD)
		ft_printf_err("%s: No such file or directory\n", cmd->tab[0]);
	if (type == INFILE_PERM_DENIED && cmd->file_in.str)
		ft_printf_err("%s: Permission denied\n", cmd->file_in.str);
	if (type == OUTFILE_PERM_DENIED)
		ft_printf_err("%s: Permission denied\n", cmd->file_out.str);
	if (type == NO_COMMAND && (!cmd->tab[0] || !cmd->tab[0][0]))
		ft_printf_err("'': command not found\n");
	else if (type == NO_COMMAND)
		ft_printf_err("%s: command not found\n", cmd->tab[0]);
	if (type == PERMISSION_DENIED)
		ft_printf_err("%s: Permission denied\n", cmd->tab[0]);
	if (type == IS_DIRECTORY)
		ft_printf_err("%s: Is a directory\n", cmd->tab[0]);
	if (type == FILENAME)
		(ft_printf_err(" .: filename argument required\n"),
			ft_printf_err(".: usage: . filename [arguments]\n"));
	if (type == WRITE)
		ft_printf_err("write error: No space left on device\n");
	return (-1);
}

int	exit_command(char *path, t_pipex pipex)
{
	if (path == 0 || access(path, F_OK) == -1)
	{
		ft_free_str(path);
		free_pid_list(pipex.errors);
		ft_free_strtab(*(pipex.envp), -2);
		clear_env(pipex.env);
		free(pipex.text);
		ft_clear_list_cmd(&(pipex.list_cmds));
		exit(127);
	}
	else
	{
		free(path);
		free_pid_list(pipex.errors);
		ft_free_strtab(*(pipex.envp), -2);
		clear_env(pipex.env);
		free(pipex.text);
		ft_clear_list_cmd(&(pipex.list_cmds));
		exit(126);
	}
}

int	exit_and_free(int code, int type, t_pipex pipex)
{
	error_msg(type, NULL);
	close_pipes(pipex);
	free_pid_list(pipex.errors);
	ft_free_strtab(*(pipex.envp), -2);
	clear_env(pipex.env);
	free(pipex.text);
	ft_clear_list_cmd(&(pipex.list_cmds));
	exit (code);
	return (-1);
}
