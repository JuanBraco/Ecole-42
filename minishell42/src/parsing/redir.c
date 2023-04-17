/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:26:22 by jde-la-f          #+#    #+#             */
/*   Updated: 2023/03/27 15:38:24 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	create_new_node_redir(t_node *tmp, t_parser *parser_tools)
{
	t_node	*node;
	int		index_1;
	int		index_2;

	node = ft_new_node(ft_strdup(tmp->next->str), tmp->token);
	if (!node)
		ft_error(1, parser_tools->data);
	ft_node_add_back(&parser_tools->redir, node);
	index_1 = tmp->i;
	index_2 = tmp->next->i;
	ft_rm_node_i(&parser_tools->node_list, index_1);
	ft_rm_node_i(&parser_tools->node_list, index_2);
	parser_tools->num_redir++;
	return (0);
}

void	rm_redir(t_parser *parser_tools)
{
	t_node	*tmp;

	tmp = parser_tools->node_list;
	while (tmp && tmp->token == 0)
		tmp = tmp->next;
	if (!tmp || tmp->token == PIPE)
		return ;
	if (!tmp->next)
		ft_error(0, parser_tools->data);
	if (tmp->next->token)
		token_error(parser_tools->data, parser_tools->data->node_list,
			tmp->next->token);
	if ((tmp->token >= GREAT && tmp->token <= LESS_LESS))
		create_new_node_redir(tmp, parser_tools);
	rm_redir(parser_tools);
}

/* Verifier si il y a le meme type de redir dans la liste */
int	check_same_redir(t_node *redir)
{
	int	token;

	token = redir->token;
	redir = redir->next;
	while (redir)
	{
		if ((token == LESS_LESS || token == LESS)
			&& (redir->token == LESS_LESS || redir->token == LESS))
			return (1);
		if ((token == GREAT_GREAT || token == GREAT)
			&& (redir->token == GREAT_GREAT || redir->token == GREAT))
			return (1);
		redir = redir->next;
	}
	return (0);
}
