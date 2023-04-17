/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanbraco <juanbraco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:34:56 by jde-la-f          #+#    #+#             */
/*   Updated: 2023/03/21 17:01:28 by juanbraco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*delete_quotes(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\"' || str[i] == '\'')
		{
			j = 1;
			while (str[i + j] != str[i])
				j++;
			ft_strlcpy(&str[i], &str[i + 1], ft_strlen(str) - i);
			i += j - 1;
			ft_strlcpy(&str[i], &str[i + 1], ft_strlen(str) - i);
		}
		if (str[i] && str[i] != '\"' && str[i] != '\'')
			i++;
	}
	return (str);
}

int	check_token(int c)
{
	if (c == '|')
		return (PIPE);
	else if (c == '>')
		return (GREAT);
	else if (c == '<')
		return (LESS);
	else
		return (0);
}

int	handle_token(char *str, int i, t_node **node_list)
{
	int	token;

	token = check_token(str[i]);
	if (token == GREAT && check_token(str[i + 1]) == GREAT)
	{
		if (!add_node(NULL, GREAT_GREAT, node_list))
			return (-1);
		return (2);
	}
	else if (token == LESS && check_token(str[i + 1]) == LESS)
	{
		if (!add_node(NULL, LESS_LESS, node_list))
			return (-1);
		return (2);
	}
	else if (token)
	{
		if (!add_node(NULL, token, node_list))
			return (-1);
		return (1);
	}	
	return (0);
}

int	read_words(int i, char *str, t_node **node_list)
{
	int	j;

	j = 0;
	while (str && str[i + j] && !check_token(str[i + j]))
	{
		j += handle_quotes(i + j, str, '\"');
		j += handle_quotes(i + j, str, '\'');
		if (is_whitespace(str[i + j]))
			break ;
		else
			j++;
	}
	if (!add_node(ft_substr(str, i, j), 0, node_list))
		return (-1);
	return (j);
}

int	text_reader(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (data->text && data->text[i])
	{
		j = 0;
		skip_spaces(data->text, &i);
		if (check_token(data->text[i]))
			j = handle_token(data->text, i, &data->node_list);
		else
			j = read_words(i, data->text, &data->node_list);
		if (j < 0)
			return (0);
		i += j;
	}
	return (1);
}
