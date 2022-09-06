/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_forked_builtin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 10:21:50 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/27 18:57:47 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief Some builtins need a child process to run. This function checks if a
 * builtin needs a child process. If it does, it returns 1. Otherwise, it
 * returns 0. The builtins that need a child process are: cd, exit, unset.
 *
 * @param command The command to execute.
 * @return int 1 if the command needs a child process, 0 otherwise.
 */
int	is_forked_command(t_cmd *command)
{
	if (!ft_strncmp(command->exec_path, "cd\0", 3)
		|| !ft_strncmp(command->exec_path, "unset\0", 6)
		|| !ft_strncmp(command->exec_path, "exit\0", 5))
	{
		if (!command->is_piped)
			send_to_execution_in_parent(command);
		return (0);
	}
	else if (!ft_strncmp(command->exec_path, "export\0", 7)
		&& command->exec[1] && *command->exec[1])
	{
		if (!command->is_piped)
			send_to_execution_in_parent(command);
		return (0);
	}
	return (1);
}
