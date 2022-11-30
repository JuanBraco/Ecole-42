/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 19:14:17 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/10/01 17:30:01 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

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

int	t_s(char **strs, int size)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != 0)
		{
			c++;
			j++;
		}
		i++;
	}
	return (c);
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

char	*c_ptr_0(void)
{
	char	*c;

	c = malloc(sizeof(char) * 1);
	*c = 0;
	return (c);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ptr;
	int		i;
	int		t;

	i = 0;
	if (size == 0)
		return (c_ptr_0());
	t = ft_strlen(sep);
	ptr = malloc(sizeof(char) * (t_s(strs, size) + (size - 1) * t + 1));
	if (ptr == 0)
		return (0);
	while (i < t_s(strs, size) + (size - 1) * t)
		ptr[i++] = 0;
	i = 0;
	while (i < size)
	{
		ft_strcat(ptr, strs[i]);
		if (i < size - 1)
			ft_strcat(ptr, sep);
		i++;
	}
	ptr[t_s(strs, size) + t * (size - 1)] = '\0';
	return (ptr);
}

int	main(void)
{
	char *s1 = "Hello";
	char *s3 = "";
	char *s2 = "Hell";
	char *sep = "_";

	char *strs[3];
	
	strs[0] = s1;
	strs[1] = s2;
	strs[2] = s3;
	char *res = ft_strjoin(3 ,strs,sep);
	printf("%s", res);
	free(res);		
}
