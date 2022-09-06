/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dollar_and_quotes.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:15:56 by elraira-          #+#    #+#             */
/*   Updated: 2022/09/06 19:36:11 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	free_expansion(char *expansion);
static void	free_and_replace_value(t_token *token, char *new_value);

/**
 * @brief This function will iterate through the char* string "token_value" and,
 * if it finds a dollar sign, it will replace it with the value of the variable
 * with the same name through the function "expand_parameter". If it finds a
 * quote, it will treat it as a string and will expand it through the function
 * "expand_quotes".
 *
 * @param token
 */
void	expand_dollar_and_quotes(t_token **token)
{
	int		index;

	index = 0;
	while ((*token)->token_value[index])
	{
		if (!ft_strncmp("$EMPTY", (*token)->token_value, 5))
			rl_on_new_line();
		if ((*token)->token_value[index] == 36)
			expand_parameter(token, &index);
		else if ((*token)->token_value[index] == 34
			|| (*token)->token_value[index] == 39)
			expand_quotes(token, &index, (*token)->token_value[index]);
		index++;
	}
}

/**
 * @brief This function will treat the quote expansion. It will iterate through
 * the char* string "token_value" and, if it finds a dollar sign followed by a
 * double quote, it will replace it with the value of the variable with the same
 * name. If it finds a single quote, it will preserve the user input, for
 * example, ig the user types "echo '$USER'", it will print "$USER" instead of
 * the value of the variable $USER. Double quotes will treat what would be
 * considered as multiple tokens as a single token.
 *
 * @param token The token to be treated.
 * @param index The index of the token to be treated.
 * @param value The value of the quote (either ' or ").
 */
void	expand_quotes(t_token **token, int *index, char value)
{
	char	*prev;
	char	*next;
	char	*expansion;
	char	*result;
	int		size;

	prev = ft_strndup((*token)->token_value, *index);
	(*index)++;
	size = 0;
	while ((*token)->token_value[*index + size] && (*token)->token_value[*index + size] != value)
	{
		if ((*token)->token_value[(*index) + size] == 36 && value == 34)
			quote_expansion(*token, *index, &size);
		size++;
	}
	expansion = ft_strndup(&(*token)->token_value[*index], size++);
	result = ft_strjoin(prev, expansion);
	free(prev);
	if (expansion)
		free(expansion);
	next = ft_strdup(&(*token)->token_value[*index + size]);
	*index = ft_strlen(result) - 1;
	free((*token)->token_value);
	(*token)->token_value = ft_strjoin(result, next);
	free(result);
	free(next);
}

/**
 * @brief Parameter expansion is the expansion of a variable name. It will
 * replace the variable name with its value.
 *
 * @param token The token to be treated.
 * @param index The currentindex of the token to be treated.
 */
void	expand_parameter(t_token **token, int *index)
{
	char	*prev;
	char	*next;
	char	**expansion;
	t_token	*last;
	int		count;

	if (!is_expandable((*token)->token_value[(*index) + 1]))
		return ;
	prev = ft_strndup((*token)->token_value, (*index)++);
	expansion = parameter_expansion(*token, index);
	next = ft_strdup(&(*token)->token_value[*index]);
	last = (*token)->next;
	(*token)->next = NULL;
	count = 0;
	free((*token)->token_value);
	(*token)->token_value = ft_strjoin(prev, expansion[count]);
	while (expansion[0] && expansion[++count])
		token_add_back(token, create_new_token(ft_strdup(expansion[count]), 1));
	while ((*token)->next)
		(*token) = (*token)->next;
	free(prev);
	prev = (*token)->token_value;
	free((*token)->token_value);
	(*token)->token_value = ft_strjoin(prev, next);
	(*index) = ft_strlen(expansion[count]) - 1;
	(*token)->next = last;
	free_expansion_array(expansion, next);
}
