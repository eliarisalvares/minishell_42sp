/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:34:25 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/30 01:22:47 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	unset_pair(char *key);

/**
 * @brief Unsets a variable from the envp list.
 *
 * @param exec the exec list of parameters.
 * @return int 0 for success, 1 for error.
 */
int	unset_builtin(char **exec)
{
	int		i;

	i = 0;
	while (exec[++i])
		unset_pair(exec[i]);
	return (0);
}

/**
 * @brief Removes a pair from the envp list.
 *
 * @param key The variable's key to delete.
 */
static void	unset_pair(char *key)
{
	t_hashpair	*pair;
	t_hashpair	*prev;
	int			i;

	i = hash_function(key, g_minishell.envp->size);
	prev = NULL;
	pair = g_minishell.envp->pair_list[i];
	while (pair)
	{
		if (!ft_strncmp(pair->pair_key, key, ft_strlen(key) + 1))
		{
			if (!prev)
				g_minishell.envp->pair_list[i] = pair->next;
			else
				prev->next = pair->next;
			free(pair->pair_key);
			free(pair->pair_value);
			free(pair);
			pair = NULL;
			break ;
		}
		prev = pair;
		pair = pair->next;
	}
}
