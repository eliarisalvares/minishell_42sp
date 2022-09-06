/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_expansion_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:15:56 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/30 01:23:52 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief This function will iterate through the tokens members of the double
 * pointer string freeing them and then freeing the string itself.
 * If there's still a token left, it will free it too.
 *
 * @param str The string to be freed.
 * @param next
 */
void	free_expansion_array(char **str, char *next)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	if (next)
		free(next);
}
