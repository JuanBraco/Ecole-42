/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanbraco <juanbraco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 23:25:30 by juanbraco         #+#    #+#             */
/*   Updated: 2023/01/10 00:21:08 by juanbraco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_list
{
	int			value;
	struct s_list	*next;
}	t_list;

void	free_stack(t_list **stack);
int	ft_atoi(const char *nptr);
t_list	*init_stack_a(int ac, char **av);
int	is_sorted(t_list *stack);
void	ft_putstr(char *str);

static void	rotate(t_list **stack);
void	do_ra(t_list **stack_a);
void	do_rb(t_list **stack_b);
void	do_rr(t_list **stack_a, t_list **stack_b);

void		do_pa(t_list **stack_a, t_list **stack_b);
void		do_pb(t_list **stack_a, t_list **stack_b);
void		do_sa(t_list **stack_a);
void		do_sb(t_list **stack_b);
void		do_ss(t_list **stack_a, t_list **stack_b);
void		do_ra(t_list **stack_a);
void		do_rb(t_list **stack_b);
void		do_rr(t_list **stack_a, t_list **stack_b);
void		do_rrr(t_list **stack_a, t_list **stack_b);
void		do_rra(t_list **stack_a);
void		do_rrb(t_list **stack_b);

#endif