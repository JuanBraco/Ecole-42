/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:58:48 by avast             #+#    #+#             */
/*   Updated: 2023/03/03 15:07:22 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"
#include "../../includes/minishell.h"
#include "../../libft/libft.h"

/*On suppose que le flag -n ne peut que etre juste apres echo*/
int	builtin_echo(char **cmd, int flag_var, t_env **env)
{
	int		i;
	char	*line_var;

	if (!ft_strcmp(cmd[1], "-n"))
		i = 2;
	else
		i = 1;
	while (cmd[i])
	{
		line_var = cmd[i];
		if (flag_var == 1)
			line_var = update_var_line(cmd[i], env);
		ft_printf("%s", line_var);
		if (cmd[i + 1])
			ft_printf(" ");
		if (flag_var == 1)
			free(line_var);
		i++;
	}
	if (!ft_strcmp(cmd[1], "-n"))
		return (0);
	ft_printf("\n");
	return (0);
}

/* 
int	main(int argc, char **argv, char **envp)
{
	t_env	*env;

	env = NULL;
	(void)argc;
	create_env(&env, envp);
	ft_printf("On interprete les $ :\n");
	builtin_echo(argv + 1, 1, &env);
	ft_printf("On n'interprete pas les $ :\n");
	builtin_echo(argv + 1, 0, &env);
	clear_env(&env);
	return (0);
}
 */