/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_execution_array(.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 21:25:54 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/28 09:38:16 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief This function will prepare the array of strings to be executed by
 * iterating through the command structure and converting each token into an
 * array of strings by calling convert_to_array().
 */
void	create_execution_array(void)
{
	t_cmd	*cmd;

	cmd = g_minishell.command;
	while (cmd)
	{
		cmd->exec = convert_to_array(cmd->commands);
		cmd = cmd->next;
	}
}
