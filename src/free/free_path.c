/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:08:16 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/27 21:16:16 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief This function will iterate through the path and free each element.
 *
 * @param path The path list to free.
 */
void	free_path(char **path)
{
	int	index;

	index = 0;
	while (path[index])
	{
		free(path[index]);
		index++;
	}
	free(path);
}
