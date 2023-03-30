/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:01:58 by avast             #+#    #+#             */
/*   Updated: 2023/03/23 16:08:38 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"

/* Gerer les commandes ` export var+=value` */
static char	**handle_plus_for_export(char **tab, t_env **env)
{
	int		i;
	char	**new_tab;
	t_env	*var;

	i = 0;
	while (ft_strlen(tab[0]) > 1 && tab[0][i + 2])
		i++;
	if (ft_strlen(tab[0]) <= 1 || tab[0][i + 1] != '+'
		|| !ft_isalnum(tab[0][i]) || tab[0][i] != '_')
		return (tab);
	new_tab = malloc(3 * sizeof(char *));
	if (!new_tab)
		return (ft_free_strtab(tab, -2), NULL);
	new_tab[0] = ft_substr(tab[0], 0, ft_strlen(tab[0]) - 1);
	if (!new_tab[0])
		return (ft_free_strtab(tab, -2), free(new_tab), NULL);
	var = find_var(env, new_tab[0]);
	if (var && var->value)
		new_tab[1] = ft_strjoin(var->value, tab[1]);
	else
		new_tab[1] = ft_strdup(tab[1]);
	if (!new_tab[1])
		return (ft_free_strtab(tab, 0), NULL);
	new_tab[2] = NULL;
	return (ft_free_strtab(tab, -2), new_tab);
}

/* Verifier validite de la variable et obtenir nom et value pour export */
static char	**get_var_for_export(t_pipex *pipex, char *str)
{
	char	*new_str;
	char	**var;

	new_str = str;
	if (!ft_isalpha(str[0]) && str[0] != '_')
		return (builtin_error_msg(EXPORT_IDENT, "export", str, pipex), NULL);
	var = ft_split_in_two(new_str, '=');
	if (!var)
		return (NULL);
	var = handle_plus_for_export(var, pipex->env);
	if (!var)
		return (NULL);
	if (!check_var_name(var[0]))
	{
		builtin_error_msg(EXPORT_IDENT, "export", str, pipex);
		return (ft_free_strtab(var, -2), NULL);
	}
	return (var);
}

/* Si var est valide, l'ajouter dans les variables d'environnement */
static int	add_var_for_export(t_pipex *pipex, char **var_cont)
{
	t_env	*var;

	var = find_var(pipex->env, var_cont[0]);
	if (var && var_cont[1])
	{
		if (var->value)
			free(var->value);
		var->value = ft_strdup(var_cont[1]);
		if (!var->value)
			return (error_msg(MALLOC, NULL), -1);
	}
	else if (!var)
	{
		var = create_var(var_cont[0], var_cont[1]);
		if (!var)
			return (error_msg(MALLOC, NULL), -1);
		env_add_var(pipex->env, var);
	}
	return (0);
}

/* Sans argument : affiche toutes les variables */
/* S'il y a un pipe ou plus, ne fait rien */
int	builtin_export(t_cmds *cmd, t_pipex *pipex, int fdout)
{
	int		i;
	char	**var;

	if (fdout < 0)
		return (0);
	if (!cmd->tab[1])
		return (display_env(cmd, EXPORT_BUILTIN, pipex, fdout));
	if (pipex->nb_cmds > 1)
		return (0);
	i = 1;
	while (cmd->tab[i])
	{
		var = get_var_for_export(pipex, cmd->tab[i]);
		if (var)
		{
			if (add_var_for_export(pipex, var) == -1)
				ft_printf_err("malloc failed for variable '%s'\n", var[0]);
			ft_free_strtab(var, -2);
		}
		i++;
	}
	update_env_char(pipex->env, pipex->envp);
	return (0);
}
