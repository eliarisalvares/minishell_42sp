/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 12:04:27 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/30 06:11:35 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static size_t	ft_countword(const char *str, char c)
{
	size_t	count;

	if (!*str)
		return (0);
	count = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str)
			count++;
		while (*str != c && *str)
			str++;
	}
	return (count);
}

char	**ft_split(const char *str, char c)
{
	char	**lst;
	size_t	word_len;
	int		i;

	lst = (char **)malloc((ft_countword(str, c) + 1) * sizeof(char *));
	if (!str || !lst)
		return (0);
	i = 0;
	while (*str)
	{
		while (*str == c && *str)
			str++;
		if (*str)
		{
			if (!ft_strchr(str, c))
				word_len = ft_strlen(str);
			else
				word_len = ft_strchr(str, c) - str;
			lst[i++] = ft_substr(str, 0, word_len);
			str += word_len;
		}
	}
	lst[i] = NULL;
	return (lst);
}
