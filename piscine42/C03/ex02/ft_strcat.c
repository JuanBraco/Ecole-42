/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 20:45:18 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/09/20 16:06:59 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_strlen(char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	destl;

	i = 0;
	destl = ft_strlen(dest);
	while (src[i] != '\0')
	{
		dest[destl + i] = src[i];
		i++;
	}
	dest[destl + i] = '\0';
	return (dest);
}

/*#include <stdio.h>
#include <string.h>
int main(void)
{
	char c[] = "def\0";
	char d[] = "abcllllllf";
	printf("%s", ft_strcat(c, d));
}*/
