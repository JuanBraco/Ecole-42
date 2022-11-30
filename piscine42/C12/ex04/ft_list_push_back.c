/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:16:09 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/10/05 23:35:11 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	(*list).data = data;	
	(*list).next = NULL;
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*ptr;

	ptr = ft_create_elem(data);
	if (!*begin_list)
		*beguin_list = ptr;
	while (*begin_list->next)
	{
		*begin_list = *begin_list->next;
	}
	*begin_list->next = ptr;
	
}
