/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:19:54 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/30 01:43:32 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief This function cleans the previous path and search for the new one. If
 * the command is not a minishell builtin, it must be searched in the PATH
 * environment variable. The PATH environment variable is split by ':' and each
 * path is checked for the command. If the command is found, the path is
 * returned. The PATH variable holds the paths to all programs (binaries) that
 * are installed on the system.
 *
 * @param command The command to be searched.
 * @return char* The path to the command.
 */
char	*get_command_path(t_cmd *command)
{
	char	*path;

	if (!*command->exec)
		return (NULL);
	if (command->exec_path)
		free(command->exec_path);
	if (is_minishell_command(command))
		path = ft_strdup(command->exec[0]);
	else
	{
		path = split_path(command);
		if (!path)
		{
			if (!key_lookup("PATH"))
				command_path_error(command, 1);
			else
				command_path_error(command, 2);
		}
	}
	return (path);
}
