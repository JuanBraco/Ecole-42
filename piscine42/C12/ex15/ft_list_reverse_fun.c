/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:01:17 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/10/06 17:25:34 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*list_prv;
	t_list	*list_cur;
	t_list	*list_tmp;

	list_cur = begin_list;
	list_prev = 0;
	while (list_cur->next)
	{
		list_tmp = list_cur;
		list cur = list_cur->next
		list_tmp->next = list_prev;
		list_prev = list_tmp;
	}
	begin_list = list_cur;
}
