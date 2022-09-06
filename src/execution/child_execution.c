/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:04:49 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/30 16:41:19 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	child_execution(t_cmd *command)
{
	if (command->fd_in > 2)
		dup2(command->fd_in, STDIN_FILENO);
	if (command->fd_out > 2)
		dup2(command->fd_out, STDOUT_FILENO);
	close_all_file_descriptors();
	if (is_minishell_command(command))
		send_to_execution_in_child(command);
	else
	{
		child_signals();
		execve(command->exec_path, command->exec, command->envp);
		return_error(command->exec[0], errno);
	}
	free_minishell();
	exit(g_minishell.exit_code);
}
