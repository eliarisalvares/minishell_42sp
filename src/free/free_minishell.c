/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:05:21 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/30 01:29:49 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief This function will free all the memory allocated by the minishell.
 */
void	free_minishell(void)
{
	if (g_minishell.envp)
		free_hashtable();
	if (g_minishell.parser)
		free_parser_struct();
	if (g_minishell.command)
		free_command_struct();
	rl_clear_history();
}
