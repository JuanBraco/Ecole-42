/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:49:16 by jde-la-f          #+#    #+#             */
/*   Updated: 2023/03/27 15:44:10 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

volatile t_global	g_global;

int	reset_prompt(t_data *data, t_env **env)
{
	if (data->list_cmds)
		ft_clear_list_cmd(&data->list_cmds);
	data->list_cmds = NULL;
	free(data->text);
	data->text = NULL;
	g_global.g_status = 0;
	prompt_loop(data, env);
	return (1);
}

void	init_text(t_data *data, t_env **env)
{
	char		*tmp;

	if (data->text && !data->text[0])
	{
		free(data->text);
		prompt_loop(data, env);
	}
	add_history(data->text);
	tmp = ft_strtrim(data->text, " ");
	free(data->text);
	data->text = tmp;
	if (!data->text)
	{
		ft_free_strtab(data->envp, -2);
		clear_env(data->env);
		ft_putendl_fd("\b\bexit", STDOUT_FILENO);
		exit(EXIT_SUCCESS);
	}
	if (!data->text[0])
	{
		free(data->text);
		prompt_loop(data, env);
	}
}

void	del_quotes(t_data *data)
{
	t_cmds	*cur;
	t_node	*redir;
	int		i;

	cur = data->list_cmds;
	while (cur)
	{
		redir = cur->redir;
		i = 0;
		while (cur->tab[i])
		{
			delete_quotes(cur->tab[i]);
			i++;
		}
		while (redir)
		{
			delete_quotes(redir->str);
			redir = redir->next;
		}
		cur = cur->next;
	}
}

int	prompt_loop(t_data *data, t_env **env)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, &sig_int);
	data->text = readline("minishell$ ");
	if (g_global.g_status == SIG_INT)
	{
		data->rv = 130;
		g_global.g_status = 0;
	}
	init_text(data, env);
	if (!count_quotes(data->text))
		return (ft_error(2, data));
	data->text = update_var_line(data->text, data, NO);
	if (!text_reader(data))
		return (ft_error(1, data));
	count_pipes(data->node_list, data);
	parser(data);
	del_quotes(data);
	pipex(data);
	ft_clear_list_cmd(&data->list_cmds);
	reset_prompt(data, env);
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	t_env	*env;

	if (argc == 1 && !argv[1] && envp)
	{
		env = NULL;
		data.env = create_env(&env, envp);
		data.envp = create_env_char(&env);
		data.rv = 0;
		data.list_cmds = NULL;
		data.node_list = NULL;
		g_global.g_status = 0;
		if (!prompt_loop(&data, &env))
			return (1);
	}
	else
		write(2, "Invalid number of arguments.\n", 29);
	return (0);
}
