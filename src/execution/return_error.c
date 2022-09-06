/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errno_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:16:59 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/30 16:41:19 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief This function will print the error message corresponding to the errno
 * value.
 *
 * @param filename The file to be used for error messages.
 * @param error_number The error number. EACCES means that the file is 
 * not readable.
 * ENOENT means that the file does not exist.
 *
 */
void	return_error(char *filename, int error_number)
{
	if (error_number == EACCES)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(filename, 2);
		ft_putstr_fd(": Permission denied\n", 2);
		g_minishell.exit_code = 1;
	}
	else if (error_number == ENOENT)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(filename, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		g_minishell.exit_code = 1;
	}
	else
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(filename, 2);
		ft_putstr_fd(": Command not found\n", 2);
		g_minishell.exit_code = 127;
	}
}
