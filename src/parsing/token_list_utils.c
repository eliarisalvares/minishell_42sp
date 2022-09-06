/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 21:25:54 by elraira-          #+#    #+#             */
/*   Updated: 2022/09/01 04:27:59 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief Will create a new t_token node.
 * @param token the token to be added to the node.
 * @param is_sig whether the token is a significant token or not. If it is, it
 * will be defined by the token_type enum using the define_token_type function.
 * @return t_token* the new node.
 */
t_token	*create_new_token(char *token_value, int is_sig)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
	{
		free_minishell();
		exit(12);
	}
	token->token_value = token_value;
	if (!is_sig)
		token->token_type = define_token_type(token_value);
	else
		token->token_type = T_WORD;
	token->next = NULL;
	return (token);
}

/**
 * @brief This function copies a t_token token.
 *
 * @param src The token to be copied.
 * @return t_token* The copied token.
 */
t_token	*token_copy(t_token *src)
{
	t_token	*dest;

	dest = malloc(sizeof(t_token));
	if (!dest)
	{
		free_minishell();
		exit(12);
	}
	dest->token_value = ft_strdup(src->token_value);
	dest->token_type = src->token_type;
	dest->next = NULL;
	return (dest);
}

/**
 * @brief This function will iterate through the t_token list and will
 * return its size.
 *
 * @param list the list to be iterated.
 * @return size_t the size of the list.
 */
size_t	get_lst_size(t_token *lst)
{
	size_t	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

/**
 * @brief add the create t_token node at the back of the tokens linked
 * list.
 *
 * @param head a pointer to the list in which the node will be added.
 * @param new_token the node to be added.
 */
void	token_add_back(t_token **head, t_token *new_token)
{
	t_token	*aux;

	aux = *head;
	if (!aux)
		(*head) = new_token;
	else
	{
		while (aux->next)
			aux = aux->next;
		aux->next = new_token;
	}
}
