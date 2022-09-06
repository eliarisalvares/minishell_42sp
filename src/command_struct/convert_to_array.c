/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 21:25:54 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/30 06:09:31 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief This function will convert a linked list of tokens into an array of
 * strings.
 *
 * @param token The linked list of tokens to convert.
 * @return The array of strings.
 */
char	**convert_to_array(t_token *token)
{
	size_t	size;
	char	**array;
	int		i;

	size = get_lst_size(token) + 1;
	array = ft_calloc(sizeof(char *), size);
	if (!array)
	{
		free_minishell();
		exit(11);
	}
	i = 0;
	while (token)
	{
		array[i] = ft_strdup(token->token_value);
		token = token->next;
		i++;
	}
	return (array);
}
