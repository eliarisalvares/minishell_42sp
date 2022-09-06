/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 20:49:12 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/31 22:30:29 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_minishell	g_minishell;

/**
 * @brief This function is a handler for the SIGINT signal. It is used to
 * print a new line when the user presses Ctrl+C.
 *
 * @param signal The signal received.
 */
static void	handler(int signal)
{
	(void)signal;
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

/**
 * @brief This function will open the shell and wait for input in an infinite
 * loop until the user exits the shell. Firstly, it will change the response
 * to received signals so that them will respond to minishell. Then, it will
 * clear all the structs so they will be ready for the next input. Finally, it
 * will open the prompt and wait for input, then take the input and send to
 * parsing and execution functions.
 */
static void	main_loop(void)
{
	while (1)
	{
		signal(SIGINT, handler);
		signal(SIGQUIT, SIG_IGN);
		free_parser_struct();
		free_command_struct();
		g_minishell.parser = init_parser_struct();
		g_minishell.parser->input = readline("\e[91m🔥 MINISHELL:\e[0m $ ");
		if (ft_is_eof(g_minishell.parser->input))
		{
			ft_putstr_fd("exit", 2);
			free_minishell();
			exit(0);
		}
		add_history(g_minishell.parser->input);
		if (!start_tokenization_process())
			continue ;
		start_execution();
	}
}

/**
 * @brief The main function starts the shell. First, it checks if there are no
 * other arguments than the program name. If there are, it prints an error. If
 * everything is ok, it deals with environment variables and sends both the
 * environment variables and the buffer to the first parsing function.
 */
int	main(int argc, char **argv, char **envp)
{
	if (argc > 1 && argv)
		ft_putstr_fd("Invalid arguments. Try ./minishell\n", 2);
	g_minishell.envp = init_hashtable_struct();
	send_env_to_hashtable(envp);
	g_minishell.parser = NULL;
	g_minishell.command = NULL;
	g_minishell.exit_code = 0;
	main_loop();
	return (0);
}
