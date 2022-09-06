/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:27:35 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/30 01:33:54 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief This function will print the list of environment variables.
 *
 * @param command The command struct to get the environment variables from.
 * @return int The return value of the system call.
 */
int	env_builtin(t_cmd *command)
{
	size_t		i;
	char		**exec;
	int			ret;

	exec = command->exec;
	ret = 127;
	if (!key_lookup("PATH"))
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(exec[0], 2);
		ft_putstr_fd(": no such file or directory\n", 2);
	}
	else if (!exec[1] || !*exec[1])
	{
		i = -1;
		while (command->envp[++i])
			printf("%s\n", command->envp[i]);
		ret = 0;
	}
	return (ret);
}
