/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_expandable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 01:55:58 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/30 16:38:59 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief Checks whether the current char indicates an expandable variable.
 * The variable is expandable if is followd by an '?' or an letter. If, it 
 * is followed by a digit, it won't produce an output but the '$' also won't
 * be treated as an ordinary character.
 *
 * @param c The current char.
 * @return int 0 if the current char is expandable, 1 otherwise.
 */
int	is_expandable(char c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	if (c == 63)
		return (1);
	return (0);
}
