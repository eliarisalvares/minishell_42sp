/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_parameter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:15:56 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/30 05:30:53 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	**define_expansion_result(char *expansion);

/**
 * @brief If the token is expandable, this function will expand it first by
 * calling the find_expansion function which will find what kind of substitution
 * is needed. If the '$' token is followed by a '?', the shell responds with the
 * last exit status of the last command executed. If the '$' token is followed
 * by a digit or an invalid environment variable name the shell won't respond.
 * If the '$' token is followed by a valid environment variable name, the shell
 * responds with the value of the environment variable by searching for it in
 * the hashtable.
 */

char	**parameter_expansion(t_token *token, int *index)
{
	char	*expansion;
	char	*pair_key;
	int		count;

	count = 0;
	if (token->token_value[*index] == 63)
		expansion = ft_itoa(g_minishell.exit_code);
	else if (ft_isdigit(token->token_value[*index]))
		expansion = NULL;
	else
	{
		while (ft_isalnum(token->token_value[(*index) + count])
			|| token->token_value[(*index) + count] == 95)
			count++;
		pair_key = ft_strndup(&token->token_value[*index], count--);
		expansion = ft_strdup(key_lookup(pair_key));
		free(pair_key);
	}
	(*index) = (*index) + 1 + (count);
	return (define_expansion_result(expansion));
	if (expansion)
		free(expansion);
}

/**
 * @brief This function will define the result of the expansion
 * to avoid program trying access to unreachable space. So,
 * the first thing to check is whether there was a result to
 * the paramenter expansion proccess. It not, we must return
 * an empty line. Then, to return correctly and environment
 * variable with spaces, we must split the spaces into tokens.
 * 
 */
static char	**define_expansion_result(char *expansion)
{
	char	**expansion_result;

	if (!expansion)
	{
		expansion_result = malloc(1 * sizeof(char *));
		expansion_result[0] = NULL;
	}
	else
		expansion_result = ft_split(expansion, ' ');
	if (expansion)
		free(expansion);
	return (expansion_result);
}
