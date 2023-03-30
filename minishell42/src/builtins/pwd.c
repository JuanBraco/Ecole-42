/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:58:48 by avast             #+#    #+#             */
/*   Updated: 2023/03/23 15:57:38 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/minishell.h"

int	builtin_pwd(t_cmds *cmd, int fdout, t_pipex *pipex)
{
	char	pwd[1000];
	t_env	*pwd_var;
	int		a;

	(void)cmd;
	if (fdout < 0)
		return (0);
	if (!getcwd(pwd, 1000))
	{
		pwd_var = find_var(pipex->env, "PWD");
		if (!pwd_var || !pwd_var->value)
			return (ft_printf_err("pwd: pathname unavailable"), -1);
		else
			a = ft_printf_fd(fdout, "%s\n", pwd_var->value);
	}
	else
		a = ft_printf_fd(fdout, "%s\n", pwd);
	if (a == -1)
		return (WRITE);
	return (0);
}
