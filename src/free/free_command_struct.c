/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_command_struct.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:05:21 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/30 01:39:01 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief This function will free all the memory allocated by the command
 * struct. First, it will free all the command tokens, then the redirect tokens,
 * then the exec array and finally the exec_path string.
 */
void	free_command_struct(void)
{
	t_cmd	*curr;
	t_cmd	*aux;

	curr = g_minishell.command;
	while (curr)
	{
		aux = curr;
		curr = curr->next;
		free_tokens(&aux->commands);
		free_tokens(&aux->redirections);
		free_execution_list(aux->exec);
		if (aux->envp)
			free_envp(aux);
		if (aux->exec_path)
			free(aux->exec_path);
		free(aux);
	}
	g_minishell.command = NULL;
}
