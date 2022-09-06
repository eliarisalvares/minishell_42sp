/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 23:03:51 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/27 21:08:34 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void	join_args(int number, va_list list, char **result);

char	*ft_strnjoin(int number, ...)
{
	char	*result;
	va_list	list;

	if (number == 0)
		return (NULL);
	va_start(list, number);
	result = NULL;
	join_args(number, list, &result);
	va_end(list);
	return (result);
}

static void	join_args(int number, va_list list, char **result)
{
	char	*buf;
	char	*aux;
	int		i;

	i = -1;
	while (++i < number)
	{
		buf = va_arg(list, char *);
		if (i == 0)
			*result = ft_strdup(buf);
		else
		{
			aux = ft_strjoin(*result, buf);
			if (*result)
				free(*result);
			*result = aux;
		}
	}
}
