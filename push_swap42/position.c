/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:37:48 by jde-la-f          #+#    #+#             */
/*   Updated: 2023/01/19 13:29:56 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_position(t_list **stack)
{
	t_list	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

static int	get_target(t_list **a, int b_idx, int target_idx, int target_pos)
{
	t_list	*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index > b_idx && tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (target_idx != INT_MAX)
		return (target_pos);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (target_pos);
}

void	get_target_position(t_list **a, t_list **b)
{
	t_list	*tmp_b;
	int		target_pos;

	tmp_b = *b;
	get_position(a);
	get_position(b);
	target_pos = 0;
	while (tmp_b)
	{
		target_pos = get_target(a, tmp_b->index, INT_MAX, target_pos);
		tmp_b->target_pos = target_pos;
		tmp_b = tmp_b->next;
	}
}

int	get_lowest_index_position(t_list **stack)
{
	t_list	*tmp;
	int		lowest_index;
	int		lowest_pos;

	tmp = *stack;
	lowest_index = INT_MAX;
	get_position(stack);
	lowest_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}
