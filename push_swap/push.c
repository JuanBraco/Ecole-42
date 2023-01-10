/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanbraco <juanbraco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 00:18:09 by juanbraco         #+#    #+#             */
/*   Updated: 2023/01/10 00:18:41 by juanbraco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* push:
*	Pushes the top element of src stack to the top of dest stack.
*/
static void	push(t_list **src, t_list **dest)
{
	t_list	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}

/* do_pa:
*	Pushes the top element of stack b to the top of stack a.
*	Prints "pa" to the standard output.
*/
void	do_pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
	ft_putstr("pa\n");
}

/* do_pb:
*	Pushes the top element of stack a to the top of stack b.
*	Prints "pb" to the standard output.
*/
void	do_pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr("pb\n");
}