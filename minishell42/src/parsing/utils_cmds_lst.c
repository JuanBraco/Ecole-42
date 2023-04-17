/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cmds_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:11:51 by jde-la-f          #+#    #+#             */
/*   Updated: 2023/03/22 10:53:05 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_clear_list_cmd(t_cmds **lst)
{
	t_cmds	*tmp;
	t_node	*redir_tmp;

	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		redir_tmp = (*lst)->redir;
		ft_clear_list_node(&redir_tmp);
		if ((*lst)->tab)
			ft_free_tab(((*lst)->tab));
		if ((*lst)->hd_file_name)
			free((*lst)->hd_file_name);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

t_cmds	*ft_new_list_cmd(char **tab, int num_redir, t_node *redir)
{
	t_cmds	*new_element;

	new_element = (t_cmds *)malloc(sizeof(t_cmds));
	if (!new_element)
		return (0);
	new_element->tab = tab;
	new_element->built_in = 0;
	new_element->hd_file_name = NULL;
	new_element->num_redir = num_redir;
	new_element->redir = redir;
	new_element->file_in.fd = 0;
	new_element->file_out.fd = 0;
	new_element->file_in.str = NULL;
	new_element->file_out.str = NULL;
	new_element->next = NULL;
	return (new_element);
}

void	ft_add_back_lst_cmd(t_cmds **lst, t_cmds *new)
{
	t_cmds	*tmp;

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
