/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:20:59 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/10/06 16:09:07 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*list_prv;
	t_list	*list_curr;
	t_list	*list_tmp;
	
	while (*begin_list && !(*cmp)(begin_list->data), data_ref)
	{
		(*free_fct)(*begin_list->data);
		list_tmp = (*begin_list)->next;
		free(*begin_list);
		*begin_list = list_tmp;
	}

	list_curr = *begin_list;
	while (list_curr)
	{
		if (!(*cmp)(list_curr->data, data_ref))
		{
			(*free_fct)(list_curr->data);
			list_tmp = list_curr->next;
			list_prev->next = list_tmp;
			free(list_curr);
			list_curr = list_tmp;
			
		}
		else
		{
			list_prv = list_curr;
			list_curr = list_curr->next
		}
	}
}

