/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 08:49:56 by jde-la-f          #+#    #+#             */
/*   Updated: 2023/01/18 14:30:08 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*access_last_link(t_list *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_list	*new_link(int value)
{
	t_list	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->pos = -1;
	new->target_pos = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

void	add_link_bottom(t_list **stack, t_list *new)
{
	t_list	*tail;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tail = access_last_link(*stack);
	tail->next = new;
}

t_list	*init_stack_a(int ac, char **av)
{
	t_list	*stack_a;
	long	nb;
	int		i;

	stack_a = NULL;
	nb = 0;
	i = 1;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			return (NULL);
		if (i == 1)
			stack_a = new_link((int)nb);
		else
			add_link_bottom(&stack_a, new_link((int)nb));
		i++;
	}
	return (stack_a);
}

void	assign_index(t_list *stack_a, int stack_size)
{
	t_list	*ptr;
	t_list	*highest;
	int		value;

	while (--stack_size > 0)
	{
		ptr = stack_a;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				highest = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}
