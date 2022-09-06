/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_list_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 21:25:54 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/30 15:49:36 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief This function will add a new t_cmd command to the back of the linked
 * list.
 *
 * @param command The command node to add to the back of the t_cmd linked list.
 */
void	command_add_back(t_cmd *command)
{
	t_cmd	*command_lst;

	command_lst = g_minishell.command;
	if (!command_lst)
		g_minishell.command = command;
	else
	{
		while (command_lst->next)
			command_lst = command_lst->next;
		command_lst->next = command;
	}
}

/**
 * @brief This function will add a new t_cmd node to the front of the linked
 * list.
 *
 * @param command The node to add to the front of the t_cmd linked list.
 */
void	command_add_front(t_cmd *command)
{
	t_cmd	*command_lst;
	t_cmd	*aux;

	command_lst = g_minishell.command;
	if (!command_lst)
		g_minishell.command = command;
	else
	{
		aux = command_lst;
		g_minishell.command = command;
		g_minishell.command->next = aux;
	}
}

/**
 * @brief This function will create a new t_cmd node by allocating memory for
 * it and initializing its fields.
 *
 * @param id The id of the command.
 * @return t_cmd* The new node.
 */
t_cmd	*init_command_struct(int id)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
	{
		free_minishell();
		exit(12);
	}
	cmd->id = id;
	cmd->commands = NULL;
	cmd->redirections = NULL;
	cmd->endpoint = -1;
	cmd->is_piped = 0;
	cmd->exec = NULL;
	cmd->exec_path = NULL;
	cmd->envp = NULL;
	cmd->fd_in = -2;
	cmd->fd_out = -2;
	cmd->next = NULL;
	return (cmd);
}
