/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 19:40:44 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/27 09:33:31 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(const char *s1)
{
	int		length;
	char	*str;

	if (!s1)
		return (NULL);
	length = ft_strlen((char *)s1);
	str = malloc((length + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s1, length);
	str[length] = '\0';
	return (str);
}
