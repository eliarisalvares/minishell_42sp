/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:49:01 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/30 18:46:10 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief Will change the value of the PWD and OLDPWD in the environment
 * after cd is executed.
*/
char	**export_pwd_oldpwd(char *pwd, char *oldpwd)
{
	char	**exec;
	char	*command;

	exec = ft_calloc(4, sizeof(char *));
	if (!exec)
		return (NULL);
	command = ft_strdup("export");
	exec[0] = command;
	exec[1] = pwd;
	exec[2] = oldpwd;
	return (exec);
}
