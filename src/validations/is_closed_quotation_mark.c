/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_closed_quotation_mark.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 09:08:07 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/30 18:48:25 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief This function will iterate through the token and check if the closing
 * mark is correct (both '\' and \"').
 *
 * @param token the token node to be checked.
 * @return int return 1 if the quotation marks are correct, and 0 otherwise.
 */
int	is_closed_quotation_mark(t_token *t)
{
	int		flag;
	int		i;

	flag = -1;
	i = 0;
	if (!t->next)
	{
		while (t->token_value[i])
		{
			if (flag == -1 && (t->token_value[i] == 34
					|| t->token_value[i] == 39))
				flag = i;
			else if (flag != -1 && t->token_value[i] == t->token_value[flag])
				flag = -1;
			i++;
		}
		if (flag != -1)
		{
			ft_putstr_fd("minishell: found EOF when expecting quote\n", 2);
			free_minishell();
			exit(2);
			return (0);
		}
	}
	return (1);
}
