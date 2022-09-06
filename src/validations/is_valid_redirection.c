/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_redirection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 09:05:44 by elraira-          #+#    #+#             */
/*   Updated: 2022/09/01 04:32:44 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief This function will check if the token is a valid redirection. A
 * redirection is valid if it is a redirection operator (>, <, >>, <<) and if
 * the next token is a word. If the redirection is invalid, the function will
 * print an error message.
 *
 * @param token the token node to be checked.
 * @return int return 1 if the redirection is valid, and 0 otherwise.
 */
int	is_valid_redirection(t_token *token)
{
	if (token->token_type == T_REDIR_IN
		|| token->token_type == T_REDIR_OUT_APPEND
		|| token->token_type == T_REDIR_OUT || token->token_type == T_HEREDOC)
	{
		if (!token->next)
		{
			ft_putstr_fd("minishell: syntax error near unexpected token ", 2);
			ft_putstr_fd("`newline'\n", 2);
			return (0);
		}
		else if (token->next->token_type != T_WORD)
		{
			ft_putstr_fd("minishell: syntax error near unexpected token: ", 2);
			ft_putstr_fd(token->next->token_value, 2);
			ft_putstr_fd("\n", 2);
			return (0);
		}
	}
	return (1);
}
