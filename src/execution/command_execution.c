/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_execution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:04:49 by elraira-          #+#    #+#             */
/*   Updated: 2022/09/01 04:27:40 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	check_pid(t_cmd **command, pid_t pid[1024], int id);

/**
 * @brief Executables are first searched for in the "PATH" environment variable.
 * The PATH variable is a list of directories separated by the ":" character.
 * So, to search for an executable, we iterate through the PATH variable and
 * check if the executable exists in each directory. Then, we must fork and
 * execute the command and then wait for the child to finish so that the prompt
 * can be displayed again. For example, if the command is "ls", then we must
 * search for ls, usr/bin/ls or /bin/ls to find the executable and then execute
 * it. The fork is needed so that when its execution ends, the minishell
 * isn't interrupted.
 * @pid If the pid is -1, then an error has occurred and minishell should exit.
 * If the pid is 0, then the child process should execute the command.
 * The parent process should wait for the child to finish and all the file
 * descriptors should be closed.
 * @1024 is the maximum number of processes that can be created at once.
 *
 * @param command The command to be executed.
 */
void	command_execution(t_cmd **command)
{
	pid_t	pid[1024];
	int		id;

	id = -1;
	while (*command)
	{
		parent_signals();
		(*command)->exec_path = get_command_path(*command);
		create_execution_envp(*command);
		if ((*command)->fd_in == -1 || (*command)->fd_out == -1)
			return_error((*command)->filename, (*command)->error_number);
		else if ((*command)->exec_path && is_forked_command(*command))
		{
			pid[++id] = fork();
			check_pid(command, pid, id);
		}
		close_single_file_descriptor(*command, IN_OUT);
		*command = (*command)->next;
	}
	wait_pids(pid, id);
}

static void	check_pid(t_cmd **command, pid_t pid[1024], int id)
{
	if (pid[id] == -1)
	{
		free_minishell();
		exit(11);
	}
	if (pid[id] == 0)
		child_execution(*command);
}
