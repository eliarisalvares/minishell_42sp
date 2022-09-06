/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_single_file_descriptor.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:22:50 by elraira-          #+#    #+#             */
/*   Updated: 2022/09/01 04:27:40 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief This function will check for open file descriptors and close them.
 *
 * @param command The command to check.
 * @param  fd_type Whether the file descriptors should be closed on the input
 * or output or both.
 */
void	close_single_file_descriptor(t_cmd *command, int fd_type)
{
	if ((fd_type == IN || fd_type == IN_OUT) && command->fd_in > 2)
		close(command->fd_in);
	if ((fd_type == OUT || fd_type == IN_OUT) && command->fd_out > 2)
		close(command->fd_out);
}
