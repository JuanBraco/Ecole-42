/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:34:08 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/11/21 11:19:06 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	taille_calc(char const *s1, char const *s2)
{
	size_t	size;

	size = 0;
	if (s1 == 0)
		size = ft_strlen(s2);
	else if (s2 == 0)
		size = ft_strlen(s1);
	else
		size = ft_strlen(s1) + ft_strlen(s2);
	return (size);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	i;
	size_t	j;
	size_t	size;

	if (s1 == 0 && s2 == 0)
		return (0);
	size = taille_calc(s1, s2);
	ptr = malloc(sizeof(char) * (size + 1));
	if (ptr == 0)
		return (0);
	i = 0;
	while (s1 && i < ft_strlen(s1))
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && j < ft_strlen(s2))
	{
		ptr[i + j] = s2[j];
		j++;
	}
	ptr[i + j] = '\0';
	return (ptr);
}
