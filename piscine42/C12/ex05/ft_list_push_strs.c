/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:35:36 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/10/05 23:54:56 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_create_elem(void *data)
{
	t_list *list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (0);
	(*list).data = data;	
	(*list).next = NULL;
	return (list);
}


t_list	*ft_list_push_strs(int size, char **strs)
{
	int	i;
	t_list	*list;
	t_list	*tmp;

	i = 0;
	tmp = 0;
	while (i < size)
	{
		list = ft_create_elem(strs[i]);
		list->next = tmp;
		tmp = list;
		i++;
	}
}
