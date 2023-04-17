/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:52:03 by avast             #+#    #+#             */
/*   Updated: 2023/03/18 15:13:52 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(char const *s1, char const *s2, char const *s3)
{
	if (s1 == 0 && s2 == 0 && s3 == 0)
		return (0);
	else if (s1 == 0 && s2 == 0)
		return (ft_strlen(s3));
	else if (s1 == 0 && s3 == 0)
		return (ft_strlen(s2));
	else if (s2 == 0 && s3 == 0)
		return (ft_strlen(s1));
	else if (s1 == 0)
		return (ft_strlen(s2) + ft_strlen(s3));
	else if (s2 == 0)
		return (ft_strlen(s1) + ft_strlen(s3));
	else if (s3 == 0)
		return (ft_strlen(s1) + ft_strlen(s2));
	else
		return (ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3));
}

char	*ft_strjoin_three(char const *s1, char const *s2, char const *s3)
{
	char	*str;
	size_t	size;
	size_t	i;

	size = get_size(s1, s2, s3);
	if (!size)
		return (NULL);
	str = (char *)ft_calloc(size + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < size)
	{
		while (s1 != 0 && *s1 != 0)
			str[i++] = *s1++;
		while (s2 != 0 && *s2 != 0)
			str[i++] = *s2++;
		while (s3 != 0 && *s3 != 0)
			str[i++] = *s3++;
	}
	str[i] = '\0';
	return (str);
}
