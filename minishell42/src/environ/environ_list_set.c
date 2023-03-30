/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ_list_set.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:15:02 by avast             #+#    #+#             */
/*   Updated: 2023/03/23 12:58:05 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/minishell.h"

t_env	*create_var(char *name, char *value)
{
	t_env	*var;
	char	*dup_name;
	char	*dup_value;

	var = malloc(sizeof(t_env));
	if (!var)
		return (NULL);
	dup_name = ft_strdup(name);
	if (!dup_name)
		return (free(var), NULL);
	dup_value = ft_strdup(value);
	var->name = dup_name;
	var->value = dup_value;
	var->next = NULL;
	return (var);
}

/* Ajouter variable triee dans l'ordre alphabetique */
void	env_add_var(t_env **env, t_env *var)
{
	t_env	*cur;

	cur = *env;
	if (*env == 0 || ft_strcmp(var->name, (*env)->name) < 0)
	{
		*env = var;
		var->next = cur;
		return ;
	}
	while (cur->next)
	{
		if (ft_strcmp(var->name, cur->name) > 0
			&& ft_strcmp(cur->next->name, var->name) > 0)
		{
			var->next = cur->next;
			cur->next = var;
			return ;
		}
		cur = cur->next;
	}
	cur->next = var;
}

static int	handle_var_copy(char *str, t_env **env)
{
	char	**var_char;
	t_env	*var;
	char	*level;

	var_char = ft_split_in_two(str, '=');
	if (!var_char)
		return (clear_env(env), -1);
	if (ft_strcmp(var_char[0], "SHLVL"))
		var = create_var(var_char[0], var_char[1]);
	else
	{
		level = ft_itoa(ft_atoi(var_char[1]) + 1);
		var = create_var(var_char[0], level);
		ft_free_str(level);
	}
	if (!var)
		return (clear_env(env), -1);
	(env_add_var(env, var), ft_free_strtab(var_char, -2));
	return (0);
}

static t_env	**create_basic_env(t_env **env)
{
	t_env	*var;
	char	pwd[1000];

	if (!getcwd(pwd, 1000))
		return (ft_printf_err("getcwd : %s\n", strerror(errno)), NULL);
	var = create_var("PWD", pwd);
	if (!var)
		return (clear_env(env), NULL);
	env_add_var(env, var);
	var = create_var("SHLVL", "1");
	if (!var)
		return (clear_env(env), NULL);
	env_add_var(env, var);
	var = create_var("_", "/usr/bin/env");
	if (!var)
		return (clear_env(env), NULL);
	env_add_var(env, var);
	return (env);
}

t_env	**create_env(t_env **env, char **envp)
{
	int		i;
	t_env	*var;

	i = 0;
	if (!envp || !envp[0])
		return (create_basic_env(env));
	while (envp[i])
	{
		if (handle_var_copy(envp[i], env) == -1)
			return (NULL);
		i++;
	}
	var = create_var("1_HOME", find_var(env, "HOME")->value);
	if (!var)
		return (clear_env(env), NULL);
	env_add_var(env, var);
	return (env);
}
