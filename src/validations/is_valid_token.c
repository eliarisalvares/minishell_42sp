/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 08:29:23 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/31 22:49:11 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief This function will identify if the current char from the input
 * reading is a new valid token to add to the list.
 *
 * @param input The input string.
 * @param index The current index in the input string.
 * @param prev The previous token.
 * @return int Returns 1 if the current char is a new token, otherwise 0.
 */
int	is_valid_token(const char *input, size_t index, size_t prev)
{
	if (!index || !input[index])
		return (1);
	if (has_matching_quote(input, index))
		return (0);
	if (ft_strchr("|<> ", input[index]))
	{
		if (index - prev == 1)
		{
			if (input[index] == '<' && input[prev] == '<'
				|| input[index] == '>' && input[prev] == '>'
				|| input[index] == ' ' && input[prev] == ' ')
				return (0);
		}
		if (ft_isblank(input[index]) && ft_isblank(input[index - 1]))
			return (0);
		return (1);
	}
	if (index > 0 && ft_strchr("|<> ", input[index - 1]))
		return (1);
	return (0);
}
