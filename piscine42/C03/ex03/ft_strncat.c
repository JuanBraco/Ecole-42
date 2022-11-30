/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 21:11:27 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/09/20 11:21:27 by jde-la-f         ###   ########.fr       */
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

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	destl;
	unsigned int	i;

	i = 0;
	destl = ft_strlen(dest);
	while (src[i] != '\0' && i < nb)
	{
		dest[destl + i] = src[i];
		i++;
	}
	dest[destl + i] = '\0';
	return (dest);
}
/*#include <string.h>
#include <stdio.h>
int main(void)
{
	char c[] = "abc";
	char d[] = "def";
	printf("%s", strncat(c, d, 0));
}*/
