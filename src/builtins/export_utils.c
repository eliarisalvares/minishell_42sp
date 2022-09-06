/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:33:03 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/30 21:15:51 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief This function is called in export(). It contains a list of invalid
 * characters, character combinations or blanks for export names.
 * @param key The key to check.
 * @return int 0 if the identifier is invalid, 1 otherwise.
 */
int	is_valid_identifier(char *key)
{
	int	i;

	i = 0;
	while (key[i])
	{
		if (key[i] == '-' || key[i] == '.' || key[i] == '{' || key[i] == '}'
			|| key[i] == '*' || key[i] == '#' || key[i] == '@' || key[i] == '!'
			|| key[i] == '^' || key[i] == '~' || key[i] == 39 || key[i] == '|'
			|| key[i] == 34 || key[i] == 36 || key[i] == ';' || key[i] == '&'
			|| key[i] == '=' || key[i] == ' ' || !ft_isalnum(key[i]))
		{	
			g_minishell.exit_code = 1;
			return (0);
		}
		if (key[i] == '+' && key[i + 1] != '=')
		{
			g_minishell.exit_code = 1;
			return (0);
		}
		i++;
	}
	return (1);
}

/**
 * @brief This function will replace a pair in the hashtable.
 */
void	replace_pair(char *pair_key, char *pair_value)
{
	t_hashtable	*table;
	t_hashpair	*list;
	char		*replace;
	int			index;

	table = g_minishell.envp;
	index = hash_function(pair_key, table->size);
	list = table->pair_list[index];
	while (ft_strncmp(list->pair_key, pair_key, ft_strlen(pair_key)))
		list = list->next;
	replace = list->pair_value;
	list->pair_value = ft_strdup(pair_value);
	free(replace);
	free(pair_key);
	free(pair_value);
}

/**
 * @brief This function will export a variable set locally to the enviroment.
 *
 * @param pair_key The key to set.
 * @param new_location The new location of the key.
 */
void	export_pair(char *pair_key, int new_location)
{
	t_hashtable	*table;
	t_hashpair	*list;
	int			index;

	table = g_minishell.envp;
	index = hash_function(pair_key, table->size);
	list = table->pair_list[index];
	while (ft_strncmp(list->pair_key, pair_key, ft_strlen(pair_key)))
		list = list->next;
	list->location = new_location;
	free(pair_key);
}
