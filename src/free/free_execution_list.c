/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_execution_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:05:21 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/30 01:23:38 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/**
 * @brief This function will free all the memory allocated by the execution
 * list.
 * @param exec The execution list to free.
 */
void	free_execution_list(char **exec)
{
	int	i;

	if (!exec)
		return ;
	i = -1;
	while (exec[++i])
		free(exec[i]);
	free(exec);
}
