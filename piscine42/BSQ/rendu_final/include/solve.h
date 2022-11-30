/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stde-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:40:10 by stde-la-          #+#    #+#             */
/*   Updated: 2022/10/05 11:41:13 by stde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_H
# define SOLVE_H
# include "map_check.h"

typedef struct t_square
{
	int	size;
	int	x;
	int	y;
}	t_square;

typedef struct t_dim
{
	int	height;
	int	width;
}	t_dim;

int			is_ok(t_square sqr, char *map, t_dim *map_dim, t_chars *chars);
void		fill_map(t_square sqr, char *map, t_dim *map_dim, t_chars *chrs);
t_square	solve(char *map, t_dim *map_dim, t_chars *chars);
void		print_map(char *map, t_dim *map_dim);

#endif
