/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:19:54 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/30 01:25:08 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief Check if a file exists and is executable.
 * @param command The command to check.
 * @param path_list The list of directories to check.
 * @param path The path to the file.
 */
void	check_access(t_cmd *command, char **path_list, char **path)
{
	char	*aux;
	int		i;

	i = -1;
	while (path_list[++i])
	{
		aux = ft_strnjoin(3, path_list[i], "/", command->exec[0]);
		if (access(aux, F_OK) == 0)
		{
			*path = aux;
			break ;
		}
		free(aux);
	}
	free_path(path_list);
}
