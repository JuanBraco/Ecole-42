/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanbraco <juanbraco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:36:05 by juanbraco         #+#    #+#             */
/*   Updated: 2023/01/09 23:54:33 by juanbraco        ###   ########.fr       */
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

	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new->value = value;
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
	int		nb;
	int		i;

	stack_a = NULL;
	nb = 0;
	i = 1;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			return(NULL);
		else 
			add_link_bottom(&stack_a, new_link((int)nb));
		i++;
	}
	return (stack_a);
}

int	get_stack_size(t_list	*stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

static void	push_swap(t_list **stack_a, t_list **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		do_sa(stack_a);
	else if (stack_size == 3)
		tiny_sort(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

int		main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		stack_size;
		
	if (ac < 2)
		return (0);
	stack_b = NULL;
	stack_a = init_stack_a(ac, av);
	stack_size = get_stack_size(stack_a);
	
}