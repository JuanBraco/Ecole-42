/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:11:12 by avast             #+#    #+#             */
/*   Updated: 2022/11/10 14:49:21 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*begin_new;
	t_list	*cur_new;

	if (lst == 0)
		return (0);
	begin_new = 0;
	while (lst)
	{
		cur_new = ft_lstnew((*f)(lst->content));
		if (cur_new == 0)
		{
			ft_lstclear(&begin_new, del);
			return (0);
		}
		ft_lstadd_back(&begin_new, cur_new);
		lst = lst->next;
	}
	return (begin_new);
}
