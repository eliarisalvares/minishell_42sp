/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_redirection_fds.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:48:17 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/30 01:25:23 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
 * @brief This function will check if the file descriptor is valid. If it is,
 * it will iterate through the list of redirections opening the necessary ones
 * and defining its flags.
 * A negative file descriptor will be considered as an error.
 */
int	define_redirection_fds(void)
{
	t_cmd	*command;
	t_token	*redirections;

	command = g_minishell.command;
	while (command)
	{
		redirections = command->redirections;
		while (redirections)
		{
			if (command->fd_out != -1 || command->fd_in != -1)
			{
				open_redirection_files(redirections->token_type,
					redirections->next->token_value, command);
				redirections = redirections->next;
				redirections = redirections->next;
			}
		}
		if (!is_valid_file_descriptor(command))
			return (0);
		command = command->next;
	}
	return (1);
}
