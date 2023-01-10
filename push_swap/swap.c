/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanbraco <juanbraco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 00:18:17 by juanbraco         #+#    #+#             */
/*   Updated: 2023/01/10 00:18:19 by juanbraco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* swap:
*	Swaps the top 2 elements of a stack.
*	Does nothing if there is only one or no elements.
*/
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

/* do_sa:
*	Swaps the top 2 elements of stack a.
*	Prints "sa" to the standard output.
*/
void	do_sa(t_list **stack_a)
{
	swap(*stack_a);
	ft_putstr("sa\n");
}

/* do_sb:
*	Swaps the top 2 elements of stack b.
*	Prints "sb" to the standard output.
*/
void	do_sb(t_list **stack_b)
{
	swap(*stack_b);
	ft_putstr("sb\n");
}

/* do_ss:
*	Swaps the top 2 elements of stack a and the top 2 elements
*	of stack b.
*	Prints "ss" to the standard output.
*/
void	do_ss(t_list **stack_a, t_list **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	ft_putstr("ss\n");
}