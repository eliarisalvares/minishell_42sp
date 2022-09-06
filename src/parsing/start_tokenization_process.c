/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_tokenization_process.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:20:53 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/30 05:42:14 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_valid_command(void);

/**
 * @brief This function will tokenize the input line. First, it will split it
 * by the spaces, then assign each element to a token_type defined by the
 * enum token_type (see minishell.h). Then, it will create a linked list of
 * tokens. Each token has a token_type, a token_value and a next pointer.
 * The value is the actual word, the type is the type of the word (see
 * enum token_type) and the next pointer is the next token in the linked list.
 *
 * @return int 0 in casa of failure(incorrect syntax), 1 otherwise.
 */
int	start_tokenization_process(void)
{
	char	*input;
	size_t	index;
	size_t	prev;
	size_t	next;
	size_t	size;

	input = g_minishell.parser->input;
	index = 0;
	prev = index;
	next = index;
	size = 0;
	while (1)
	{
		if (is_valid_token(input, index, prev))
			next = index;
		size = next - prev;
		if (size > 0)
			token_list(&input[prev], size);
		if (!input[index])
			break ;
		prev = next;
		index++;
	}
	return (is_valid_command());
}

int	is_valid_command(void)
{
	if (check_bash_grammar())
	{
		fill_command_table();
		return (1);
	}
	return (0);
}
