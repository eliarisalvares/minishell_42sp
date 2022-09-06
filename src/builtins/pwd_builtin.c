/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 21:30:44 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/30 01:22:39 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*get_pwd(void);

/**
 * @brief Prints the current working directory and set the env var PWD using
 * ft_search_envp. According to the subject, pwd should be implemented with
 * no options.
 */
int	pwd_builtin(void)
{
	char	*pwd;

	pwd = get_pwd();
	if (!pwd)
	{
		free(pwd);
		pwd = key_lookup("PWD");
		printf("%s\n", pwd);
	}
	else
		printf("%s\n", pwd);
	free(pwd);
	return (0);
}

/**
 * @brief Gets the current working directory.
 * @return char* The NULL terminated, malloc(3) allocated string with the
 * directory path.
 */

char	*get_pwd(void)
{
	char	*buffer;

	buffer = NULL;
	return (getcwd(buffer, 4096));
}
