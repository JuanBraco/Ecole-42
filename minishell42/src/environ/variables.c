/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:24:31 by avast             #+#    #+#             */
/*   Updated: 2023/03/03 14:51:01 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/minishell.h"

char	*get_var_name(char *var)
{
	int		i;
	char	*var_name;

	if (!var[1] || (!ft_isalpha(var[1]) && var[1] != '_'))
		return (NULL);
	i = 1;
	while (var[i] && var[i] != 32
		&& (ft_isalnum(var[i]) || var[i] == '_'))
	{
		i++;
	}
	var_name = ft_substr(var, 1, i - 1);
	if (!var_name)
		return (NULL);
	return (var_name);
}

char	*replace_var_value(char *nl, char *var, int *start, t_env **env)
{
	char	*new_line;
	char	*var_content;

	var_content = find_var_content(env, var);
	new_line = ft_strreplace(nl, *start, ft_strlen(var) + 1, var_content);
	free(var);
	*start = 0;
	return (new_line);
}

char	*update_var_line(char *line, t_env **env)
{
	char	*nl;
	char	*var;
	int		i;

	i = 0;
	nl = ft_strdup(line);
	if (!nl)
		return (NULL);
	while (nl[i])
	{
		if (nl[i] == '$')
		{
			var = get_var_name(nl + i);
			if (var)
				nl = replace_var_value(nl, var, &i, env);
			else
				i++;
		}
		else
			i++;
	}
	return (nl);
}

/* 
int	main(int argc, char **argv, char **envp)
{
	t_env	*env;
	char	*str;
	int		i;

	env = NULL;
	(void)argc;
	create_env(&env, envp);
	i = 1;
	while (argv[i])
	{
		str = update_var_line(argv[i], &env);
		ft_printf("#%d\n- v1 : %s\n- v2 : %s\n\n", i, argv[i], str);
		free(str);
		i++;
	}
	clear_env(&env);
	return (0);
}
 */