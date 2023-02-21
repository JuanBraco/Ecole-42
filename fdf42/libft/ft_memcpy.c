/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:41:52 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/11/14 16:55:29 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == 0 && src == 0)
		return (0);
	while (i < n)
	{
		*(char *)(dest + i) = *(char *)(src + i);
		i++;
	}
	return (dest);
}
