/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hashtable_struct.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:34:25 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/30 02:00:17 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief This function will allocate memory for the hashtable struct and init
 * its member's values. It will also allocate memory for the hashtable's pairs.
 * The hashtable will be of size 80 so that it can hold 80 variables which
 * should be enough for most cases.
 *
 * @return t_hashtable* The hashtable allocated and initialized.
 */
t_hashtable	*init_hashtable_struct(void)
{
	t_hashtable	*table;

	table = malloc(sizeof(t_hashtable));
	if (!table)
	{
		free_minishell();
		exit(12);
	}
	table->size = 80;
	table->count = 0;
	table->pair_list = ft_calloc(sizeof(t_hashpair *), 80);
	if (!table->pair_list)
	{
		free_minishell();
		exit(12);
	}
	return (table);
}
