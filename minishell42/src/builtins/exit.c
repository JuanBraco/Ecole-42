/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:02:55 by avast             #+#    #+#             */
/*   Updated: 2023/03/23 15:51:07 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"

static int	get_exit_code(t_cmds *cmd)
{
	int	i;

	if (ft_strtab_size(cmd->tab) == 1)
		return (0);
	i = 0;
	if (cmd->tab[1][0] == '-' || cmd->tab[1][0] == '+')
		i++;
	while (cmd->tab[1][i])
	{
		if (!ft_isdigit(cmd->tab[1][i]))
			break ;
		i++;
	}
	if (cmd->tab[1][i])
		return (-1);
	return (1);
}

static int	check_limits(char *str)
{
	if (*str == '-' && ft_strlen(str) > 19 && ft_atol(str) > 0)
		return (1);
	if (((*str == '+' && ft_strlen(str) > 19) || (*str >= '0' && *str <= '9'
				&& ft_strlen(str) > 18)) && ft_atol(str) < LLONG_MAX)
		return (1);
	return (0);
}

static void	free_and_close(t_cmds *cmd, t_pipex pipex)
{
	close_pipes(pipex);
	close_command_fds(cmd);
	free_pid_list(pipex.errors);
	ft_free_strtab(*(pipex.envp), -2);
	clear_env(pipex.env);
	free(pipex.text);
}

int	builtin_exit(t_cmds *cmd, t_pipex *pipex)
{
	long long int	code;

	if (pipex->nb_cmds > 1)
		return (0);
	code = get_exit_code(cmd);
	if (ft_strtab_size(cmd->tab) > 2 && code > 0)
	{
		builtin_error_msg(TOO_MANY_ARG, "exit", NULL, pipex);
		return (0);
	}
	free_and_close(cmd, *pipex);
	ft_printf("exit\n");
	if (code < 0 || (cmd->tab[1] && check_limits(cmd->tab[1])))
	{
		builtin_error_msg(NUMERIC_ARG, "exit", cmd->tab[1], pipex);
		(ft_clear_list_cmd(&(pipex->list_cmds)), exit(2));
	}
	else
	{
		if (code)
			code = ft_atol(cmd->tab[1]);
		(ft_clear_list_cmd(&(pipex->list_cmds)), exit(code));
	}
	return (0);
}
