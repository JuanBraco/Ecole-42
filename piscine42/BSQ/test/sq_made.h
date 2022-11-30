/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sq_made.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:28:32 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/10/03 17:28:36 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQ_MADE_H
# define SQ_MADE_H

#include "include/map_check.h"

struct t_point	pos_square(char **tab);
void			write_square(char **tab, struct t_point sqr, t_characters chars);
char			val_r1(int posr, int posc, char **tab);
char			val_c1(int posr, int posc, char **tab);
char			val_d1(int posr, int posc, char **tab);

typedef struct t_point
{
	int	pos_r;
	int	pos_c;
	int	size_sq;
}	t_point;

#endif
