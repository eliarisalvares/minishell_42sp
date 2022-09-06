/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_to_execution_in_child.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:13:34 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/27 05:52:19 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/********
 * @brief This function executes the builtins that are executed in a child
 * process. The reason some commands are executed in a child process is because
 *
 * @param command
 */
void	send_to_execution_in_child(t_cmd *command)
{
	if (!ft_strncmp(command->exec_path, "env\0", 4))
		g_minishell.exit_code = env_builtin(command);
	else if (!ft_strncmp(command->exec_path, "export\0", 7))
		g_minishell.exit_code = export_builtin(command->exec);
	else if (!ft_strncmp(command->exec_path, "echo\0", 5))
		g_minishell.exit_code = echo_builtin(command->exec);
	else if (!ft_strncmp(command->exec_path, "pwd\0", 4))
		g_minishell.exit_code = pwd_builtin();
}
