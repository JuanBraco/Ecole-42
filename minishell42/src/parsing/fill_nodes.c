/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanbraco <juanbraco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:59:58 by juanbraco         #+#    #+#             */
/*   Updated: 2023/03/10 15:05:06 by juanbraco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	g_status;

int	get_fd(int oldfd, char *path, int flags[2])
{
	int	fd;

	if (oldfd > 2)
		close(oldfd);
	if (!path)
		return (-1);
	if (access(path, F_OK) == -1 && !flags[0])
		ft_perror(NDIR, path, 127);
	else if (!flags[0] && access(path, R_OK) == -1)
		ft_perror(NPERM, path, 126);
	else if (flags[0] && access(path, W_OK) == -1 && access(path, F_OK) == 0)
		ft_perror(NPERM, path, 126);
	if (flags[0] && flags[1])
		fd = open(path, O_CREAT | O_WRONLY | O_APPEND, 0666);
	else if (flags[0] && !flags[1])
		fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	else if (!flags[0] && oldfd != -1)
		fd = open(path, O_RDONLY);
	else
		fd = oldfd;
	return (fd);
}

t_node	*get_outfile1(t_node *node, char **args, int i)
{
	char	*nl;
	int		flags[2];

	flags[0] = 1;
	flags[1] = 0;
	nl = "minishell: syntax error near unexpected token `newline'";
	(i)++;
	if (args[i])
		node->outfile = get_fd(node->outfile, args[i], flags);
	if (!args[i] || node->outfile == -1)
	{
		node = NULL;
		if (node->outfile != -1)
		{
			ft_putendl_fd(nl, 2);
			g_status = 2;
		}
		else
			g_status = 1;
	}
	return (node);
}

t_node	*get_outfile2(t_node *node, char **args, int i)
{
	char	*nl;
	int		flags[2];

	flags[0] = 1;
	flags[1] = 1;
	nl = "minishell: syntax error near unexpected token `newline'";
	(i)++;
	if (args[++(i)])
		node->outfile = get_fd(node->outfile, args[i], flags);
	if (!args[i] || node->outfile == -1)
	{
		node = NULL;
		if (node->outfile != -1)
		{
			ft_putendl_fd(nl, 2);
			g_status = 2;
		}
		else
			g_status = 1;
	}
	return (node);
}

t_node	*get_infile1(t_node *node, char **args, int i)
{
	char	*nl;
	int		flags[2];

	flags[0] = 0;
	flags[1] = 0;
	nl = "minishell: syntax error near unexpected token `newline'";
	(i)++;
	if (args[i])
		node->infile = get_fd(node->infile, args[i], flags);
	if (!args[i] || node->infile == -1)
	{
		node = NULL;
		if (node->infile != -1)
		{
			ft_putendl_fd(nl, 2);
			g_status = 2;
		}
		else
			g_status = 1;
	}
	return (node);
}

static t_node	*node_init(void)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->full_cmd = NULL;
	node->full_path = NULL;
	node->infile = STDIN_FILENO;
	node->outfile = STDOUT_FILENO;
	return (node);
}

static t_node	*get_params(t_node *node, char **args, int i)
{
	if (!args[i])
	{
		ft_perror(PIPENDERR, NULL, 2);
		return (NULL);
	}

	if (args[i][0] == '>' && args[i + 1] && args[i + 1][0] == '>')
		node = get_outfile2(node, args, i);
	else if (args[i][0] == '>')
		node = get_outfile1(node, args, i);
	/*else if (args[i][0] == '<' && args[i + 1] && args[i + 1][0] == '<')
		node = get_infile2(node, args, i);*/
	else if (args[i][0] == '<')
		node = get_infile1(node, args, i);
	else if (args[i][0] != '|')
		node->full_cmd = ft_extend_tab(node->full_cmd, args[i]);
	else
	{
		ft_perror(PIPENDERR, NULL, 2);
		return (NULL);
	}
	return (node);
}

static char	**get_trimmed(char **args)
{
	char	**temp;
	char	*aux;
	int		j;

	j = -1;
	temp = ft_tabdup(args);
	while (temp && temp[++j])
	{
		aux = ft_strtrim_all(temp[j], 0, 0);
		free(temp[j]);
		temp[j] = aux;
	}
	return (temp);
}

static t_list	*stop_fill(t_list *cmds, char **args, char **temp)
{
	ft_lstclear(&cmds, free_content);
	ft_free_tab(&temp);
	ft_free_tab(&args);
	return (NULL);
}

t_list *fill_nodes(char **args)
{
    t_list	*cmds;
    t_list	*cur_cmd;
    char	**trimmed_args;
    int		i;

	cmds = ft_lstnew(node_init());
	cur_cmd = cmds;
	trimmed_args = get_trimmed(args);
	i = 0;
    while (trimmed_args[i]) 
	{
        if (trimmed_args[i][0] == '|') 
		{
            cur_cmd = ft_lstnew(node_init());
            ft_lstadd_back(&cmds, cur_cmd);
        } 
		else 
		{
            cur_cmd->content = get_params(cur_cmd->content, trimmed_args, i);
            if (!cur_cmd->content) 
                return (stop_fill(cmds, args, trimmed_args));
        }
        i++;
    }
    ft_free_tab(&trimmed_args);
    ft_free_tab(&args);
    return (cmds);
}
