/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pair_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 21:38:48 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/27 21:28:30 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief The pair has a key and a value. This function extracts the key.
 * @param pair The pair string.
 * @return char* The key string.
 */
char	*get_pair_key(char *pair)
{
	char	*pair_key;
	int		index;

	if (!ft_strchr(pair, '='))
		return (NULL);
	index = 0;
	while (pair[index] != '=')
		index++;
	pair_key = malloc(sizeof(char) * (++index));
	if (!pair_key)
		return (NULL);
	ft_strlcpy(pair_key, pair, index);
	return (pair_key);
}
