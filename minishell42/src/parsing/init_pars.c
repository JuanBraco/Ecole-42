/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanbraco <juanbraco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:49:16 by jde-la-f          #+#    #+#             */
/*   Updated: 2023/03/10 11:11:39 by juanbraco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void remove_double_spaces(char *str)
{
    int i = 0;
	int j = 0;
    int quote_count = 0, single_quote_count = 0;

    while (str[i] != '\0') {
        if (str[i] == '"' && (i == 0 || str[i - 1] != '\\')) {
            quote_count++;
        }
        if (str[i] == '\'' && (i == 0 || str[i - 1] != '\\')) {
            single_quote_count++;
        }
        if (str[i] == ' ' && str[i + 1] == ' ' && quote_count % 2 == 0 && single_quote_count % 2 == 0) {
            continue;
        }
        str[j++] = str[i++];
    }
    str[j] = '\0';
}

static int	ft_count_words(const char *s, char *c, int counts[2])
{
	int		q[2];

	q[0] = 0;
	q[1] = 0;
	while (s[counts[0]] != '\0')
	{
		if (!ft_strchr(c, s[counts[0]]))
		{
			counts[1]++;
			while ((!ft_strchr(c, s[counts[0]]) || q[0]) && s[counts[0]] != '\0')
			{
				if (!q[1] && (s[counts[0]] == '\"' || s[counts[0]] == '\''))
					q[1] = s[counts[0]];
				q[0] = (q[0] + (s[counts[0]] == q[1])) % 2;
				q[1] *= q[0] != 0;
				counts[0]++;
			}
			if (q[0])
				return (-1);
		}
		else
			counts[0]++;
	}
	return (counts[1]);
}


static char	**ft_fill_array(char **aux, char const *s, char *set, int i[3])
{
	int		s_len;
	int		q[2];

	q[0] = 0;
	q[1] = 0;
	s_len = ft_strlen(s);
	while (s[i[0]])
	{
		while (ft_strchr(set, s[i[0]]) && s[i[0]] != '\0')
			i[0]++;
		i[1] = i[0];
		while ((!ft_strchr(set, s[i[0]]) || q[0] || q[1]) && s[i[0]])
		{
			q[0] = (q[0] + (!q[1] && s[i[0]] == '\'')) % 2;
			q[1] = (q[1] + (!q[0] && s[i[0]] == '\"')) % 2;
			i[0]++;
		}
		if (i[1] >= s_len)
			aux[i[2]++] = "\0";
		else
			aux[i[2]++] = ft_substr(s, i[1], i[0] - i[1]);
	}
	return (aux);
}

char	**ft_cmdtrim(char const *s, char *set)
{
	char	**aux;
	int		nwords;
	int		i[3];
	int		counts[2];

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	counts[0] = 0;
	counts[1] = 0;
	if (!s)
		return (NULL);
	nwords = ft_count_words(s, set, counts);
	if (nwords == -1)
		return (NULL);
	aux = malloc((nwords + 1) * sizeof(char *));
	if (aux == NULL)
		return (NULL);
	aux = ft_fill_array(aux, s, set, i);
	aux[nwords] = NULL;
	return (aux);
}