/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 00:14:08 by avast             #+#    #+#             */
/*   Updated: 2023/02/28 17:21:19 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipes.h"
#include "../../libft/libft.h"

void	display_heredoc(int cmds)
{
	while (cmds--)
		ft_putstr_fd("pipe ", 1);
	ft_putstr_fd("heredoc> ", 1);
}

int	heredoc(char *limiter, int argc)
{
	int		pfd[2];
	char	*new_limiter;
	char	*line;
	char	*infile;

	if (pipe(pfd) == -1)
		return (error_msg(PIPE));
	new_limiter = ft_strjoin(limiter, "\n");
	infile = 0;
	while (1)
	{
		display_heredoc(argc - 5);
		line = get_next_line(0);
		if (!ft_strncmp(line, new_limiter, ft_strlen(line)))
			break ;
		infile = ft_strjoin_gnl(infile, line);
		free(line);
	}
	ft_putstr_fd(infile, pfd[1]);
	return (close(pfd[1]), free(infile), free(line),
		free(new_limiter), pfd[0]);
}

int	get_infile_fd(int argc, char **argv)
{
	int	infile;

	if (!ft_strncmp(argv[1], "here_doc\0", 9))
		infile = heredoc(argv[2], argc);
	else
	{
		infile = open(argv[1], O_RDONLY);
		if (infile == -1 && access(argv[1], F_OK) == 0)
			return (shell_error_msg(argv[1], PERMISSION_DENIED));
		else if (infile == -1 && access(argv[1], F_OK) == -1)
			return (shell_error_msg(argv[1], NO_FILE));
	}
	return (infile);
}

int	get_outfile_fd(int argc, char **argv)
{
	int	outfile;

	if (!ft_strncmp(argv[1], "here_doc\0", 9))
		outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_APPEND, 0644);
	else
		outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
		return (PERMISSION_DENIED);
	return (outfile);
}
