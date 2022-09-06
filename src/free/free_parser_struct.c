/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parser_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:05:21 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/26 16:53:36 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief This function will free the memory previously allocated for the
 * parser struct.
 */
void	free_parser_struct(void)
{
	if (!g_minishell.parser)
		return ;
	if (g_minishell.parser->input)
		free(g_minishell.parser->input);
	if (g_minishell.parser->tokens)
		free_tokens(&g_minishell.parser->tokens);
	free(g_minishell.parser);
	g_minishell.parser = NULL;
}
