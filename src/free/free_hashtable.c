/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_hashtable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:05:21 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/30 01:38:50 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief This function will free the memory previously allocated for the
 * hashtable.
 */
void	free_hashtable(void)
{
	t_hashtable	*hashtable;
	size_t		i;

	i = 0;
	hashtable = g_minishell.envp;
	while (i < hashtable->size)
	{
		free_pairs(hashtable->pair_list[i]);
		i++;
	}
	free(hashtable->pair_list);
	free(hashtable);
}
