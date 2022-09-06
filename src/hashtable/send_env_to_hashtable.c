/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_env_to_hashtable.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 22:33:53 by elraira-          #+#    #+#             */
/*   Updated: 2022/09/01 04:26:58 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief This function takes the list of environment variables and inserts
 * them into the hashtable.
 *
 * @param envp The list of environment variables.
 * @return t_hashtable* The hashtable containing the environment variables.
 */
void	send_env_to_hashtable(char **envp)
{
	char		*pair_key;
	char		*pair_value;
	int			index;

	index = 0;
	while (envp[index])
	{
		pair_key = get_pair_key(envp[index]);
		pair_value = get_pair_value(envp[index]);
		insert_pair(pair_key, pair_value, GLOBAL);
		index++;
	}
	if (!key_lookup("OLDPWD"))
	{
		pair_key = ft_strdup("OLDPWD");
		pair_value = NULL;
		insert_pair(pair_key, pair_value, GLOBAL);
	}
}
