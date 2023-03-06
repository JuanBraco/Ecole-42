/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:58:48 by avast             #+#    #+#             */
/*   Updated: 2023/03/01 16:09:41 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"
#include "../../includes/minishell.h"
#include "../../libft/libft.h"

int	builtin_pwd(char **cmd)
{
	char	pwd[1000];

	//je suppose que cmd[0] = "cd" et cmd[1] = "path ou on veut aller"
	if (!getcwd(oldpwd, 1000))
		return (ft_printf_err("getwcd : %s\n", strerror(errno)), -1);
}
