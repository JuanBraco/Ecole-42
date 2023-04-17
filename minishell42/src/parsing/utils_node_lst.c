/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_node_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:07:56 by jde-la-f          #+#    #+#             */
/*   Updated: 2023/03/22 11:29:44 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_node	*ft_clear_first_node(t_node **lst)
{
	if ((*lst)->str)
	{
		free((*lst)->str);
		(*lst)->str = NULL;
	}
	free(*lst);
	*lst = NULL;
	return (NULL);
}

void	ft_rm_first_node(t_node **lst)
{
	t_node	*node;

	node = *lst;
	*lst = node->next;
	ft_clear_first_node(&node);
}

void	ft_rm_node_i(t_node **lst, int key)
{
	t_node	*node;
	t_node	*prev;
	t_node	*start;

	start = *lst;
	node = start;
	if ((*lst)->i == key)
	{
		ft_rm_first_node(lst);
		return ;
	}
	while (node && node->i != key)
	{
		prev = node;
		node = node->next;
	}
	if (node)
		prev->next = node->next;
	else
		prev->next = NULL;
	ft_clear_first_node(&node);
	*lst = start;
}

void	ft_clear_list_node(t_node **lst)
{
	t_node	*tmp;

	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		if ((*lst)->str)
			free((*lst)->str);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}
