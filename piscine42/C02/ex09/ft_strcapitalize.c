/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 12:15:30 by jde-la-f          #+#    #+#             */
/*   Updated: 2022/09/17 18:31:24 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	no_carac_alph(char c, int a)
{
	if (a == 1 && (c < '0' || c > 'z'))
	{
		return (-1);
	}
	else if (a == 1 && (c < 'a' && c > 'Z'))
	{
		return (-1);
	}
	else if (a == 1 && (c < 'A' && c > '9'))
	{
		return (-1);
	}
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	while (str[i] != '\0')
	{
		if (tmp == 0 && str[i] <= 'z' && str[i] >= 'a')
		{
			str[i] = str[i] - 32;
			tmp++;
		}
		else if (tmp == 0 && (str[i] >= '0' && str[i] <= '9'))
			tmp++;
		else if (tmp == 0 && (str[i] >= 'A' && str[i] <= 'Z'))
			tmp++;
		else if (tmp == 1 && str[i] <= 'Z' && str[i] >= 'A')
			str[i] = str[i] + 32;
		else if (no_carac_alph(str[i], tmp) == -1)
			tmp --;
		i++;
	}
	return (str);
}
