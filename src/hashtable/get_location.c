/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_location.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:32:19 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/30 01:53:31 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief This function will get the hashtable's location of a variable.
 *
 * @param key The variable's key to get the location of.
 * @return int
 */
int	get_location(char *key)
{
	t_hashtable	*table;
	t_hashpair	*aux;
	int			index;

	table = g_minishell.envp;
	index = hash_function(key, table->size);
	aux = table->pair_list[index];
	while (aux)
	{
		if (!ft_strncmp(aux->pair_key, key, ft_strlen(key)))
			return (aux->location);
		aux = aux->next;
	}
	return (-1);
}
