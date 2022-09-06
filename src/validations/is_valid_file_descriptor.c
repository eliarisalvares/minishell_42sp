/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_file_descriptor.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:48:17 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/29 19:13:12 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief This function will check if the file descriptors are valid.
 * If they are not, the function will return 0.
 *
 * @param command The command structure that contains the file descriptor.
 * @return 1 if the file descriptors are valid, 0 otherwise.
 */
int	is_valid_file_descriptor(t_cmd *command)
{
	if (command->fd_in == -3)
	{
		g_minishell.exit_code = 130;
		return (0);
	}
	if (command->fd_in == -2)
		command->fd_in = STDIN_FILENO;
	if (command->fd_out == -2)
		command->fd_out = STDOUT_FILENO;
	return (1);
}
