/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanbraco <juanbraco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 00:07:22 by juanbraco         #+#    #+#             */
/*   Updated: 2023/01/10 00:11:42 by juanbraco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* rotate:
*	The top element of the stack is sent to the bottom.
*/
static void	rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*tail;

	tmp = *stack;
	*stack = (*stack)->next;
	tail = access_last_link(*stack);
	tmp->next = NULL;
	tail->next = tmp;
}

/* do_ra:
*	Sends the top element of stack a to the bottom.
*	Prints "ra" to the standard output.
*/
void	do_ra(t_list **stack_a)
{
	rotate(stack_a);
	ft_putstr("ra\n");
}

/* do_rb:
*	Sends the top element of stack b to the bottom.
*	Prints "rb" to the standard output.
*/
void	do_rb(t_list **stack_b)
{
	rotate(stack_b);
	ft_putstr("rb\n");
}

/* do_rr:
*	Sends the top element of both stack a and stack b to the bottom
*	of their respective stacks.
*	Prints "rr" to the standard output.
*/
void	do_rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr("rr\n");
}