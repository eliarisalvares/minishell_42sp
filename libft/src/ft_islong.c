/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islong.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 13:38:39 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/27 09:40:10 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_islong(const char *str)
{
	int		i;
	int		neg;
	long	value;

	i = 0;
	value = 0;
	neg = 0;
	while ((str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '-')
		neg = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		if (value > 922337203685477580 || (value == 922337203685477580
				&& ((!neg && str[i] - '0' > 7) || (neg && str[i] - '0' > 8))))
			return (0);
		value = (value * 10) + str[i++] - '0';
	}
	while (ft_isblank(str[i]))
		i++;
	return (str[i] == '\0');
}
