/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:01:05 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/30 23:28:14 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	too_many_arguments(void);
static int	numeric_argument_required(char **exec);

/**
 * @brief The exit builtin command. This command exits the current shell with a
 * given status. If omitted the exit status of the last run command is used.
 * 0 (zero) signifies success, non-zero signifies failure. So, it is necessary
 * to check if the command is given a numeric parameter. If not, a error
 * "exit: numeric argument required" will be printed on STDERR and exit
 * status set to 1. If exit is given a numeric argument, we will check if the
 * number of arguments is valid. If it is, we will exit the shell with the given
 * exit status. If it is not, we will print an error message and exit with
 * status 1.
 *
 * @param exec The exec list of parameters.
 * @return int 0 if the command was executed successfully.
 */
int	exit_builtin(char **exec)
{
	int	ret;

	ret = 0;
	if (exec[1] && exec[2])
	{
		too_many_arguments();
		return (1);
	}
	else if (exec[1] && ft_islong(exec[1]))
		ret = ft_atol(exec[1]);
	else if (exec[1] && !ft_islong(exec[1]))
		numeric_argument_required(exec);
	g_minishell.exit_code = ret;
	ft_putstr_fd("exit\n", 2);
	free_minishell();
	exit(g_minishell.exit_code);
	return (0);
}

/**
 * @brief This function is an auxiliary function to the exit function.
 * It will output on STDERR the "exit: too many arguments" message and set the
 * exit status to 1.
 */
static int	too_many_arguments(void)
{
	ft_putendl_fd("Minishell: exit: too many arguments", 2);
	g_minishell.exit_code = 1;
	return (0);
}

/**
 * @brief This function is an auxiliary function to exit function. It will
 * output on STDERR the "numberic argument required" error message. It will also
 * set the exit status to 2.
 * @return int 1 as this function will exit the shell.
 */
static int	numeric_argument_required(char **exec)
{
	ft_putstr_fd("Minishell: exit: ", 2);
	ft_putstr_fd(exec[1], 2);
	ft_putendl_fd(": numeric argument required", 2);
	exit(2);
	return (1);
}
