/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pairs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:05:21 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/27 21:18:15 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief This function will free the memory previously allocated for the
 * pairs of the hashtable.
 */
void	free_pairs(t_hashpair *pair)
{
	t_hashpair	*aux;

	while (pair)
	{
		aux = pair;
		pair = aux->next;
		free(aux->pair_key);
		free(aux->pair_value);
		free(aux);
	}
}
