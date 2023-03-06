/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:49:38 by avast             #+#    #+#             */
/*   Updated: 2022/11/10 18:42:37 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*tab;
	size_t			mem;
	size_t			i;

	if (nmemb == 0 || size == 0)
		return (ft_calloc(1, 1));
	mem = nmemb * size;
	if (mem / nmemb != size)
		return (0);
	tab = malloc(mem);
	if (!tab)
		return (0);
	i = 0;
	while (i < mem)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}
