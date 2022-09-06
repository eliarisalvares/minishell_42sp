/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bash_grammar.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:32:36 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/30 01:24:42 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief This function checks if the command is valid. Which means it will
 * make sure the list of tokens is in the correct order so that the shell can
 * execute the command properly.
 * @param tokens The list of tokens to be checked.
 * @return Returns 1 if the command is valid, 0 otherwise.
 */
int	check_bash_grammar(void)
{
	t_token	*token;
	int		index;

	token = g_minishell.parser->tokens;
	index = 0;
	while (token)
	{
		if (!is_valid_pipe(token, index) || !is_valid_redirection(token)
			|| !is_closed_quotation_mark(token))
			return (0);
		token = token->next;
		index++;
	}
	return (1);
}
