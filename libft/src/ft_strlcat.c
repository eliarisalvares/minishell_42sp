/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 13:46:50 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/27 09:33:31 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t n)
{
	size_t	srcsize;
	size_t	destsize;

	if (!dest || !src)
		return (0);
	srcsize = ft_strlen(src);
	destsize = ft_strlen(dest);
	if (n < destsize)
		return (srcsize + n);
	else
	{
		dest = dest + destsize;
		ft_strlcpy(dest, src, n - destsize);
		return (srcsize + destsize);
	}
}
