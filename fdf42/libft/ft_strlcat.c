/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:42:23 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/11/16 09:57:07 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	destl;
	size_t	srcl;

	i = 0;
	if (dest == 0 && size == 0)
		return (0);
	destl = ft_strlen(dest);
	srcl = ft_strlen((char *)src);
	if (size <= destl || size == 0)
		return (srcl + size);
	while (src[i] != '\0' && i < size - destl - 1)
	{
		dest[destl + i] = src[i];
		i++;
	}
	dest[destl + i] = '\0';
	return (destl + srcl);
}
