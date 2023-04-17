/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ_list_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:24:31 by avast             #+#    #+#             */
/*   Updated: 2023/03/23 12:38:56 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/minishell.h"

/* Supprimer une variable d'env selon son nom */
int	env_delete_var(t_env **env, char *var)
{
	t_env	*tmp;
	t_env	*cur;

	if (ft_strstr(var, (*env)->name))
	{
		tmp = *env;
		*env = (*env)->next;
		if (tmp->value)
			free(tmp->value);
		return (free(tmp->name), free(tmp), 0);
	}
	cur = *env;
	while (cur && cur->next)
	{
		if (ft_strstr(var, cur->next->name))
		{
			tmp = cur->next;
			cur->next = cur->next->next;
			if (tmp->value)
				free(tmp->value);
			return (free(tmp->name), free(tmp), 0);
		}
		cur = cur->next;
	}
	return (0);
}

/* Retrouver le pointeur sur la variable d'env en fonction du nom */
t_env	*find_var(t_env	**env, char *name)
{
	t_env	*cur;

	cur = *env;
	while (cur)
	{
		if (!ft_strcmp(name, cur->name))
			break ;
		cur = cur->next;
	}
	return (cur);
}

/* Utile pour set et unset des variables */
int	check_var_name(char *name)
{
	int	i;

	if (!ft_isalpha(name[0]) && name[0] != '_')
		return (0);
	i = 1;
	while (name[i])
	{
		if (!ft_isalnum(name[i]) && name[i] != '_')
			return (0);
		i++;
	}
	return (1);
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
		free(tmp->name);
		if (tmp->value)
			free(tmp->value);
		free(tmp);
	}
	*env = NULL;
}
