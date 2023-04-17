/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:31:18 by jde-la-f          #+#    #+#             */
/*   Updated: 2023/03/18 14:33:49 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
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
			ft_free_tab(t_dup);
			return (t_dup);
		}
		i++;
	}
	return (t_dup);
}
