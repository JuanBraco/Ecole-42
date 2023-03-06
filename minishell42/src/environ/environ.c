/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:15:02 by avast             #+#    #+#             */
/*   Updated: 2023/03/03 14:59:03 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/minishell.h"

t_env	*create_var(char *variable)
{
	t_env	*var;
	char	*dup;

	var = malloc(sizeof(t_env));
	if (!var)
		return (NULL);
	dup = ft_strdup(variable);
	if (!dup)
		return (free(var), NULL);
	var->variable = dup;
	var->set = 0;
	var->next = NULL;
	return (var);
}

void	env_add_back(t_env **env, t_env *var)
{
	t_env	*cur;

	var->set = 1;
	if (*env == 0)
	{
		*env = var;
		return ;
	}
	cur = *env;
	while (cur->next)
		cur = cur->next;
	cur->next = var;
}

void	display_env(t_env **env)
{
	t_env	*cur;

	cur = *env;
	while (cur)
	{
		if (cur->set)
			ft_printf("%s\n", cur->variable);
		cur = cur->next;
	}
}

void	clear_env(t_env **env)
{
	t_env	*tmp;

	if (env == 0 || *env == 0)
		return ;
	while (*env)
	{
		tmp = *env;
		*env = (*env)->next;
		free(tmp->variable);
		free(tmp);
	}
}

t_env	*find_var(t_env	**env, char *name)
{
	t_env	*cur;

	cur = *env;
	if (!ft_strcmp(name, "path"))
		name = "PATH";
	while (cur)
	{
		if (ft_strstr(name, cur->variable))
			break ;
		cur = cur->next;
	}
	return (cur);
}

char	*find_var_content(t_env	**env, char *name)
{
	t_env	*var;

	var = find_var(env, name);
	if (!var)
		return (NULL);
	return (var->variable + ft_strlen(name) + 1);
}

t_env	**create_env(t_env **env, char **envp)
{
	int		i;
	t_env	*var;

	i = 0;
	while (envp[i])
	{
		var = create_var(envp[i]);
		if (!var)
			return (clear_env(env), NULL);
		env_add_back(env, var);
		i++;
	}
	return (env);
}

/* int	main(int argc, char **argv, char **envp)
{
	t_env	*env;

	env = NULL;
	(void)argc;
	(void)argv;
	create_env(&env, envp);
	display_env(&env);
	ft_printf("1 : %s\n", find_var(&env, "PATH")->variable);
	ft_printf("2 : %s\n", find_var(&env, "path")->variable);
	ft_printf("3 : %p\n", find_var(&env, "pAtH"));
	ft_printf("1 : %s\n", find_var_content(&env, "PATH"));
	ft_printf("2 : %s\n", find_var_content(&env, "path"));
	ft_printf("3 : %s\n", find_var_content(&env, "pAtH"));
	clear_env(&env);
	return (0);
}
 */