/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:06:31 by avast             #+#    #+#             */
/*   Updated: 2023/02/28 17:21:19 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipes.h"
#include "../../libft/libft.h"

int	check_environment(void)
{
	int	i;

	if (!environ)
		return (ft_putstr_fd("environment error: no environment\n", 2), -1);
	i = 0;
	while (environ[i])
	{
		if (ft_strstr("SHELL=\0", environ[i]))
			return (0);
		else
			i++;
	}
	return (ft_putstr_fd("environment error: no shell\n", 2), -1);
}

void	free_tab(char **tab, int index)
{
	int	i;

	i = 0;
	if (index < 0)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
	}
	else
	{
		while (index >= 0)
		{
			free(tab[index]);
			index--;
		}
	}
	free(tab);
}

int	error_msg(int type)
{
	if (type == ENV)
		return (-1);
	if (type == ARG)
		ft_putstr_fd("too few arguments\n", 2);
	if (type == PIPE)
		ft_putstr_fd("pipe failed\n", 2);
	if (type == FORK)
		ft_putstr_fd("fork failed\n", 2);
	if (type == MALLOC)
		ft_putstr_fd("malloc failed\n", 2);
	if (type == DUP2)
		ft_putstr_fd("dup2 failed\n", 2);
	if (type == CLOSE)
		ft_putstr_fd("close failed\n", 2);
	return (-1);
}

int	shell_error_msg(char *cmd, int type)
{
	int	i;

	i = 0;
	if (type == NO_ERROR)
		return (0);
	if (type == FILE_CREATION)
	{
		ft_putstr_fd("file creation failed: ", 2),
		(ft_putstr_fd(cmd, 2), ft_putstr_fd("\n", 2));
		return (-1);
	}
	while (environ[i] && !ft_strstr("SHELL=/bin/\0", environ[i]))
		i++;
	ft_putstr_fd(environ[i] + 11, 2);
	if (type == NO_COMMAND)
		ft_putstr_fd(": command not found: ", 2);
	if (type == NO_FILE)
		ft_putstr_fd(": no such file or directory: ", 2);
	if (type == PERMISSION_DENIED)
		ft_putstr_fd(": permission denied: ", 2);
	if (!cmd)
		ft_putstr_fd("(null)", 2);
	(ft_putstr_fd(cmd, 2), ft_putstr_fd("\n", 2));
	return (-1);
}

int	exit_and_free(int type, t_pipex pipex)
{
	error_msg(type);
	close_pipes(pipex);
	free_cmd(pipex.errors);
	free(pipex.pipes);
	exit (-1);
	return (-1);
}
