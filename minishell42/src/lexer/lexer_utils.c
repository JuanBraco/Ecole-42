/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:52:21 by jde-la-f          #+#    #+#             */
/*   Updated: 2023/03/18 15:25:44 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_whitespace(char c)
{
	return (c == ' ' || (c > 8 && c < 14));
}

void	skip_spaces(char *str, int *i)
{
	int	j;

	j = 0;
	while (is_whitespace(str[*i + j]))
		j++;
	*i += j;
}

int	handle_quotes(int i, char *str, char del)
{
	int	j;

	j = 0;
	if (str && str[i + j] == del)
	{
		j++;
		while (str[i + j] != del && str[i + j])
			j++;
	}
	return (j);
}

int	find_matching_quote(char *line, int i, int *num_del, int del)
{
	int	j;

	j = i + 1;
	*num_del += 1;
	while (line[j] && line[j] != del)
		j++;
	if (line[j] == del)
		*num_del += 1;
	return (j - i);
}

int	count_quotes(char *line)
{
	int	i;
	int	s;
	int	d;

	s = 0;
	d = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '\"')
			i += find_matching_quote(line, i, &d, '\"');
		if (line[i] == '\'')
			i += find_matching_quote(line, i, &s, '\'');
		if (line[i])
			i++;
	}
	if ((d > 0 && d % 2 != 0) || (s > 0 && s % 2 != 0))
		return (0);
	return (1);
}
