/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_command_table.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:04:49 by elraira-          #+#    #+#             */
/*   Updated: 2022/09/01 02:59:24 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief This function will take the token list and fill the command table.
 * First, it will init the command struct, then it will send to
 * set_command_endpoints to fill the command and redirect list and
 * add the endpoint to the command struct.
 */
void	fill_command_table(void)
{
	t_cmd	*command_node;
	t_token	*token_list;
	int		prev;
	int		index;

	token_list = g_minishell.parser->tokens;
	prev = -1;
	index = 0;
	while (token_list)
	{
		command_node = init_command_struct(index);
		set_command_endpoints(&command_node, &token_list, &prev);
		command_add_back(command_node);
		index++;
	}
	start_expansion();
	create_execution_array();
}
