/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_pair.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:34:25 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/30 01:24:28 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	add_back(t_hashpair **pair, char *key, char *value, int location);

/**
 * @brief This function inserts a new key-value pair into the hashtable.
 *
 * @param pair_key The key of the new pair.
 * @param pair_value The pair_value of the new pair.
 * @param location The location of the new pair.
 * @param hashtable The hashtable to insert the new pair into.
 */
void	insert_pair(char *pair_key, char *pair_value, int location)
{
	t_hashtable	*hashtable;
	int			index;

	hashtable = g_minishell.envp;
	index = hash_function(pair_key, hashtable->size);
	add_back(&(hashtable->pair_list[index]), pair_key, pair_value, location);
	hashtable->count++;
	free(pair_key);
	free(pair_value);
}

/**
 * @brief This function adds a new pair to the end of the list.
 *
 * @param pair The list to add the new pair to.
 * @param key The key of the new pair.
 * @param value The value of the new pair.
 * @param location The location of the new pair.
 */
static void	add_back(t_hashpair **pair, char *key, char *value, int location)
{
	t_hashpair	*new_pair;
	t_hashpair	*aux;

	new_pair = malloc(sizeof(t_hashpair));
	if (!new_pair)
		return ;
	new_pair->pair_key = ft_strdup(key);
	new_pair->pair_value = ft_strdup(value);
	new_pair->location = location;
	new_pair->next = NULL;
	aux = *pair;
	if (!aux)
		*pair = new_pair;
	else
	{
		while (aux->next)
			aux = aux->next;
		aux->next = new_pair;
	}
}
