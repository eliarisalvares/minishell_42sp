/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_signals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:30:06 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/19 16:54:42 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	quit_handler(int signal);
static void	interrupt_handler(int signal);

/**
 * @brief When executing a command, the child shell can receive the signals
 * SIGQUIT and SIGINT. This function changes the default signals received by
 * these signals, to avoid that these signals will respond to the parent shell,
 * instead of the current.
 */
void	child_signals(void)
{
	signal(SIGINT, interrupt_handler);
	signal(SIGQUIT, quit_handler);
}

/**
 * @brief Handler for the SIGQUIT signal.
 * @param signal The signal received.
 */
static void	interrupt_handler(int signal)
{
	(void)signal;
	free_minishell();
	exit(130);
}

/**
 * @brief Handler for the SIGINT signal.
 * @param signal The signal received.
 */
static void	quit_handler(int signal)
{
	(void)signal;
	free_minishell();
	exit(131);
}
