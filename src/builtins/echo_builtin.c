/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:49:01 by elraira-          #+#    #+#             */
/*   Updated: 2022/09/06 18:52:05 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief Prints the arguments following "echo" and a newline. The "-n" option
 * omits the trailing newline. So, first we check if the "-n" option is present,
 * and if it is, we set the n_option variable to 1. If it is not, we set the
 * n_option variable to 0. At the end, we print the arguments, and if the "-n"
 * option is not present, the new line is printed.
 */
int	echo_builtin(char **exec)
{
	int		n_option;
	int		i;

	i = 1;
	n_option = 0;
	while (exec[i] && exec[i][0] == '-' && exec[i][1] == 'n')
	{
		n_option = 1;
		i++;
	}
	while (exec && exec[i])
	{
		printf("%s", exec[i++]);
		if (exec[i])
			printf(" ");
	}
	if (n_option == 0)
		printf("\n");
	return (0);
}
