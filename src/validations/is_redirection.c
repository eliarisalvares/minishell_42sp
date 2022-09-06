/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:04:49 by elraira-          #+#    #+#             */
/*   Updated: 2022/09/01 04:32:31 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief Checks if the character is a redirection character in the token_type
 * enum.
 *
 * @param prev The previous character.
 * @param token_type The token type.
 * @return int 1 if the character is a redirection character, 0 otherwise.
 */
int	is_redirection(int prev, int token_type)
{
	if (token_type == T_REDIR_OUT || token_type == T_HEREDOC
		|| token_type == T_REDIR_IN || token_type == T_REDIR_OUT_APPEND
		|| prev == T_REDIR_IN || prev == T_REDIR_OUT
		|| prev == T_REDIR_OUT_APPEND || prev == T_HEREDOC)
		return (1);
	return (0);
}
