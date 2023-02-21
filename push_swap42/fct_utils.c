/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 23:26:40 by juanbraco         #+#    #+#             */
/*   Updated: 2023/01/19 15:11:44 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *nptr)
{
	int		i;
	int		s;
	long	nb;

	i = 0;
	s = 1;
	nb = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			s *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = 10 * nb + nptr[i] - 48;
		i++;
	}
	return (nb * s);
}

void	free_stack(t_list **stack)
{
	t_list	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

int	is_sorted(t_list *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	get_stack_size(t_list *stack)
{
	int		size;
	t_list	*tmp;

	tmp = stack;
	size = 0;
	if (!stack)
		return (0);
	while (tmp)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}
