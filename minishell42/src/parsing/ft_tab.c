/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanbraco <juanbraco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:59:58 by juanbraco         #+#    #+#             */
/*   Updated: 2023/03/10 14:09:51 by juanbraco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_tablen(char **m)
{
	int	i;

	i = 0;
	while (m && m[i])
		i++;
	return (i);
}

char	**ft_tab_replace_in(char ***big, char **small, int n)
{
	char	**aux;
	int		i[3];

	i[0] = -1;
	i[1] = -1;
	i[2] = -1;
	if (!big || !*big || n < 0 || n >= ft_tablen(*big))
		return (NULL);
	aux = ft_calloc(ft_tablen(*big) + ft_tablen(small), sizeof(char *));
	while (aux && big[0][++i[0]])
	{
		if (i[0] != n)
			aux[++i[2]] = ft_strdup(big[0][i[0]]);
		else
		{
			while (small && small[++i[1]])
				aux[++i[2]] = ft_strdup(small[i[1]]);
		}
	}
	ft_free_tab(big);
	*big = aux;
	return (*big);
}

char	**ft_tabdup(char **tab)
{
	char	**t_dup;
	size_t	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	t_dup = ft_calloc(sizeof(char *), i + 1);
	if (!t_dup)
		return (NULL);
	i = 0;
	while (tab[i] != NULL)
	{
		t_dup[i] = ft_strdup(tab[i]);
		if (t_dup[i] == NULL)
		{
			ft_free_tab(&t_dup);
			return (t_dup);
		}
		i++;
	}
	return (t_dup);
}

char	**ft_extend_tab(char **in, char *newstr)
{
	char	**out;
	int		len;
	int		i;

	i = -1;
	out = NULL;
	if (!newstr)
		return (in);
	len = ft_tablen(in);
	out = malloc(sizeof(char *) * (len + 2));
	if (!out)
		return (in);
	out[len + 1] = NULL;
	while (++i < len)
	{
		out[i] = ft_strdup(in[i]);
		if (!out[i])
		{
			ft_free_tab(&in);
			ft_free_tab(&out);
		}
	}
	out[i] = ft_strdup(newstr);
	ft_free_tab(&in);
	return (out);
}