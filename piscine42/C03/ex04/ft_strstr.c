/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 14:23:39 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/09/20 22:23:34 by jde-la-f         ###   ########.fr       */
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

char	*ft_strstr(char *str, char *to_find)
{
	int	t;
	int	i;

	t = 0;
	i = 0;
	if (ft_strlen(to_find) == '\0')
		return (str);
	while (str[i] != '\0')
	{
		if (str[i] != to_find[t])
			t = 0;
		while (str[i] == to_find[t])
		{
			t++;
		}
		if (t == ft_strlen(to_find))
		{
			return (str + i - ft_strlen(to_find) + 1);
		}
		i++;
	}
	return ('\0');
}
/*#include <stdio.h>
#include <string.h>

int main(void)
{
	char c[] = "";
	char d[] = "a";

	printf("%s", ft_strstr(c, d));
}*/
