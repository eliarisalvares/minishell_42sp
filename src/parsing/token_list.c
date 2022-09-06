/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:20:53 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/30 01:13:47 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief This function will split the input by spaces and add each token to the
 * tokens list first by allocating memory for the token and copying the token
 * string and size using the ft_strdup function then creating a new token node
 * and lastly adding the new token node to the tokens list.
 *
 * @param input The input string.
 * @param size The input string size.
 */
void	token_list(const char *input, size_t size)
{
	t_token	*token_list;
	char	*token_value;

	while (ft_isblank(*input))
	{
		size--;
		input++;
	}
	if (!size || !(*input))
		return ;
	token_value = ft_strndup(input, size);
	token_list = create_new_token(token_value, 0);
	token_add_back(&g_minishell.parser->tokens, token_list);
}
