/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stde-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:19:47 by stde-la-          #+#    #+#             */
/*   Updated: 2022/10/03 23:19:57 by stde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_CHECK_H
# define MAP_CHECK_H

typedef struct	t_characters
{
	char	vide;
	char	obstacle;
	char	plein;
}	t_characters;

int	first_line_len(char *map);
int	check_char(char *map);
void	get_characters(t_characters *chars, char *map);

#endif

