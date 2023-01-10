/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanbraco <juanbraco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 00:13:19 by juanbraco         #+#    #+#             */
/*   Updated: 2023/01/10 00:17:19 by juanbraco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* rev_rotate:
*	Brings the bottom element of a stack to the top.
*/
static void	rev_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*tail;
	t_list	*before_tail;

	tail = access_last_link(*stack);
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
    tail = access_last_link(*stack);
	tail->next = NULL;
}

/* do_rra:
*	Brings the bottom element of stack a to the top.
*	Prints "rra" to the standard output.
*/
void	do_rra(t_list **stack_a)
{
	rev_rotate(stack_a);
	ft_putstr("rra\n");
}

/* do_rrb:
*	Brings the bottom element of stack b to the top.
*	Prints "rrb" to the standard output.
*/
void	do_rrb(t_list **stack_b)
{
	rev_rotate(stack_b);
	ft_putstr("rrb\n");
}

/* do_rrr:
*	Brings the bottom element of both stack a and stack be
*	to the top of their respective stacks.
*	Prints "rrr" to the standard output.
*/
void	do_rrr(t_list **stack_a, t_list **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_putstr("rrr\n");
}