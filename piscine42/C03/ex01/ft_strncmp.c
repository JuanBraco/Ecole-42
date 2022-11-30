/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 19:24:42 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/09/20 19:48:27 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n - 1)
	{
			i++;
	}
	return (s1[i] - s2[i]);
}
/*#include <string.h>

int	main(void)
{
	char c[] = "ab";
	char d[] = "abbb";
	printf("%d", ft_strncmp(c, d, 1));
}*/
