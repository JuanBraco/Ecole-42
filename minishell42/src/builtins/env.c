/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:04:28 by avast             #+#    #+#             */
/*   Updated: 2023/03/27 17:47:21 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/minishell.h"

static int	display_var(t_env *cur, int type, int fdout)
{
	int	a;

	a = 0;
	if (type == ENV_BUILTIN && cur->value && !ft_isdigit(cur->name[0]))
		a = ft_printf_fd(fdout, "%s=", cur->name);
	else if (type == EXPORT_BUILTIN && !ft_isdigit(cur->name[0]))
		a = ft_printf_fd(fdout, "declare -x %s", cur->name);
	if (type == ENV_BUILTIN && cur->value && !ft_isdigit(cur->name[0]))
		a = ft_printf_fd(fdout, "%s\n", cur->value);
	else if (type == EXPORT_BUILTIN && !ft_isdigit(cur->name[0]))
	{
		if (cur->value)
			a = ft_printf_fd(fdout, "=\"%s\"\n", cur->value);
		else
			a = ft_printf_fd(fdout, "\n");
	}
	return (a);
}

/* Afficher var : flag type determine si on affiche les var vides ou non */
int	display_env(t_cmds *cmd, int type, t_pipex *pipex, int fdout)
{
	t_env	*cur;

	if (fdout < 0)
		return (0);
	if (type == ENV_BUILTIN && ft_strtab_size(cmd->tab) > 1)
		return (builtin_error_msg(TOO_MANY_ARG, "env", NULL, pipex), 0);
	cur = *(pipex->env);
	while (cur)
	{
		if (display_var(cur, type, fdout) == -1)
			return (WRITE);
		cur = cur->next;
	}
	return (0);
}
