/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:49:01 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/30 01:33:15 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	cd_lookup(char *variable);
static int	change_current_directory(char *path);

/**
 * @brief This is the main function of the cd builtin. It handles the cd
 * builtin with no arguments (sets the current directory to home), with more
 * arguments than expetected (returns an error), and with the expected
 * arguments (in this case, the cd builtin will lead to the corresponding
 * directory).
 */
int	cd_builtin(char **exec)
{
	char	*parameter;
	int		ret;

	parameter = exec[1];
	ret = 1;
	if (parameter && exec[2])
	{
		ft_putendl_fd("Minishell: cd: too many arguments", 2);
		return (1);
	}
	else if (!parameter || !*parameter || !ft_strncmp(parameter, "~\0", 2)
		|| !ft_strncmp(parameter, "#\0", 2))
		ret = cd_lookup("HOME");
	else if (!ft_strncmp(parameter, "-", 2))
		ret = cd_lookup("OLDPWD");
	else
		ret = change_current_directory(parameter);
	return (ret);
}

/**
 * @brief This function will search for the corresponding variable in the
 * environment and will change the current directory to the value of the
 * variable. If the path variable is not found, the function will return an
 * error.
 */
static int	cd_lookup(char *env)
{
	char	*path;
	int		ret;

	path = key_lookup(env);
	ret = 1;
	if (!path || !*path)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(env, 2);
		ft_putstr_fd(" not set\n", 2);
		g_minishell.exit_code = 1;
	}
	else
	{
		if (!ft_strncmp("OLDPWD", env, 6))
			printf("%s\n", path);
		ret = change_current_directory(path);
	}
	return (ret);
}

/**
 * @brief This function will be called by the cd builtin main function. It will
 * change the current directory to the path passed as a parameter using chdir().
 * Then, it will replace the environment variables $PWD and $OLDPWD.
 * @param path The path to change the current directory to.
 */
static int	change_current_directory(char *path)
{
	char	*oldpwd;
	char	*pwd;
	char	*curr_pwd;
	char	**exec;

	if (chdir(path) == -1)
	{
		ft_putstr_fd("minishell: cd:", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		g_minishell.exit_code = 1;
		return (1);
	}
	oldpwd = ft_strjoin("OLDPWD=", key_lookup("PWD"));
	curr_pwd = get_pwd();
	pwd = ft_strjoin("PWD=", curr_pwd);
	free(curr_pwd);
	exec = export_pwd_oldpwd(pwd, oldpwd);
	export_builtin(exec);
	free_export_pwd_oldpwd(exec);
	return (0);
}
