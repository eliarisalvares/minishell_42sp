/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_envp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:05:21 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/19 17:06:21 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief Will free the memory previously allocated for the execution envp.
 *
 * @param command The command to execute.
 */
void	free_envp(t_cmd *command)
{
	int		i;

	i = -1;
	while (command->envp[++i])
		free(command->envp[i]);
	free(command->envp);
	command->envp = NULL;
}
