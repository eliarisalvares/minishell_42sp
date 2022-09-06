/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pair_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 21:38:48 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/27 21:27:48 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief The pair has a key and a value. This function extracts the value.
 * @param pair The pair string.
 * @return char* The value string.
 */
char	*get_pair_value(char *pair)
{
	char	*pair_value;
	int		index;

	if (!ft_strchr(pair, '='))
		return (NULL);
	index = 0;
	while (pair[index] != '=')
		index++;
	pair_value = ft_strdup(&pair[++index]);
	return (pair_value);
}
