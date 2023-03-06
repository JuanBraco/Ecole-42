/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:07:48 by avast             #+#    #+#             */
/*   Updated: 2023/03/03 15:07:44 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>

/*CD*/
int	builtin_cd(char **cd_cmd, t_env **env);
int	update_pwd(t_env **env, char *pwd, char *oldpwd);

/*ECHO*/
int	builtin_echo(char **cmd, int flag_var, t_env **env);

/*PWD*/
int	builtin_pwd(char **cmd);

#endif