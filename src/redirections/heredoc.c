/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:48:17 by elraira-          #+#    #+#             */
/*   Updated: 2022/09/01 04:21:36 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	write_error(char *limiter);
static void	heredoc_loop(char *limiter, int *file_descriptor);

/**
 * @brief A here-document is a special kind of redirection. It is used to
 * redirect the output of a command to a file. The user is then prompted for
 * input and the input is written to the file when the command is executed.
 * It will keep prompting the user until it finds the given delimiter
 * (<<delimiter). The prompting is done in a loop using realine until is broken 
 * by the delimiter recognition. If EOF is found, an error is returned. If
 * the fd is invalid or there's an error with the process, it will also return
 * an error.
 * @param line The line of the command.
 */
int	heredoc(char *name)
{
	int		fd[2];
	int		pid;
	int		status;

	if (pipe(fd) == -1)
		return (heredoc_error(NULL));
	pid = fork();
	if (pid == -1)
		return (heredoc_error(NULL));
	if (!pid)
	{
		close(fd[0]);
		heredoc_loop(ft_strdup(name), &fd[1]);
	}
	heredoc_parent_signal();
	close(fd[1]);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status) == 130)
		return (heredoc_error(fd));
	return (fd[0]);
}

static void	heredoc_loop(char *limiter, int *file_descriptor)
{
	char	*line;
	int		size;

	heredoc_child_signal();
	line = readline("> ");
	size = ft_strlen(limiter);
	while (1)
	{
		if (!line)
			write_error(limiter);
		if (!line || (!ft_strncmp(limiter, line, size) && !line[size]))
			break ;
		ft_putendl_fd(line, *file_descriptor);
		free(line);
		line = readline("> ");
	}
	free(line);
	close(*file_descriptor);
	free(limiter);
	exit(0);
}

static void	write_error(char *limiter)
{
	ft_putstr_fd("minishell: warning: here-document delimited by ", 2);
	ft_putstr_fd("end of file (wanted", 2);
	ft_putstr_fd(limiter, 2);
	ft_putstr_fd(")\n", 2);
}
