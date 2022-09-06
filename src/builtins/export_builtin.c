/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:18:21 by elraira-          #+#    #+#             */
/*   Updated: 2022/09/01 04:26:58 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	check_environment(char *key, char *value);
static void	check_valid_input(char **exec);
static void	print_declare(t_hashpair *node);
static void	export_error(char *pair_key);

/**
 * @brief The export command is a built-in command of the shell. Environmental
 * variables are exported in it as child processes. The existing environment
 * variables are not affected. The Export command having no argument is used to
 * display all the variables that are exported in the environment. This is
 * the main function of the export built-in command. It will iterate through the
 * arguments given to export and check their validity. If the variable to export
 * already exists in the environment, it will be replaced. If the variable to
 * export does not exist, it will be added to the environment. If no "=" is
 * found in the argument, nothing will be done but no error will be printed.
 *
 *
 * @param exec The exec list of parameters.
 * @return int 0 if the command was executed successfully.
 */
int	export_builtin(char **exec)
{
	char	*pair_key;
	char	*pair_value;
	int		i;

	i = 0;
	check_valid_input(exec);
	while (exec[++i])
	{
		pair_key = get_pair_key(exec[i]);
		if (!pair_key)
			pair_key = ft_strdup(exec[i]);
		if ((*exec[1] == '=' && exec[2] == NULL)
			|| !is_valid_identifier(pair_key))
		{
			export_error(pair_key);
			free(pair_key);
		}
		else
		{
			pair_value = get_pair_value(exec[i]);
			check_environment(pair_key, pair_value);
		}
	}
	return (0);
}

/**
 * @brief This function will figure out if the variable to export already exists
 * in the environment. If it does, it will replace the pair_value. If it 
 * does not, it will add the variable to the environment. If the variable to 
 * export is local, it will be added to the environment.
 *
 * @param pair_key The pair_key of the variable to export.
 * @param pair_value The pair_value of the variable to export.
 */
static void	check_environment(char *pair_key, char *pair_value)
{
	int	location;

	location = get_location(pair_key);
	if (location == -1)
		insert_pair(pair_key, pair_value, GLOBAL);
	else if (location == GLOBAL && pair_value)
		replace_pair(pair_key, pair_value);
	else if (location == LOCAL)
		export_pair(pair_key, GLOBAL);
}

/**
 * @brief This function is called by ft_export() function in case there's no
 * argument or if the first argument is an empty string. It will print all the
 * environment variables that are exported. This is the default behavior of the
 * export command.
 */
static void	check_valid_input(char **exec)
{
	t_hashpair	**pair;
	t_hashpair	*node;
	size_t		index;

	if (!exec[1] || !*exec[1])
	{
		pair = g_minishell.envp->pair_list;
		index = 0;
		while (index < g_minishell.envp->size)
		{
			node = pair[index];
			while (node)
			{
				if (node->location == GLOBAL)
					print_declare(node);
				node = node->next;
			}
			index++;
		}
	}
}

/**
 * @brief Will print the list of environment variables in case
 * export is called with no arguments preceded  by "declare -x"
*/
static void	print_declare(t_hashpair *node)
{
	if (!node->pair_value)
		printf("declare -x %s\n", node->pair_key);
	else
		printf("declare -x %s=\"%s\"\n",
			node->pair_key, node->pair_value);
}

/**
 * @brief Will print tan error message in case
 * export is called with an invalid identifier
*/
static void	export_error(char *pair_key)
{
	ft_putstr_fd("minishell: export: ", 2);
	ft_putstr_fd(pair_key, 2);
	ft_putstr_fd(": not a valid identifier\n", 2);
}
