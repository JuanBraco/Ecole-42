/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:17:46 by avast             #+#    #+#             */
/*   Updated: 2023/03/14 12:22:37 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_strtab(char **tab, int index)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	if (index < -1)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
	}
	else
	{
		while (index >= 0)
		{
			free(tab[index]);
			index--;
		}
	}
	free(tab);
}
