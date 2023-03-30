/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:59:58 by juanbraco         #+#    #+#             */
/*   Updated: 2023/03/27 17:47:59 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	handle_pipe_errors(t_data *data, int token)
{
	if (token == PIPE)
	{
		token_error(data, data->node_list, data->node_list->token);
		return (EXIT_FAILURE);
	}
	if (!data->node_list)
	{
		ft_error(0, data);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	handle_token_errors(t_data *data, int token)
{
	if (token == PIPE)
	{
		token_error(data, data->node_list, data->node_list->token);
		return (EXIT_FAILURE);
	}
	if (!data->node_list)
	{
		ft_error(0, data);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
