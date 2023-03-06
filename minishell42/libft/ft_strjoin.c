/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:52:03 by avast             #+#    #+#             */
/*   Updated: 2023/01/16 16:26:03 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	size;
	size_t	i;

	if (s1 == 0 && s2 == 0)
		return (0);
	if (s1 == 0)
		size = ft_strlen(s2);
	else if (s2 == 0)
		size = ft_strlen(s1);
	else
		size = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)ft_calloc(size + 1, sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (i < size)
	{
		while (s1 != 0 && *s1 != 0)
			str[i++] = *s1++;
		while (s2 != 0 && *s2 != 0)
			str[i++] = *s2++;
	}
	str[i] = '\0';
	return (str);
}
