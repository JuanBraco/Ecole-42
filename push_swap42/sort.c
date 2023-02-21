/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 08:49:03 by jde-la-f          #+#    #+#             */
/*   Updated: 2023/01/19 13:34:03 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	shift_stack(t_list **stack_a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = get_stack_size(*stack_a);
	lowest_pos = get_lowest_index_position(stack_a);
	if (lowest_pos > stack_size / 2)
	{
		while ((*stack_a)->index != 1)
			do_rra(stack_a);
	}
	else
	{
		while ((*stack_a)->index != 1)
			do_ra(stack_a);
	}
}

void	value5_sort(t_list **stack_a, t_list **stack_b)
{
	int	size_a;

	size_a = get_stack_size(*stack_a);
	while ((*stack_a)->index != size_a && (*stack_a)->index != size_a - 1)
		do_ra(stack_a);
	do_pb(stack_a, stack_b);
	while ((*stack_a)->index != size_a && (*stack_a)->index != size_a - 1)
		do_ra(stack_a);
	do_pb(stack_a, stack_b);
	if (is_sorted(*stack_b))
		do_sb(stack_b);
	if (get_stack_size(*stack_a) == 3 && !is_sorted(*stack_a))
		value3_sort(stack_a);
	else if (get_stack_size(*stack_a) == 2 && !is_sorted(*stack_a))
		do_sa(stack_a);
	do_pa(stack_a, stack_b);
	do_pa(stack_a, stack_b);
	do_ra(stack_a);
	do_ra(stack_a);
}

static void	ft_push_to_b(t_list **stack_a, t_list **stack_b)
{
	int	stack_size_init;
	int	i;
	int	j;

	i = 0;
	j = 0;
	stack_size_init = get_stack_size(*stack_a);
	while (i < stack_size_init)
	{
		if ((*stack_a)->index == j && get_stack_size(*stack_a) != 1)
		{
			j++;
			do_ra(stack_a);
			i++;
		}
		else
		{
			do_pb(stack_a, stack_b);
			i++;
		}
	}
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	ft_push_to_b(stack_a, stack_b);
	while (*stack_b)
	{
		get_target_position(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		do_cheapest_move(stack_a, stack_b);
	}
	shift_stack(stack_a);
}
