/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:58:48 by avast             #+#    #+#             */
/*   Updated: 2023/03/27 17:47:15 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"

static int	echo_home(t_env **env, int fdout)
{
	int	a;

	if (find_var(env, "HOME") && find_var(env, "HOME")->value)
		a = ft_printf_fd(fdout, "%s", find_var(env, "HOME")->value);
	else
		a = ft_printf_fd(fdout, "%s", find_var(env, "1_HOME")->value);
	return (a);
}

static int	check_option_n(char *str)
{
	if (!str || *str != '-')
		return (0);
	str++;
	while (*str)
	{
		if (*str != 'n')
			return (0);
		str++;
	}
	return (1);
}

/*On suppose que le flag -n ne peut que etre juste apres echo*/
int	builtin_echo(t_cmds *cmd, t_env **env, int fdout)
{
	int		i;
	int		a;

	a = 0;
	if (fdout < 0)
		return (0);
	if (check_option_n(cmd->tab[1]))
		i = 2;
	else
		i = 1;
	while (cmd->tab[i])
	{
		if (cmd->tab[i][0] == '~' && cmd->tab[i][1] == 0)
			a = echo_home(env, fdout);
		else
			a = ft_printf_fd(fdout, "%s", cmd->tab[i]);
		if (cmd->tab[i + 1])
			ft_printf_fd(fdout, " ");
		i++;
	}
	if (check_option_n(cmd->tab[1]))
		return (0);
	if (ft_printf_fd(fdout, "\n") == -1 || a == -1)
		return (WRITE);
	return (0);
}
