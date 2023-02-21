/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 23:25:30 by juanbraco         #+#    #+#             */
/*   Updated: 2023/01/19 15:09:50 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_list	*next;
}					t_list;

//cost.c

void				do_cheapest_move(t_list **stack_a, t_list **stack_b);
void				get_cost(t_list **stack_a, t_list **stack_b);

//check_input.c

int					input_check(int ac, char **av);

//init_list.c

t_list				*access_last_link(t_list *stack);
t_list				*new_link(int value);
void				add_link_bottom(t_list **stack, t_list *new);
t_list				*init_stack_a(int ac, char **av);
void				assign_index(t_list *stack_a, int stack_size);

//fct_utils.c

void				free_stack(t_list **stack);
long				ft_atoi(const char *nptr);
int					is_sorted(t_list *stack);
void				ft_putstr(char *str);
int					get_stack_size(t_list *stack);

//push.c rotate.c rev_rotate.c swap.c

void				do_pa(t_list **stack_a, t_list **stack_b);
void				do_pb(t_list **stack_a, t_list **stack_b);
void				do_sa(t_list **stack_a);
void				do_sb(t_list **stack_b);
void				do_ss(t_list **stack_a, t_list **stack_b);
void				do_ra(t_list **stack_a);
void				do_rb(t_list **stack_b);
void				do_rr(t_list **stack_a, t_list **stack_b);
void				do_rrr(t_list **stack_a, t_list **stack_b);
void				do_rra(t_list **stack_a);
void				do_rrb(t_list **stack_b);

//sort.c

void				value5_sort(t_list **stack_a, t_list **stack_b);
void				sort(t_list **stack_a, t_list **stack_b);

//main.c

void				value3_sort(t_list **stack);

//position.c

void				get_target_position(t_list **a, t_list **b);
int					get_lowest_index_position(t_list **stack);

//opti_move.c

void				do_move(t_list **a, t_list **b, int cost_a, int cost_b);

#endif