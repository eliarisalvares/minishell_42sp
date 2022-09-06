/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_token_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:43:22 by elraira-          #+#    #+#             */
/*   Updated: 2022/09/01 04:28:51 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief Will define the token type by comparing the token with the available
 * token types.
 *
 * @param token The token to compare.
 * @return int The token type.
 */
int	define_token_type(char *token)
{
	if (!ft_strncmp(token, "|", 1) && ft_strncmp(token, "||", 2))
		return (T_PIPE);
	if (!ft_strncmp(token, ">", 1) && ft_strncmp(token, ">>", 2))
		return (T_REDIR_OUT);
	if (!ft_strncmp(token, "<", 1) && ft_strncmp(token, "<<", 2))
		return (T_REDIR_IN);
	if (!ft_strncmp(token, ">>", 2))
		return (T_REDIR_OUT_APPEND);
	if (!ft_strncmp(token, "<<", 2))
		return (T_HEREDOC);
	else
		return (T_WORD);
}
