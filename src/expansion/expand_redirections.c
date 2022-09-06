/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_redirections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:15:56 by elraira-          #+#    #+#             */
/*   Updated: 2022/09/01 03:24:04 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief This function will iterate through the redirections members of the
 * command structure and, with the exeption of "<<" which is the beginning of a
 * heredoc redirection, it will jump to the next token and, through the function
 * "expand_dollar_and_quotes", it will expand any dollar sign and quotes found
 * in the token.
 *
 * @param command The command structure to be iterated through.
 */
void	expand_redirections(t_cmd *command)
{
	t_token	*token;

	token = command->redirections;
	while (token)
	{
		if (ft_strncmp(token->token_value, "<<", 3))
		{
			token = token->next;
			expand_dollar_and_quotes(&token);
		}
		else
			token = token->next;
		token = token->next;
	}
}
