/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:05:21 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/30 01:24:02 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief Will free the memory previously allocated for the tokens.
 *
 * @param tokens The tokens to free.
 */
void	free_tokens(t_token **tokens)
{
	t_token	*token;
	t_token	*aux;

	token = *tokens;
	while (token)
	{
		aux = token;
		token = token->next;
		free(aux->token_value);
		free(aux);
	}
	*tokens = NULL;
}
