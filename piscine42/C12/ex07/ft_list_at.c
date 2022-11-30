/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:02:02 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/10/06 10:29:13 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	while (nbr > 0)
	{
		if (!(*begin_list).next)
			return (0);
		begin_list = (*begin_list).next;
		nbr--;
	}
	return (begin_list);
		
}
