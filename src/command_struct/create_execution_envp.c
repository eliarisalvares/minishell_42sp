/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_execution_envp.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 21:25:54 by elraira-          #+#    #+#             */
/*   Updated: 2022/09/01 04:26:58 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief Create a execution envp object by allocating memory for it and
 * then filling it with the exported environment variables.
 * @param command The command to execute.
 */
void	create_execution_envp(t_cmd *command)
{
	t_hashtable	*table;
	t_hashpair	*pair;
	char		**envp;
	size_t		i;
	int			count;

	table = g_minishell.envp;
	envp = malloc((table->count + 1) * sizeof(char *));
	i = 0;
	count = 0;
	while (i < table->size)
	{
		pair = table->pair_list[i];
		while (pair)
		{
			if (pair->location == GLOBAL)
				envp[count++]
					= ft_strnjoin(3, pair->pair_key, "=", pair->pair_value);
			pair = pair->next;
		}
		i++;
	}
	envp[count] = NULL;
	command->envp = envp;
}
