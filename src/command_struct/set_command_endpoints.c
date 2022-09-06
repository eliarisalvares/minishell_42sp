/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_command_endpoints.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:04:49 by elraira-          #+#    #+#             */
/*   Updated: 2022/09/01 04:28:51 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief This function will take the initialized command struct and the list
 * of tokens and fill the command and redirect list by iterating through the
 * token list and analyzing the tokens. If the token is a redirection token,
 * it will add the token to the redirect list. If the token is a command token,
 * it will add the token to the command list. Then, it will set the tokens
 * as endpoints for the command struct.
 *
 * @param cmd The command struct.
 * @param list The list of tokens.
 * @param prev The previous token.

 */
void	set_command_endpoints(t_cmd **cmd, t_token **list, int *prev)
{
	t_token	**location;

	while (*list && (*list)->token_type < T_PIPE)
	{
		location = &(*cmd)->commands;
		if (is_redirection(*prev, (*list)->token_type))
			location = &(*cmd)->redirections;
		token_add_back(location, token_copy(*list));
		(*prev) = (*list)->token_type;
		(*list) = (*list)->next;
	}
	if (*list)
	{
		(*cmd)->endpoint = (*list)->token_type;
		(*prev) = (*list)->token_type;
		(*list) = (*list)->next;
	}
}
