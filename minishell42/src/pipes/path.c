/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:59:09 by avast             #+#    #+#             */
/*   Updated: 2023/03/23 11:54:37 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
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

/* Obtenir le path d'une commande  */
char	*get_command_path(char *cmd, t_env **environ)
{
	t_env	*paths;
	char	**sub_path;
	char	*cmd_path;
	int		i;

	paths = find_var(environ, "PATH");
	if (!paths || !(paths->value)
		|| cmd[0] == '/' || cmd[0] == '.' || cmd[0] == '~')
		return (ft_strdup(cmd));
	if (!cmd[0])
		return (NULL);
	sub_path = ft_split(paths->value, ':');
	i = 0;
	cmd_path = ft_strjoin_cmd(sub_path[i], cmd);
	while (sub_path[i] && access(cmd_path, X_OK) == -1)
	{
		i++;
		free(cmd_path);
		cmd_path = ft_strjoin_cmd(sub_path[i], cmd);
	}
	if (access(cmd_path, X_OK) == 0 || access(cmd_path, F_OK) == 0)
		return (ft_free_strtab(sub_path, -2), cmd_path);
	else
		return (ft_free_strtab(sub_path, -2), free(cmd_path), NULL);
}
