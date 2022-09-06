/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:08:52 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/30 01:22:05 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief This function will start the execution of the commands. First, all
 * the pipes are opened, then the redirections and heredocs are applied. Finally,
 * the commands are executed.
 */
void	start_execution(void)
{
	t_cmd	*cmd;

	cmd = g_minishell.command;
	open_necessary_pipes();
	if (!define_redirection_fds())
		return ;
	while (cmd)
	{
		command_execution(&cmd);
		if (cmd)
			cmd = cmd->next;
	}
}
