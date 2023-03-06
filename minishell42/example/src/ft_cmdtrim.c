/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmdtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 15:28:36 by aperez-b          #+#    #+#             */
/*   Updated: 2023/03/01 16:01:32 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

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
