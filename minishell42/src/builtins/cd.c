/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:58:48 by avast             #+#    #+#             */
/*   Updated: 2023/03/03 11:38:45 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"
#include "../../includes/minishell.h"
#include "../../libft/libft.h"


int	update_pwd(t_env **env, char *pwd, char *oldpwd)
{
	char	*char_pwd;
	char	*char_oldpwd;
	t_env	*var_pwd;
	t_env	*var_oldpwd;

	var_pwd = find_var(env, "PWD");
	if (var_pwd)
	{
		char_pwd = ft_strjoin("PWD=", pwd);
		if (!char_pwd)
			return (ft_printf_err("ft_strjoin : malloc failed\n"), -1);
		free(var_pwd->variable);
		var_pwd->variable = char_pwd;
	}
	var_oldpwd = find_var(env, "OLDPWD");
	if (var_oldpwd)
	{
		char_oldpwd = ft_strjoin("OLDPWD=", oldpwd);
		if (!char_oldpwd)
			return (ft_printf_err("ft_strjoin : malloc failed\n"), -1);
		free(var_oldpwd->variable);
		var_oldpwd->variable = char_oldpwd;
	}
	return (0);
}

int	builtin_cd(char **cmd, t_env **env)
{
	char	oldpwd[1000];
	char	pwd[1000];
	char	*home;

	//je suppose que cmd[0] = "cd" et cmd[1] = "path ou on veut aller"
	if (!getcwd(oldpwd, 1000))
		return (ft_printf_err("getwcd : %s\n", strerror(errno)), -1);
	// Dans le cas ou on fait juste "cd"
	if (!cmd[1])
	{
		home = find_var(env, "HOME")->variable;
		if (!home)
			return (0);
		if (chdir(home + 5) == -1)
			return (ft_printf_err("cd : %s\n", strerror(errno)), -1);
	}
	else
	{
		if (chdir(cmd[1]) == -1)
			return (ft_printf_err("cd : %s: %s\n", strerror(errno), cmd[1]), -1);
	}
	if (!getcwd(pwd, 1000))
		return (ft_printf_err("getwcd : %s\n", strerror(errno)), -1);
	update_pwd(env, pwd, oldpwd);
	return (0);
}

/* 
int	main(int ac, char **argv, char **envp)
{
	t_env	*env;

	(void)ac;
	env = NULL;
	create_env(&env, envp);
	ft_printf("before : %s\n", find_var(&env, "PWD")->variable);
	ft_printf("before : %s\n", find_var(&env, "OLDPWD")->variable);
	builtin_cd(argv + 1, &env);
	ft_printf("after : %s\n", find_var(&env, "PWD")->variable);
	ft_printf("after : %s\n", find_var(&env, "OLDPWD")->variable);
	clear_env(&env);
	return (0);
}
 */