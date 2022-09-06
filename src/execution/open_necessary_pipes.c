/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_necessary_pipes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:45:39 by elraira-          #+#    #+#             */
/*   Updated: 2022/09/01 04:28:51 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief Will open all necessary pipes defined by the T_PIPE endpoints. It
 * will also determine the correct file descriptors for input and output of
 * the executables.
 */
void	open_necessary_pipes(void)
{
	t_cmd	*command;

	command = g_minishell.command;
	while (command)
	{
		if (command->endpoint == T_PIPE)
		{
			if (pipe(command->fd_pipe) == -1)
			{
				free_minishell();
				exit(11);
			}
			command->fd_out = command->fd_pipe[1];
			command->is_piped = 1;
			command->next->fd_in = command->fd_pipe[0];
			command->next->is_piped = 1;
		}
		command = command->next;
	}
}
