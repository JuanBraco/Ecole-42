/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_expansion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:08:39 by avast             #+#    #+#             */
/*   Updated: 2023/03/23 12:24:44 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/minishell.h"

/* Recuperer le nom de la variable apres le $ */
/* Gerer le $? plus tard selon ce qu'on decide de faire */
char	*get_var_name(char *var)
{
	int		i;
	char	*var_name;

	if (var[1] == '?')
		return (ft_strdup("?"));
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

/* Sous-fonction de update_var_line() pour remplacer une var de la line */
char	*replace_var_value(char *nl, char *name, int *start, t_data *data)
{
	char	*new_line;
	t_env	*var;
	char	*var_content;

	var = find_var(data->env, name);
	if (var && var->value)
		var_content = var->value;
	else if (name[0] == '?')
		var_content = ft_itoa(data->rv);
	else
		var_content = NULL;
	new_line = ft_strreplace(nl, *start, ft_strlen(name) + 1, var_content);
	if (name[0] == '?')
		free(var_content);
	free(name);
	*start = 0;
	return (new_line);
}

static void	check_flags(t_flag *flags, char c)
{
	if (flags->double_q == 0 && c == '\"')
		flags->double_q = 1;
	else if (flags->double_q == 1 && c == '\"')
		flags->double_q = 0;
	else if (flags->single_q == 0 && c == '\'' && flags->double_q == 0)
		flags->single_q = 1;
	else if (flags->single_q == 1 && c == '\'')
		flags->single_q = 0;
}

static void	handle_var(char **nl, int *i, t_flag *flags, t_data *data)
{
	char	*var;

	var = get_var_name(*nl + *i);
	if (var)
	{
		*nl = replace_var_value(*nl, var, i, data);
		flags->single_q = 0;
		flags->double_q = 0;
	}
	else
		(*i)++;
}

/* Remplacer tous les $VAR par leur valeur, au besoin on peut free line */
char	*update_var_line(char *line, t_data *data, int flag_hd)
{
	char	*nl;
	t_flag	flags;
	int		i;

	i = 0;
	nl = ft_strdup(line);
	flags.single_q = 0;
	flags.double_q = 0;
	if (!nl)
		return (NULL);
	while (nl[i])
	{
		check_flags(&flags, nl[i]);
		if (nl[i] == '$' && (flags.single_q == 0 || flag_hd))
			handle_var(&nl, &i, &flags, data);
		else
			i++;
	}
	return (free(line), nl);
}
