/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 09:24:21 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/10/06 17:51:36 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	list_tmp;

	if (!begin_list)
		return ;
	while (begin_list)
	{
		list_tmp = begin_list;
		free_fct(begin_list->data);
		free(begin_list);
		begin_list = list_tmp->next;
	}
}
