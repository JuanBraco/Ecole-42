/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:25:18 by jde-la-f          #+#    #+#             */
/*   Updated: 2023/03/15 09:40:42 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_node	*ft_new_node(char *str, int token)
{
	t_node		*new_element;
	static int	i = 0;

	new_element = (t_node *)malloc(sizeof(t_node));
	if (!new_element)
		return (0);
	new_element->str = str;
	new_element->token = token;
	new_element->i = i++;
	new_element->next = NULL;
	return (new_element);
}

void	ft_node_add_back(t_node **lst, t_node *new)
{
	t_node	*tmp;

	tmp = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

int	add_node(char *str, int token, t_node **node_list)
{
	t_node	*node;

	node = ft_new_node(str, token);
	if (!node)
		return (0);
	ft_node_add_back(node_list, node);
	return (1);
}
