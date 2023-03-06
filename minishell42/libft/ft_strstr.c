/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:48:52 by avast             #+#    #+#             */
/*   Updated: 2023/02/17 16:49:07 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strstr(const char *to_find, const char *big)
{
	size_t	i;

	i = 0;
	while (to_find[i] && big[i] && to_find[i] == big[i])
		i++;
	if (!to_find[i])
		return (1);
	return (0);
}
