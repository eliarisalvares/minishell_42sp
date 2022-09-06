/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_to_execution_in_parent.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:13:34 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/27 21:19:42 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief There are two types of builtins: 1) builtins that are executed in the
 * parent process, and 2) builtins that are executed in a child process. The
 * builtins that are executed in the parent process are: env, export, echo, pwd.
 * The builtins that are executed in a child process are: cd, exit, unset.
 * This function executes the builtins that are executed in the parent process.
 * The reason some commands are executed in the parent process is because they
 * won't have the desired effect if they are executed in a child process.
 * The cd builtin and unset builtin builtin needs to be executed in the
 * parent process because they need update the environment variables not
 * only in the child process that carries a copy of it, but in the parent
 * process as well. The exit builtin needs to be executed in the parent process
 * because it needs to exit the shell as a whole.
 *
 * @param cmd The command to be executed.
 */
void	send_to_execution_in_parent(t_cmd *command)
{
	if (!ft_strncmp(command->exec_path, "cd\0", 3))
		g_minishell.exit_code = cd_builtin(command->exec);
	else if (!ft_strncmp(command->exec_path, "export\0", 7))
		g_minishell.exit_code = export_builtin(command->exec);
	else if (!ft_strncmp(command->exec_path, "unset\0", 6))
		g_minishell.exit_code = unset_builtin(command->exec);
	else if (!ft_strncmp(command->exec_path, "exit\0", 5))
		g_minishell.exit_code = exit_builtin(command->exec);
	free_envp(command);
	create_execution_envp(command);
}
