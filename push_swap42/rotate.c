/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 00:07:22 by juanbraco         #+#    #+#             */
/*   Updated: 2023/01/19 14:58:30 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	do_ra(t_list **stack_a)
{
	rotate(stack_a);
	ft_putstr("ra\n");
}

void	do_rb(t_list **stack_b)
{
	rotate(stack_b);
	ft_putstr("rb\n");
}

void	do_rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr("rr\n");
}
