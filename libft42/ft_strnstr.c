/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:51:49 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/11/16 15:48:05 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *l, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*l == 0 || l == 0)
		return ((char *)big);
	if (len == 0)
		return (0);
	while (big[i] && i < len)
	{
		j = 0;
		while (l[j] && l[j] == big[i + j] && big[i + j] && i + j < len)
		{
			if (!l[j + 1])
			{
				return ((char *)(big + i));
			}
			j++;
		}
		i++;
	}
	return (0);
}
