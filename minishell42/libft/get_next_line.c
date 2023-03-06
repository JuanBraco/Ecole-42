/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:19:11 by avast             #+#    #+#             */
/*   Updated: 2023/01/25 11:56:40 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*fill_buffer(int fd, char *buff)
{
	char	*tmp;
	int		a;

	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (0);
	tmp[BUFFER_SIZE] = '\0';
	a = BUFFER_SIZE;
	while (a == BUFFER_SIZE && !ft_strchr_gnl(buff, '\n'))
	{
		a = read(fd, tmp, BUFFER_SIZE);
		if (a == -1)
		{
			free(tmp);
			return (0);
		}
		tmp[a] = '\0';
		if (a != 0)
			buff = ft_strjoin_gnl(buff, tmp);
		if (!buff)
			break ;
	}
	free(tmp);
	return (buff);
}

char	*extract_line(char *buff)
{
	char	*str;
	int		len;

	len = 0;
	while (buff[len] && buff[len] != '\n')
		len++;
	if (buff[len] == '\n')
		len++;
	str = ft_substr_gnl(buff, 0, len);
	if (!str)
	{
		free (buff);
		return (0);
	}
	return (str);
}

char	*update_buffer(char *buff)
{
	char	*new_buff;
	int		start;

	start = 0;
	while (buff[start] && buff[start] != '\n')
		start++;
	if (buff[start] == '\n')
		start++;
	new_buff = ft_substr_gnl(buff, start, ft_strlen(buff) - start);
	if (!new_buff)
		return (0);
	free (buff);
	return ((char *)new_buff);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buff = fill_buffer(fd, buff);
	if (!buff)
		return (0);
	if (buff[0] == '\0')
		return (free_buff(&buff), NULL);
	str = extract_line(buff);
	if (!str)
		return (free_buff(&buff), NULL);
	buff = update_buffer(buff);
	if (!buff)
		return (0);
	if (fd == 0)
		free_buff(&buff);
	return (str);
}
