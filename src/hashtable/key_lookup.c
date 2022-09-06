/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_lookup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:11:50 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/27 07:36:39 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief This function searches for the value of a given key in a specific
 * hashtable.
 * @param key The variable key.
 * @return char* The value string of the pair with the given key.
 */
char	*key_lookup(char *key)
{
	t_hashtable	*hashtable;
	t_hashpair	*aux;
	int			index;

	hashtable = g_minishell.envp;
	index = hash_function(key, hashtable->size);
	aux = hashtable->pair_list[index];
	while (aux)
	{
		if (!ft_strncmp(aux->pair_key, key, ft_strlen(key)))
			return (aux->pair_value);
		aux = aux->next;
	}
	return (NULL);
}
