/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ_char_set.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:03:13 by avast             #+#    #+#             */
/*   Updated: 2023/03/27 17:47:33 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/minishell.h"

int	get_var_count(t_env **env)
{
	int		size;
	t_env	*cur;

	if (!env || !*env)
		return (0);
	size = 0;
	cur = *env;
	while (cur)
	{
		if (cur->value && cur->value[0])
			size++;
		cur = cur->next;
	}
	return (size);
}

char	**create_env_char(t_env **env)
{
	int		size;
	char	**tab;
	t_env	*cur;
	int		i;

	size = get_var_count(env);
	tab = malloc(sizeof (char *) * (size + 1));
	i = 0;
	cur = *env;
	while (i < size)
	{
		while (!cur->value || !cur->value[0])
			cur = cur->next;
		tab[i] = ft_strjoin_three(cur->name, "=", cur->value);
		if (!tab[i])
			ft_free_strtab(tab, i - 1);
		i++;
		cur = cur->next;
	}
	tab[i] = NULL;
	return (tab);
}

char	**update_env_char(t_env **env, char ***tab)
{
	ft_free_strtab(*tab, -2);
	*tab = create_env_char(env);
	if (!tab)
		return (NULL);
	return (*tab);
}
