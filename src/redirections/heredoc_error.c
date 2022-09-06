/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:48:17 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/30 01:53:19 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief This function will deal with error while running heredoc. If pid is
 * negative, then there was an error while executing the command. Also, if the
 * fd is negative, then there was an error while opening the file.
 *
 * @param fd The file descriptor of the file.
 * @return int return failure.
 */
int	heredoc_error(int *fd)
{
	if (fd)
		close(fd[0]);
	else
	{
		free_minishell();
		exit(-54);
	}
	return (-3);
}
