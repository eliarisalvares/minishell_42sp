/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_path_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:19:54 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/30 17:03:16 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief This function will ouput to STDERR the correct error message
 * accordin to the number provided.
*/
void	command_path_error(t_cmd *command, int nb)
{
	if (nb == 1)
	{
		g_minishell.exit_code = 127;
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(command->exec[0], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
	else
	{
		g_minishell.exit_code = 127;
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(command->exec[0], 2);
		ft_putstr_fd(": Command not found\n", 2);
	}
}
