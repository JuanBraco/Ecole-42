/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:56:54 by avast             #+#    #+#             */
/*   Updated: 2023/03/22 15:15:15 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"

int	get_buitlin_fdout(t_cmds *cmd, t_pipex *pipex, int i)
{
	if (cmd->file_out.fd > 0)
		return (cmd->file_out.fd);
	if (i == pipex->nb_cmds && !cmd->file_out.fd)
		return (1);
	if (i == pipex->nb_cmds && cmd->file_out.fd < 0)
		return (-1);
	if (i < pipex->nb_cmds && !cmd->file_out.fd)
		return (pipex->pipes[1]);
	return (0);
}

int	check_if_builtin(t_cmds *cmd)
{
	if (!ft_strcmp(cmd->tab[0], "cd"))
		return (CD_BUILTIN);
	else if (!ft_strcmp(cmd->tab[0], "echo"))
		return (ECHO_BUILTIN);
	else if (!ft_strcmp(cmd->tab[0], "env"))
		return (ENV_BUILTIN);
	else if (!ft_strcmp(cmd->tab[0], "export"))
		return (EXPORT_BUILTIN);
	else if (!ft_strcmp(cmd->tab[0], "pwd"))
		return (PWD_BUILTIN);
	else if (!ft_strcmp(cmd->tab[0], "unset"))
		return (UNSET_BUILTIN);
	else if (!ft_strcmp(cmd->tab[0], "exit"))
		return (EXIT_BUILTIN);
	else
		return (0);
}

int	builtin_error_msg(int type, char *cmd, char *file, t_pipex *pipex)
{
	ft_printf_err("minishell: ");
	if (cmd)
		ft_printf_err("%s: ", cmd);
	if (file && type != EXPORT_IDENT)
		ft_printf_err("%s: ", file);
	if (type == TOO_MANY_ARG)
		ft_printf_err("too many arguments\n");
	else if (type == NOT_ENOUGH_ARG)
		ft_printf_err("not enought arguments\n");
	else if (type == NUMERIC_ARG)
		ft_printf_err("numeric argument required\n");
	else if (type == EXPORT_IDENT)
		ft_printf_err("`%s`: not a valid identifier\n", file);
	else if (type == INVALID_PARAM_NAME)
		ft_printf_err("invalid parameter name\n");
	else if (type == HOME_NOT_SET)
		ft_printf_err("HOME not set\n");
	pipex->data->rv = 1;
	return (-1);
}
