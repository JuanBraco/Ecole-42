/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:29:43 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/09/21 12:37:04 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	destl;
	unsigned int	srcl;

	i = 0;
	destl = ft_strlen(dest);
	srcl = ft_strlen(src);
	if (size <= destl || size == '\0')
		return (srcl + size);
	while (src[i] != '\0' && i < size - destl - 1)
	{
		dest[destl + i] = src[i];
		i++;
	}
	dest[destl + i] = '\0';
	return (destl + srcl);
}

#include <string.h>
#include <stdio.h>
int main(void)
{
	char c[] = "efgh";
	char d[] = "abcd";
	printf("%d", strlcat(d, c, 6));
}
