/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:51:51 by avast             #+#    #+#             */
/*   Updated: 2023/01/25 11:35:57 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchr_gnl(char *s, int c)
{
	if (s == 0)
		return (0);
	while (*s && *s != (unsigned char)c)
		s++;
	if (*s == (unsigned char)c)
		return (1);
	return (0);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char		*s;
	long int	size;
	long int	i;
	char		*tmp;

	tmp = s1;
	if (s1 == 0)
		size = ft_strlen(s2);
	else
		size = ft_strlen(s1) + ft_strlen(s2);
	s = (char *)ft_calloc(size + 1, sizeof(char));
	if (!s)
		return (0);
	i = 0;
	while (i < size)
	{
		while (s1 != 0 && *s1 != 0)
			s[i++] = *s1++;
		while (s2 != 0 && *s2 != 0)
			s[i++] = *s2++;
	}
	s[i] = '\0';
	if (tmp)
		free(tmp);
	return (s);
}

char	*ft_substr_gnl(char *s, unsigned int start, unsigned int len)
{
	char		*str;
	long int	size;
	long int	i;

	if (s == 0)
		return (0);
	if (start > ft_strlen(s) || len == 0)
		return (ft_calloc(1, 1));
	if (ft_strlen(s) - start < len)
		size = ft_strlen(s) - start;
	else
		size = len;
	str = ft_calloc(size + 1, sizeof(char));
	if (!str)
	{
		free(s);
		return (0);
	}
	i = -1;
	while (++i < size)
		str[i] = s[start + i];
	str[i] = '\0';
	return (str);
}

void	free_buff(char **buff)
{
	free(*buff);
	*buff = 0;
}
