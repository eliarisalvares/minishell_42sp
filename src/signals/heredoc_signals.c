/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heredoc_signals.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 20:51:29 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/23 15:44:23 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	handler(int signal);

/**
 * @brief This function will change the default responses of the signals
 * received by the child shell while executing the heredoc, to avoid that these
 * signals will respond to the parent shell, instead of the current.
 */
void	heredoc_child_signal(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, handler);
}

/**
 * @brief Handler for the SIGINT signal received by the child shell while
 * executing the heredoc. This function will free the memory and exit the shell.
 *
 * @param signal The signal received.
 */
static void	handler(int signal)
{
	(void)signal;
	ft_putstr_fd("\n", 2);
	free_minishell();
	exit(130);
}

/**
 * @brief This function will change the default responses of the signals
 * received by the parent shell while executing the heredoc, to avoid that these
 * signals will respond to the child shell, instead of the current. The signal
 * SIGQUIT and SIGINT will be ignored.
 */
void	heredoc_parent_signal(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, SIG_IGN);
}
