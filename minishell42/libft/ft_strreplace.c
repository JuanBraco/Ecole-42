/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:27:49 by avast             #+#    #+#             */
/*   Updated: 2023/03/03 11:56:00 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static void	free_char(char *str)
{
	if (str)
		free(str);
}

char	*ft_strreplace(char *str, int start, int len, char *replace)
{
	char	*str_p1;
	char	*str_p2;
	char	*join1;
	char	*join2;

	str_p1 = ft_substr(str, 0, (size_t)start);
	if (!str_p1 && start > 0)
		return (NULL);
	str_p2 = ft_strdup(str + start + len);
	if (!str_p2)
		return (free_char(str_p1), NULL);
	join1 = ft_strjoin(str_p1, replace);
	if (!join1)
		return (free_char(str_p1), free(str_p2), NULL);
	join2 = ft_strjoin(join1, str_p2);
	if (!join2)
		return (free_char(str_p1), free(str_p2), free(join1), NULL);
	(free_char(str_p1), free(str_p2), free(join1));
	if (str)
		free(str);
	return (join2);
}

/* int	main(int argc, char **argv)
{
	char *str;
	(void)argv;
	str = ft_strreplace(argv[1], atoi(argv[2]), atoi(argv[3]), argv[4]);
	printf("%s\n", str);
	free(str);
	return (0);
}
 */