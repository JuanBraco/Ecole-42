/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:20:39 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/11/21 10:36:33 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_new_node;
	t_list	*lst_new;

	lst_new = NULL;
	while (lst && del)
	{
		lst_new_node = ft_lstnew((*f)(lst->content));
		if (lst_new_node)
			ft_lstadd_back(&lst_new, lst_new_node);
		else
		{
			ft_lstclear(&lst_new, del);
			return (0);
		}
		lst = lst->next;
	}
	return (lst_new);
}
