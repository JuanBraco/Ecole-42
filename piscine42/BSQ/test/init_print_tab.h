/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_print_tab.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:31:01 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/10/03 17:31:27 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_PRINT_TAB_H
# define INIT_PRINT_TAB_H

#include "include/map_check.h"

void	full_tab_init(char **tab, t_characters chars);
void	tab_nbr_square(char **tab);
void	print_tab(char **tab);
int		ft_min(int a, int b, int c);

#endif
