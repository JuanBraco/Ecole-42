/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:33:20 by jde-la-f          #+#    #+#             */
/*   Updated: 2023/03/27 15:44:04 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	count_pipes(t_node *node_list, t_data *tools)
{
	t_node	*tmp;

	tmp = node_list;
	tools->nb_pipe = 0;
	while (tmp)
	{
		if (tmp->token == PIPE)
			tools->nb_pipe++;
		tmp = tmp->next;
	}
}

int	count_args(t_node *node_list)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = node_list;
	while (tmp && tmp->token != PIPE)
	{
		if (tmp->i >= 0)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

t_parser	init_parser(t_node *node_list, t_data *data)
{
	t_parser	parser_data;

	parser_data.node_list = node_list;
	parser_data.redir = NULL;
	parser_data.num_redir = 0;
	parser_data.data = data;
	return (parser_data);
}

t_cmds	*initialize_cmd(t_parser *parser_tools)
{
	char	**tab;
	int		i;
	int		arg_size;
	t_node	*tmp;

	i = 0;
	rm_redir(parser_tools);
	arg_size = count_args(parser_tools->node_list);
	tab = ft_calloc(arg_size + 1, sizeof(char *));
	if (!tab)
		ft_error(1, parser_tools->data);
	tmp = parser_tools->node_list;
	while (arg_size > 0)
	{
		if (tmp->str)
		{
			tab[i++] = ft_strdup(tmp->str);
			ft_rm_node_i(&parser_tools->node_list, tmp->i);
			tmp = parser_tools->node_list;
		}
		arg_size--;
	}
	return (ft_new_list_cmd(tab, parser_tools->num_redir, parser_tools->redir));
}

int	parser(t_data *data)
{
	t_cmds		*list_cmds;
	t_parser	parser_tools;

	data->list_cmds = NULL;
	if (data->node_list && data->node_list->token == PIPE)
		return (token_error(data, data->node_list, data->node_list->token));
	while (data->node_list)
	{
		if (data->node_list && data->node_list->token == PIPE)
			ft_rm_node_i(&data->node_list, data->node_list->i);
		if (data->node_list && handle_pipe_errors(data, data->node_list->token))
			return (token_error(data, data->node_list, data->node_list->token));
		else if (!data->node_list)
			ft_error(3, data);
		parser_tools = init_parser(data->node_list, data);
		list_cmds = initialize_cmd(&parser_tools);
		if (!list_cmds)
			ft_error(0, data);
		if (!data->list_cmds)
			data->list_cmds = list_cmds;
		else
			ft_add_back_lst_cmd(&data->list_cmds, list_cmds);
		data->node_list = parser_tools.node_list;
	}
	return (EXIT_SUCCESS);
}
