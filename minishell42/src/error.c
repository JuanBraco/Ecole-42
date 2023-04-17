/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-la-f <jde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:49:16 by jde-la-f          #+#    #+#             */
/*   Updated: 2023/03/22 12:53:52 by jde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_error(int error, t_data *data)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	if (error == 0)
		ft_putstr_fd("syntax error near unexpected token `newline'\n",
			STDERR_FILENO);
	else if (error == 1)
		ft_putstr_fd("memory error: unable to assign memory\n", STDERR_FILENO);
	else if (error == 2)
		ft_putstr_fd("syntax error: unable to locate closing quotation\n",
			STDERR_FILENO);
	else if (error == 3)
		ft_putstr_fd("Parser problem\n", STDERR_FILENO);
	if (data->node_list)
	{
		ft_clear_list_node(&data->node_list);
		data->node_list = NULL;
	}
	data->rv = 2;
	reset_prompt(data, data->env);
	return (EXIT_FAILURE);
}

int	token_error(t_data *data, t_node *node_list, int token)
{
	ft_putstr_fd("minishell: syntax error near unexpected token ",
		STDERR_FILENO);
	if (token == GREAT)
		ft_putstr_fd("`>\'\n", STDERR_FILENO);
	else if (token == GREAT_GREAT)
		ft_putstr_fd("`>>\'\n", STDERR_FILENO);
	else if (token == LESS)
		ft_putstr_fd("`<\'\n", STDERR_FILENO);
	else if (token == LESS_LESS)
		ft_putstr_fd("`<<\'\n", STDERR_FILENO);
	else if (token == PIPE)
		ft_putstr_fd("`|\'\n", STDERR_FILENO);
	else
		ft_putstr_fd("\n", STDERR_FILENO);
	ft_clear_list_node(&node_list);
	data->node_list = NULL;
	data->rv = 2;
	reset_prompt(data, data->env);
	return (EXIT_FAILURE);
}
