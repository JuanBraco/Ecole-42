/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 00:18:17 by juanbraco         #+#    #+#             */
/*   Updated: 2023/01/19 14:58:43 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}

void	do_sa(t_list **stack_a)
{
	swap(*stack_a);
	ft_putstr("sa\n");
}

void	do_sb(t_list **stack_b)
{
	swap(*stack_b);
	ft_putstr("sb\n");
}

void	do_ss(t_list **stack_a, t_list **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	ft_putstr("ss\n");
}
