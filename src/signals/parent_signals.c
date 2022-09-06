/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_signals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:30:06 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/19 16:56:01 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	handler(int signal);

/**
 * @brief This function changes the default responses of the signals received by
 * the parent shell, to avoid that these signals will respond to the child
 * shell, instead of the current.
 */
void	parent_signals(void)
{
	signal(SIGQUIT, handler);
	signal(SIGINT, handler);
}

/**
 * @brief Handler for the SIGQUIT and SIGINT signals.
 *
 * @param signal The signal received.
 */
static void	handler(int signal)
{
	if (signal == SIGQUIT)
	{
		ft_putstr_fd("Quit\n", 2);
		g_minishell.exit_code = 131;
	}
	if (signal == SIGINT)
	{
		ft_putstr_fd("\n", 2);
		g_minishell.exit_code = 130;
	}
}
