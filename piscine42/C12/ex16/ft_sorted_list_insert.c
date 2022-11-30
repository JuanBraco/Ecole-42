/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:26:22 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/10/06 17:48:20 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

t_list	*ft_create_elem(void *data)
{
	t_list	list_ptr;

	list_ptr = malloc(sizeof(t_list));
	if(!list_ptr)
		return (0);
	list_ptr->data = data;
	list_ptr->next = NULL;
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	list_ptr;

	list_ptr = ft_create_elem(data);
	while (*begin_list->next)
	{
		if ((*cmp)(*begin_list->data, list_ptr->data) < 0 
			&& (*cmp)(*begin_list->next->data, list_ptr->data) > 0 )
		{
			
		}	
			
	}
}
