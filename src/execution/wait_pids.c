/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_pids.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:04:49 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/27 12:04:17 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief This function will wait for the child processes to finish.
 * WIFEXITED is used to check if the child process has finished.
 * @1024 is the maximum number of processes that can be created at once.
 */
void	wait_pids(int pid[1024], int id)
{
	int		max_id;
	int		wstatus;

	if (id == -1)
		return ;
	max_id = id;
	id = -1;
	wstatus = 0;
	while (++id <= max_id)
		waitpid(pid[id], &wstatus, 0);
	if (WIFEXITED(wstatus))
		g_minishell.exit_code = WEXITSTATUS(wstatus);
}
