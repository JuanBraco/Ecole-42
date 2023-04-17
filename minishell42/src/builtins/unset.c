/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:02:41 by avast             #+#    #+#             */
/*   Updated: 2023/03/23 15:52:10 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"

/* Parsing : verifier quand le type d'argument est mauvais */
/* S'il y a un pipe ou plus, ne fait rien */
int	builtin_unset(t_cmds *cmd, t_pipex *pipex)
{
	int		i;

	i = 1;
	while (cmd->tab[i])
	{
		env_delete_var(pipex->env, cmd->tab[i]);
		i++;
	}
	update_env_char(pipex->env, pipex->envp);
	return (0);
}
