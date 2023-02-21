/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:30:10 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/11/21 10:33:13 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	r_len;

	i = 0;
	r_len = len;
	if (s == 0)
		return (0);
	if (start > ft_strlen(s))
		return (ft_calloc(1, 1));
	if (len > ft_strlen(s) - start)
		r_len = ft_strlen(s) - start;
	ptr = malloc(sizeof(*s) * (r_len + 1));
	if (ptr == 0)
		return (0);
	while (s[i] != '\0' && i < r_len)
	{
		ptr[i] = s[i + start];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
