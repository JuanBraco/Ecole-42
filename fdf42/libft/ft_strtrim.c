/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:48:46 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/11/21 10:31:32 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	includes(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	if (!s1 || !set)
		return (0);
	j = ft_strlen(s1) - 1;
	while (s1[i] != '\0' && includes(s1[i], set) == 1)
		i++;
	while (j > i && includes(s1[j], set) == 1)
		j--;
	ptr = malloc(sizeof(char) * (j - i + 2));
	if (ptr == 0)
		return (0);
	while (i <= j)
		ptr[k++] = s1[i++];
	ptr[k] = '\0';
	return (ptr);
}
