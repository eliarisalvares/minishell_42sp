/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_all_file_descriptors.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:22:50 by elraira-          #+#    #+#             */
/*   Updated: 2022/09/01 04:27:40 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief This function will iterate through the command list and will close
 * each file descriptor.
 */
void	close_all_file_descriptors(void)
{
	t_cmd	*command;

	command = g_minishell.command;
	while (command)
	{
		close_single_file_descriptor(command, IN_OUT);
		command = command->next;
	}
}
