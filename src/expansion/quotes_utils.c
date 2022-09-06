/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:15:56 by elraira-          #+#    #+#             */
/*   Updated: 2022/09/06 19:31:53 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*find_what_to_replace(t_token *token, int *index);

/**
 * @brief If the token is expandable, this function will expand it first by
 * calling the find_what_to_replace function which will find what kind of
 * substitution is needed. If the '$' token is followed by a '?', the shell
 * responds with the  last exit status of the last command executed. If the '$'
 * token is followed by a digit or an invalid environment variable name the
 * shell won't respond. If the '$' token is followed by a valid environment
 * variable name, the shell responds with the value of the environment variable
 * by searching for it in the hashtable.
 */

void	quote_expansion(t_token *token, int start, int *size)
{
	char	*prev;
	char	*expansion;
	char	*next;
	int		index;

	index = start + (*size);
	if (is_expandable(token->token_value[index + 1]))
	{
		prev = ft_strndup(token->token_value, index++);
		expansion = find_what_to_replace(token, &index);
		next = ft_strdup(&token->token_value[index]);
		free (token->token_value);
		token->token_value = ft_strnjoin(3, prev, expansion, next);
		*size = (*size) + ft_strlen(expansion) - 2;
		if (expansion)
			free(expansion);
		free(prev);
		free(next);
	}
}

/**
 * This function will find what needs to be the replacement for the
 * expansion: the exit_code or the environment variable. If a
 * digit follows the '$', it won't be expanded. 
*/
static char	*find_what_to_replace(t_token *token, int *index)
{
	char	*expansion;
	char	*pair_key;
	int		count;

	count = 0;
	if (token->token_value[*index] == '?')
		expansion = ft_itoa(g_minishell.exit_code);
	else if (ft_isdigit(token->token_value[*index]))
		expansion = NULL;
	else
	{
		while (ft_isalnum(token->token_value[(*index) + count]))
			count++;
		pair_key = ft_strndup(&token->token_value[*index], count--);
		expansion = ft_strdup(key_lookup(pair_key));
		free(pair_key);
	}
	*index = (*index) + 1 + (count);
	return (expansion);
}
