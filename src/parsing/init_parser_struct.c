/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parser_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:36:21 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/30 01:24:52 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief This function will allocate memory for the parser struct and
 * initialize all its members.
 *
 * @return t_parser* The parser struct.
 */
t_parser	*init_parser_struct(void)
{
	t_parser	*parser;

	parser = malloc(sizeof(t_parser));
	if (!parser)
	{
		free_minishell();
		exit(12);
	}
	parser->input = NULL;
	parser->tokens = NULL;
	return (parser);
}
