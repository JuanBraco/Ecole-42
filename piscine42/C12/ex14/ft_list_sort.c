/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:10:32 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/10/06 17:00:07 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(t_list *elem1, t_list *elem2)
{
	void	*tmp;
	
	tmp = a->data;
	*a = *b;
	*b = tmp;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*list_ptr;
	t_list	*list_ptr1;

	list_ptr = *begin_list;
	while (list_ptr)
	{
		list_ptr1 = *begin_list;
		while (list_ptr1)
		{
			if ((*cmp)(list_ptr->data, list_ptr1->data) > 0)
				ft_swap(list_ptr->data, list_ptr1->data);
			list_ptr1 = list_ptr1->next;
		}
		list_ptr = list_ptr->next;
	}
}
