/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:55:26 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/09/29 17:53:55 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*ptr;

	i = 0;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	ptr = malloc(sizeof(int) * (max - min));
	*range = ptr;
	if (ptr == 0)
	{
		*range = 0;
		return (-1);
	}
	while (i < (max - min))
	{
		ptr[i] = min + i;
		i++;
	}	
	return (max - min);
}

/*#include <stdio.h>
int	main(void)
{
	int **range;
	ft_ultimate_range(range, 0, 5);
}*/
