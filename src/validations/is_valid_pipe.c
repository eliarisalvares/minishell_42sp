/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 19:23:59 by elraira-          #+#    #+#             */
/*   Updated: 2022/09/01 04:28:51 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief Check if the pipe token_type is not at the beginning of the input or
 * if it is not followed by a command. In case of error, it prints an error
 * message.
 *
 * @param token The token to be checked.
 * @param pos The index of the char in token's string.
 * @return int 1 if the syntax is correct, 0 otherwise.
 */
int	is_valid_pipe(t_token *token, int pos)
{
	if (token->token_type == T_PIPE)
	{
		if (pos == 0 || !token->next)
		{
			ft_putstr_fd("syntax error near unexpected token `|'\n", 2);
			return (0);
		}
	}
	return (1);
}
