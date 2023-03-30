/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:58:48 by avast             #+#    #+#             */
/*   Updated: 2023/03/27 17:40:28 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"

static int	update_pwd(t_env **env, char *pwd, char *oldpwd)
{
	char	*char_pwd;
	char	*char_oldpwd;
	t_env	*var_pwd;
	t_env	*var_oldpwd;

	var_pwd = find_var(env, "PWD");
	if (var_pwd && var_pwd->value)
	{
		char_pwd = ft_strdup(pwd);
		if (!char_pwd)
			return (ft_printf_err("ft_strjoin : malloc failed\n"), -1);
		free(var_pwd->value);
		var_pwd->value = char_pwd;
	}
	var_oldpwd = find_var(env, "OLDPWD");
	if (var_oldpwd && var_oldpwd->value)
	{
		char_oldpwd = ft_strdup(oldpwd);
		if (!char_oldpwd)
			return (ft_printf_err("ft_strjoin : malloc failed\n"), -1);
		free(var_oldpwd->value);
		var_oldpwd->value = char_oldpwd;
	}
	return (0);
}

static int	got_to_dir_args(t_cmds *cmd, t_pipex *pipex, int fdout)
{
	char	*path;

	if (cmd->tab[1][0] == '~' && find_var(pipex->env, "HOME"))
		path = ft_strjoin(find_var(pipex->env, "HOME")->value,
				cmd->tab[1] + 1);
	else if (cmd->tab[1][0] == '-' && cmd->tab[1][1] == '\0')
	{
		if (builtin_pwd(NULL, fdout, pipex) == WRITE)
			return (WRITE);
		return (0);
	}
	else
		path = ft_strdup(cmd->tab[1]);
	if (chdir(path) == -1)
		return (ft_printf_err("cd : %s: %s\n", path,
				strerror(errno)), ft_free_str(path), -1);
	ft_free_str(path);
	return (0);
}

static int	go_to_dir(t_cmds *cmd, t_pipex *pipex, int fdout)
{
	char	*home;
	int		a;

	if (!cmd->tab[1])
	{
		if (!find_var(pipex->env, "HOME"))
			return (builtin_error_msg(HOME_NOT_SET, "cd", NULL, pipex));
		home = find_var(pipex->env, "HOME")->value;
		if (chdir(home) == -1)
			return (ft_printf_err("cd : %s\n", strerror(errno)), -1);
	}
	else
	{
		a = got_to_dir_args(cmd, pipex, fdout);
		if (a == WRITE)
			return (WRITE);
		else if (a < 0)
			return (-1);
	}
	return (0);
}

/* S'il y a un pipe ou plus, ne fait rien */
int	builtin_cd(t_cmds *cmd, t_pipex *pipex, int fdout)
{
	char	oldpwd[1000];
	char	pwd[1000];
	int		flag;
	int		a;

	flag = 0;
	if (ft_strtab_size(cmd->tab) > 2)
		return (builtin_error_msg(TOO_MANY_ARG, "cd", NULL, pipex), 0);
	if (pipex->nb_cmds > 1)
		return (0);
	if (!getcwd(oldpwd, 1000))
		flag = 1;
	a = go_to_dir(cmd, pipex, fdout);
	if (a < 0)
	{
		pipex->data->rv = 1;
		return (a);
	}
	if (!getcwd(pwd, 1000))
		return (ft_printf_err("getcwd : %s\n", strerror(errno)), -1);
	if (!flag || !find_var(pipex->env, "PWD")
		|| !find_var(pipex->env, "PWD")->value)
		update_pwd(pipex->env, pwd, oldpwd);
	update_env_char(pipex->env, pipex->envp);
	return (0);
}
