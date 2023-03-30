/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 00:14:08 by avast             #+#    #+#             */
/*   Updated: 2023/03/27 16:02:45 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../libft/libft.h"

static void	heredoc_child(t_pipex pipex, char *limiter, int pfd[2])
{
	char	*line;

	close(pfd[0]);
	while (1)
	{
		line = readline("> ");
		line = update_var_line(line, pipex.data, YES);
		if (!line)
		{	
			error_msg(HEREDOC, limiter);
			break ;
		}
		if (!ft_strcmp(line, limiter))
			break ;
		line = ft_strjoin_gnl(line, "\n");
		ft_putstr_fd(line, pfd[1]);
		free(line);
	}
	close(pfd[1]);
	ft_free_str(line);
	exit_and_free(0, 0, pipex);
}

static int	heredoc(char *limiter, t_pipex *pipex)
{
	int		pfd[2];
	pid_t	pid;
	int		status;

	signal(SIGINT, &here_sig);
	if (pipe(pfd) == -1)
		return (error_msg(PIPER, NULL));
	pid = fork();
	if (pid < 0)
		return (error_msg(FORK, NULL));
	if (pid == 0)
		heredoc_child(*pipex, limiter, pfd);
	signal(SIGINT, SIG_IGN);
	waitpid(pid, &status, 0);
	signal(SIGINT, &sig_int);
	if (WIFEXITED(status) && WEXITSTATUS(status) == 200)
		return (close(pfd[1]), close(pfd[0]), -2);
	else
		return (close(pfd[1]), pfd[0]);
}

static int	token_to_fd(t_node *redir, t_pipex *pipex)
{
	int	fd;

	if (redir->token == LESS_LESS)
		fd = heredoc(redir->str, pipex);
	else if (redir->token == LESS)
	{
		fd = open(redir->str, O_RDONLY);
		if (fd == -1 && access(redir->str, F_OK) == 0)
			return (INFILE_PERM_DENIED);
		else if (fd == -1 && access(redir->str, F_OK) == -1)
			return (NO_FILE);
	}
	if (redir->token == GREAT_GREAT)
		fd = open(redir->str, O_RDWR | O_CREAT | O_APPEND, 0644);
	else if (redir->token == GREAT)
		fd = open(redir->str, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (OUTFILE_PERM_DENIED);
	if (fd == -2)
		return (HEREDOC);
	return (fd);
}

static int	update_cmd_fd(t_node *redir, t_cmds *cmd, t_pipex *p)
{
	if (redir->token == LESS || redir->token == LESS_LESS)
	{
		cmd->file_in.fd = token_to_fd(redir, p);
		cmd->file_in.str = redir->str;
		if (check_same_redir(redir) && cmd->file_in.fd > 0)
			close(cmd->file_in.fd);
		if (cmd->file_in.fd < 0)
			return (list_add_pid(&(p->errors), cmd, NULL,
					cmd->file_in.fd), cmd->file_in.fd);
	}
	else if (redir->token == GREAT || redir->token == GREAT_GREAT)
	{
		cmd->file_out.fd = token_to_fd(redir, p);
		cmd->file_out.str = redir->str;
		if (check_same_redir(redir) && cmd->file_out.fd > 0)
			close(cmd->file_out.fd);
		if (cmd->file_out.fd < 0)
			return (list_add_pid(&(p->errors), cmd, NULL,
					cmd->file_out.fd), -1);
	}
	return (0);
}

int	get_command_fds(t_cmds *cmd, t_pipex *pipex)
{
	t_node	*redir;
	int		a;

	redir = cmd->redir;
	while (redir)
	{
		a = update_cmd_fd(redir, cmd, pipex);
		if (a == HEREDOC)
			return (HEREDOC);
		else if (a < 0)
			return (-1);
		redir = redir->next;
	}
	return (EXIT_SUCCESS);
}
