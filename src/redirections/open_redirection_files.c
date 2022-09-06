/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_redirection_files.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:48:17 by elraira-          #+#    #+#             */
/*   Updated: 2022/09/01 04:28:40 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief This function will open the file descriptor for the redirection and
 * set the flags for the file descriptor.
 * The flags are: O_RDWR, which is the read and write flag, O_CREAT which will
 * create the file if it doesn't exist, O_TRUNC which will truncate the file if
 * it exists, O_RDONLY which will open the file in read only mode and O_APPEND
 * which will append to the file if it exists.
 * The
 *
 * @param redir_type The type of redirection.
 * @param filename The name of the file to open.
 * @param cmd The command that is being executed.
 */
void	open_redirection_files(int redir_type, char *filename, t_cmd *command)
{
	if (redir_type == T_REDIR_OUT_APPEND || redir_type == T_REDIR_OUT)
	{
		if (command->fd_out != -2)
			close(command->fd_out);
	}
	else if (redir_type == T_HEREDOC || redir_type == T_REDIR_IN)
	{
		if (command->fd_in != -2)
			close(command->fd_in);
	}
	if (redir_type == T_REDIR_OUT_APPEND)
		command->fd_out = open(filename, O_RDWR | O_APPEND | O_CREAT, 0777);
	else if (redir_type == T_REDIR_OUT)
		command->fd_out = open(filename, O_RDWR | O_TRUNC | O_CREAT, 0777);
	else if (redir_type == T_REDIR_IN)
		command->fd_in = open(filename, O_RDONLY);
	else if (redir_type == T_HEREDOC)
		command->fd_in = heredoc(filename);
	command->error_number = errno;
	if (errno != 0)
		command->filename = filename;
}
