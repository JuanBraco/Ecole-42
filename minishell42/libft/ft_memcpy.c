/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:42:39 by avast             #+#    #+#             */
/*   Updated: 2022/11/09 10:26:34 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*str_dest;

	if (dest == 0 && src == 0)
		return (0);
	str_dest = dest;
	while (n)
	{
		*str_dest = *(unsigned char *)(src);
		str_dest++;
		src++;
		n--;
	}
	return (dest);
}
