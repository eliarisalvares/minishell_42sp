/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 23:03:51 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/27 09:33:31 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*c_s;

	if (!s || !f)
		return (NULL);
	c_s = (char *)malloc((ft_strlen((char *)s) + 1) * sizeof(char));
	i = -1;
	if (c_s == NULL)
		return (NULL);
	while (s[++i] != '\0')
		c_s[i] = (*f)(i, s[i]);
	c_s[i] = '\0';
	return (c_s);
}
