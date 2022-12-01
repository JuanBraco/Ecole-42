/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 07:06:50 by amuller           #+#    #+#             */
/*   Updated: 2022/09/18 19:43:03 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putstr(char *str);

void	rush(int x, int y);

int		ft_atoi(char *nbr);

int	main(int ac, char **av)
{
	int		a;
	int		b;

	(void)ac;
	a = ft_atoi(av[1]);
	b = ft_atoi(av[2]);
	rush(a, b);
	return (0);
}
