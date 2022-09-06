/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_charset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 20:24:55 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/27 09:33:31 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static char	**free_table(char **tab, int i)
{
	while (i-- > 0)
		free(tab[i]);
	free(tab);
	return (NULL);
}

static char	*push(char *str, int begin, int end)
{
	int		i;
	char	*aux;

	i = 0;
	aux = malloc(sizeof(char) * (end - begin + 1));
	if (!aux)
		return (NULL);
	while (begin < end)
	{
		aux[i] = str[begin];
		i++;
		begin++;
	}
	aux[i] = '\0';
	return (aux);
}

static int	sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (!sep(str[i], charset)
			&& (sep(str[i + 1], charset) || str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

char	**ft_split_charset(char *str, char *charset)
{
	char	**ret;
	int		begin;
	int		word;
	int		i;

	ret = malloc(sizeof(char *) * (count_words(str, charset) + 1));
	if (!ret)
		return (NULL);
	i = -1;
	word = -1;
	while (str[++i] != '\0')
	{
		if (!sep(str[i], charset)
			&& (i == 0 || sep(str[i - 1], charset)))
			begin = i;
		if ((i != 0 && sep(str[i], charset) && !sep(str[i - 1], charset))
			|| (str[i + 1] == '\0' && !sep(str[i], charset)))
			ret[++word] = push(str, begin, i + (!sep(str[i], charset)));
		if (word != -1 && !ret[word])
			return (free_table(ret, word));
	}
	ret[++word] = 0;
	return (ret);
}
