/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 07:11:06 by amuller           #+#    #+#             */
/*   Updated: 2022/09/17 12:20:18 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_print_border(int x, int col)
{
	while (col < x)
	{
		if (col == 0 || col == x - 1)
		{
			ft_putchar('o');
		}
		else
			ft_putchar('-');
		col++;
	}
}

void	ft_print_middle_row(int x, int col)
{
	while (col < x)
	{
		if (col == 0 || col == x - 1)
		{
			ft_putchar('|');
		}
		else
			ft_putchar(' ');
		col++;
	}
}

void	ft_display(int row, int col, int x, int y)
{
	if (row == 0 || row == y - 1)
	{
		ft_print_border(x, col);
	}
	else
	{
		ft_print_middle_row(x, col);
	}
}	

void	rush(int x, int y)
{
	int	row;
	int	col;

	row = 0;
	while (row < y)
	{
		col = 0;
		ft_display(row, col, x, y);
		ft_putchar('\n');
		row++;
	}
}
