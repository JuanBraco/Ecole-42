/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:36:05 by juanbraco         #+#    #+#             */
/*   Updated: 2023/01/19 15:07:58 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_highest_index(t_list *stack)
{
	int		index;
	t_list	*tmp;

	tmp = stack;
	index = tmp->index;
	while (tmp)
	{
		if (tmp->index > index)
			index = tmp->index;
		tmp = tmp->next;
	}
	return (index);
}

void	value3_sort(t_list **stack)
{
	int	highest;

	if (is_sorted(*stack))
		return ;
	highest = find_highest_index(*stack);
	if ((*stack)->index == highest)
		do_ra(stack);
	else if ((*stack)->next->index == highest)
		do_rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		do_sa(stack);
}

static void	exit_error(t_list **stack_a, t_list **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		free_stack(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		free_stack(stack_b);
	write(2, "Error\n", 6);
	exit(1);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		stack_size;

	if (ac < 2)
		return (0);
	if (input_check(ac, av))
		exit_error(NULL, NULL);
	stack_b = NULL;
	stack_a = init_stack_a(ac, av);
	stack_size = get_stack_size(stack_a);
	assign_index(stack_a, stack_size + 1);
	if (stack_size == 2 && !is_sorted(stack_a))
		do_sa(&stack_a);
	else if (stack_size == 3 && !is_sorted(stack_a))
		value3_sort(&stack_a);
	else if ((stack_size < 6) && !is_sorted(stack_a))
		value5_sort(&stack_a, &stack_b);
	else if (stack_size >= 6 && !is_sorted(stack_a))
		sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
}
