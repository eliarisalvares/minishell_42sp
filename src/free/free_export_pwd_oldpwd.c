/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_export_pwd_oldpwd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:15:56 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/30 22:48:06 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_export_pwd_oldpwd(char **export)
{
	int	index;

	index = -1;
	while (export[++index])
		free(export[index]);
	free(export);
}
