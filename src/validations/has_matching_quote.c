/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_matching_quote.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 01:55:58 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/30 16:40:30 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief Checks if the current strin is between an even number 
 * of quotes.
 * @param input The input string.
 * @param index The current char index in the input string.
 * @return int 1 if the current string is between quotes, 0 otherwise.
 */
int	has_matching_quote(const char *input, size_t index)
{
	int		match;
	int		count;

	match = -1;
	count = 0;
	while (count < (int)index)
	{
		if (input[count] == 34 || input[count] == 39)
		{
			if (match == -1)
				match = (int)count;
			else if (match != -1 && input[match] == input[count])
				match = -1;
		}
		count++;
	}
	if (match != -1)
		return (1);
	return (0);
}
