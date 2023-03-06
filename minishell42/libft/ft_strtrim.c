/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:52:03 by avast             #+#    #+#             */
/*   Updated: 2022/11/09 16:27:37 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*str;
	unsigned int	start;
	size_t			end;

	if (!s1)
		return (0);
	if (!set)
	{
		str = ft_strdup(s1);
		if (!str)
			return (0);
		return (str);
	}
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_is_in_set(s1[start], set))
		start++;
	while (s1[end] && ft_is_in_set(s1[end], set))
		end--;
	str = ft_substr(s1, start, end - start + 1);
	if (!str)
		return (0);
	return (str);
}
