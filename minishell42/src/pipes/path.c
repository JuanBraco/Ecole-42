/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:59:09 by avast             #+#    #+#             */
/*   Updated: 2023/02/28 17:21:19 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipes.h"
#include "../../libft/libft.h"

char	*ft_strjoin_cmd(char const *s1, char const *s2)
{
	char	*str;
	size_t	size;
	size_t	i;

	if (s1 == 0)
		size = ft_strlen(s2) + 1;
	else if (s2 == 0)
		size = ft_strlen(s1) + 1;
	else
		size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)ft_calloc(size + 1, sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (i < size)
	{
		while (s1 != 0 && *s1 != 0)
			str[i++] = *s1++;
		str[i++] = '/';
		while (s2 != 0 && *s2 != 0)
			str[i++] = *s2++;
	}
	str[i] = '\0';
	return (str);
}

int	check_path(void)
{
	int	i;

	i = 0;
	while (environ[i])
	{
		if (ft_strstr("PATH=", environ[i]))
			return (i);
		else
			i++;
	}
	return (-1);
}

char	*get_command_path(char *cmd)
{
	char	**path;
	char	*cmd_path;
	int		i;

	i = check_path();
	if (!cmd)
		return (NULL);
	if (i < 0 || cmd[0] == '/' || cmd[0] == '.' || cmd[0] == '~')
		return (ft_strdup(cmd));
	path = ft_split((environ[i] + 5), ':');
	i = 0;
	cmd_path = ft_strjoin_cmd(path[i], cmd);
	while (path[i] && access(cmd_path, X_OK) == -1)
	{
		i++;
		free(cmd_path);
		cmd_path = ft_strjoin_cmd(path[i], cmd);
	}
	if (access(cmd_path, X_OK) == 0)
		return (free_tab(path, -1), cmd_path);
	else if (access(cmd_path, F_OK) == 0)
		return (free_tab(path, -1), cmd_path);
	else
		return (free_tab(path, -1), free(cmd_path), NULL);
}

void	free_path(char *path, char **arg)
{
	if (path)
		free(path);
	free_tab(arg, -1);
}
