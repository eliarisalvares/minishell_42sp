/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_minishell_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 10:21:50 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/30 01:35:20 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief Checks if the command is a subject defined command.
 *
 * @param cmd The command to be checked.
 * @return int 1 if the command is a subject defined command, 0 otherwise.
 */
int	is_minishell_command(t_cmd *cmd)
{
	if (!ft_strncmp(cmd->exec[0], "echo\0", 5))
		return (1);
	else if (!ft_strncmp(cmd->exec[0], "pwd\0", 4))
		return (1);
	else if (!ft_strncmp(cmd->exec[0], "cd\0", 3))
		return (1);
	else if (!ft_strncmp(cmd->exec[0], "export\0", 7))
		return (1);
	else if (!ft_strncmp(cmd->exec[0], "unset\0", 6))
		return (1);
	else if (!ft_strncmp(cmd->exec[0], "env\0", 4))
		return (1);
	else if (!ft_strncmp(cmd->exec[0], "exit\0", 5))
		return (1);
	return (0);
}
