/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:19:54 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/26 14:39:02 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief Split a path into a list of directories.
 * @param path The path to split.
 * @return A list of directories.
 */
char	*split_path(t_cmd *command)
{
	char	**path_list;
	char	*path;
	char	*aux;

	path_list = NULL;
	path = NULL;
	if (ft_strchr(command->exec[0], '/') != NULL)
	{
		path = ft_strdup(command->exec[0]);
		return (path);
	}
	aux = key_lookup("PATH");
	if (aux)
		path_list = ft_split(aux, ':');
	if (path_list)
		check_access(command, path_list, &path);
	if (!path && !access(command->exec[0], F_OK | X_OK))
		path = ft_strdup(command->exec[0]);
	return (path);
}
