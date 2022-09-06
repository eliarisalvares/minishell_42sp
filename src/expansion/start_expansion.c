/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:15:56 by elraira-          #+#    #+#             */
/*   Updated: 2022/09/06 19:32:19 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief This function will substitute the value of the nodes of the t_token
 * list according to bash's rules of expansion. The expansion rules contemplated
 * are: parameter expansion (for $), exit_code expansion (for $?), and
 * quote expansion (for " and ').
 */
void	start_expansion(void)
{
	t_cmd	*command;
	t_token	*token;

	command = g_minishell.command;
	while (command)
	{
		token = command->commands;
		while (token)
		{
			expand_dollar_and_quotes(&token);
			token = token->next;
		}
		expand_redirections(command);
		command = command->next;
	}
}
