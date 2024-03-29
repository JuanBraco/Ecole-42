/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:38:43 by jde-la-f          #+#    #+#             */
/*   Updated: 2023/01/30 15:16:19 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_read(char *buf, int fd)
{
	char	*temp_buf;
	int		read_bites;

	temp_buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (temp_buf == 0)
		return (0);
	temp_buf[BUFFER_SIZE] = 0;
	read_bites = 1;
	while (read_bites > 0)
	{
		read_bites = read(fd, temp_buf, BUFFER_SIZE);
		if (read_bites == -1)
		{
			free(buf);
			free(temp_buf);
			return (NULL);
		}
		temp_buf[read_bites] = 0;
		buf = ft_concat(buf, temp_buf);
		if (ft_strchr(temp_buf, '\n'))
			break ;
	}
	free(temp_buf);
	return (buf);
}

char	*fill_line(char *buf)
{
	char	*line;
	int		i;

	i = 0;
	if (!*buf)
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		line = ft_calloc(sizeof(char), (i + 2));
	else
		line = ft_calloc(sizeof(char), (i + 1));
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		line[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
	{
		line[i] = buf[i];
		i++;
	}
	line[i] = 0;
	return (line);
}

char	*next_line(char *buf)
{
	char	*new_line;
	int		i;
	int		j;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
	{
		free(buf);
		return (NULL);
	}
	new_line = ft_calloc((ft_strlen(buf) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buf[i])
		new_line[j++] = buf[i++];
	new_line[j] = 0;
	free(buf);
	return (new_line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buf)
		buf = ft_calloc(1, 1);
	buf = ft_read(buf, fd);
	if (!buf)
		return (NULL);
	line = fill_line(buf);
	buf = next_line(buf);
	return (line);
}

/*int main(int argc, char **argv)
{
	int fd;
	int line;
	char *buff;

	line = 0;
	//fd = open(argv[1], O_RDONLY);
	printf("%i", fd);
	while ((buff = get_next_line(fd)) > 0)
	{
		printf(" Line #%d: %s\n", ++line, buff);
		free(buff);
	}
	return (0);
}*/
