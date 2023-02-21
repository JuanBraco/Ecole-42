/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 00:13:19 by juanbraco         #+#    #+#             */
/*   Updated: 2023/01/19 14:59:06 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*get_stack_before_bottom(t_list *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

static void	rev_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*tail;
	t_list	*before_tail;

	tail = access_last_link(*stack);
	before_tail = get_stack_before_bottom(*stack);
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	before_tail->next = NULL;
}

void	do_rra(t_list **stack_a)
{
	rev_rotate(stack_a);
	ft_putstr("rra\n");
}

void	do_rrb(t_list **stack_b)
{
	rev_rotate(stack_b);
	ft_putstr("rrb\n");
}

void	do_rrr(t_list **stack_a, t_list **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_putstr("rrr\n");
}
